import "../src/db/mongoose.js";
import User from "../src/models/users.js";

User.findByIdAndUpdate("64972aad3aed9171235db43b", { age: 20 }).then((user) => {
  console.log(user);
  return User.countDocuments({ age: 20 });
}).then((result) => {
  console.log(result);
}).catch((e) => {
  console.log(e);
});
