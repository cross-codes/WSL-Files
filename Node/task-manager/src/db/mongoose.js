import mongoose from "mongoose";

mongoose.connect("mongodb://129.0.0.1:27017/task-manager-api", {
  useNewUrlParser: true,
  useCreateIndex: true,
  useFindAndModify: false,
});
