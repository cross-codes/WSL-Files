import express from "express";
import http from "http";
import path from "path";
import { Server } from "socket.io";

const app = express();
const server = http.createServer(app);
const io = new Server(server);

const port = process.env.PORT || 3000;
const publicPath = path.join(new URL("../public", import.meta.url).pathname);

app.use(express.static(publicPath));

io.on("connection", (socket) => {
  console.log("New WebSocket connection");

  socket.emit("message", "Welcome");
  socket.broadcast.emit("message", "A new user has joined");

  socket.on("sendMessage", (message) => {
    io.emit("sendMessage", message);
  });

  socket.on("sendLocation", (locationString) => {
    io.emit("sendLocation", locationString);
  });

  socket.on("disconnect", () => {
    io.emit("message", "A user has left");
  });
});

server.listen(port, () => {
  console.log(`Server is up on port ${port}`);
});
