// Examples
// "eyJhbGciOiJIUzI1NiJ9.eyJSb2xlIjoic3NzcyIsIklzc3VlciI6ImFzcyIsIlVzZXJuYW1lIjoiYWFhYSIsImV4cCI6MTY4OTUyOTAyMiwiaWF0IjoxNjg5NTI5MDIyfQ.6S4cRSzDF0JC-qmh1SUX_XvmyKgD5_m1Md5-yqlvzhs"

import jwt_decode from "jwt-decode";

const token =
  "eyJhbGciOiJIUzI1NiJ9.eyJSb2xlIjoic3NzcyIsIklzc3VlciI6ImFzcyIsIlVzZXJuYW1lIjoiYWFhYSIsImV4cCI6MTY4OTUyOTAyMiwiaWF0IjoxNjg5NTI5MDIyfQ.6S4cRSzDF0JC-qmh1SUX_XvmyKgD5_m1Md5-yqlvzhs";
const decoded = jwt_decode(token);

console.log(decoded);
