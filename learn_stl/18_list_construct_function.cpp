#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

struct Node 
{
    int a;
    char c;
    Node():a(count++), c('x') {}
    Node(int i_val, char c_val): a(i_val), c(c_val) {}
private:
    static int count;
};

int Node::count = 0;

class LearnListDefine
{
public:
    void listDefine()
    {
        // 方法1：无参数构造函数
        list<Node> lst_1;

        // 方法2：构造包含指定节点个数的 list
        list<Node> lst_2(5);
        for_each(lst_2.begin(), lst_2.end(), cout_list_elem);
        cout << endl;

        // 方法3：构造包含指定节点个数、指定节点值的 list
        list<Node> lst_3(5, Node(6, 'y'));
        for_each(lst_3.begin(), lst_3.end(), cout_list_elem);
        cout << endl;

        // 方法4：使用一个已经存在的 list 对当前 list 进行初始化
        list<Node> lst_4(lst_2);
        for_each(lst_4.begin(), lst_4.end(), cout_list_elem);
        cout << endl;

        // 方法5：使用一个已经存在的 list 的一段节点对当前 list 进行初始化
        // list<Node> lst_5(lst_2.begin() + 1, lst_2.begin() + 4);  // 由于 list 是个链表，它的迭代器只支持 ++ -- 操作，所以无法执行上述操作
        list<Node>::iterator iter_sta = lst_2.begin();
        advance(iter_sta, 1);  // 使用 advance 函数，移动 list 类型的迭代器
        list<Node>::iterator iter_end = lst_2.begin();
        advance(iter_end, 4);
        list<Node> lst_5(iter_sta, iter_end);
        for_each(lst_5.begin(), lst_5.end(), cout_list_elem);
        cout << endl;
    }

private:
    static void cout_list_elem(Node & node)
    {
        cout << node.a << " " << node.c << endl;
    }
};


int main()
{
    LearnListDefine lld;

    lld.listDefine();

    system("pause");
    return 0;
}