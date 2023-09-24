import Table from "cli-table";
import dotenv from "dotenv";
import readline from "readline";
import convert from "./utils/convert.js";
import list from "./utils/list.js";

dotenv.config();

const prompt = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

const getUserInput = (question) => {
  return new Promise((resolve) => {
    prompt.question(question, (input) => {
      resolve(input);
    });
  });
};

const main = async () => {
  try {
    const from = await getUserInput("Enter the currency code you want to convert from: ");
    const to = await getUserInput("Enter the currency code you want to convert to: ");
    const amount = await getUserInput("Enter the base amount: ");
    const date = await getUserInput("Enter date (YYYY-MM-DD): ");

    const response = await convert(amount, from, to, date);
    if (response && response.converted) {
      console.log(
        `${amount} ${from} is equivalent to ${
          parseFloat((response.converted).toFixed(2))
        } ${to} as of ${response.date}`,
      );
      const conversions = await list(from, date, ["USD", "EUR", "CAD", "INR", "JPY", "GBP"]);
      if (conversions) {
        const table = new Table({
          head: ["Currency", `Equivalent value to 1 ${from}`],
          colWidths: [15, 30],
        });
        Object.keys(conversions).forEach((currency) => {
          table.push([currency, conversions[currency].toFixed(2)]);
        });
        console.log(table.toString());
      }
    }
  } catch (error) {
    console.error("An error occurred:", error);
  } finally {
    prompt.close();
  }
};

main();
