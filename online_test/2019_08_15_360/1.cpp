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
    int N, M;
    cin >> N >> M;

    vector<vector<int> > A(N+2, vector<int>(M+2, 0));
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            cin >> A[i][j];
        }
    }

    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            sum += 2;
            if (A[i][j] > A[i-1][j])
                sum += (A[i][j] - A[i-1][j]);
            if (A[i][j] > A[i][j-1])
                sum += (A[i][j] - A[i][j-1]);
            if (A[i][j] > A[i+1][j])
                sum += (A[i][j] - A[i+1][j]);
            if (A[i][j] > A[i][j+1])
                sum += (A[i][j] - A[i][j+1]);
        }
    }
    cout << sum << endl;

    return 0;
}