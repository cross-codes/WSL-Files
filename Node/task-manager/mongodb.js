// Crud operations - Create, Read, Update and Delete operations

const mongodb = require("mongodb");
const MongoClient = mongodb.MongoClient;
const ObjectID = mongodb.ObjectId;

const connectionURL = "mongodb://127.0.0.1:27017";
const databaseName = "task-manager";

MongoClient.connect(connectionURL, { useNewUrlParser: true }, (error, client) => {
  if (error) {
    return console.log("Unable to connect to database");
  }

  const db = client.db(databaseName);

  db.collection("users").findOne({ _id: new ObjectID("64736cb709e2fb399d50f5f4") }, (error, user) => {
    if (error) {
      return console.log("Unable to fetch");
    }

    console.log(user);
  });

  db.collection("users").find({ age: 30 }).toArray((error, users) => {
    if (error) {
      return console.log("Unable to connect to database");
    }

    console.log(users);
  });

  db.collection("users").find({ age: 30 }).count((error, users) => {
    if (error) {
      return console.log("Unable to connect to database");
    }

    console.log(users);
  });
});
