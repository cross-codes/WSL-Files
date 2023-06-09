#define csum(A) (A * (A + 1) / 2)

int sumOfMultiples(int n) {
  int lim1 = n / 3, lim2 = n / 5, lim3 = n / 7, nlim1 = n / 15, nlim2 = n / 21,
      nlim3 = n / 35, nlim4 = n / 105;

  return (3 * csum(lim1) + 5 * csum(lim2) + 7 * csum(lim3) - 15 * csum(nlim1) -
          21 * csum(nlim2) - 35 * csum(nlim3) + 105 * csum(nlim4));
}
