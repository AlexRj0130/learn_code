#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        if (n <= 1)
            return n;

        if (record.count(n) != 0)
            return record.at(n);
        
        int tmp = Fibonacci(n - 1) + Fibonacci(n - 2);
        record.insert(pair<int, int>(n, tmp));
        return tmp;
    }
private:
    map<int, int> record;
};

int main()
{
    return 0;
}