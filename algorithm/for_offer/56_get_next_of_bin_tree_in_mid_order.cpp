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

struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};

class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode)
    {
        if (pNode == NULL)
            return NULL;
        if (pNode->right != NULL)
        {
            TreeLinkNode * pTmp = pNode->right;
            while (pTmp->left != NULL)
                pTmp = pTmp->left;
            return pTmp;
        }

        // If pNode is the right-child, then do the following
        while (pNode->next != NULL && pNode != pNode->next->left)
            pNode = pNode->next;
        return pNode->next;
    }
};

int main()
{
    return 0;
}