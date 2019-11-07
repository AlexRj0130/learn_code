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
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    vector<int> b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    int no = 0, ne = 0, mo = 0, me = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2)
            no++;
        else
            ne++;
    }
    for (int i = 0; i < m; i++)
    {
        if (b[i] % 2)
            mo++;
        else
            me++;
    }
    int ret = 0;
    ret = no < me ? no : me;
    ret += (ne < mo ? ne : mo);
    cout << ret << endl;

    return 0;
}