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

struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};

class Solution {
public:
    bool isSymmetrical(TreeNode* pRoot)
    {
        TreeNode * pCopy = copy(pRoot);
        mirror(pCopy);
        return match(pRoot, pCopy);
    }

    TreeNode * copy(TreeNode * pRoot)
    {
        if (pRoot == NULL)
            return NULL;
        
        TreeNode * node = new TreeNode(pRoot->val);
        node->left = copy(pRoot->left);
        node->right = copy(pRoot->right);
        return node;
    }

    void mirror(TreeNode * pRoot)
    {
        if (pRoot == NULL)
            return;
        
        TreeNode * pTmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = pTmp;
        
        mirror(pRoot->left);
        mirror(pRoot->right);
    }

    bool match(TreeNode * pRoot1, TreeNode * pRoot2)
    {
        if (pRoot1 == NULL && pRoot2 == NULL)
            return true;
        else if (pRoot1 != NULL && pRoot2 == NULL)
            return false;
        else if (pRoot1 == NULL && pRoot2 != NULL)
            return false;
        
        if (pRoot1->val != pRoot2->val)
            return false;
        
        return match(pRoot1->left, pRoot2->left) && match(pRoot1->right, pRoot2->right);
    }

};

int main()
{
    return 0;
}