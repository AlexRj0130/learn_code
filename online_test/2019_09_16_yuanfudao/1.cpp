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

void printMat(const vector<vector<int> > & arr, int staN, int staM, int endN, int endM)
{
    if (staN > endN || staM > endM)
        return;
    if (staN == endN && staM < endM)
    {
        for(int i = endM; i >= staM; i--)
            cout << arr[staN][i] << " ";
        return;
    }
    else if (staN < endN && staM == endM)
    {
        for (int i = staN; i <= endN; i++)
            cout << arr[i][staM] << " ";
        return;
    }
    else if (staN == endN && staM == endM)
    {
        cout << arr[staN][staM];
        return;
    }
    else
    {
        int i = staN;
        int j = staM;
        for (; i < endN; i++)
            cout << arr[i][j] << " ";
        for (; j < endM; j++)
            cout << arr[i][j] << " ";
        for (; i > staN; i--)
            cout << arr[i][j] << " ";
        for (; j > staM; j--)
            cout << arr[i][j] << " ";
    }
    printMat(arr, staN+1, staM+1, endN-1, endM-1);
}

int main()
{
    // string path = "D:\\users\\Documents\\code\\learn_code\\debug\\"; // windows format
    // ifstream cin;
    // cin.open(path + "data.dat");
    // if (!cin.is_open())
    // {
    //     cout << "open failed..." << endl;
    //     return 0;
    // }
    int N, M;
    cin >> N >> M;
    vector<vector<int> > arr(N, vector<int>(M));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
            cin >> arr[i][j];

    
    printMat(arr, 0, 0, N-1, M-1);

    return 0;
}