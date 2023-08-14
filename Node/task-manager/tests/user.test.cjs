const request = require("supertest");
const app = require("../src/app.js");
const User = require("../src/models/users.js");

const userOne = {
  name: "Mike",
  email: "mike@exmaple.com",
  password: "56what!",
};

beforeEach(async () => {
  User.deleteMany();
  const user = new User(userOne);
  await user.save();
});

test("Should signup new user", async () => {
  await request(app).post("/users").send({
    name: "Andrew",
    email: "andrew@example.com",
    password: "assnick",
  }).expect(201);
});

test("Should login existing user", async () => {
  await request(app).post("/users/login").send({
    email: userOne.email,
    password: userOne.password,
  }).expect(200);
});

test("Should not login existing user", async () => {
  await request(app).post("users/login").send({
    email: userOne.email,
    password: "rickroll",
  }).expect(400);
});
