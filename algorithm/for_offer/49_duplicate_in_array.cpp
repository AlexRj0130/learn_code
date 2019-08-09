#include <iostream>
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

class Solution {
public:
    // Parameters:
    //        numbers:     an array of integers
    //        length:      the length of array numbers
    //        duplication: (Output) the duplicated number in the array number
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    bool duplicate(int numbers[], int length, int* duplication) {
        vector<int> count(length, 0);
        for (int i = 0; i < length; i++)
        {
            count[numbers[i]]++;
            if (count[numbers[i]] > 1)
            {
                *duplication = numbers[i];
                return true;
            }
        }
        return false;
    }
};

int main()
{
    return 0;
}