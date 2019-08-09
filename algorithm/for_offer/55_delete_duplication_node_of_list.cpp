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
    ListNode(int x, ListNode * n) :
        val(x), next(n) {
    }
};

class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead)
    {
        ListNode * pTmp = pHead;
        ListNode * pPre = pHead;
        while (pTmp != NULL)
        {
            if (pTmp->next == NULL)
                break;
            if (pTmp->val != pTmp->next->val)
            {
                pPre = pTmp;
                pTmp = pTmp->next;
                continue;
            }
            
            while (pTmp->next != NULL && pTmp->next->val == pTmp->val)
            {
                ListNode* pLocal = pTmp->next;
                pTmp->next = pTmp->next->next;
                delete pLocal;
            } 

            if (pTmp == pHead)
            {
                pTmp = pTmp->next;
                pPre = pTmp;
                delete pHead;
                pHead = pTmp;
                continue;                
            }
            ListNode* pLocal = pTmp;
            pTmp = pTmp->next;
            pPre->next = pTmp;
            delete pLocal;
        }

        return pHead;
    }
};

int main()
{
    ListNode * pHead = new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(3, new ListNode(4, new ListNode(4, new ListNode(5, NULL)))))));
    Solution solution;
    ListNode * pRet = solution.deleteDuplication(pHead);
    while (pRet != NULL)
    {
        cout << pRet->val << endl;
        pRet = pRet->next;
    }
    return 0;
}