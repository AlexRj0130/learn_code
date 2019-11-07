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
    void Mirror(TreeNode *pRoot) {
        if (pRoot == NULL)
            return;
        
        TreeNode * tmp = pRoot->left;
        pRoot->left = pRoot->right;
        pRoot->right = tmp;

        Mirror(pRoot->left);
        Mirror(pRoot->right);
    }
};

int main()
{
    return 0;
}