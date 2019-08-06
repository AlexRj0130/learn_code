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
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return Help(pRoot) != -1;
    }

public:
    int Help(TreeNode * root)
    {
        if (root == NULL)
            return 0;

        int lDepth = Help(root->left);
        int rDepth = Help(root->right);

        if (lDepth < 0 || rDepth < 0)
            return -1;

        int minDepth = lDepth <= rDepth ? lDepth : rDepth;
        int maxDepth = lDepth > rDepth ? lDepth : rDepth;

        if (maxDepth - minDepth <= 1)
            return maxDepth + 1;
        return -1;
    }
};

int main()
{
    return 0;
}