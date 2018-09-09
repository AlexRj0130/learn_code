#include <iostream>

#include <string>

using namespace std;

class LearnStringCopyAndCompare
{
public:
    // 使用比较运算符对比两个 string
    void stringCompareOperator()
    {
        string str_1("abcdef");
        string str_2("abd");

        cout << (str_1 > str_2) << endl;
        cout << (str_1 >= str_2) << endl;
        cout << (str_1 < str_2) << endl;
        cout << (str_1 <= str_2) << endl;
        cout << (str_1 == str_2) << endl;
        cout << (str_1 != str_2) << endl;
    }

    // 使用 compare 成员函数进行比较
    void stringCompare()
    {
        // 比较两个 string 对象
        string str_1("abcdefg");
        cout << str_1.compare(string("abcdef")) << endl;

        // string 与字符串进行比较
        string str_2("abcdefg");
        cout << str_2.compare("abcdefgh") << endl;

        // string 的指定范围(index, len)与另一个 string 比较
        // string.compare(index, len, str)
        string str_3("abcdefg");
        cout << str_3.compare(3, 3, string("def")) << endl;

        // string 的指定范围(index1, len1)与另一个 string 的指定范围(index2, len2)比较
        // string.compare(index1, len1, str, index2, len2)
        string str_4("abcdefg");
        cout << str_4.compare(3, 3, string("cdefgh"), 1, 3) << endl;
    }

    // 使用 copy 成员函数将 string 中的某一段内容复制到字符数组（字符串）中
    void stringCopy()
    {
        string str("abcdefg");
        char c_tmp[16];
        // 将 string 中从 index 开始的 len 个字符复制到字符数组中
        // string.copy(c_tmp, len, index)
        str.copy(c_tmp, 2, 3);
        cout << c_tmp << endl;
    }

};

int main()
{
    LearnStringCopyAndCompare lscc;

    // lscc.stringCompareOperator();
    // lscc.stringCompare();
    lscc.stringCopy();

    return 0;
}