#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
  int n, num, sum = 0, l, idx = 0;
  int mx[] = {0, 1, 0, -1, 1, 1, -1, -1};
  int my[] = {1, 0, -1, 0, 1, -1, 1, -1};
  string s[1500], part;
  bool shouldAdd;

  ifstream input("day3_input.txt");

  while (getline(input, s[idx++]));
  n = s[0].size();
  for (int k = 0; k < idx; k++) {
    std::cout << s[k] << endl;
    for (int i = 0; i < n; i++) {
      if (s[k][i] >= '0' && s[k][i] <= '9') {
        num = 0;
        shouldAdd = false;
        for (l = i; l < n; l++) {
          if (s[k][l] >= '0' && s[k][l] <= '9') {
            num *= 10;
            num += s[k][l] - '0';
            s[k][l] = '.';
            if (!shouldAdd) {
              for (int j = 0; j < 8; j++) {
                if (k + my[j] < 0 || k + my[j] >= idx || l + mx[j] < 0 || l + mx[j] >= n) continue;
                // *&@/+-%$=#
                if (s[k + my[j]][l + mx[j]] == '*' || s[k + my[j]][l + mx[j]] == '&' || s[k + my[j]][l + mx[j]] == '@' || s[k + my[j]][l + mx[j]] == '/' || s[k + my[j]][l + mx[j]] == '+' || s[k + my[j]][l + mx[j]] == '-' || s[k + my[j]][l + mx[j]] == '%' || s[k + my[j]][l + mx[j]] == '$' || s[k + my[j]][l + mx[j]] == '=' || s[k + my[j]][l + mx[j]] == '#') {
                  std::cout << k + my[j] << " " << l + mx[j] << ":" << s[k + my[j]][l + mx[j]] << ' ';
                  shouldAdd = true;
                  break;
                }
              }
            }
          } else break;
        }
        std::cout << num << endl;
        i = l - 1;
        if (shouldAdd) sum += num;
      }
    }
  }
  ofstream output("day3_output.txt");
  for (int i = 0; i < idx; i++)
    output << s[i] << endl;
  std::cout << sum << endl;
  return 0;
}
