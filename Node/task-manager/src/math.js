const calculateTip = function(total, TipPercent) {
  const tip = total * TipPercent;
  return total + tip;
};

module.exports = {
  calculateTip,
};
