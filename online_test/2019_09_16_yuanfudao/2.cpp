#include <iostream>
#include <fstream>
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
    int n, s;
    cin >> n >> s;
    vector<int> vec(n);
    for (int i = 0; i < n; i++)
        cin >> vec[i];

    int max = 0;
    int sta = 0;
    int sum = 0;
    for (int end = 0; end < n; end++)
    {
        sum += vec[end];
        while (sum > s && sta <= end)
        {
            sum -= vec[sta];
            sta++;
        }
        int count = end - sta + 1;
        max = max > count ? max : count;
    }
    cout << max << endl;

    return 0;
}