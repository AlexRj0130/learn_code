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

struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};

class Solution {
public:
    ListNode* EntryNodeOfLoop(ListNode* pHead)
    {
        map<ListNode*, bool> record;
        while (pHead != NULL)
        {
            if (record.count(pHead) != 0)
                return pHead;

            record.insert(pair<ListNode*, bool>(pHead, true));
            pHead = pHead->next;
        }

        return NULL;
    }
};

int main()
{
    return 0;
}