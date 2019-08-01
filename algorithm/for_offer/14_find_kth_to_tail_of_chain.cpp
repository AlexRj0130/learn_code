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
    ListNode* FindKthToTail(ListNode* pListHead, unsigned int k) {
        ListNode * first = pListHead;
        ListNode * second = pListHead;

        if (0 == k)
            return NULL;

        while(k > 1)
        {
            if (first == NULL || first->next == NULL)
                return NULL;
            first = first->next;
            k--;
        }

        while(first->next != NULL)
        {
            first = first->next;
            second = second->next;
        }

        return second;
    }
};

int main()
{
    return 0;
}