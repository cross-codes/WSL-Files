import "../src/db/mongoose.js";
import Task from "../src/models/tasks.js";

Task.findByIdAndRemove("64872f835bef0b5deba2b72f").then((task) => {
  console.log(task);
  return Task.countDocuments({ completed: false });
}).then((result) => {
  console.log(result);
}).catch((e) => {
  console.log(e);
});
