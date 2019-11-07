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

/* 
属于有序容器，操作函数跟 map 都一样
区别：
    1. 允许键值重复
    2. 计数 count，记录同一个键值的个数
    3. find 函数返回第一个匹配的元素，没找到返回最后一个
 */
class LearnMultimap
{
public:
    void multimapConstruct()
    {
        multimap<int, char> mmp;
        mmp.insert(pair<int, char>(1, 'a'));
        mmp.insert(pair<int, char>(2, 'b'));
        mmp.insert(pair<int, char>(2, 'c'));
        mmp.insert(pair<int, char>(3, 'd'));
        mmp.insert(pair<int, char>(3, 'd'));
        mmp.insert(pair<int, char>(3, 'e'));

        print_elem_multimap(mmp);  // 输出 1:a 2:b 2:c 3:d 3:d 3:e
    }

    void multimapCount()
    {
        multimap<int, char> mmp;
        mmp.insert(pair<int, char>(1, 'a'));
        mmp.insert(pair<int, char>(2, 'b'));
        mmp.insert(pair<int, char>(2, 'c'));
        mmp.insert(pair<int, char>(3, 'd'));
        mmp.insert(pair<int, char>(3, 'd'));
        mmp.insert(pair<int, char>(3, 'e'));

        cout << mmp.count(1) << endl;  // 输出 1
        cout << mmp.count(2) << endl;  // 输出 2
        cout << mmp.count(3) << endl;  // 输出 3
    }

    void multimapFind()
    {
        /* 
        返回的不是所有匹配到的元素的迭代器，而是第一个匹配到的元素的迭代器
         */
        multimap<int, char> mmp;
        mmp.insert(pair<int, char>(1, 'a'));
        mmp.insert(pair<int, char>(2, 'b'));
        mmp.insert(pair<int, char>(2, 'c'));
        mmp.insert(pair<int, char>(3, 'd'));
        mmp.insert(pair<int, char>(3, 'd'));
        mmp.insert(pair<int, char>(3, 'e'));

        multimap<int, char>::iterator iter_1, iter_2, iter_3;
        iter_1 = mmp.find(1);
        iter_2 = mmp.find(2);
        iter_3 = mmp.find(3);

        cout << iter_1->first << ":" << iter_1->second << endl;  // 输出 1:a
        ++iter_1;

        cout << (iter_1 == iter_2) << endl;  // 输出 1

        cout << iter_2->first << ":" << iter_2->second << endl;  // 输出 2:b
        ++iter_2; 
        cout << iter_2->first << ":" << iter_2->second << endl;  // 输出 2:c
        ++iter_2; 

        cout << (iter_2 == iter_3) << endl;  // 输出 1

        cout << iter_3->first << ":" << iter_3->second << endl;  // 输出 3:d
        ++iter_3;
        cout << iter_3->first << ":" << iter_3->second << endl;  // 输出 3:d
        ++iter_3;
        cout << iter_3->first << ":" << iter_3->second << endl;  // 输出 3:e
        ++iter_3;

        cout << (iter_3 == mmp.end()) << endl;  // 输出 1
    }

private:
    void print_elem_multimap(multimap<int, char> & mmp)
    {
        multimap<int, char>::iterator iter, iter_end;
        iter = mmp.begin();
        iter_end = mmp.end();
        
        for (; iter != iter_end; ++iter)
        {
            cout << iter->first << ":" << iter->second << " ";
        }
        cout << endl;
    }
};


int main()
{
    LearnMultimap lmmp;

    // lmmp.multimapConstruct();
    // lmmp.multimapCount();
    lmmp.multimapFind();

    system("pause");
    return 0;
}