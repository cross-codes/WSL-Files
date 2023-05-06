const api = require("./.secrets.js");
const request = require("request");

_API_KEY = api.apikey;
const url = "http://api.openweathermap.org/data/2.5/find?q=Pilani&units=imperial&type=accurate&APPID=" + _API_KEY;

request({ url: url }, (error, response) => {
  const data = (JSON.parse(response.body)).list;
  console.log(data);
});
