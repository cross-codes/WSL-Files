import got from "got";

const convert = async function(amount, from, to, date) {
  const url = `https://api.apilayer.com/exchangerates_data/convert?to=${encodeURIComponent(to)}&from=${
    encodeURIComponent(from)
  }&amount=${encodeURIComponent(amount)}&date=${encodeURIComponent(date)}&apikey=${
    encodeURIComponent(process.env.API_KEY)
  }`;

  try {
    const response = await got.get(url, {
      throwHttpErrors: false,
    });
    const body = JSON.parse(response.body);
    if (body.error) {
      console.log("Please validate input");
      return null;
    }
    if (body.success) {
      return { converted: body.result, date: body.date };
    } else {
      console.log("Unable to convert between currencies. Please validate input");
      return null;
    }
  } catch (error) {
    console.log("An error was encountered");
  }
};

export default convert;
