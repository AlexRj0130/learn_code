#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LearnVectorConstruct
{
public:
    void vectorConstruct()
    {
        // 方法1：无参构造函数
        vector<int> vec_1;
        // cout << vec_1[0] << endl;  // 由于 vec_1 中没有元素，所以会出现异常，无法输出。

        // 方法2：带有一个参数的构造函数
        vector<int> vec_2(5);
        for (int i = 0; i < vec_2.size(); i++)  // 输出 0 0 0 0 0 
        {
            cout << vec_2[i] << " ";
        }
        cout << endl;

        // 方法3：带有两个参数的构造函数
        vector<int> vec_3(5, 12);
        for (int i = 0; i < vec_3.size(); i++)  // 输出 12 12 12 12 12 
        {
            cout << vec_3[i] << " ";
        }
        cout << endl;

        // 方法4：用另一个 vector 初始化当前 vector
        vector<int> vec_4(vec_3);
        for (int i = 0; i < vec_4.size(); i++)  // 输出 12 12 12 12 12 
        {
            cout << vec_4[i] << " ";
        }
        cout << endl;

        // 方法4：用另一个 vector 中的一段初始化当前 vector
        vector<int> vec_5(vec_4.begin(), vec_4.begin()+3);
        for (int i = 0; i < vec_5.size(); i++)  // 输出 12 12 12 
        {
            cout << vec_5[i] << " ";
        }
        cout << endl;

    }
};


int main()
{
    LearnVectorConstruct lvc;

    lvc.vectorConstruct();

    return 0;
}