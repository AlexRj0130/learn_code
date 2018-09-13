#include <iostream>

#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class LearnVectorOutput
{
public:
    // 通过下标运算输出 vector 中的内容
    void vectorOutputIndex()
    {
        vector<int> vec;
        for (int i = 0; i < 10; i++)
        {
            vec.push_back(i);
        }
        for (int i = 0; i < vec.size(); i++)  // 输出 0 1 2 3 4 5 6 7 8 9 
        {
            cout << vec[i] << " ";
        }
        cout << endl;
    }

    // 通过 at() 输出 vector 中的内容
    void vectorAt()
    {
        // at() 的功能基本与下标运算是相同的
        // 区别在于，当越界时，at9() 会抛出异常，而 [] 直接崩溃
        vector<int> vec;
        for (int i = 0; i < 10; i++)
        {
            vec.push_back(i);
        }
        for (int i = 0; i < vec.size(); i++)  // 输出 0 1 2 3 4 5 6 7 8 9 
        {
            cout << vec.at(i) << " ";
        }
        cout << endl;
    }

    // 通过 back() 输出 vector 末尾的元素
    void vectorBack()
    {
        vector<int> vec;
        for (int i = 0; i < 10; i++)
        {
            vec.push_back(i);
        }
        cout << vec.back() << endl;  // 输出 9
    }

    // 通过迭代器输出 vector 中的所有元素
    void vectorIterator()
    {
        vector<int> vec;
        for (int i = 0; i < 10; i++)
        {
            vec.push_back(i);
        }
        for (vector<int>::iterator iter = vec.begin(); iter != vec.end(); ++iter)  // 输出 0 1 2 3 4 5 6 7 8 9 
        {
            cout << *iter << " ";
        }
        cout << endl;
    }

    // 通过 for_each 算法输出 vector 中的所有元素
    void vectorForEach()
    {
        vector<int> vec;
        for (int i = 0; i < 10; i++)
        {
            vec.push_back(i);
        }
        for_each(vec.begin(), vec.end(), cout_vec_elem);  // 输出 0 1 2 3 4 5 6 7 8 9 
        cout << endl;
    }

private:
    static void cout_vec_elem(int a)
    {
        cout << a << " ";
    }
};


int main()
{
    LearnVectorOutput lvo;

    // lvo.vectorOutputIndex();
    // lvo.vectorAt();
    // lvo.vectorBack();
    lvo.vectorIterator();
    // lvo.vectorForEach();

    return 0;
}