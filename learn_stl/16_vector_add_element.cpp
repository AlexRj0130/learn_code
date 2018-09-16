#include <iostream>
#include <stdlib.h>
#include <ctime>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <random>  // std::default_random_engine
#include <chrono>  // std::chrono::system_clock

using namespace std;

class LearnVectorOperation
{
public:
    // 添加元素方法1：在末尾添加，通过 vector.push_back完成（略）

    // 添加元素方法2：在中间添加，通过 insert 实现 
    // 注，通过 insert 添加元素的时候，效率是比较低的
    void vectorInsert()
    {
        vector<int> vec(5, 6);
        // 在指定迭代器位置，插入一个指定元素
        vec.insert(vec.begin()+2, 8);
        for_each(vec.begin(), vec.end(), cout_vec_elem);  // 输出 6 6 8 6 6 6
        cout << endl;

        vector<int> vec_2(5, 6);
        // 在指定迭代器位置，插入指定个数的指定元素
        vec_2.insert(vec_2.begin()+2, 2, 8);
        for_each(vec_2.begin(), vec_2.end(), cout_vec_elem);  // 输出 6 6 8 8 6 6 6 
        cout << endl;

        vector<int> vec_3(5, 6);
        int array[5] = {1, 2, 3, 4, 5};
        vector<int> vec_4(array, array + 5);
        // 在迭代器指定位置，插入由另一个容器的迭代器指定的范围
        vec_3.insert(vec_3.begin() + 2, vec_4.begin() + 1, vec_4.begin() + 4);  // 输出 6 6 2 3 4 6 6 6 
        for_each(vec_3.begin(), vec_3.end(), cout_vec_elem);
        cout << endl;
    }

    // 删除元素方法1：在末尾删除，通过 vector.pop_back 完成（略）

    // 删除元素方法2：删除指定元素或指定范围的元素，通过 erase 实现
    void vectorErase()
    {
        int array[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
        vector<int> vec(array, array + 10);
        // 删除指定元素
        vec.erase(vec.begin() + 1);
        for_each(vec.begin(), vec.end(), cout_vec_elem);  // 输出 0 2 3 4 5 6 7 8 9 
        cout << endl;

        // 删除指定范围的元素
        vec.erase(vec.begin() + 1, vec.begin() + 6);
        for_each(vec.begin(), vec.end(), cout_vec_elem);  // 输出 0 7 8 9
        cout << endl;

    }

    // 修改元素的方法：可以通过下标修改，也可以通过迭代器修改（略）

    // 修改元素的方法2：通过 for_each 修改指定范围内的元素
    void vectorForEachModify()
    {
        vector<int> vec(9, 1);
        for_each(vec.begin() + 3, vec.begin() + 6, modify_vec_elem);
        for_each(vec.begin(), vec.end(), cout_vec_elem);  // 输出 1 1 1 6 6 6 1 1 1 
        cout << endl;
    }

    // 交换两个 vector 的内容
    void vectorSwap()
    {
        vector<int> vec_1(3, 1);
        vector<int> vec_2(4, 2);
        vec_1.swap(vec_2);
        for_each(vec_1.begin(), vec_1.end(), cout_vec_elem);  // 输出 2 2 2 2 
        cout << endl;
        for_each(vec_2.begin(), vec_2.end(), cout_vec_elem);  // 输出 1 1 1 
        cout << endl;
    }

    // vector 的比较运算符重载
    void vectorOperatorCompare()
    {
        vector<int> vec_1(3, 2);
        vector<int> vec_2(4, 1);
        vector<int> vec_3(2, 3);
        vector<int> vec_4(4, 2);

        cout << (vec_1 > vec_2) << endl;  // 输出 1 
        cout << (vec_1 > vec_3) << endl;  // 输出 0
        cout << (vec_1 > vec_4) << endl;  // 输出 0

        // 可见，在 vector 的比较过程中，只比较对应位置的元素；
        // 如果对应位置已经可以判断出大小关系，那么久不比较后面的元素了；
        // 如果对应位置无法判断出大小关系，那么就继续比较下一个下标位置，直至判断出大小关系或 vector 中已经没有更多元素。

        // vector 支持的常用的比较运算符，包括
        // >, >=, ==, <=, <, !=
    }

    // vector 算法之 for_each，用来对迭代器指定范围内的元素逐一施加某一操作（略）

    // vector 算法之 sort，用来对迭代器指定范围内的元素进行排序
    void vectorSort()
    {
        int array[10] = {1, 4, 2, 6, 7, 3, 0, 9, 8, 5};
        vector<int> vec(array, array+10);
        // 默认从小到大排序
        sort(vec.begin() + 2, vec.begin() + 6);
        for_each(vec.begin(), vec.end(), cout_vec_elem);  // 输出 1 4 2 3 6 7 0 9 8 5
        cout << endl;

        // 指定从大到小排序
        sort(vec.begin(), vec.end(), greater<int>());
        for_each(vec.begin(), vec.end(), cout_vec_elem);  // 输出 9 8 7 6 5 4 3 2 1 0
        cout << endl;

        // 自定义排序顺序：奇数在前，偶数在后；奇偶相同，小在前，大在后
        sort(vec.begin(), vec.end(), self_compare);
        for_each(vec.begin(), vec.end(), cout_vec_elem);  // 输出 1 3 5 7 9 0 2 4 6 8 
        cout << endl;
    }

    // 清除所有元素
    void vectorClear()
    {
        vector<int> vec(8, 1);
        vec.clear();
        cout << vec.capacity() << endl;  // 输出 8
        cout << vec.size() << endl;  // 输出 0
    }

    // 赋值函数
    void vectorAssign()
    {
        int array[10] = {1, 4, 2, 6, 7, 3, 0, 9, 8, 5};
        vector<int> vec_1(8, 1);
        vector<int> vec_2(array, array+ 10);

        // 通过另一个 vector 的迭代器为当前 vector 赋值
        vec_1.assign(vec_2.begin() + 3, vec_2.begin() + 8);
        for_each(vec_1.begin(), vec_1.end(), cout_vec_elem);  // 输出 6 7 3 0 9
        cout << endl;

        // 为 vector 赋值指定个数的某一元素值
        vec_1.assign(5, 6);
        for_each(vec_1.begin(), vec_1.end(), cout_vec_elem);  // 输出 6 6 6 6 6 
        cout << endl;
        
        // 通过 = 操作符，将另一个 vector 的所有值赋值给当前的 vector
        vec_1 = vec_2;
        for_each(vec_1.begin(), vec_1.end(), cout_vec_elem);  // 输出 1 4 2 6 7 3 0 9 8 5 
        cout << endl;
    }

    // 将 vector 中的元素随机乱序
    void vectorRandomShuffle()
    {
        int array[10] = {0, 1, 2, 3, 4, 6, 7, 8, 9};
        vector<int> vec(array, array + 10);

        // int min = 0, max = 9;
        // static default_random_engine e;
        // static uniform_int_distribution<unsigned> u(min, max);
        srand(unsigned(time(NULL)));
        random_shuffle(vec.begin() + 2, vec.end() + 6);

        for_each(vec.begin(), vec.end(), cout_vec_elem);  //
        cout << endl;
    }

private:
    static void cout_vec_elem(int val)
    {
        cout << val << " ";
    }

    static void modify_vec_elem(int & val)
    {
        val += 5;
    }

    // 奇数在前，偶数在后；
    // 较小数在前，较大数在后。
    static bool self_compare(int a, int b)
    {
        if ((a % 2 == 1) && (b % 2 == 0))
            return true;
        if ((a % 2 == 0) && (b % 2 == 1))
            return false;
        return a < b;
    }
};


int main()
{
    LearnVectorOperation lvo;

    // lvo.vectorInsert();
    // lvo.vectorErase();
    // lvo.vectorForEachModify();
    // lvo.vectorSwap();
    // lvo.vectorOperatorCompare();
    // lvo.vectorSort();
    // lvo.vectorClear();
    // lvo.vectorAssign();
    lvo.vectorRandomShuffle();

    // system("pause");
    return 0;
}