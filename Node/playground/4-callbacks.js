// setTimeout(() => {
//   console.log("Two seconds are up");
// }, 2000);
//
// const names = ["Akshaj", "Ayush"];
// const shortNames = names.filter((name) => {
//   return name.length <= 4;
// });
//
// const geocode = (address, callback) => {
//   setTimeout(() => {
//     const data = {
//       latitude: 0,
//       longitude: 0,
//     };
//     callback(data);
//   }, 2000);
// };
//
// geocode("Bangalore", (data) => {
//   console.log(data);
// });

const add = (x, y, callback) => {
  setTimeout(() => {
    const sum = x + y;

    callback(sum);
  }, 2000);
};

add(1, 4, (sum) => {
  console.log(sum); // Should print: 5
});
