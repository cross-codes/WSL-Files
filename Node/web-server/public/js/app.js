console.log("Client side JS file is loaded");

fetch("http://localhost:3000/weather?address=Boston").then((response) => {
  response.json().then((data) => {
    if (data.error) {
      console.log(data.error);
    } else {
      console.log(data.description);
      console.log(data.humidity);
      console.log(data.temperature);
      console.log(data.location);
    }
  });
});
