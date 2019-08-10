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

struct QueueMember {
    TreeNode * node;
    int level;
    QueueMember(int level, TreeNode * node) : level(level), node(node) {}
};

class Solution {
public:
    vector<vector<int> > Print(TreeNode* pRoot) {
        vector<vector<int> > ret;
        if (pRoot == NULL)
            return ret;

        queue<QueueMember> que;
        que.push(QueueMember(0, pRoot));
        while (!que.empty())
        {
            int level = que.front().level;
            vector<int> tmp;
            while (que.front().level == level)
            {
                TreeNode * node = que.front().node;
                que.pop();
                tmp.push_back(node->val);
                if (node->left != NULL)
                    que.push(QueueMember(level + 1, node->left));
                if (node->right != NULL)
                    que.push(QueueMember(level + 1, node->right));
            }
            ret.push_back(tmp);
        }
        return ret;
    }
};

int main()
{
    return 0;
}