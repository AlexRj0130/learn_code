#include <iostream>
#include <stack>

using namespace std;

class BinTreeNode 
{
public:
    BinTreeNode(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }

    BinTreeNode(int data, BinTreeNode * left, BinTreeNode * right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }

private:
    int data;
    BinTreeNode * left;
    BinTreeNode * right;

};

class BinTreeTranverse
{
    void FirstOrder(BinTreeNode * root)
    {
        if (root == NULL)
            return;

        
    }

    void MidOrder(BinTreeNode * root)
    {

    }

    void LastOrder(BinTreeNode * root)
    {

    }
};

int main()
{
    string input;
    cin >> input;
    cout << input << endl;
    return 0;
}