const chalk = require("chalk");
const add = require("./utils");
const getNotes = require("./notes");

const sum = add(111, -69);
console.log(sum);

const val = getNotes();
console.log(val);

console.log(chalk.green.bold.inverse("Success!"));
