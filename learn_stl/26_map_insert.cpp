#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

class LearnMap
{
public:
    void mapInsert()
    {
        // 直接插入
        map<int, char> mp;

        mp.insert(pair<int, char>(1, 'a'));
        mp.insert(pair<int, char>(3, 'c'));
        mp.insert(pair<int, char>(5, 'e'));
        mp.insert(pair<int, char>(2, 'b'));
        mp.insert(pair<int, char>(4, 'd'));
        mp.insert(pair<int, char>(6, 'f'));
        print_elem_map(mp);  // 输出 1:a 2:b 3:c 4:d 5:e 6:f

        // 在指定位置插入，插入的实际位置仍然是排序后应该在的位置

        map<int, char>::iterator iter;

        iter = mp.begin();
        iter++; iter++; iter++;
        print_pair(*iter);  // 输出 4:d
        cout << endl;

        iter = mp.begin();
        advance(iter, 3);
        print_pair(*iter);  // 输出 4:d
        cout << endl;

        mp.insert(iter, pair<int, char>(7, 'g'));  // 输出 1:a 2:b 3:c 4:d 5:e 6:f 7:g
        print_elem_map(mp);

        // 插入另一个 map 中的一段
        map<int, char> mp_2;
        map<int, char>::iterator iter_sta = mp.begin();
        map<int, char>::iterator iter_ter = mp.begin();
        advance(iter_sta, 2);
        advance(iter_ter, 5);
        mp_2.insert(iter_sta, iter_ter);
        print_elem_map(mp_2);  // 输出 3:c 4:d 5:e

        // 默认插入时，按照键值从小到大排序
        // 通过 greater 类型，指定按照从大到小排序
        map<int, char, greater<int>> mp_3;
        mp_3.insert(pair<int, char>(1, 'a'));
        mp_3.insert(pair<int, char>(2, 'b'));
        mp_3.insert(pair<int, char>(3, 'c'));

        map<int, char, greater<int>>::iterator iter_3, iter_3_ter;
        iter_3 = mp_3.begin();
        iter_3_ter = mp_3.end();
        for(; iter_3 != iter_3_ter; ++iter_3)  // 输出 3:c 2:b 1:a
        {
            cout << iter_3->first << ":" << iter_3->second << " ";
        }
        cout << endl;
    }

    void mapSize()
    {
        typedef pair<int, char> input_pair;
        map<int, char> mp;
        
        mp.insert(input_pair(1, 'a'));
        mp.insert(input_pair(2, 'b'));
        mp.insert(input_pair(3, 'c'));
        mp.insert(input_pair(4, 'd'));
        mp.insert(input_pair(5, 'e'));

        cout << mp.size() << endl;  // 输出 5
    }

    void mapCount()  // 用来判断一个 map 中是否存在某个 key 值
    {
        restoreMap();
        cout << mp.count(1) << endl;  // 输出 1
        cout << mp.count(0) << endl;  // 输出 0
    }

    void mapEmpty()  // 用来判断一个 map 是否为空
    {   
        cout << mp.empty() << endl;  // 输出 1
        restoreMap();
        cout << mp.empty() << endl;  // 输出 0
        mp.clear();
        cout << mp.empty() << endl;  // 输出 1
    }

    void mapOutput()  // 输出 map 中的元素的方法
    {
        // 方式1：通过迭代器，循环遍历输出 map 中的元素
        restoreMap();
        map<int, char>::iterator iter, iter_ter;
        iter = mp.begin();
        iter_ter = mp.end();
        for (; iter != iter_ter; ++iter)  // 输出 1:a 2:b 3:c 4:d 5:e
        {
            cout << iter->first << ":" << iter->second << " ";
        }
        cout << endl;

        // 方式2：使用 for_each 输出 map 中的元素
        // 需要自定义 for_each 调用的操作函数
        // （略）
    }

    void mapErase()  // 删除 map 容器中的元素
    {
        // 方式1：通过迭代器删除指定的元素
        restoreMap();
        map<int, char>::iterator iter = mp.begin();
        advance(iter, 2);
        mp.erase(iter);
        print_elem_map(mp);  // 输出 1:a 2:b 4:d 5:e

        // 方式2：通过迭代器删除特定的一段元素
        restoreMap();
        map<int, char>::iterator iter_ter;
        iter = mp.begin();
        iter_ter = mp.begin();
        advance(iter, 1);
        advance(iter_ter, 3);
        mp.erase(iter, iter_ter);
        print_elem_map(mp);  // 输出 1:a 4:d 5:e

        // 方式3：通过键删除特定的元素
        restoreMap();
        mp.erase(4);
        print_elem_map(mp);  // 输出 1:a 2:b 3:c 5:e
    }

    void mapFind()  // 通过键在 map 中查找元素，返回值为指向找到的元素的迭代器
    {
        restoreMap();
        map<int, char>::iterator iter = mp.find(3);
        if (iter != mp.end())  // 输出 3:c
            cout << iter->first << ":" << iter->second << endl;
        iter = mp.find(0);
        if (iter == mp.end())  // 输出 Can not find key=0
            cout << "Can not find key=0" << endl;
    }

    void mapSwap()  // 交换两个 map 容器中的元素
    {
        map<int, char> mp_2;
        typedef pair<int, char> in_pair;
        mp_2.insert(in_pair(7, 'g'));
        mp_2.insert(in_pair(8, 'h'));
        mp_2.insert(in_pair(9, 'i'));

        restoreMap();
        mp.swap(mp_2);
        
        print_elem_map(mp);  // 输出 7:g 8:h 9:i
        print_elem_map(mp_2);  // 输出 1:a 2:b 3:c 4:d 5:e
    }

    void mapLowerBound()  // 返回第一个指向 map 中大于等于指定键值的元素的迭代器
    {
        // 首先，测试 map 中键值按照从小到大顺序排列的情况
        restoreMap();
        map<int, char>::iterator iter = mp.lower_bound(3);
        for (; iter != mp.end(); ++iter)  // 输出 3:c 4:d 5:e
        {
            cout << iter->first << ":" << iter->second << " ";
        }
        cout << endl;

        // 然后，测试 map 中键值按照从大到小顺序排列的情况
        map<int, char, greater<int> > mp_2;
        mp_2.insert(pair<int, char>(1, 'a'));
        mp_2.insert(pair<int, char>(2, 'b'));
        mp_2.insert(pair<int, char>(3, 'c'));
        mp_2.insert(pair<int, char>(4, 'd'));
        mp_2.insert(pair<int, char>(5, 'e'));

        map<int, char, greater<int> >::iterator iter_2 = mp_2.lower_bound(3);
        for (; iter_2 != mp_2.end(); ++iter_2)  // 输出 3:c 2:b 1:a
        {
            cout << iter_2->first << ":" << iter_2->second << " ";
        }
        cout << endl;
    }

    void mapUpperBound()  // 返回第一个指向 map 中小于等于指定键值的元素的下一个元素的迭代器 
    {
        // 首先，测试 map 中键值按照从小到大顺序排列的情况
        restoreMap();
        map<int, char>::iterator iter = mp.begin();
        map<int, char>::iterator iter_ter = mp.upper_bound(3);
        for (; iter != iter_ter; ++iter)  // 输出 1:a 2:b 3:c
        {
            cout << iter->first << ":" << iter->second << " ";
        }
        cout << endl;

        iter = iter_ter;
        for (; iter != mp.end(); ++iter)  // 输出 4:d 5:e
        {
            cout << iter->first << ":" << iter->second << " ";
        }
        cout << endl;

        // 然后，测试 map 中键值按照从大到小顺序排列的情况
        // 注意这里的测试结果，虽然返回的是上界， 但是迭代器位于上界前面的元素的键均大于该上界元素的键
        map<int, char, greater<int> > mp_2;
        mp_2.insert(pair<int, char>(1, 'a'));
        mp_2.insert(pair<int, char>(2, 'b'));
        mp_2.insert(pair<int, char>(3, 'c'));
        mp_2.insert(pair<int, char>(4, 'd'));
        mp_2.insert(pair<int, char>(5, 'e'));

        map<int, char, greater<int> >::iterator iter_2_ter = mp_2.upper_bound(3);
        map<int, char, greater<int> >::iterator iter_2 = mp_2.begin();
        for (; iter_2 != iter_2_ter; ++iter_2)  // 输出 5:e 4:d 3:c
        {
            cout << iter_2->first << ":" << iter_2->second << " ";
        }
        cout << endl;

        iter_2 = iter_2_ter;
        for (; iter_2 != mp_2.end(); ++iter_2)  // 输出 2:b 1:a
        {
            cout << iter_2->first << ":" << iter_2->second << " ";
        }
        cout << endl;
    }

    // void mapEqualRange()
    // {
    //     restoreMap();
    //     pair<map<int, char>::iterator, map<int, char>::iterator> iter_pair;
    //     iter_pair = equal_range(mp.begin(), mp.end(), 3);
    //     map<int, char>::iterator iter = iter_pair.first;
    //     map<int, char>::iterator iter_ter = iter_pair.second;
    //     for (; iter != iter_ter; ++iter)
    //     {
    //         cout << iter->first << ":" << iter->second << " ";
    //     } 
    //     cout << endl;
    // }

private:
    void print_elem_map(map<int, char> & mp)
    {
        for_each(mp.begin(), mp.end(), print_pair);
        cout << endl;
    }

    static void print_pair(pair<int, char> pr)
    {
        cout << pr.first << ":" << pr.second << " ";
    }

    void restoreMap()
    {
        mp.clear();
        typedef pair<int, char> input_pair;
        mp.insert(input_pair(1, 'a'));   
        mp.insert(input_pair(2, 'b'));   
        mp.insert(input_pair(3, 'c'));   
        mp.insert(input_pair(4, 'd'));   
        mp.insert(input_pair(5, 'e'));   
    }

private:
    map<int, char> mp;

};


int main()
{
    LearnMap lm;

    // lm.mapInsert();
    // lm.mapSize();
    // lm.mapCount();
    // lm.mapEmpty();
    // lm.mapOutput();
    // lm.mapErase();
    // lm.mapFind();
    // lm.mapSwap();
    lm.mapLowerBound();
    lm.mapUpperBound();

    system("pause");
    return 0;
}