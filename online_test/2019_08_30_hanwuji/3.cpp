#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector<int> & vec1, vector<int> & vec2)
{
    if (vec1[1] < vec2[1])
        return false;
    else if (vec1[1] > vec2[1])
        return true;
    
    if (vec1[2] < vec2[2])
        return false;
    else if (vec1[2] > vec2[2])
        return true;
    
    if (vec1[0] < vec2[0])
        return false;
    else if (vec1[0] > vec2[0])
        return true;
    
    return vec1[3] > vec2[3];
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > array;
    for (int i = 0; i < n; i++)
    {
        vector<int> tmp(4);
        for (int j = 0; j < 4; j++)
        {
            cin >> tmp[j];
        }
        array.push_back(tmp);
    }
    
    sort(array.begin(), array.end(), cmp);
    
    for (int i = 0; i < n; i++)
    {
        cout << array[i][1] << " " << array[i][2] << " " << array[i][0] << " " << array[i][3] << endl;
    }
    return 0;
}