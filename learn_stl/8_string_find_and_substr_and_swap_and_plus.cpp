#include <iostream>

#include <string>

using namespace std;

class LearnStringFind
{
public:
    // 使用 find() 成员函数查找子串
    void stringFind()
    {
        string str_1("abcdefg");
        string str_2("cde");

        // 方法1：在一个 string 中，从指定下标开始，查找另一个子 string

        // 在str_1中，从头开始，查找str_2
        cout << str_1.find(str_2) << endl;  // 输出2
        // 在str_1中，从下标1开始，查找str_2
        cout << str_1.find(str_2, 1) << endl;  // 输出2
        // 在str_1中，从下标3开始，查找str_2
        cout << str_1.find(str_2, 3) << endl;  // 输出18446744073709551615
        cout << string::npos << endl;  // 输出18446744073709551615
        cout << (int)string::npos << endl;  // 输出-1

        // 方法2：在一个 string 中，从指定下标开始，查找一个字符串

        // 在 str_1 中，从头开始，查找字符串
        cout << str_1.find("cde") << endl;  // 输出2
        // 在 str_1 中，从下标1开始，查找字符串
        cout << str_1.find("cde", 1) << endl;  // 输出2
        // 在 str_1 中，从下标3开始，查找字符串
        cout << str_1.find("cde", 3) << endl;  // 输出 string::npos

        // 方法3：在一个 string 中，从指定下标开始，查找一个字符

        // 在 str_1 中，从头开始，查找字符
        cout << str_1.find('c') << endl;  // 输出2
        // 在 str_1 中，从下标1开始，查找字符
        cout << str_1.find('c', 1) << endl;  // 输出2
        // 在 str_1 中，从下标3开始，查找字符
        cout << str_1.find('c', 3) << endl;  // 输出 string::npos

    }

    // 返回 string 中的一个子串
    void stringSubstr()
    {
        string str("abcdefg");
        cout << str.substr(2, 3) << endl;  // 输出 cde
    }

    // 交换两个 string 的内容
    void stringSwap()
    {
        string str_1("abc");
        string str_2("def");

        str_1.swap(str_2);
        cout << str_1 << endl;  // 输出 def
        cout << str_2 << endl;  // 输出 abc
    }

    // string 的 ＋ 运算符
    void stringPlus()
    {
        string str_1("abc");
        string str_2("def");

        // 两个 string 相加
        cout << (str_1 + str_2) << endl;  // 输出 abcdef
        // string + 字符串
        cout << (str_1 + "def") << endl;  // 输出 abcdef
        // string + 字符
        cout << (str_1 + 'd') << endl;  // 输出 abcd
    }
};


int main()
{
    LearnStringFind lsf;

    // lsf.stringFind();
    // lsf.stringSubstr();
    // lsf.stringSwap();
    lsf.stringPlus();

    return 0;
}