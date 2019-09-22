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

};

int main()
{
    int h, x;
    cin >> h >> x;

    int num = 1;
    for (int i = 0; i < h; i++)
        num *= 2;
    num -= 1;

    x %= num;

    int size = num + 1;
    int len = size;
    
    vector<bool> arr(size, false);
    int res = 0;
    int count = 0;
    while (count < x && len >= 1)
    {
        int pos = 0;
        while (pos < size)
        {
            for (int i = 0; i < size; i+=len)
            {
                if (arr[i])
                    continue;
                else
                {
                    count += 1;
                    if (count == x)
                    {
                        cout << i << endl;
                        return 0;
                    }
                    arr[i] = true;
                }
            }
            pos += len;
        }
        len /= 2;
    }
    cout << res << endl;

    return 0;
}