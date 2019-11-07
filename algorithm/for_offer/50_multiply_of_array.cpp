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
    vector<int> multiply(const vector<int>& A) {
        int size = A.size();
        vector<int> ret(size, 1);

        for (int i = 1; i < size; i++)
        {
            ret[i] = ret[i - 1] * A[i - 1];
        }

        vector<int> tmp(size, 1);
        for (int i = size - 2; i >= 0; i--)
        {
            tmp[i] = tmp[i + 1] * A[i + 1];
        }

        for (int i = 0; i < size; i++)
        {
            ret[i] *= tmp[i];
        }
        
        return ret;
    }
};

int main()
{
    return 0;
}