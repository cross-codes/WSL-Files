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

io.on("connection", () => {
  console.log("New WebSocket connection");
});

server.listen(port, () => {
  console.log(`Server is up on port ${port}`);
});
