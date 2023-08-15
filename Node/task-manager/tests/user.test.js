import jwt from "jsonwebtoken";
import mongoose from "mongoose";
import request from "supertest";
import app from "../src/app.js";
import User from "../src/models/users.js";

const userOneID = new mongoose.Types.ObjectId();
const userOne = {
  _id: userOneID,
  name: "Mike",
  email: "mike@exmaple.com",
  password: "56what!",
  tokens: [{
    token: jwt.sign({ _id: userOneID }, process.env.JWT_SECRET),
  }],
};

beforeEach(async () => {
  await User.deleteMany();
  const user = new User(userOne);
  await user.save();
});

test("Should signup new user", async () => {
  const response = await request(app).post("/users").send({
    name: "Andrew",
    email: "andrew@example.com",
    password: "aaron!!__",
  }).expect(200);

  // Assert that the database was changed correctly
  const user = await User.findById(response.body.user._id);
  expect(user).not.toBeNull();

  // Assertions about the response
  expect(response.body).toMatchObject({
    user: {
      name: "Andrew",
      email: "andrew@example.com",
    },
    token: user.tokens[0].token,
  });
  expect(user.password).not.toBe("aaron!!__");
});

test("Should login existing user", async () => {
  const response = await request(app).post("/users/login").send({
    email: userOne.email,
    password: userOne.password,
  }).expect(200);

  const user = await User.findById(userOneID);
  expect(response.body.token).toBe(user.tokens[1].token);
});

test("Should not login existing user", async () => {
  await request(app).post("/users/login").send({
    email: userOne.email,
    password: "rickroll",
  }).expect(400);
});

test("Should get profile for user", async () => {
  await request(app).get("/users/me")
    .set("Authorization", `Bearer ${userOne.tokens[0].token}`)
    .send()
    .expect(200);
});

test("Should not get profile for unauthorized user", async () => {
  await request(app)
    .get("/users/me")
    .send()
    .expect(401);
});

test("Should delete account for user", async () => {
  await request(app)
    .delete("/users/me")
    .set("Authorization", `Bearer ${userOne.tokens[0].token}`)
    .send()
    .expect(200);

  const user = await User.findById(userOneID);
  expect(user).toBeNull();
});

test("Should not delete account if unauthorized", async () => {
  await request(app)
    .delete("/users/me")
    .send()
    .expect(401);
});
