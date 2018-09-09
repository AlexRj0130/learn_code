#include <iostream>

#include <string>

using namespace std;

class LearnStringModify
{
public:
    // 修改字符串中的某个字符
    void stringChange()
    {
        string str("abcdefg");
        // 方法1：通过[]运算符修改指定下标对应的字符
        str[0] = 'x';
        // 方法2：通过 at 成员函数修改指定下标对应的字符
        str.at(1) = 'y';
        
        cout << str << endl;
    }

    // 在字符串中进行插入操作
    void stringInsert()
    {
        // 方法1：在 index 位置，插入 string
        string str_1("abcdefg");
        str_1.insert(3, string("xxx"));
        cout << str_1 << endl;

        // 方法2：在 index 位置，插入字符串
        string str_2("abcdefg");
        str_2.insert(3, "yyy");
        cout << str_2 << endl;

        // 方法3：在 index 位置，插入 string 的指定范围，范围通过起始下标+长度指定
        string str_3("abcdefg");
        str_3.insert(3, string("hijklmn"), 2, 3);
        cout << str_3 << endl;

        // 方法4：在 index 位置，插入 string 的从起始下标到末尾的字符
        string str_4("abcdefg");
        str_4.insert(3, string("hijklmn"), 3);
        cout << str_4 << endl;

        // 方法5：在 index 位置，插入字符串的指定范围，范围通过起始下标+长度指定
        string str_5("abcdefg");
        str_5.insert(3, "hijklmn", 2, 3);
        cout << str_5 << endl;

        // 方法6：在 index 位置，插入字符串的前 n 个字符
        string str_6("abcdefg");
        str_6.insert(3, "hijklmn", 3);
        cout << str_6 << endl;

        // 方法7：在 index 位置，插入 num 个 字符 ch
        string str_7("abcdefg");
        str_7.insert(3, 3, 'x');
        cout << str_7 << endl;
    }
};

int main()
{
    LearnStringModify lsm;

    // lsm.stringChange();
    lsm.stringInsert();


    return 0;
}