const { calculateTip } = require("../src/math.js");

test("Should calculate total with tip ", () => {
  const total = calculateTip(10, 0.300);

  expect(total).toBe(13);
});
