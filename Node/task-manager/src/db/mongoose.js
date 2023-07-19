import mongoose from "mongoose";

mongoose.connect("mongodb://0.0.0.0:27017/task-manager-api", {
  useNewUrlParser: true,
  useCreateIndex: true,
  useFindAndModify: false,
});
