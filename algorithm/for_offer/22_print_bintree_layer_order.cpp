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
    vector<int> PrintFromTopToBottom(TreeNode* root) {
        vector<int> ret;
        if (root == NULL)
            return ret;

        queue<TreeNode *> que;
        que.push(root);
        while(!que.empty())
        {
            TreeNode * tmp = que.front();
            que.pop();

            ret.push_back(tmp->val);
            if (tmp->left != NULL)
                que.push(tmp->left);
            if (tmp->right != NULL)
                que.push((tmp->right));
        }
        return ret;
    }
};

int main()
{
    return 0;
}