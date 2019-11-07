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
    vector<int> printListFromTailToHead(ListNode* head) {
        vector<int> ret, tmp;
        if (head == NULL)
            return ret;
        
        while(head != NULL)
        {
            tmp.push_back(head->val);
            head = head->next;
        }

        while(!tmp.empty())
        {
            ret.push_back(tmp.back());
            tmp.pop_back();
        }

        return ret;
    }
};

int main()
{
    return 0;
}