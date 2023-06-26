import "../src/db/mongoose.js";
import Task from "../src/models/tasks.js";

// Task.findByIdAndRemove("64872f835bef0b5deba2b72f").then((task) => {
//   console.log(task);
//   return Task.countDocuments({ completed: false });
// }).then((result) => {
//   console.log(result);
// }).catch((e) => {
//   console.log(e);
// });

const deleteTaskAndCount = async (id) => {
  const task = await Task.findByIdAndRemove(id);
  const count = await Task.countDocuments({ completed: false });

  return count;
};

deleteTaskAndCount("648f47a37556ec63921c5438").then((count) => {
  console.log(count);
}).catch((e) => {
  console.log(e);
});
