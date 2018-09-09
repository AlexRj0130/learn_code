#include <iostream>

#include <string>

using namespace std;

class LearnStringCout
{
public:
    // 输出全部字符串
    void stringCoutAll()
    {
        string str_1("abcdefg");
        // 方法1：直接调用重载运算符 <<
        cout << str_1 << endl;
        // 方法2：使用字符串的首地址输出整个字符串
        cout << str_1.c_str() << endl;
    }

    // 输出单个字符
    void stringCoutSingle()
    {
        // 方法1：调用重载运算符[]
        string str("abcdefg");
        cout << str[3] << endl;
        // 方法2：使用 at 成员方法
        cout << str.at(4) << endl;  // at 成员的输入参数同样为字符串的下标

        // 注：使用上述两种方法，输入参数均为字符串的下标；
        // 当使用 at 成员时，如果下标超过字符串的范围，将触发异常；
        // 当使用 [] 运算符时，如果下标超过字符串的范围，程序崩溃。
    }
};

int main()
{
    LearnStringCout lsc;

    // lsc.stringCoutAll();
    lsc.stringCoutSingle();


    return 0;
}