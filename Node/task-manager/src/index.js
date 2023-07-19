import express from "express";
import "./db/mongoose.js";
import Task from "./models/tasks.js";
import User from "./models/users.js";

const app = express();
const port = process.env.PORT || 3000;

app.use(express.json());

app.post("/users", async (req, res) => {
  const user = new User(req.body);

  try {
    await user.save();
    res.status(201);
    res.send(user);
  } catch (e) {
    res.status(400);
    res.send(e);
  }
});

app.get("/users", async (req, res) => {
  try {
    const users = await (User.find({}));
    res.send(users);
  } catch (e) {
    res.status(500);
    res.send(e);
  }
});

app.get("/users/:id", async (req, res) => {
  const _id = req.params.id;

  try {
    const user = await (User.findById(_id));
    if (!user) {
      return res.status(404).send();
    }
    res.send(user);
  } catch (e) {
    res.status(500);
    res.send(e);
  }
});

app.patch("/users/:id", async (req, res) => {
  const updates = Object.keys(req.body);
  const allowedUpdates = ["name", "age", "password", "email"];
  const isValidOperation = updates.every((update) => allowedUpdates.includes(update));

  if (!isValidOperation) {
    return res.status(400).send({ error: "Attempt to update invalid methods" });
  }
  try {
    const user = await User.findByIdAndUpdate(req.params.id, req.body, { new: true, runValidators: true });
    if (!user) {
      return res.status(404).send();
    }
    res.send(user);
  } catch (e) {
    res.status(404);
    res.send();
  }
});

app.post("/tasks", async (req, res) => {
  const task = new Task(req.body);

  try {
    await task.save();
    res.status(201);
    res.send(task);
  } catch (e) {
    res.status(400);
    res.send(e);
  }
});

app.get("/tasks", async (req, res) => {
  try {
    const tasks = await (Task.find({}));
    res.send(tasks);
  } catch (e) {
    res.status(500);
    res.send(e);
  }
});

app.get("/tasks/:id", async (req, res) => {
  const _id = req.params.id;

  try {
    const task = await (Task.findById(_id));
    if (!task) {
      return res.status(404).send();
    }
    res.send(task);
  } catch (e) {
    res.status(500);
    res.send(e);
  }
});

app.listen(port, () => {
  console.log(`Server is up on port ${port}`);
});
