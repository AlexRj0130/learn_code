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

int main()
{
    int n, q;
    cin >> n >> q;

    priority_queue<int> heap;
    for (int i = 0; i < n; i++)
    {
        int tmp ;
        cin >> tmp;
        heap.push(tmp);
    }
    
    stack<int> stk;
    for (int i = 0; i < q; i++)
    {
        int count = 0;
        int tmp ;
        cin >> tmp;
        while (!heap.empty() && tmp <= heap.top())
        {
            int top = heap.top();
            heap.pop();
            top--;
            stk.push(top);
            count ++;
        };
        while(!stk.empty())
        {
            heap.push(stk.top());
            stk.pop();
        }
        cout << count << endl;
    }

    return 0;
}