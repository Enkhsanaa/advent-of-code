#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

string s[20000];
int N = 0, M;
int mx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int my[] = {-1, 0, 1, -1, 1, -1, 0, 1};
bool visited[1500][1500];
int answer = 0;

bool isNumber(char c)
{
    return c >= '0' && c <= '9';
}

bool isX(char c)
{
    return c == 'x';
}

bool isOtherChar(char c)
{
    // '*', '%', '-', '#', '=', '@', '$', '/', '+', '&'
    return c == '*' || c == '%' || c == '-' || c == '#' || c == '=' || c == '@' || c == '$' || c == '/' || c == '+' || c == '&';
}

bool isGear(char c)
{
    return c == '*';
}

int scrapeNumber(int x, int y)
{
    while (isNumber(s[x][--y]))
        ;
    y++;
    int number = 0;
    while (isNumber(s[x][y]))
    {
        number *= 10;
        number += s[x][y] - '0';
        s[x][y++] = 'x';
    }
    return number;
}

int exploreMap(int x, int y)
{
    int num1 = -1, num2 = -1;
    visited[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int xx = x + mx[i], yy = y + my[i];
        if (xx >= 0 && xx < N && yy >= 0 && yy < M && !visited[xx][yy] && isNumber(s[xx][yy]))
        {
            int num = scrapeNumber(xx, yy);
            if (num1 == -1)
                num1 = num;
            else
            {
                if (num2 == -1)
                {
                    num2 = num;
                }
                else
                {
                    return 0;
                }
            }
        }
    }
    if (num1 != -1 && num2 != -1)
        return num1 * num2;
    return 0;
}

int main()
{
    ifstream input("day3_input.txt");

    while (getline(input, s[N++]))
        ;
    M = s[0].size();

    vector<pair<int, int> > startingPoint;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            visited[i][j] = false;
            if (isGear(s[i][j]))
                startingPoint.push_back(make_pair(i, j));
        }
    }

    for (int i = 0; i < startingPoint.size(); i++)
    {
        int x = startingPoint[i].first, y = startingPoint[i].second;
        if (!visited[x][y])
            answer += exploreMap(x, y);
    }

    std::cout << answer << endl;
    return 0;
}