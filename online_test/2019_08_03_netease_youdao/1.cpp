#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <iomanip>

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
    int n;
    cin >> n;

    vector<double> grade;
    for (int i = 0; i < n; i++)
    {
        double tmp;
        cin >> tmp;
        grade.push_back(tmp);
    }

    int q;
    cin >> q;
    vector<int> student;
    for (int i = 0; i < q; i++)
    {
        int tmp;
        cin >> tmp;
        student.push_back(tmp);
    }

    vector<double> gradeCopy(grade);
    sort(gradeCopy.begin(), gradeCopy.end());
    map<double, double> grade2index;

    for (int i = 0; i < gradeCopy.size(); i++)
    {
        double scoreSta = gradeCopy[i];
        while (i + 1 < gradeCopy.size() && scoreSta == gradeCopy[i + 1])
            i++;
        double pos = double(i) / double(n) * 100;
        grade2index.insert(pair<double, double>(scoreSta, pos));
    }

    for (int i = 0; i < student.size(); i++)
        cout << fixed << setprecision(6) << grade2index.at(grade[student[i] - 1]) << endl;

    return 0;
}