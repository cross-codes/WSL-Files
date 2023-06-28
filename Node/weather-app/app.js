const geocode = require("./utils/geocode");
const forecast = require("./utils/forecast");

const location = process.argv[2];

if (!location) {
  console.log("Please enter a valid location");
} else {
  geocode.geocode(location, (geocodeError, geocodeData) => {
    if (geocodeError) {
      return console.log(geocodeError);
    }
    forecast.forecast(geocodeData.latitude, geocodeData.longitude, (weatherError, weatherData) => {
      if (weatherError) {
        return console.log(weatherError);
      }
      console.log("Location: " + geocodeData.location);
      console.log(
        "Description: " + weatherData.description + ", Temperature: " + weatherData.temperature + ", Humidity: "
          + weatherData.humidity,
      );
    });
  });
}
