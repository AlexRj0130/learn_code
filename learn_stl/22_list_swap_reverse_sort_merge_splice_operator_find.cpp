#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class LearnListSwapMerge
{
public:
    void listSwap()  // 交换两个 list 容器中的内容
    {
        list<int> lst_1 = {1, 3, 5};
        list<int> lst_2 = {2, 4, 6};
        lst_1.swap(lst_2);
        for_each(lst_1.begin(), lst_1.end(), cout_list_elem);  // 输出 2 4 6
        cout << endl;
        for_each(lst_2.begin(), lst_2.end(), cout_list_elem);  // 输出 1 3 5
        cout << endl;
    }

    void listReverse()  // 翻转 list 容器中的内容
    {
        list<int> lst = {1, 2, 3};
        lst.reverse();
        for_each(lst.begin(), lst.end(), cout_list_elem);  // 输出 3 2 1 
        cout << endl;   
    }

    void listSort()  // list 容器自己有一个 sort 成员函数，使用成员函数排序，效率可能会更高一些
    {
        list<int> lst = {1, 3, 4, 2};
        lst.sort();
        for_each(lst.begin(), lst.end(), cout_list_elem);  // 输出 1 2 3 4
        cout << endl;

        // 如果需要实现从大到小排序，可以再调用 reverse 成员函数即可
    }

    void listMerge()  // 合并两个 list，合并前的两个链表必须是有序的，合并后的链表也是有序的
    {
        list<int> lst_1 = {1, 3, 5};
        list<int> lst_2 = {2, 4, 6};
        lst_1.merge(lst_2);
        for_each(lst_1.begin(), lst_1.end(), cout_list_elem);  // 输出 1 2 3 4 5 6 
        cout << endl;
        for_each(lst_2.begin(), lst_2.end(), cout_list_elem);  // 无输出
        cout << endl;
        cout << lst_2.size() << endl;  // 输出 0 
    }

    void listSplice()  // 拼接两个 list
    {
        // 方法1：将一个 list 拼接到另一个 list 的指定位置
        list<int> lst_1 = {1, 2, 3};
        list<int> lst_2 = {4, 5, 6};

        list<int>::iterator iter_1_pos = lst_1.begin();
        advance(iter_1_pos, 1);
        lst_1.splice(iter_1_pos, lst_2);
        for_each(lst_1.begin(), lst_1.end(), cout_list_elem);  // 输出 1 4 5 6 2 3
        cout << endl;
        for_each(lst_2.begin(), lst_2.end(), cout_list_elem);  // 无输出
        cout << endl;
        cout << lst_2.size() << endl;  // 输出 0

        // 方法2：将一个 list 中的某个指定节点，拼接到另一个 list 的指定位置
        list<int> lst_3 = {1, 2, 3};
        list<int> lst_4 = {4, 5, 6};

        list<int>::iterator iter_3_pos = lst_3.begin();
        advance(iter_3_pos, 1);
        list<int>::iterator iter_4_del = lst_4.begin();
        advance(iter_4_del, 1);
        lst_3.splice(iter_3_pos, lst_4, iter_4_del);

        for_each(lst_3.begin(), lst_3.end(), cout_list_elem);  // 输出 1 5 2 3
        cout << endl;
        for_each(lst_4.begin(), lst_4.end(), cout_list_elem);  // 输出 4 6 
        cout << endl;

        // 方法3：将一个 list 中的指定范围内的节点，拼接到另一个 list 的指定位置
        list<int> lst_5 = {1, 2, 3};
        list<int> lst_6 = {4, 5, 6};

        list<int>::iterator iter_5_pos = lst_5.begin();
        advance(iter_5_pos, 1);
        list<int>::iterator iter_6_sta = lst_6.begin();
        list<int>::iterator iter_6_end = lst_6.begin();
        advance(iter_6_sta, 1);
        advance(iter_6_end, 3);

        lst_5.splice(iter_5_pos, lst_6, iter_6_sta, iter_6_end);
        
        for_each(lst_5.begin(), lst_5.end(), cout_list_elem);  // 输出 1 5 6 2 3 
        cout << endl;
        for_each(lst_6.begin(), lst_6.end(), cout_list_elem);  // 输出 4 
        cout << endl;
    }

    void listOperatorOverload()
    {
        // list 的比较运算符也就逐个节点一一对应的进行比较
        // 直到能够找到两个不相等的节点，从而确定大小关系
        // 或者，一个 list 已经走到末尾，从而确定大小关系
        // 或者，两个 list 均走到末尾，从而确定相等关系

        list<int> lst_1 = {1, 2, 3};
        list<int> lst_2 = {2 ,3, 4};
        list<int> lst_3 = {0, 1, 2};
        list<int> lst_4 = {1, 2, 3, 4};
        list<int> lst_5 = {1, 2};
        list<int> lst_6 = {1, 2, 3};

        cout << (lst_1 > lst_2) << endl;  // 输出 0
        cout << (lst_1 >= lst_2) << endl;  // 输出 0
        cout << (lst_1 == lst_2) << endl;  // 输出 0
        cout << (lst_1 <= lst_2) << endl;  // 输出 1
        cout << (lst_1 < lst_2) << endl;  // 输出 1
        cout << (lst_1 != lst_2) << endl;  // 输出 1
        cout << endl;
        
        cout << (lst_1 > lst_3) << endl;  // 输出 1
        cout << (lst_1 >= lst_3) << endl;  // 输出 1
        cout << (lst_1 == lst_3) << endl;  // 输出 0
        cout << (lst_1 <= lst_3) << endl;  // 输出 0
        cout << (lst_1 < lst_3) << endl;  // 输出 0
        cout << (lst_1 != lst_3) << endl;  // 输出 1
        cout << endl;

        cout << (lst_1 > lst_4) << endl;  // 输出 0
        cout << (lst_1 >= lst_4) << endl;  // 输出 0
        cout << (lst_1 == lst_4) << endl;  // 输出 0
        cout << (lst_1 <= lst_4) << endl;  // 输出 1
        cout << (lst_1 < lst_4) << endl;  // 输出 1
        cout << (lst_1 != lst_4) << endl;  // 输出 1
        cout << endl;

        cout << (lst_1 > lst_5) << endl;  // 输出 1
        cout << (lst_1 >= lst_5) << endl;  // 输出 1
        cout << (lst_1 == lst_5) << endl;  // 输出 0
        cout << (lst_1 <= lst_5) << endl;  // 输出 0
        cout << (lst_1 < lst_5) << endl;  // 输出 0
        cout << (lst_1 != lst_5) << endl;  // 输出 1
        cout << endl;

        cout << (lst_1 > lst_6) << endl;  // 输出 0
        cout << (lst_1 >= lst_6) << endl;  // 输出 1
        cout << (lst_1 == lst_6) << endl;  // 输出 1
        cout << (lst_1 <= lst_6) << endl;  // 输出 1
        cout << (lst_1 < lst_6) << endl;  // 输出 0
        cout << (lst_1 != lst_6) << endl;  // 输出 0
        cout << endl;
    }

    void listFind()  // 在一个 list 的指定范围内查找，找到则返回指向该元素的迭代器
    {
        list<int> lst = {1, 2, 3, 4, 5, 6};
        list<int>::iterator iter_find_res;

        iter_find_res = find(lst.begin(), lst.end(), 4);
        for_each(iter_find_res, lst.end(), cout_list_elem);  // 输出 4 5 6 
        cout << endl;

        iter_find_res = find(lst.begin(), lst.end(), 7);
        cout << (iter_find_res == lst.end()) << endl;  // 输出 1 
    }

private:
   static void cout_list_elem(const int & val)
   {
       cout << val << " ";
   } 
};


int main()
{
    LearnListSwapMerge llsm;

    // llsm.listSwap();
    // llsm.listReverse();
    // llsm.listSort();
    // llsm.listMerge();
    // llsm.listSplice();
    // llsm.listOperatorOverload();
    llsm.listFind();

    system("pause");
    return 0;
}