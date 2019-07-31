#include <iostream>
#include <stdlib.h>

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <iterator>
#include <numeric>

using namespace std;

class Solution {
public:
	void replaceSpace(char *str,int length) {
        string tmp(str, str+length);
        
        int i = 0;
        while(i < tmp.length())
        {
            if (tmp[i] == ' ')
            {
                tmp.replace(i, 1, "%20");
                i+=2;
            }
            i++;
        }

        // str = const_cast<char *>(tmp.c_str());  // 这样不行，原因在于 str 中传的是指针的值，而不是指针的指针
        for(i = 0; i < tmp.length(); i++)
        {
            str[i] = tmp[i];
        } 
	}
};

int main()
{
    Solution solution;
    char s[] = {"Hello world"};
    solution.replaceSpace(s, sizeof(s));
    cout << s << endl;
    return 0;
}