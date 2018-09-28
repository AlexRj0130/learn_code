#include <iostream>

#include <string>
#include <algorithm>

using namespace std;

class LearnString
{
public:
    void stringConstruct()
    {
        // 方法1：创建一个空字符串
        string str_1;
        cout << str_1 << endl;  // 输出 

        // 方法2：初始化指定个数的某个字符
        string str_2(5, 'a');
        cout << str_2 << endl;  // 输出 aaaaa

        // 方法3：使用字符串初始化
        string str_3("abcdefg");
        cout << str_3 << endl;  // 输出 abcdefg

        // 方法4：使用字符串中前面指定个数的字符初始化
        string str_4("abcdefg", 3);
        cout << str_4 << endl;  // 输出 abc

        // 方法5：使用字符串中指定位置(从0开始计数)开始的指定个数的字符初始化
        string str_5("abcdefg", 2, 3);
        cout << str_5 << endl;  // 输出 cde

        string str_6(str_3, 4, 3);
        cout << str_6 << endl;  // 输出 efg

        // 方法6：使用拷贝构造函数进行初始化
        string str_7(str_2);
        cout << str_7 << endl;  // 输出 aaaaa

        cout << endl;
    }

    // 输出全部字符串
    void stringCoutAll()
    {
        string str_1("abcdefg");
        // 方法1：直接调用重载运算符 <<
        cout << str_1 << endl;  // 输出 abcdefg

        // 方法2：使用字符串的首地址输出整个字符串
        cout << str_1.c_str() << endl;  // 输出 abcdefg
    }

    // 输出单个字符
    void stringCoutSingle()
    {
        // 方法1：调用重载运算符[]
        string str("abcdefg");
        cout << str[3] << endl;  // 输出 d

        // 方法2：使用 at 成员方法
        cout << str.at(4) << endl;  // 输出 e
        // at 成员的输入参数同样为字符串的下标

        // 注：使用上述两种方法，输入参数均为字符串的下标；
        // 当使用 at 成员时，如果下标超过字符串的范围，将触发异常；
        // 当使用 [] 运算符时，如果下标超过字符串的范围，程序崩溃。
    }

    void stringCapacity()
    {
        // 容量属性：capacity
        /* 容量属性与编译器有关
          在 vs 编译器中，初始容量为15；每溢出一个，容量增加16；
          在 vc6.0 编译器中，初始容量为31；每溢出一个，容量增加32；
          在 g++ 编译器中，初始容量为22；第一次溢出，容量增加9；后面每溢出一个，容量增加16。*/
        string str_1;
        cout << str_1.capacity() << endl;  // 输出 15

        string str_2(32, 'a');
        cout << str_2.capacity() << endl;  // 输出 32

        cout << endl;
    }

    void stringReserve()
    {
        // 修改容量：reserve
        /* reserve只能用来申请比实际字符数大的容量，而不能比实际字符数小；
           当 reserve 给定的参数比实际字符数大的时候，那么修改后的容量为满足容量属性增加规律的，比给定值大且与给定值最接近的容量值。*/
        string str_1(1, 'a');
        str_1.reserve(23);
        cout << str_1.capacity() << endl;  // 输出 30

        str_1.reserve(1);
        cout << str_1.capacity() << endl;  // 输出 15

        cout << endl;
    }

    void stringLengthAndSize()
    {
        // 获取字符串的长度或字符的个数
        /* length 和 size 的返回值是相同的，都代表当前容器中字符的个数。*/
        string str_1;
        cout << str_1.length() << " " << str_1.size() << endl;  // 输出 0 0 

        string str_2(5, 'a');
        cout << str_2.length() << " " << str_2.size() << endl;  // 输出 5 5

        cout << endl;
    }

    void stringResize()
    {
        // 截断字符串，只保留从前面开始的指定个数的字符
        string str_1("abcdefg");
        str_1.resize(3);
        cout << str_1 << " " << str_1.capacity() << " " << str_1.length() << " " << str_1.size() << endl;  // 输出 abc 15 3 3

        cout << endl;
    }

    // 修改字符串中的某个字符
    void stringChange()
    {
        string str("abcdefg");
        // 方法1：通过[]运算符修改指定下标对应的字符
        str[0] = 'x';

        // 方法2：通过 at 成员函数修改指定下标对应的字符
        str.at(1) = 'y';
        
        cout << str << endl;  // 输出 xycdefg
    }

    // 在字符串中进行插入操作
    void stringInsert()
    {
        // 方法1：在 index 位置，插入 string
        string str_1("abcdefg");
        str_1.insert(3, string("xxx"));
        cout << str_1 << endl;  // 输出 abcxxxdefg

        // 方法2：在 index 位置，插入字符串
        string str_2("abcdefg");
        str_2.insert(3, "yyy");
        cout << str_2 << endl;  // 输出 abcyyydefg

        // 方法3：在 index 位置，插入 string 的指定范围，范围通过起始下标+长度指定
        string str_3("abcdefg");
        str_3.insert(3, string("hijklmn"), 2, 3);
        cout << str_3 << endl;  // 输出 abcjkldefg

        // 方法4：在 index 位置，插入 string 的从起始下标到末尾的字符
        string str_4("abcdefg");
        // str_4.insert(3, string("hijklmn"), 3);
        cout << str_4 << endl;  // 输出 abcdefg

        // 方法5：在 index 位置，插入字符串的指定范围，范围通过起始下标+长度指定
        string str_5("abcdefg");
        str_5.insert(3, "hijklmn", 2, 3);
        cout << str_5 << endl;  // 输出 abcjkldefg

        // 方法6：在 index 位置，插入字符串的前 n 个字符
        string str_6("abcdefg");
        str_6.insert(3, "hijklmn", 3);
        cout << str_6 << endl;  // 输出 abchijdefg

        // 方法7：在 index 位置，插入 num 个 字符 ch
        string str_7("abcdefg");
        str_7.insert(3, 3, 'x');
        cout << str_7 << endl;  // 输出 abcxxxdefg

        // 通过迭代器插入
        // 在 string 的指定下标位置，连续插入指定个数的同一字符
        string str_8("abcdefg");
        str_8.insert(str_8.begin() + 2, 3, 'X');
        cout << str_8 << endl;  // 输出 abXXXcdefg

        // 在 string 的指定下标位置，插入另一个 string 的一段子串
        string str_9("abcdefg");
        string str_10("ABCDEFG");
        str_9.insert(str_9.begin() + 2, str_10.begin() + 2, str_10.begin() + 5);
        cout << str_9 << endl;  // 输出 abCDEcdefg
    }

    // 使用比较运算符对比两个 string
    void stringCompareOperator()
    {
        string str_1("abcdef");
        string str_2("abd");

        cout << (str_1 > str_2) << endl;  // 输出 0
        cout << (str_1 >= str_2) << endl;  // 输出 0
        cout << (str_1 < str_2) << endl;  // 输出 1
        cout << (str_1 <= str_2) << endl;  // 输出 1
        cout << (str_1 == str_2) << endl;  // 输出 0
        cout << (str_1 != str_2) << endl;  // 输出 1
    }

    // 使用 compare 成员函数进行比较
    void stringCompare()
    {
        // 比较两个 string 对象
        string str_1("abcdefg");
        cout << str_1.compare(string("abcdef")) << endl;  // 输出 1

        // string 与字符串进行比较
        string str_2("abcdefg");
        cout << str_2.compare("abcdefgh") << endl;  // 输出 -1

        // string 的指定范围(index, len)与另一个 string 比较
        // string.compare(index, len, str)
        string str_3("abcdefg");
        cout << str_3.compare(3, 3, string("def")) << endl;  // 输出 0

        // string 的指定范围(index1, len1)与另一个 string 的指定范围(index2, len2)比较
        // string.compare(index1, len1, str, index2, len2)
        string str_4("abcdefg");
        cout << str_4.compare(3, 3, string("cdefgh"), 1, 3) << endl;  // 输出 0
    }

    // 使用 copy 成员函数将 string 中的某一段内容复制到字符数组（字符串）中
    void stringCopy()
    {
        string str("abcdefg");
        char c_tmp[16];
        // 将 string 中从 index 开始的 len 个字符复制到字符数组中
        // string.copy(c_tmp, len, index)
        str.copy(c_tmp, 2, 3);
        cout << c_tmp << endl;  // 输出 de
    }

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
    LearnString ls;

    // ls.stringConstruct();
    // ls.stringCoutAll();
    // ls.stringCoutSingle();
    // ls.stringCapacity();
    // ls.stringReserve();
    // ls.stringLengthAndSize();
    // ls.stringResize();
    // ls.stringChange();
    // ls.stringInsert();
    // ls.stringCompareOperator();
    // ls.stringCompare();
    // ls.stringCopy();
    // ls.stringFind();
    // ls.stringSubstr();
    // ls.stringSwap();
    // ls.stringPlus();
    // ls.stringIterator();
    // ls.stringInvalidIterator();
    // ls.stringAppend();
    // ls.stringErase();
    // ls.stringForEach();
    ls.stringSort();

    system("pause");
    return 0;
}
