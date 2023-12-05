#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  int n, num, sum = 0, firstDigit, lastDigit;
  string s, digits[] = {"one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

  ifstream input("day1_input.txt");

  while (input >> s) {
    cout << s << ' ';
    n = s.size();
    firstDigit = -1;
    lastDigit = -1;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < 9; j++) {
        if (s.substr(i, digits[j].size()) == digits[j]) {
          if (firstDigit == -1) {
            firstDigit = j + 1;
          }
          lastDigit = j + 1;
        }
      }
      if ('0' <= s[i] && s[i] <= '9') {
        if (firstDigit == -1) {
          firstDigit = s[i] - '0';
        }
        lastDigit = s[i] - '0';
      }
    }
    num = firstDigit * 10 + lastDigit;
    cout << num << endl;
    sum += num;
  }
  cout << sum << endl;
  return 0;
}
