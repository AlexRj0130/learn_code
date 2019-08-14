#include <iostream>
#include <stdlib.h>
#include <sstream>

#include <string>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <stack>
#include <iterator>
#include <numeric>
#include <algorithm>

using namespace std;

int main()
{
    string input;
    cin >> input;
    if (input.size() == 0)
    {
        cout << 0 << endl;
        return 0;
    }
    if (input[0] == ',')
    {
        cout << "ERROR" << endl;
        return 0;
    }
        
    vector<string> output;
    while(!input.empty())
    {
        bool flag = false;
        if (input[0] == '"')
            flag = true;
        if (input[0] == ',')
        {
            output.push_back("--");
            input = input.substr(1, input.size());
            continue;
        }
        int sta = -1;
        int end = -1;
        int nextSta = -1;
        for (int i = 1; i <= input.size(); i++)
        {
            if (i >= input.size())
            {
                if (flag)
                {
                    cout << "ERROR" << endl;
                    return 0;
                }
                sta = 0;
                end = input.size();
                break;
            }

            if (!flag)
            {
                if ((end == -1) && (input[i] == ','))
                {
                    if (i + 1 == input.size())
                    {
                        cout << "ERROR" << endl;
                        return 0;
                    }
                    sta = 0;
                    end = i;
                    nextSta = i + 1;
                    break;
                }
            }
            else 
            {
                if ((end == -1) && (input[i] == '"') && ((i == input.size() - 1)))
                {
                    sta = 1;
                    end = i;
                    break;
                }
                if ((end == -1) && (input[i] == '"') && (i < input.size() - 1) && (input[i+1] == ','))
                {
                    if (i + 1 == input.size())
                    {
                        cout << "ERROR" << endl;
                        return 0;
                    }
                    sta = 1;
                    end = i;
                    nextSta = i+2;
                    break;
                }
            }
        }

        string tmp = input.substr(sta, end - sta);
        if (tmp == "")
            output.push_back("--");
        else
        {
            string tmptmp = "";
            int countTmp = 0;
            for (int i = 0; i < tmp.size(); i++)
            {
                if (tmp[i] == '"')
                {
                    countTmp++;
                    if (countTmp % 2 == 0)
                        tmptmp += tmp[i];
                }
                else
                {
                    tmptmp += tmp[i];
                }
            }
            if (countTmp % 2 != 0)
                cout << "ERROR" << endl;
            output.push_back(tmptmp);
        } 
        if (nextSta == -1)
            break;
        input = input.substr(nextSta, input.size());

        if (-1 == end)
            cout << "ERROR" << endl;
    }
    cout << output.size() << endl;
    for (int i = 0; i < output.size(); i++)
    {
        cout << output[i] << endl;
    }
    return 0;
}