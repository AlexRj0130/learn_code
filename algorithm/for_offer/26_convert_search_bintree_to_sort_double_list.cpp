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
    TreeNode* Convert(TreeNode* pRootOfTree)
    {
        if (pRootOfTree == NULL)
            return NULL;
        
        TreeNode * left = helpLeft(pRootOfTree->left);
        TreeNode * right = helpRight(pRootOfTree->right);
        if (left != NULL)
        {
            pRootOfTree->left = left;
            left->right = pRootOfTree;
        }
        if (right != NULL)
        {
            pRootOfTree->right = right;
            right->left = pRootOfTree;
        }
        while (pRootOfTree->left != NULL)
        {
            pRootOfTree = pRootOfTree->left;
        }
        return pRootOfTree;
    }

private:
    TreeNode * helpLeft(TreeNode * root)
    {
        if (root == NULL)
            return NULL;

        TreeNode * left = helpLeft(root->left);
        TreeNode * right = helpRight(root->right);
        if (left != NULL)
        {
            root->left = left;
            left->right = root;
        }
        if (right != NULL)
        {
            root->right = right;
            right->left = root;
        }

        while(root->right != NULL)
            root = root->right;
        return root;
    }

    TreeNode * helpRight(TreeNode * root)
    {
        if (root == NULL)
            return NULL;
        
        TreeNode * left = helpLeft(root->left);
        TreeNode * right = helpRight(root->right);
         if (left != NULL)
        {
            root->left = left;
            left->right = root;
        }
        if (right != NULL)
        {
            root->right = right;
            right->left = root;
        }

        while(root->left != NULL)
            root = root->left;
        return root;
    }
};

int main()
{
    return 0;
}