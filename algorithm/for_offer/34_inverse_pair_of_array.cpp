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

using namespace std;

class Solution {
public:
    int InversePairs(vector<int> data) {
        int count = 0;
        for (int i = 0; i < data.size(); i++)
        {
            for (int j = i + 1; j < data.size(); j++)
            {
                if (data[i] > data[j])
                    count++;
            }
        }
        return count;
    }
};

int main()
{
    return 0;
}