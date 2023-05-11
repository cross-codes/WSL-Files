const path = require("path");
const express = require("express");

// NOTE: The website is on http://localhost:3000/

const app = express();

app.set("view engine", "hbs");
app.use(express.static(path.join(__dirname, "../public")));

app.get("", (req, res) => {
  res.render("index", {
    title: "Weather App",
    name: "Akshaj Rao",
  });
});

app.get("/about", (req, res) => {
  res.render("about", {
    title: "About Me",
    name: "Akshaj Rao",
  });
});

app.get("/help", (req, res) => {
  res.render("help", {
    message: "What a noob",
  });
});

app.get("/weather", (req, res) => {
  res.send({
    weather: "weather",
    location: "location",
  });
});

app.listen(3000, () => {
  console.log("Server is running on port 3000");
});
