#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iterator>
#include <numeric>

using namespace std;

class Solution
{
public:
    void push(int node) {
        while(!stack2.empty())
        {
            stack1.push(stack2.top());
            stack2.pop();
        } 
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty())
        {
            stack2.push(stack1.top());
            stack1.pop();
        }
        int top = stack2.top();
        stack2.pop();
        return top;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};

int main()
{
    return 0;
}