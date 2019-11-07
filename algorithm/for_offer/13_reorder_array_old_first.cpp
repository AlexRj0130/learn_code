#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
    void reOrderArray(vector<int> &array) {
        queue<int> tmp1, tmp2;
        for(int i = 0; i < array.size(); i++)
        {
            if (array[i] % 2 != 0)
                tmp1.push(array[i]);
            else
                tmp2.push(array[i]);            
        }

        int index = 0;
        while(!tmp1.empty())
        {
            array[index++] = tmp1.front();
            tmp1.pop();
        }
        while(!tmp2.empty())
        {
            array[index++] = tmp2.front();
            tmp2.pop();
        }
    }
};

int main()
{
    return 0;
}