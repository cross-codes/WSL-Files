const mongoose = require("mongoose");

mongoose.connect("mongodb://127.0.0.1:27017/task-manager-api", {
  useNewUrlParser: true,
  useCreateIndex: true,
});

const Task = mongoose.model("Task", {
  description: {
    type: String,
  },
  completed: {
    type: Boolean,
  },
});

const test = new Task({
  description: "This is a test task",
  completed: true,
});

test.save().then(() => {
  console.log(test);
}).catch((error) => {
  console.log("Error ", error);
});
