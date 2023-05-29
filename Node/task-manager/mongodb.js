// Crud operations - Create, Read, Update and Delete operations

// db.collection("users").insertOne({
//   name: "Prashanth Rao",
//   age: 60,
// }, (error, result) => {
//   if (error) {
//     return console.log("Unable to insert user");
//   }
//   console.log(result);
// });
// db.collection("users").insertMany([
//   {
//     name: "Jyothi",
//     age: 47,
//   },
//   {
//     name: "Tavish",
//     age: 19,
//   },
// ], (error, result) => {
//   if (error) {
//     console.log("Unable to insert documents");
//   } else {
//     console.log(result);
//   }
// });

const mongodb = require("mongodb");
const MongoClient = mongodb.MongoClient;

const connectionURL = "mongodb://127.0.0.1:27017";
const databaseName = "task-manager";

MongoClient.connect(connectionURL, { useNewUrlParser: true }, (error, client) => {
  if (error) {
    return console.log("Unable to connect to database");
  }

  const db = client.db(databaseName);

  db.collection("tasks").insertMany([
    {
      description: "This is a test task",
      completed: true,
    },
    {
      description: "Configure neovim to be the best editor in the world",
      completed: true,
    },
    {
      description: "Go to sleep",
      completed: false,
    },
  ], (error, response) => {
    if (error) {
      console.log("Unable to insert documents");
    } else {
      console.log(response);
    }
  });
});
