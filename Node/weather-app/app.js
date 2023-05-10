const geocode = require("./utils/geocode");
const forecast = require("./utils/forecast");

const location = process.argv[2];

if (!location) {
  console.log("Please enter a valid location");
} else {
  geocode.geocode(location, (error_g, data_g) => {
    if (error_g) {
      return console.log(error_g);
    }
    forecast.forecast(data_g.latitude, data_g.longitude, (error_w, data_w) => {
      if (error_w) {
        return console.log(error_w);
      }
      console.log("Location: " + data_g.location);
      console.log(
        "Description: " + data_w.description + ", Temperature: " + data_w.temperature + ", Humidity: "
          + data_w.humidity,
      );
    });
  });
}
