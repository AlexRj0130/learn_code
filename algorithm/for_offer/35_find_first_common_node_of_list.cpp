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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        int len1 = 0;
        int len2 = 0;

        ListNode * p1 = pHead1;
        ListNode * p2 = pHead2;
        while (p1 != NULL)
        {
            len1++;
            p1 = p1->next;
        }
        while (p2 != NULL)
        {
            len2++;
            p2 = p2->next;
        }

        if (len1 >= len2)
        {
            p1 = pHead1;
            p2 = pHead2;
        }
        else
        {
            p1 = pHead2;
            p2 = pHead1;
            int tmp = len1;
            len1 = len2;
            len2 = tmp;
        }
        
        while (len2 < len1)
        {
            p1 = p1->next;
            len1--;
        }

        while (p1 != NULL && p2 != NULL)
        {
            if (p1 == p2)
                return p1;
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};

int main()
{
    return 0;
}