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

int main()
{
    int num;
    cin >> num;
    int five = 5;
    int two = 2;
    int count = 0;
    int pos = -1;
    for (int i = 0; i < 29; i++)
    {
        if (((five & num) + (two & num)) == five)
        {
            count++;
            if (pos == -1)
                pos = i;
        }
        five = (five << 1);
        two = (two << 1);
    }
    cout << count << " " << pos << endl;
    return 0;
}