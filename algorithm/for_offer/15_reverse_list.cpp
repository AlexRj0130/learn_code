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
    ListNode* ReverseList(ListNode* pHead) {
        if (pHead == NULL || pHead->next == NULL)
            return pHead; 

        ListNode * newHead = pHead;
        pHead = pHead->next;
        newHead->next = NULL;

        while(pHead != NULL)
        {
            ListNode * tmp = pHead;
            pHead = pHead->next;
            tmp->next = newHead;
            newHead = tmp;
        }

        return newHead;
    }
};

int main()
{
    return 0;
}