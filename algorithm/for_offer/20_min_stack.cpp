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
    void push(int value) {
        if (minStk.empty() || value <= minStk.top())
            minStk.push(value);
        stk.push(value);
    }

    void pop() {
        int tmp = stk.top();
        stk.pop();

        if (tmp == minStk.top())
            minStk.pop();
    }

    int top() {
        return stk.top();
    }

    int min() {
        return minStk.top(); 
    }

private:
    stack<int> stk;
    stack<int> minStk;
};

int main()
{
    return 0;
}