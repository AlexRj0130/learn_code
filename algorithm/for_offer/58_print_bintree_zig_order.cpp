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
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ret;
        if (pRoot == NULL)
            return ret;
        
        stack<TreeNode *> s1;
        stack<TreeNode *> s2;
        s1.push(pRoot);
        bool dir = false;
        while((!s1.empty() && dir == false) || (!s2.empty() && dir == true))
        {
            if (!dir)  // left to right
            {
                vector<int> tmp;
                while (!s1.empty())
                {
                    TreeNode * node = s1.top();
                    s1.pop();
                    tmp.push_back(node->val);
                    if (node->left != NULL)
                        s2.push(node->left);
                    if (node->right != NULL)
                        s2.push(node->right);
                }
                ret.push_back(tmp);
                dir = true;
            }
            else  // right to left
            {
                vector<int> tmp;
                while (!s2.empty())
                {
                    TreeNode * node = s2.top();
                    s2.pop();
                    tmp.push_back(node->val);
                    if (node->right != NULL)
                        s1.push(node->right);
                    if (node->left != NULL)
                        s1.push(node->left);
                }
                ret.push_back(tmp);
                dir = false;
            }
        }
        return ret;
    }
    
};

int main()
{
    return 0;
}