#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class LearnListDeleteAndChange
{
public:
    void listDelete()
    {
        int array[6] = {1, 2, 3, 4, 5, 6};

        // 删除 list 头部的元素
        list<int> lst_1(array, array+6);
        lst_1.pop_front();
        for_each(lst_1.begin(), lst_1.end(), cout_list_elem);  // 输出 2 3 4 5 6 
        cout << endl;

        // 删除 list 尾部的元素
        list<int> lst_2(array, array+6);
        lst_2.pop_back();
        for_each(lst_2.begin(), lst_2.end(), cout_list_elem);  // 输出 1 2 3 4 5 
        cout << endl;

        // 删除 list 指定位置的元素
        list<int> lst_3(array, array+6);
        list<int>::iterator iter = lst_3.begin();
        advance(iter, 3);
        lst_3.erase(iter);
        for_each(lst_3.begin(), lst_3.end(), cout_list_elem);  // 输出 1 2 3 5 6 
        cout << endl;

        // 删除 list 指定位置的一段元素
        list<int> lst_4(array, array+6);
        list<int>::iterator iter_sta = lst_4.begin(), iter_end = lst_4.begin();
        advance(iter_sta, 2);
        advance(iter_end, 4);
        lst_4.erase(iter_sta, iter_end);
        for_each(lst_4.begin(), lst_4.end(), cout_list_elem);  // 输出 1 2 5 6 
        cout << endl;

        // 删除 list 中指定值的元素
        int array_2[6] = {1, 3, 4, 3, 5, 3};
        list<int> lst_5(array_2, array_2+6);
        lst_5.remove(3);
        for_each(lst_5.begin(), lst_5.end(), cout_list_elem);  // 输出 1 4 5
        cout << endl;

        // 删除 list 中满足指定条件的元素（例如，删除所有奇数）
        list<int> lst_6(array, array+6);
        lst_6.remove_if(is_odd);
        for_each(lst_6.begin(), lst_6.end(), cout_list_elem);  // 输出 2 4 6 
        cout << endl;

        // 删除 list 中重复的元素(去重之前先要排序，原因在于 unique 只能去除相邻的重复元素)
        list<int> lst_7(array_2, array_2+6);
        lst_7.sort();
        lst_7.unique();
        for_each(lst_7.begin(), lst_7.end(), cout_list_elem);  // 输出 1 3 4 5
        cout << endl;
    }

    void listChangeAll()
    {
        list<int> lst = {1, 2, 3, 4, 5, 6};
        list<int>::iterator lst_sta = lst.begin();
        list<int>::iterator lst_end = lst.begin();
        advance(lst_sta, 2);
        advance(lst_end, 4);

        // 使用等于号对 list 进行赋值
        list<int> lst_1;
        lst_1 = lst;
        for_each(lst_1.begin(), lst_1.end(), cout_list_elem);  // 输出 1 2 3 4 5 6 
        cout << endl;

        // 使用 assign 函数对 list 赋值指定数量的指定值
        list<int> lst_2;
        lst_2 = lst;
        lst_2.assign(4, 1);
        for_each(lst_2.begin(), lst_2.end(), cout_list_elem);  // 输出 1 1 1 1 
        cout << endl;

        // 使用 assign 函数对 list 赋值另一个 list 的一段元素
        list<int> lst_3;
        lst_3.assign(lst_sta, lst_end);
        for_each(lst_3.begin(), lst_3.end(), cout_list_elem);  // 输出 3 4 
        cout << endl;

    }
    
private: 
    static void cout_list_elem(const int & val)
    {
        cout << val << " ";
    }

    static bool is_odd(const int & val)
    {
        return ((val % 2) == 1);
    }
};


int main()
{
    LearnListDeleteAndChange lldac;

    // lldac.listDelete();
    lldac.listChangeAll();

    system("pause");
    return 0;
}