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

// Definition for binary tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
        if (pre.empty())
        {
            return NULL;
        }

        TreeNode * node = new TreeNode(pre[0]); 
        if (1 == pre.size())
            return node;
        
        int midPos = 0;
        for (int i = 0; i < vin.size(); i++)
        {
            if (pre[0] == vin[i])
            {
                midPos = i;
                break;
            }
        }

        node->left = reConstructBinaryTree(
            vector<int>(pre.begin() + 1, pre.begin() + midPos + 1), 
            vector<int>(vin.begin(), vin.begin() + midPos));
        node->right = reConstructBinaryTree(
            vector<int>(pre.begin() + midPos + 1, pre.end()),
            vector<int>(vin.begin() + midPos + 1, vin.end()));

        return node;
    }
};

int main()
{
    return 0;
}