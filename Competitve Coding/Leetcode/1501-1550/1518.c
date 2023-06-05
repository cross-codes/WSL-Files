int numWaterBottles(int numBottles, int numExchange) {
  int numDrunk = 0, numFull = numBottles, numEmpty = 0;

  while (numFull != 0) {
    numDrunk += numFull;
    numEmpty += numFull;
    numFull = numEmpty / numExchange;
    numEmpty -= numFull * numExchange;
  }

  return numDrunk;
}
