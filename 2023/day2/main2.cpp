#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main() {
  int n, num, sum = 0, powerSum = 0, gameNo = 0, r, g, b, maxR, maxG, maxB;
  int rgb[3] = {12, 13, 14};
  bool validGame = false;
  string s, part;

  ifstream input("day2_input.txt");

  while (getline(input, s)) {
    istringstream iss(s);
    n = s.size();
    while (iss >> part) {
      if (part == "Game") {
        iss >> part;
        if (validGame) {
          sum += gameNo;
          std::cout << "Add: " << gameNo << endl;
        }
        powerSum += maxR * maxG * maxB;
        std::cout << s << endl;
        gameNo = stoi(part);
        r = g = b = 0;
        maxR = maxG = maxB = 0;
        validGame = true;
        continue;
      }
      if (part[0] <= '9' && part[0] >= '0') {
        num = stoi(part);
        iss >> part;
        if (part[0] == 'r') {
          r += num;
        } else if (part[0] == 'g') {
          g += num;
        } else if (part[0] == 'b') {
          b += num;
        }
        if (part[part.size() - 1] == ',') {
          continue;
        } else {
          std::cout << r << " " << g << " " << b << endl;
          if (r > rgb[0] || g > rgb[1] || b > rgb[2]) {
            std::cout << "Invalid game: " << gameNo << endl;
            validGame = false;
          }
          maxR = max(maxR, r);
          maxG = max(maxG, g);
          maxB = max(maxB, b);
          r = 0;
          g = 0;
          b = 0;
        }
      }
    }
  }
  if (validGame) {
    sum += gameNo;
    std::cout << "Add: " << gameNo << endl;
  }
  powerSum += maxR * maxG * maxB;
  std::cout << sum << endl;
  std::cout << powerSum << endl;
  return 0;
}
