const functions = require("../src/math.cjs");

test("Should calculate total with tip ", () => {
  const total = functions.calculateTip(10, 0.300);

  expect(total).toBe(13);
});

test("Should convert 32F to 0C", () => {
  const temp = functions.fahrenheitToCelsius(32);

  expect(temp).toBe(0);
});

test("Should convert 0C to 32F", () => {
  const temp = functions.celsiusToFahrenheit(0);

  expect(temp).toBe(32);
});

test("Should add two numbers", (done) => {
  functions.add(2, 3).then((sum) => {
    expect(sum).toBe(5);
  });
});
