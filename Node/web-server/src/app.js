const express = require("express");

const app = express();

app.get("", (req, res) => {
  res.send("Hello Express");
});

app.get("/help", (req, res) => {
  res.send("Help page");
});

app.get("/about", (req, res) => {
  res.send("About page");
});

app.get("/weather", (req, res) => {
  res.send("Weather watch");
});

app.listen(3000, () => {
  console.log("Server is running on port 3000");
});
