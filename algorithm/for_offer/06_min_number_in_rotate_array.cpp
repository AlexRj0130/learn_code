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
    int minNumberInRotateArray(vector<int> rotateArray) {
        if (0 == rotateArray.size())
            return 0;
        if (1 == rotateArray.size())
            return rotateArray[0];
        if (2 == rotateArray.size())
            return rotateArray[0] < rotateArray[1] ? rotateArray[0] : rotateArray[1];
        
        int mid = rotateArray.size() / 2;
        if ((rotateArray[0] <= rotateArray[mid]) && (rotateArray[mid] <= rotateArray[rotateArray.size() - 1]))
            return rotateArray[0];
        else if ((rotateArray[0] <= rotateArray[mid]) && (rotateArray[mid] > rotateArray[rotateArray.size() - 1]))
            return minNumberInRotateArray(vector<int>(rotateArray.begin() + mid, rotateArray.end()));
        else
            return minNumberInRotateArray(vector<int>(rotateArray.begin(), rotateArray.begin() + mid + 1));
    }
};

int main()
{
    return 0;
}