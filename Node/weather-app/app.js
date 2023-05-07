const api = require("./.secrets.js");
const request = require("request");

_API_KEY = api.apikey;
const url = "http://api.openweathermap.org/data/2.5/find?q=Mangalore&units=metric&type=accurate&APPID=" + _API_KEY;

request({ url: url, json: true }, (error, response) => {
  console.log(response.body.list[0]);
});
