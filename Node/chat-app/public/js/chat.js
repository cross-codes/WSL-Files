const socket = io();

socket.on("message", (message) => {
  console.log(message);
});

document.querySelector("#messageForm").addEventListener("submit", (e) => {
  e.preventDefault();
  socket.emit("sendMessage", e.target.elements.message.value);
});

socket.on("sendMessage", (message) => {
  console.log(message);
});

document.querySelector("#send-location").addEventListener("click", () => {
  if (!navigator.geolocation) {
    return alert("Geolocation is not supported by your browser");
  }

  navigator.geolocation.getCurrentPosition((position) => {
    const location = {};
    location.latitude = position.coords.latitude;
    location.longitude = position.coords.longitude;

    socket.emit("sendLocation", `https://google.com/maps?q=${location.latitude},${location.longitude}`);
  });
});

socket.on("sendLocation", (locationString) => {
  console.log(locationString);
});
