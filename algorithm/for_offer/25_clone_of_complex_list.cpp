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

struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};

class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if (pHead == NULL)
            return NULL; 

        RandomListNode * pRead = pHead;
        RandomListNode * head = NULL;
        RandomListNode * tail = NULL;

        int index = 0;
        while(pRead != NULL)
        {
            RandomListNode * tmp = new RandomListNode(pRead->label);
            if (head == NULL)
            {
                head = tail = tmp;
            }
            else
            {
                tail->next = tmp;
                tail = tmp;
            }
            
            nodeToIndex.insert(pair<RandomListNode*, int>(pRead, index));
            indexToNode.insert(pair<int, RandomListNode*>(index, tmp));
            
            pRead = pRead->next;
            index++;
        } 

        pRead = pHead;
        tail = head;
        index = 0;
        while(pRead != NULL)
        {
            if (pRead->random != NULL)
            {
                int tmp = nodeToIndex.at(pRead->random);
                tail->random = indexToNode.at(tmp);
            }

            pRead = pRead->next;
            tail = tail->next;
            index++;
        }

        return head;
    }

private:
    map<RandomListNode*, int> nodeToIndex;
    map<int, RandomListNode*> indexToNode;
};

int main()
{
    return 0;
}