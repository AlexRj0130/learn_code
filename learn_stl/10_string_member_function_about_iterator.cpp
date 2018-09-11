#include <iostream>

#include <string>

using namespace std;

// 测试 string 中同迭代器相关的成员函数
class LearnStringIteratorFunction
{
public:
    void stringAppend()
    {
        string str_1("abc");
        string str_2("def");

        str_1.append(str_2.begin(), str_2.begin() + 3);  // 注意这里第二个参数，说明 append 的是一个左闭右开区间
        cout << str_1 << endl;  // 输出 abcdef
    }

    void stringErase()
    {
        // 从 string 中删除指定位置的字符
        string str_1("abcdefg");
        str_1.erase(str_1.begin() + 2);
        cout << str_1 << endl;  // 输出 abdefg

        // 从 string 中删除一段连续的字符
        string str_2("abcdefg");
        str_2.erase(str_2.begin() + 2, str_2.begin() + 4);
        cout << str_2 << endl;  // 输出 abefg
    }

    void stringInsert()
    {
        // 在 string 的指定下标位置，连续插入指定个数的同一字符
        string str_1("abcdefg");
        str_1.insert(str_1.begin() + 2, 3, 'X');
        cout << str_1 << endl;  // 输出 abXXXcdefg

        // 在 string 的指定下标位置，插入另一个 string 的一段子串
        string str_2("abcdefg");
        string str_3("ABCDEFG");
        str_2.insert(str_2.begin() + 2, str_3.begin() + 2, str_3.begin() + 5);
        cout << str_2 << endl;  // 输出 abCDEcdefg
    }
};


int main()
{
    LearnStringIteratorFunction lsif;

    // lsif.stringAppend();
    // lsif.stringErase();
    lsif.stringInsert();

    return 0;
}