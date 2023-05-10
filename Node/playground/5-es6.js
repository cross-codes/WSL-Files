// Object property shorthand

const name = "Andrew";
const userAge = 27;

const user = {
  name,
  userAge,
  location: "Philadelphia",
};

console.log(user);

// Object destructuring

const product = {
  label: "Black notebook",
  price: 3,
  stock: 201,
  salePrice: undefined,
};

// const label = product.label;
// const stock = product.stock;

const { label: prodLabel, stock, rating } = product;
console.log(prodLabel);
console.log(stock);
console.log(rating);

const transaction = (type, { label, stock }) => {
  console.log(type, label, stock);
};

transaction("order", product);
