import bcrypt from "bcryptjs";
import jwt from "jsonwebtoken";
import mongoose from "mongoose";
import validator from "validator";

const userSchema = new mongoose.Schema({
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
    unique: true,
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
    minLength: 7,
    validator(value) {
      if ((value.toLowerCase().includes("password"))) {
        throw new Error("You can do better than that");
      }
    },
  },
  tokens: [
    {
      token: {
        type: String,
        required: true,
      },
    },
  ],
});

userSchema.methods.toJSON = function() {
  const userObject = this.toObject();
  delete userObject.password;
  delete userObject.tokens;

  return userObject;
};

userSchema.methods.generateAuthToken = async function() {
  // 'this' contains the userSchema data object
  const token = jwt.sign({ _id: this._id.toString() }, "generateAuth");
  this.tokens = this.tokens.concat({ token });
  await this.save(); // Save token into database, so that comparisons can be made later

  return token;
};

// Find a user by credentials (used for login)
userSchema.statics.findByCredentials = async function(email, password) {
  const user = await User.findOne({ email });

  if (!user) {
    throw new Error("Unable to login");
  }

  const isMatch = await bcrypt.compare(password, user.password);

  if (!isMatch) {
    throw new Error("Unable to login");
  }

  return user;
};

// Hash the plain text password
userSchema.pre("save", async function(next) {
  // "this" contains the userSchema data object
  if (this.isModified("password")) {
    this.password = await bcrypt.hash(this.password, 8);
  }
  next();
});

const User = mongoose.model("User", userSchema);

export default User;
