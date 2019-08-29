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

class Solution
{
public:

};

int main()
{
    string path = "D:\\users\\Documents\\code\\learn_code\\debug\\"; // windows format
    ifstream cin;
    cin.open(path + "data.dat");
    if (!cin.is_open())
    {
        cout << "open failed..." << endl;
        return 0;
    }

    return 0;
}