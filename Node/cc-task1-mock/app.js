import dotenv from "dotenv";
import readline from "readline";
import geocode from "./utils/geocode.js";
import getWeather from "./utils/weather.js";

dotenv.config();

const prompt = readline.createInterface({
  input: process.stdin,
  output: process.stdout,
});

prompt.question("Enter your location: ", async (location) => {
  const coordinates = await geocode(location);
  if (coordinates) {
    await getWeather(coordinates);
  }
  prompt.close();
});
