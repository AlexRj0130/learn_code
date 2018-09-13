#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LearnVectorCapacityAndSize
{
public:
    void vectorCapacity()
    {
        // 对于空的 vector
        vector<int> vec_1;
        cout << vec_1.capacity() << endl;  // 输出 0 

        // 初始化5个元素
        // 测试表明，在 g++ 编译器下，vector每次在 vector 后追加元素之后，
        // 如果所需容量超出了当前容量，则将当前容量加倍
        // 不过对于上述增加方式，不同的编译器的规律是不一样的
        vector<int> vec_2(5);
        cout << vec_2.capacity() << endl;  // 输出 5
        // 在 vector 的末尾添加元素
        vec_2.push_back(1);
        vec_2.push_back(1);
        cout << vec_2.capacity() << endl;  // 输出 10 
    }

    void vectorReserve()
    {
        vector<int> vec;

        vec.reserve(1);
        cout << vec.capacity() << endl;  // 输出 1

        vec.reserve(3);
        cout << vec.capacity() << endl;  // 输出 3

        vec.reserve(5);
        cout << vec.capacity() << endl;  // 输出 5

        // reserve 的参数是多大，就把 vector 的容量调整为多大
        // 需要注意的是，如果 reserve 只能将容器扩大，无法缩小

        vector<int> vec_2(2, 5);
        cout << vec_2.capacity() << endl;  // 输出 2
        cout << vec_2.size() << endl;  // 输出 2

        vec_2.reserve(10);
        cout << vec_2.capacity() << endl;  // 输出 10
        cout << vec_2.size() << endl;  // 输出 2

        vec_2.reserve(2);
        cout << vec_2.capacity() << endl;  // 输出 10
        cout << vec_2.size() << endl;  // 输出 2
    }

    void vectorSizeAndResize()
    {
        // size() 函数用来返回容器中的元素的个数
        // resize() 函数用来截断容器末尾的元素，而不会影响容器的容量
        vector<int> vec(5, 2);
        cout << vec.capacity() << endl;  // 输出 5
        cout << vec.size() << endl;  // 输出 5

        vec.resize(2);
        cout << vec.capacity() << endl;  // 输出 5
        cout << vec.size() << endl;  // 输出 2
    }

    void vectorEmpty()
    {
        vector<int> vec(1);

        cout << vec.empty() << endl;  // 输出 0

        vec.pop_back();

        cout << vec.empty() << endl;  // 输出 1
        cout << vec.capacity() << endl;  // 输出 1
    }
};


int main()
{
    LearnVectorCapacityAndSize lvcs;

    // lvcs.vectorCapacity();
    // lvcs.vectorReserve();
    // lvcs.vectorSizeAndResize();
    lvcs.vectorEmpty();

    return 0;
}