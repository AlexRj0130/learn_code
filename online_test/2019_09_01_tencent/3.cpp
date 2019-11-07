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
    vector<int> box(n + 1);
    vector<int> p(n + 1, 0);
    vector<int> pTmp(n + 1, 0);
    p[0] = m;

    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> box[i];
        sum += box[i];
    }

    int count = 0;
    while (sum > 0)
    {
        count ++;
        for (int i = 0; i < n; i++)
        {
            p[i] += pTmp[i];
            pTmp[i] = 0;
        }

        for (int i = n - 1; i >= 0; i--)
        {
            if (box[i] == 0)
            {
                pTmp[i + 1] += p[i];
                p[i] = 0;
                continue;
            }
            if (box[i] < p[i])
            {
                int tmp = p[i] - box[i];
                pTmp[i + 1] += tmp;
                p[i] -= tmp;
                continue;
            }
        }

        for (int i = 0; i <= n; i++)
        {
            if (box[i] <= p[i])
            {
                sum -= box[i];
                box[i] = 0;
                continue;
            }
            box[i] -= p[i];
            sum -= p[i];
        }
    }
    cout << count << endl;
    return 0;
}