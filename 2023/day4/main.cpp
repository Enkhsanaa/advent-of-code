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

    while (getline(input, s))
    {
        stringstream ss(s);
        string word;
        int gameNo;
        vector<string> myNumbers;
        vector<string> winningNumbers;
        bool isMyNumbers = false;
        while (ss >> word)
        {
            // cout << word << endl;
            if (word == "Card")
            {
                ss >> word;
                gameNo = stoi(word);
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
                        myNumbers.push_back(word);
                    }
                    else
                    {
                        winningNumbers.push_back(word);
                    }
                }
            }
        }
        int count = 0, prevIdx = 100000;
        for (int j = 0; j < winningNumbers.size(); j++)
        {
            for (int i = 0; i < myNumbers.size(); i++)
            {
                if (myNumbers[i] == winningNumbers[j])
                {
                    if (prevIdx < j)
                    {
                        count *= 2;
                    }
                    else
                    {
                        count++;
                    }
                    // cout << i << " " << prevIdx << " " << j << " " << myNumbers[i] << " " << winningNumbers[j] << endl;
                    prevIdx = j;
                    break;
                }
            }
        }
        // cout << count << endl;
        answer += count;
    }
    cout << answer << endl;
    return 0;
}