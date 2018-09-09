#include <iostream>

#include <string>

using namespace std;

class LearnStringConstruct
{
public:
    void stringConstruct()
    {
        // 方法1：创建一个空字符串
        string str_1;
        cout << str_1 << endl;
        // 方法2：初始化指定个数的某个字符
        string str_2(5, 'a');
        cout << str_2 << endl;
        // 方法3：使用字符串初始化
        string str_3("abcdefg");
        cout << str_3 << endl;
        // 方法4：使用字符串中前面指定个数的字符初始化
        string str_4("abcdefg", 3);
        cout << str_4 << endl;
        // 方法5：使用字符串中指定位置(从0开始计数)开始的指定个数的字符初始化
        string str_5("abcdefg", 2, 3);
        cout << str_5 << endl;
        string str_6(str_3, 4, 3);
        cout << str_6 << endl;
        // 方法6：使用拷贝构造函数进行初始化
        string str_7(str_2);
        cout << str_7 << endl;

        cout << endl;
    }
};


int main()
{
    LearnStringConstruct lsc;
    lsc.stringConstruct();
    return 0;
}
