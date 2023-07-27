import express from "express";
import "./db/mongoose.js";
import taskRouter from "./routers/task.js";
import userRouter from "./routers/user.js";

const app = express();
const port = process.env.PORT || 3000;
const maintenanceMode = false;

app.use((req, res, next) => {
  if (!maintenanceMode) {
    next();
  } else {
    res.status(503);
    res.send("The server is temporarily down, please try again later");
  }
});

app.use(express.json());
app.use(userRouter);
app.use(taskRouter);

app.listen(port, () => {
  console.log(`Server is up on port ${port}`);
});
