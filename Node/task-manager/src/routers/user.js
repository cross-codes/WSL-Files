import express from "express";
import User from "../models/users.js";
const router = new express.Router();

router.post("/users", async (req, res) => {
  const user = new User(req.body);
  try {
    await user.save();
    const token = await user.generateAuthToken();
    res.send({ user, token });
    res.status(201);
  } catch (e) {
    res.status(400);
    res.send(e);
  }
});

router.post("/users/login", async (req, res) => {
  try {
    const user = await User.findByCredentials(req.body.email, req.body.password);
    const token = await user.generateAuthToken();
    res.send({ user, token });
  } catch (e) {
    res.status(400);
    res.send();
  }
});

router.get("/users", async (req, res) => {
  try {
    const users = await (User.find({}));
    res.send(users);
  } catch (e) {
    res.status(500);
    res.send(e);
  }
});

router.get("/users/:id", async (req, res) => {
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

router.patch("/users/:id", async (req, res) => {
  const updates = Object.keys(req.body);
  const allowedUpdates = ["name", "age", "password", "email"];
  const isValidOperation = updates.every((update) => allowedUpdates.includes(update));

  if (!isValidOperation) {
    return res.status(400).send({ error: "Attempt to update invalid methods" });
  }
  try {
    const user = await User.findById(req.params.id);
    updates.forEach((update) => {
      user[update] = req.body[update];
    });
    await user.save();
    if (!user) {
      return res.status(404).send();
    }
    res.send(user);
  } catch (e) {
    res.status(404);
    res.send();
  }
});

router.delete("/users/:id", async (req, res) => {
  try {
    const user = await User.findByIdAndDelete(req.params.id);
    if (!user) {
      return res.status(404).send();
    }
    res.send(user);
  } catch (e) {
    res.status(500);
    res.send();
  }
});

export default router;
