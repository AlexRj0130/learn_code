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