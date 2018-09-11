#include <iostream>

#include <string>

using namespace std;

class LearnStringIterator
{
public:
    void stringIterator()
    {
        string str("abcdefg");

        // 定义 string 的迭代器（迭代器相当于是指向对应元素类型的指针）
        string::iterator str_iter;

        // 通过迭代器遍历 string 中的字符
        str_iter = str.begin();
        for (int i = 0; i < str.size(); i++)  // 输出 abcdefg
        {
            cout << * str_iter;
            ++str_iter;
        }
        cout << endl;

        // 通过对迭代器进行下标运算遍历 string 中的字符
        str_iter = str.begin();
        for (int i = 0; i < str.size(); i++)  // 输出 abcdefg
        {
            cout << str_iter[i];
        }
        cout << endl;

        // 通过迭代器自增操作遍历 string 中的字符
        for (str_iter = str.begin(); str_iter != str.end(); ++str_iter)  // 输出 abcdefg
        {
            cout << * str_iter;
        }
        cout << endl;

        // 通过*迭代器修改 string
        for (str_iter = str.begin(); str_iter != str.end(); ++str_iter)
        {
            *str_iter = 'a';
        }
        cout << str << endl;  // 输出 aaaaaaa

        // 通过迭代器下标运算修改 string
        str_iter = str.begin();
        for (int i = 0; i < str.size(); i++)
        {
            str_iter[i] = 'b';
        }
        cout << str << endl;  // 输出 bbbbbbb

    }

    // 测试迭代器的失效
    void stringInvalidIterator()
    {
        string str("abcdefg");
        string::iterator str_iter = str.begin();
        str.append(49, 'a');
        str_iter[3] = 'a';  // 在 mac 上测试，程序并没有崩溃
        cout << * str_iter << endl;  // 但是这里没有任何输出内容
        // 一般情况下，当容器的内存空间发生变化时，会导致迭代器失效
        // 当迭代器失效后，如果再次通过迭代器操作容器，往往会导致程序崩溃
        // 为了处理迭代器失效，可以在再次使用迭代器之前，重新为其进行赋值
    }
};


int main()
{
    LearnStringIterator lsi;

    // lsi.stringIterator();
    lsi.stringInvalidIterator();

    return 0;
}