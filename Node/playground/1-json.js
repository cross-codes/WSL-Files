const fs = require("fs");
/*
const book = {
  title: "Physics for Scientists and Engineers",
  author: "Serway and Jewett",
};

const bookJSON = JSON.stringify(book);
console.log(bookJSON);

const parsedData = JSON.parse(bookJSON);
console.log(parsedData.author);

fs.writeFileSync("test.json", bookJSON);

const dataBuffer = fs.readFileSync("test.json");
const dataJSON = dataBuffer.toString();
const data = JSON.parse(dataJSON);
console.log(data.title);
*/

const dataBuffer = fs.readFileSync("1-json.json");
const dataJSON = dataBuffer.toString();
const data = JSON.parse(dataJSON);
data.name = "Cross";
data.age = 19;

const userJSON = JSON.stringify(data);
fs.writeFileSync("1-json.json", userJSON);
