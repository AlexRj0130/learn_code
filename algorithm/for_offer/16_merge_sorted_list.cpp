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

struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};

class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
    {
        if (pHead1 == NULL && pHead2 == NULL)
            return NULL;
        if (pHead1 != NULL && pHead2 == NULL)
            return pHead1;
        if (pHead1 == NULL && pHead2 != NULL)
            return pHead2;

        ListNode * newHead = NULL;
        ListNode * newTail = NULL;
        while(pHead1 != NULL && pHead2 != NULL)
        {
            ListNode * tmp = pHead1;
            if (pHead1->val > pHead2->val)
            {
                tmp = pHead2;
                pHead2 = pHead2->next;
            }
            else
            {
                pHead1 = pHead1->next;
            }
            tmp->next=NULL;

            if (newHead == NULL)
            {
                newHead = tmp;
                newTail = tmp;
            }
            else
            {
                newTail->next = tmp;
                newTail = tmp;
            }
        }

        if (pHead1 != NULL)
            newTail->next = pHead1;
        if (pHead2 != NULL)
            newTail->next = pHead2;

        return newHead;
    }
};

int main()
{
    return 0;
}