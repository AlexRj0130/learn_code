#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iterator>
#include <algorithm>
#include <numeric>

using namespace std;

/* 
set 同样通过红黑树进行保存
与 map 不同的是，map 中存储的是 键--值 对；而 set 中只存储一个 键 值；
因此，set 中的元素是不能够重复的，即时可以重复也没有意义
 */
class LearnSet
{
public:
    void setConstruct()
    {
        set<string> st;

        st.insert(string("aba"));
        st.insert(string("abb"));
        st.insert(string("abc"));
        st.insert(string("abd"));
        st.insert(string("abe"));

        print_elem_set(st);  // 输出 aba abb abc abd abe
    }

    void setErase()
    {
        set<string> st;

        st.insert(string("aba"));
        st.insert(string("abb"));
        st.insert(string("abc"));
        st.insert(string("abd"));
        st.insert(string("abe"));

        st.erase("abb");
        print_elem_set(st);  // 输出 aba abc abd abe
    }

private:
    void print_elem_set(set<string> & st)
    {
        set<string>::iterator iter, iter_end;
        iter = st.begin();
        iter_end = st.end();
        for (; iter != iter_end; ++iter)
        {
            cout << *iter << " ";
        }
        cout << endl;
    }
};


int main()
{
    LearnSet ls;

    // ls.setConstruct();
    ls.setErase();

    system("pause");
    return 0;
}