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
	TreeNode(int x, TreeNode * l, TreeNode * r) :
			val(x), left(l), right(r) {
	}
};

class Solution {
public:
    vector<vector<int> > FindPath(TreeNode* root,int expectNumber) {
        vector<vector<int> > ret;
        if (root == NULL)
            return ret;

        vector<int> tmp;
        DFS(root, expectNumber, tmp, ret);
        return ret;
    }

private:
    void DFS(TreeNode * root, int exp, vector<int> & tmp, vector<vector<int> > & ret)
    {
        tmp.push_back(root->val);
        
        if (root->left == NULL && root->right == NULL)
        {
            int sum = 0;
            for (int i = 0; i < tmp.size(); i++)
                sum += tmp[i];

            if (sum == exp)
            {
                ret.push_back(tmp);
            }
            tmp.pop_back();
            return;
        }

        if (root->left != NULL)
            DFS(root->left, exp, tmp, ret);
        if (root->right != NULL)
            DFS(root->right, exp, tmp, ret);
        tmp.pop_back();
    }
};

int main()
{
    TreeNode * root = new TreeNode(10,
                        new TreeNode(5,
                            new TreeNode(7, NULL, NULL),
                            NULL),
                        new TreeNode(12, NULL, NULL));

    Solution solution;
    solution.FindPath(root, 22);
    return 0;
}

