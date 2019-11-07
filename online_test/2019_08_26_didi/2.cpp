#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

bool help(vector<int> & que1, vector<int> & que2, int & sta1, int & sta2)
{
    if (sta1 >= que1.size() || sta2 >= que2.size())
        return false;
    
    int newSta1 = que1.size();
    int newSta2 = que2.size();
    for (int i = sta1; i < que1.size(); i++)
        for (int j = sta2; j < que2.size(); j++)
        {
            if ((que1[i] == que2[j]) && (i + j) < (newSta1 + newSta2))
            {
                newSta1 = i;
                newSta2 = j;
            }
        }
    
    if (newSta1 == que1.size() || newSta2 == que2.size())
        return false;
    sta1 = newSta1 + 1;
    sta2 = newSta2 + 1;

    return true;
}

int main()
{
    int n, total, cost;
    cin >> n >> total >> cost;
    vector<int> que1;
    vector<int> que2;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        que1.push_back(tmp);
    }
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        que2.push_back(tmp);
    }
    
    int count = 0;
    int sta1 = 0;
    int sta2 = 0;
    while(help(que1, que2, sta1, sta2))
	{
        count++;
    }
    cout << count << endl;
    return 0;
}