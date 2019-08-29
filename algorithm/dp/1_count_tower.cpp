#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <sstream>

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution
{
public:
    int CountTower(const vector<vector<int> > & array, int h)
    {
        vector<vector<int> > tmp(array);
        for (int i = h - 2; i >= 0; i--)
        {
            for (int j = 0; j <= i; j++)
            {
                int left = tmp[i + 1][j];
                int right = tmp[i + 1][j + 1];
                tmp[i][j] += (left > right ? left : right);
            }
        }
        return tmp[0][0];
    }
};

int main()
{
    string path = "D:\\users\\Documents\\code\\learn_code\\debug\\"; // windows format
    ifstream cin;
    cin.open(path + "data.dat");
    if (!cin.is_open())
    {
        cout << "open failed..." << endl;
        return 0;
    }

    int n;
    cin >> n;
    while(n--)
    {
        int h;
        cin >> h;
        vector<vector<int> > array;
        for (int i = 1; i <= h; i++)
        {
            vector<int> arrayTmp;
            for (int j = 0; j < i; j++)
            {
                int tmp;
                cin >> tmp;
                arrayTmp.push_back(tmp);
            }
            array.push_back(arrayTmp);
        }

        Solution solution;
        cout << solution.CountTower(array, h) << endl;
    }
    
    return 0;
}