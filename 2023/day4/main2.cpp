#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    ifstream input("day4_input.txt");
    string s;
    long long answer = 0;

    map<int, int> myMap;
    for (int i = 0; i < 210; i++)
    {
        myMap[i] = 0;
    }
    while (getline(input, s))
    {
        stringstream ss(s);
        string word;
        int gameNo;
        vector<int> myNumbers;
        vector<int> winningNumbers;
        bool isMyNumbers = false;
        while (ss >> word)
        {
            if (word == "Card")
            {
                ss >> word;
                gameNo = stoi(word);
                myMap[gameNo]++;
            }
            else
            {
                if (word == "|")
                {
                    isMyNumbers = true;
                }
                else
                {
                    if (isMyNumbers)
                    {
                        myNumbers.push_back(stoi(word));
                    }
                    else
                    {
                        winningNumbers.push_back(stoi(word));
                    }
                }
            }
        }
        int count = 0, prevIdx = 100000;
        for (int i = 0; i < myNumbers.size(); i++)
        {
            for (int j = 0; j < winningNumbers.size(); j++)
            {
                if (myNumbers[i] == winningNumbers[j])
                {
                    count++;
                    prevIdx = j;
                    break;
                }
            }
        }
        for (int i = gameNo + 1; i <= gameNo + count; i++)
            myMap[i] += myMap[gameNo];
    }
    for (int i = 0; i < 210; i++)
        answer += myMap[i];
    cout << answer << endl;
    return 0;
}