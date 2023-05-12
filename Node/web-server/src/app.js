const path = require("path");
const express = require("express");
const hbs = require("hbs");

// NOTE: The website is on http://localhost:3000/

const app = express();

const viewPath = path.join(__dirname, "../templates/views");
const publicPath = path.join(__dirname, "../public");
const partialPath = path.join(__dirname, "../templates/partials");

app.set("view engine", "hbs");
app.set("views", viewPath);
app.use(express.static(publicPath));
hbs.registerPartials(partialPath);

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
    title: "Help",
    name: "Akshaj Rao",
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
