#include <iostream>
#include <stdlib.h>

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

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty())
            return false;
        if (sequence.size() <= 1)
            return true;
        
        map<int, int> count;
        for (int i = 0; i < sequence.size(); i++)
            if (count.count(sequence[i]) != 0)
                return false;
            else
                count.insert(pair<int, int>(sequence[i], 1));
        
        return help(sequence);
    }

private:
    bool help(vector<int> seq)
    {
        if (seq.size() <= 2)
            return true;
        
        int mid = -1;
        for (int i = 0; i < seq.size() - 1; i++)
        {
            if (seq[i] < seq[seq.size() - 1])
                continue;
            mid = i;
            break;
        }

        if (-1 == mid)
            return help(vector<int>(seq.begin(), seq.end() - 1));
        
        for (int i = mid + 1; i < seq.size() - 1; i++)
        {
            if (seq[i] < seq[seq.size() - 1])
                return false; 
        }

        return help(vector<int>(seq.begin(), seq.begin() + mid)) && help(vector<int>(seq.begin() + mid, seq.end() - 1));
    }
};

int main()
{
    return 0;
}