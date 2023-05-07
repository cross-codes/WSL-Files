const api = require("./.secrets.js");
const request = require("request");

const _API_KEY = api.apikey;
const url_w =
  "http://api.openweathermap.org/data/2.5/weather?lat=51.509865&lon=-0.118092&units=metric&type=accurate&appid="
  + _API_KEY;

const url_g = "http://api.openweathermap.org/geo/1.0/direct?q=Delhi&limit=1&appid=" + _API_KEY;

request({ url: url_w, json: true }, (error, response) => {
  if (error) {
    console.log("Unable to connect to the weather service!");
  } else if (response.body.message) {
    console.log("Unable to find given location");
  } else {
    const main_body_w = response.body;
    console.log(
      "Description: " + main_body_w.weather[0].description + ". It is currently " + main_body_w.main.temp
        + " degrees out. The humidity is " + main_body_w.main.humidity + "%.",
    );
  }
});

request({ url: url_g, json: true }, (error, response) => {
  if (error) {
    console.log("Unable to connect to the geolocation service!");
  } else if (response.body.length === 0) {
    console.log("Given location not found!");
  } else {
    const main_body_g = response.body[0];
    const latitude = main_body_g.lat;
    const longitude = main_body_g.lon;
    console.log("The latitute is: " + latitude + " and the longitude is: " + longitude + ".");
  }
});
