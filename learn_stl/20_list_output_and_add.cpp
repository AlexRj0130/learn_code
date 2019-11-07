#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class LearnListOutputAndAdd
{
public:
    void listOutputAll()
    {
        int array[6] = {1, 2, 3, 4, 5, 6};
        // 方法1：通过 for 循环，使用迭代器逐个输出 
        list<int> lst_1(array, array+6);
        list<int>::iterator iter = lst_1.begin();
        list<int>::iterator iter_end = lst_1.end();
        for(; iter != iter_end; ++iter)  // 输出 1 2 3 4 5 6 
        {
            cout << * iter << " ";
        }
        cout << endl;

        // 方法2：使用 for_each 输出（略）

        // 注意，list 不支持下标运算
    }

    void listOutputSingle()
    {
        int array[6] = {1, 2, 3, 4, 5, 6};
        list<int> lst(array, array+6);
        cout << lst.front() << endl;  // 输出 1
        cout << lst.back() << endl;  // 输出 6
    }

    void listAdd()
    {
        // list 的添加操作分为 头添加、尾添加、中间添加
        // vector 是没有头添加的，原因在于 vector 的头添加操作需要移动后面所有的元素，效率低

        int array[6] = {1, 2, 3};
        // 头添加
        list<int> lst_1(array, array+3);
        lst_1.push_front(9);
        for_each(lst_1.begin(), lst_1.end(), cout_list_elem);  // 输出 9 1 2 3 
        cout << endl;

        // 尾添加
        list<int> lst_2(array, array+3);
        lst_2.push_back(9);
        for_each(lst_2.begin(), lst_2.end(), cout_list_elem);  // 输出 1 2 3 9 
        cout << endl;

        // 中间指定位置添加一个元素
        list<int> lst_3(array, array+3);
        list<int>::iterator iter = lst_3.begin();
        advance(iter, 2);
        lst_3.insert(iter, 9);
        for_each(lst_3.begin(), lst_3.end(), cout_list_elem);  // 输出 1 2 9 3 
        cout << endl;

        // 中间指定位置添加指定个数的相同的元素
        list<int> lst_4(array, array+3);
        list<int>::iterator iter_4 = lst_4.begin();
        advance(iter_4, 2);
        lst_4.insert(iter_4, 3, 9);
        for_each(lst_4.begin(), lst_4.end(), cout_list_elem);  // 输出 1 2 9 9 9 3 
        cout << endl;

        // 中间指定位置插入另一个迭代器中的一段
        list<int> lst_5(array, array+3);
        list<int>::iterator iter_5= lst_5.begin();
        advance(iter_5, 2);
        
        int array_2[6] = {4, 5, 6, 7, 8, 9};
        list<int> lst_6(array_2, array_2+6);
        list<int>::iterator iter_6_sta = lst_6.begin();
        list<int>::iterator iter_6_end = lst_6.begin();
        advance(iter_6_sta, 2);
        advance(iter_6_end, 4);

        lst_5.insert(iter_5, iter_6_sta, iter_6_end);
        for_each(lst_5.begin(), lst_5.end(), cout_list_elem);  // 输出 1 2 6 7 3 
        cout << endl;
        for_each(lst_6.begin(), lst_6.end(), cout_list_elem);  // 输出 4 5 6 7 8 9  
        cout << endl;
    }

private: 
    static void cout_list_elem(const int & val)
    {
        cout << val << " ";
    }
};


int main()
{
    LearnListOutputAndAdd lloaa;

    // lloaa.listOutputAll();
    // lloaa.listOutputSingle();
    lloaa.listAdd();

    system("pause");
    return 0;
}