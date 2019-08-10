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
    TreeNode(int x, TreeNode * left, TreeNode * right) : 
        val(x), left(left), right(right) {}
};

class Solution {
public:
    char* Serialize(TreeNode *root) {    
        vector<int> buf;
        serHelp(root, buf);
        int * ser = new int[buf.size()];
        for (int i = 0; i < buf.size(); i++)
            ser[i] = buf[i];
        return (char*) ser;
    }

    TreeNode* Deserialize(char *str) {
        int * p = (int *) str;
        return desHelp(p);
    }

private:
    void serHelp(TreeNode * node, vector<int> & buf)
    {
        if (node == NULL)
        {
            buf.push_back(0xffffffff);
            return;
        }
        buf.push_back(node->val);
        serHelp(node->left, buf);
        serHelp(node->right, buf);
    }

    TreeNode * desHelp(int * &p)
    {
        if (*p == 0xffffffff)
        {
            p++;  // Note: here is very important.
            return NULL;
        }
        
        TreeNode * node = new TreeNode(*p);
        p++;  // Note: here is very important.
        node->left = desHelp(p);
        node->right = desHelp(p);
        return node;
    }

};

int main()
{
    TreeNode * pTree = 
        new TreeNode(1,
            new TreeNode(2,
                new TreeNode(3,
                    new TreeNode(5, NULL, NULL),
                    NULL
                ),
                new TreeNode(4,
                    NULL,
                    new TreeNode(6, NULL, NULL)
                )),
            new TreeNode(7,
                new TreeNode(8, NULL, NULL),
                new TreeNode(9, NULL, NULL)
            )
        );

    Solution solution;
    char * ser = solution.Serialize(pTree);
    TreeNode * des = solution.Deserialize(ser);
    return 0;
}