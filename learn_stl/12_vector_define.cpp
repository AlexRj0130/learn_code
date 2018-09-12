#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LearnVectorDefine
{
public:
    void vectorDefine()
    {
        // 定义一个存储 int 数据类型的 vector 动态数组
        // 不仅可以存储 int，还可以存储 struct，指针，对象等
        vector<int> vec; 
    }
};


int main()
{
    LearnVectorDefine lvd;

    lvd.vectorDefine();

    return 0;
}