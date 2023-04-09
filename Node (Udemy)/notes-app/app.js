const validator = require("validator");
const add = require("./utils");
const getNotes = require("./notes");

const sum = add(111, -69);
console.log(sum);

const val = getNotes();
console.log(val);
console.log(validator.isEmail("gmail.com"));
console.log(validator.isURL("https://youtube.com"));
