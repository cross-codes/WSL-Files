const chalk = require("chalk");
const yargs = require("yargs");
const getNotes = require("./notes");

// Customise yargs version
yargs.version("1.1.0");

// Creating an add command
yargs.command({
  command: "add",
  describe: "Add a new note",
  handler: function() {
    console.log("Adding a new note!");
  },
});

// Creating a remove command
yargs.command({
  command: "remove",
  describe: "Remove a note",
  handler: function() {
    console.log("Removing the note");
  },
});

// Creating a list commmand
yargs.command({
  command: "list",
  describe: "List notes available",
  handler: function() {
    console.log("Listing available notes");
  },
});

// Creating a read command
yargs.command({
  command: "read",
  describe: "Read a note",
  handler: function() {
    console.log("Reading a note");
  },
});

console.log(yargs.argv);
