const chalk = require("chalk");
const add = require("./utils");
const getNotes = require("./notes");

const sum = add(111, -69);

console.log(sum);

const val = getNotes();
console.log(val);

console.log(chalk.blue.bold("Error!"));
const command = process.argv[2];

if (command === "add") {
  console.log("Adding note");
} else if (command === "remove") {
  console.log("Removing note");
}
