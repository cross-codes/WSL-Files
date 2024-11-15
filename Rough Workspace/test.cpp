#pragma GCC target("avx2,bmi2,popcnt,lzcnt")
#include <bits/stdc++.h>

std::random_device rd{};
std::mt19937_64 gen{rd()};

double gen_uniform_random(double a, double b) {
  std::uniform_real_distribution<double> distribution(a, b);
  return distribution(gen);
}

int32_t main() {
  // array[] is as defined in the question
  double cumulative[] = {0.30, 0.80, 0.85, 1.00};
  int states[1000];

  for (int i = 0; i < 1000; i++) {
    double x = gen_uniform_random(0, 1);
    for (int j = 0; j < 4; j++) {
      if (cumulative[j] > x) {
        states[i] = j + 1;
        break;
      }
    }
  }

  for (int state : states) {
    std::cout << "State: " << state << "\n";
  }
  return 0;
}
