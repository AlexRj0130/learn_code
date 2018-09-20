#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

class LearnDeque
{
public:
    void dequeInit()
    {
        deque<int> dq;
        dq.push_front(12);
        print_elem_deque(dq);  // 输出 12    

    }

private:
    void print_elem_deque(deque<int> & dq)
    {
        deque<int>::iterator iter = dq.begin();
        deque<int>::iterator iter_end = dq.end();
        for (; iter != iter_end; ++iter)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
};


int main()
{
    LearnDeque ld;

    ld.dequeInit();

    system("pause");
    return 0;
}