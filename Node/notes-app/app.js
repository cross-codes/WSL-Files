const chalk = require("chalk");
const yargs = require("yargs");
const notes = require("./notes");

// Customise yargs version
yargs.version("1.1.0");

// Creating an add command
yargs.command({
  command: "add",
  describe: "Add a new note",
  builder: {
    title: {
      describe: "Note title",
      demandOption: true,
      type: "string",
    },
    body: {
      descibe: "Note body",
      demandOption: true,
      type: "string",
    },
  },
  handler: function(argv) {
    notes.addNote(argv.title, argv.body);
  },
});

// Creating a remove command
yargs.command({
  command: "remove",
  describe: "Remove a note",
  builder: {
    title: {
      describe: "Title to be removed",
      demandOption: true,
      type: "string",
    },
  },
  handler: function(argv) {
    notes.removeNote(argv.title);
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

yargs.parse();
