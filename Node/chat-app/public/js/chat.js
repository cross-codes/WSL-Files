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
