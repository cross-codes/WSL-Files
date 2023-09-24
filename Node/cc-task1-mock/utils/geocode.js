import got from "got";

const geocode = async function(address) {
  const url = "http://api.openweathermap.org/geo/1.0/direct?q="
    + encodeURIComponent(address)
    + "&limit=1&appid="
    + process.env.API_KEY;

  try {
    const res = await got.get(url);
    if (res.statusCode !== 200) {
      console.log("Unable to find coordinates of given location");
      return undefined;
    }
    const data = JSON.parse(res.body);
    if (data.length === 0) {
      console.log("Unable to find coordinates of given location");
      return undefined;
    }
    return { latitude: data[0].lat, longitude: data[0].lon };
  } catch (error) {
    console.log("Failed to connect with geolocation API");
    return undefined;
  }
};

export default geocode;
