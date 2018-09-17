#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <iterator>
#include <algorithm>

using namespace std;

class LearnListSizeAndResize
{
public:
    void listSize()
    {
        int array[6] = {1, 2, 3, 4, 5, 6};
        list<int> lst(array, array+6);
        cout << lst.size() << endl;  // 输出 6
        for_each(lst.begin(), lst.end(), cout_list_elem);  // 输出 1 2 3 4 5 6 
        cout << endl;   
    }

    void listResize()
    {
        int array[6] = {1, 2, 3, 4, 5, 6};
        list<int> lst(array, array+6);
        cout << lst.size() << endl;  // 输出 6
        lst.resize(3);
        cout << lst.size() << endl;  // 输出 3
        for_each(lst.begin(), lst.end(), cout_list_elem);  // 输出 1 2 3 
        cout << endl;
    }

    void listEmpty()
    {
        int array[6] = {1, 2, 3, 4, 5, 6};
        list<int> lst(array, array+6);
        cout << lst.empty() << endl;  // 输出 0
        lst.resize(0);
        cout << lst.empty() << endl;  // 输出 1
    }

private:
    static void cout_list_elem(const int & val)
    {
        cout << val << " ";
    }
};


int main()
{
    LearnListSizeAndResize llsar;

    // llsar.listSize();
    // llsar.listResize();
    llsar.listEmpty();

    system("pause");
    return 0;
}