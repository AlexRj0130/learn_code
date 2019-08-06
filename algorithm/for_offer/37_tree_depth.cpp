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
    int TreeDepth(TreeNode* pRoot)
    {
        int maxDepth = 0;
        if (pRoot == NULL)
            return 0;
        Help(pRoot, 1, maxDepth);
        return maxDepth;
    }

private:
    void Help(TreeNode * node, int curDepth, int & maxDepth)
    {
        if (node->left == NULL && node->right == NULL)
        {
            maxDepth = maxDepth > curDepth ? maxDepth : curDepth;
            return;
        }
        if (node->left != NULL)
            Help(node->left, curDepth + 1, maxDepth);
        if (node->right != NULL)
            Help(node->right, curDepth + 1, maxDepth);
    }
};

int main()
{
    return 0;
}