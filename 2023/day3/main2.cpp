#include <cstdio>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

int N, M;
int mx[] = {0, 1, 0, -1, 1, 1, -1, -1};
int my[] = {1, 0, -1, 0, 1, -1, 1, -1};
string s[150];
bool visited[150][150];
vector <int> numbers;

bool isX(char c) {
  return c == 'x';
}

bool isNumber(char c) {
  return c >= '0' && c <= '9';
}

bool isGear(char c) {
  return c == '*';
}

int exploreNumber(int x, int y) {
  while (isNumber(s[x][--y]));
  y++;
  int number = 0;
  for (int i = y; i < M; i++) {
    if (isNumber(s[x][i])) {
      number *= 10;
      number += s[x][i] - '0';
      s[x][i] = 'x';
    } else break;
  }
  return number;
}

void exploreGear(int x, int y) {
  visited[x][y] = true;
  if (isNumber(s[x][y])) numbers.push_back(exploreNumber(x, y));
  for (int i = 0; i < 8; i++) {
    int xx = x + mx[i], yy = y + my[i];
    if (xx < 0 || xx >= N || yy < 0 || yy >= M) continue;
    if (!visited[xx][yy] && (isNumber(s[xx][yy]) || isGear(s[xx][yy]) || isX(s[xx][yy]))) {
      exploreGear(xx, yy);
    }
  }
}

int main() {
  ifstream input("day3_input.txt");
  vector <pair<int, int>> startPoints;

  N = 0;
  while (getline(input, s[N++]));

  M = s[0].size();
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      visited[i][j] = false;
      if (s[i][j] == '*') startPoints.push_back(make_pair(i, j));
    }
  }
  int points = startPoints.size(), sum = 0;
  for (int i = 0; i < points; i++) {
    int x = startPoints[i].first, y = startPoints[i].second;
    if (visited[x][y]) continue;
    exploreGear(x, y);
    int numbersSize = numbers.size();
    if (numbersSize == 2) {
      int product = 1;
      for (int j = 0; j < numbersSize; j++) {
        product *= numbers[j];
      }
      sum += product;
    }
    numbers.clear();
  }
  std::cout << sum << endl;
  return 0;
}