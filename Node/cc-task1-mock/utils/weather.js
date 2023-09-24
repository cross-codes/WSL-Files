import got from "got";

const getWeather = async function(coordinates) {
  const url = "http://api.openweathermap.org/data/2.5/weather?lat=" + encodeURIComponent(coordinates.latitude) + "&lon="
    + encodeURIComponent(coordinates.longitude)
    + "&units=metric&type=accurate&appid="
    + process.env.API_KEY;

  console.log(url);

  try {
    const res = await got.get(url);
    if (res.statusCode !== 200) {
      console.log("Unable to find weather data for given location");
      return null;
    }
    const data = JSON.parse(res.body);
    console.log(data);
  } catch (error) {
    console.log("Failed to connect with weather API");
  }
};

export default getWeather;
