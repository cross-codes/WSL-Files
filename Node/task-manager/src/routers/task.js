import express from "express";
import Task from "../models/tasks.js";
const router = new express.Router();

router.post("/tasks", async (req, res) => {
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

router.get("/tasks", async (req, res) => {
  try {
    const tasks = await (Task.find({}));
    res.send(tasks);
  } catch (e) {
    res.status(500);
    res.send(e);
  }
});

router.get("/tasks/:id", async (req, res) => {
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

router.patch("/tasks/:id", async (req, res) => {
  const updates = Object.keys(req.body);
  const allowedUpdates = ["completed", "description"];
  const isValidOperation = updates.every((update) => allowedUpdates.includes(update));

  if (!isValidOperation) {
    return res.status(400).send({ error: "Attempt to update invalid methods" });
  }

  try {
    const user = await Task.findByIdAndUpdate(req.params.id, req.body, { new: true, runValidators: true });
    if (!user) {
      return res.status(404).send();
    }
    res.send(user);
  } catch (e) {
    res.status(404);
    res.send();
  }
});

router.delete("/tasks/:id", async (req, res) => {
  try {
    const task = await Task.findByIdAndDelete(req.params.id);

    if (!task) {
      return res.status(404).send();
    }

    res.send(task);
  } catch (e) {
    res.status(500);
    res.send();
  }
});

export default router;
