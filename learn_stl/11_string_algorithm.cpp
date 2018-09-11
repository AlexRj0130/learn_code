#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

class LearnStringAlgorithm
{
public:
    // 通过算法遍历 string 
    void stringForEach()
    {
        string str_1("abcdefg");
        // for_each 函数对通过迭代器指定的范围内的每一个元素，进行指定的操作
        for_each(str_1.begin(), str_1.end(), cout_char);  // 输出 abcdefg
        cout << endl;
        for_each(str_1.begin(), str_1.end(), cout_char_2);  // 输出 ABCDEFG
        cout << endl;
    }

    // 通过算法进行排序
    void stringSort()
    {
        string str_1("adfaiofkalfjiouef");
        sort(str_1.begin(), str_1.end());  // 默认按照从小到大排序
        cout << str_1 << endl;  // 输出 aaadeffffiijkloou

        string str_2("adfaiofkalfjiouef");
        sort(str_2.begin(), str_2.end(), greater<char>());  // 通过 greater 指定从大到小排序
        cout << str_2 << endl;  // 输出 uoolkjiiffffedaaa
    }

private:
    static void cout_char(char c)  // 需要特别注意的就是这个函数的输入参数类型，不能是迭代器
    {
        cout << c;
    }

    static void cout_char_2(char c)
    {
        char c_tmp = c + 'A' - 'a';
        cout << c_tmp;
    }
};


int main()
{
    LearnStringAlgorithm lsa;

    // lsa.stringForEach();
    lsa.stringSort();


    return 0;
}