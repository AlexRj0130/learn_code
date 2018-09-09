#include <iostream>

#include <string>

using namespace std;

class LearnStringProperty
{
public:
    void stringCapacity()
    {
        // 容量属性：capacity
        /* 容量属性与编译器有关
          在 vs 编译器中，初始容量为15；每溢出一个，容量增加16；
          在 vc6.0 编译器中，初始容量为31；每溢出一个，容量增加32；
          在 g++ 编译器中，初始容量为22；第一次溢出，容量增加9；后面每溢出一个，容量增加16。*/
        string str_1;
        cout << str_1.capacity() << endl;
        string str_2(32, 'a');
        cout << str_2.capacity() << endl;

        cout << endl;
    }

    void stringReserve()
    {
        // 修改容量：reserve
        /* reserve只能用来申请比实际字符数大的容量，而不能比实际字符数小；
           当 reserve 给定的参数比实际字符数大的时候，那么修改后的容量为满足容量属性增加规律的，比给定值大且与给定值最接近的容量值。*/
        string str_1(1, 'a');
        str_1.reserve(23);
        cout << str_1.capacity() << endl;
        str_1.reserve(1);
        cout << str_1.capacity() << endl;

        cout << endl;
    }

    void stringLengthAndSize()
    {
        // 获取字符串的长度或字符的个数
        /* length 和 size 的返回值是相同的，都代表当前容器中字符的个数。*/
        string str_1;
        cout << str_1.length() << " " << str_1.size() << endl;
        string str_2(5, 'a');
        cout << str_2.length() << " " << str_2.size() << endl;

        cout << endl;
    }

    void stringResize()
    {
        // 截断字符串，只保留从前面开始的指定个数的字符
        string str_1("abcdefg");
        str_1.resize(3);
        cout << str_1 << " " << str_1.capacity() << " " << str_1.length() << " " << str_1.size() << endl;

        cout << endl;
    }
};

int main()
{
    LearnStringProperty lsp;
    // lsp.stringCapacity();
    // lsp.stringReserve();
    // lsp.stringLengthAndSize();
    lsp.stringResize();

    return 0;
}