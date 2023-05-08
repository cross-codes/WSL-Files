const request = require("request");
const api = require("../.env");

const _API_KEY = api.apikey;

const forecast = (latitude, longitude, callback) => {
  const url = "http://api.openweathermap.org/data/2.5/weather?lat=" + encodeURIComponent(latitude) + "&lon="
    + encodeURIComponent(longitude)
    + "&units=metric&type=accurate&appid="
    + _API_KEY;

  request({ url: url, json: true }, (error, response) => {
    if (error) {
      callback("Unable to connect to the weather service!", undefined);
    } else if (response.body.message) {
      callback("Unable to find given location", undefined);
    } else {
      callback(undefined, {
        description: response.body.weather[0].description,
        temperature: response.body.main.temp,
        humidity: response.body.main.humidity,
      });
    }
  });
};

module.exports = {
  forecast: forecast,
};
