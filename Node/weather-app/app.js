const geocode = require("./utils/geocode");
const forecast = require("./utils/forecast");

geocode.geocode("Reykjavik", (error, data) => {
  console.log("Error", error);
  console.log("Data", data);
});

forecast.forecast(-75.7088, 44.1545, (error, data) => {
  console.log("Error", error);
  console.log("Data", data);
});
