import mongoose from "mongoose";
import validator from "validator";

mongoose.connect("mongodb://127.0.0.1:27017/task-manager-api", {
  useNewUrlParser: true,
  useCreateIndex: true,
});

const User = mongoose.model("User", {
  name: {
    type: String,
    required: true,
    trim: true,
  },
  age: {
    type: Number,
    default: 0,
    validate(value) {
      if (value < 0) {
        throw new Error("Age must be a positive number");
      }
    },
  },
  email: {
    type: String,
    required: true,
    trim: true,
    lowercase: true,
    validator(value) {
      if (!validator.isEmail(value)) {
        throw new Error("Email is invalid");
      }
    },
  },
  password: {
    type: String,
    required: true,
    trim: true,
    min: [7, "Password length must be atleast 7 characters"],
    validator(value) {
      if ((value.toLowerCase().includes("password"))) {
        throw new Error("You can do better than that");
      }
    },
  },
});

const Task = mongoose.model("Task", {
  description: {
    type: String,
    trim: true,
    required: true,
  },
  completed: {
    type: Boolean,
    required: false,
    default: false,
  },
});

const user = new User({
  name: "Scaramouche",
  age: 500,
  email: "scaramouche_06@fatui.org",
  password: "shoukinokami",
});

const task = new Task({
  description: "This task passes validation",
});

task.save().then(() => {
  console.log(task);
}).catch(error => {
  console.log(`Error: ${error}`);
});
