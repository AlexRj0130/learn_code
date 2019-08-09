#include <iostream>
#include <stdlib.h>

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
    vector<int> GetLeastNumbers_Solution(vector<int> input, int k) {
        // priority_queue<int, vector<int>, greater<int> > heap;
        priority_queue<int> heap;  // Note: 这个是大顶堆，上面那个是小顶堆

        for (int i = 0; i < input.size(); i++)
        {
            heap.push(input[i]);
            while(heap.size() > k)
            {
                heap.pop();
            }
        }

        vector<int> ret;
        while(!heap.empty())
        {
            ret.push_back(heap.top());
            heap.pop();
        }
        reverse(ret.begin(), ret.end());

        return ret.size() == k ? ret : vector<int>();
    }
};

int main()
{
    return 0;
}