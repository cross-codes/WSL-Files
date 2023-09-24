import got from "got";

const list = async function(base, date, currencies) {
  const url = `https://api.apilayer.com/exchangerates_data/${encodeURIComponent(date)}?base=${
    encodeURIComponent(base)
  }&symbols=${encodeURIComponent(currencies.join(","))}&apikey=${encodeURIComponent(process.env.API_KEY)}`;

  try {
    const response = await got.get(url, {
      throwHttpErrors: false,
    });
    const body = JSON.parse(response.body);
    if (body.error) {
      console.log("Please validate error");
      return null;
    }
    if (body.success) {
      return body.rates;
    } else {
      console.log("Unable to determine currency rates. Please validate input");
      return null;
    }
  } catch (e) {
    console.log("An error was encountered");
  }
};

export default list;
