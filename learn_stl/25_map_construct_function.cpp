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
    void mapConstruct()
    {
        // 无参构造
        map<int, char> mp;

        // 定义一个用来获取 insert 函数返回值的结构
        pair<map<int, char>::iterator, bool> mpr;

        mpr = mp.insert(pair<int, char>(1, 'a'));
        print_elem_map(mp);  // 输出 1:a
        cout << mpr.second << endl;  // 输出 1

        mpr = mp.insert(pair<int, char>(2, 'b'));
        print_elem_map(mp);  // 输出 1:a 2:b
        cout << mpr.second << endl;  // 输出 1

        mpr = mp.insert(pair<int, char>(2, 'c'));
        print_elem_map(mp);  // 输出 1:a 2:b
        cout << mpr.second << endl;  // 输出 0

        // 拷贝构造：使用已存在的 map 构造当前 map
        map<int, char> mp_2(mp);
        print_elem_map(mp_2);  // 输出 1:a 2:b

        // 使用已存在的 map 中的一段构造当前 map
        map<int, char>::iterator iter_sta = mp.begin();
        map<int, char>::iterator iter_ter = mp.end();
        map<int, char> mp_3(iter_sta, iter_ter);
        print_elem_map(mp_3);  // 输出 1:a 2:b
    }

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
};


int main()
{
    LearnMap lm;

    lm.mapConstruct();

    system("pause");
    return 0;
}