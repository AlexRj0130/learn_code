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
    vector<int> printMatrix(vector<vector<int> > matrix) {
        vector<int> result;
        printMatrixHelp(matrix, result);
        return result; 
    }

private:
    void printMatrixHelp(vector<vector<int> > matrix, vector<int> & result)
    {
        int rowNum = matrix.size();
        if (rowNum == 0)
            return;
        int colNum = matrix[0].size();
        if (colNum == 0)
            return;

        if (1 == rowNum)
        {
            for (int i = 0; i < colNum; i++)
                result.push_back(matrix[0][i]);
            return;
        }
        if (1 == colNum)
        {
            for (int i = 0; i < rowNum; i++)
                result.push_back(matrix[i][0]);
            return;
        }

        int i = 0;
        int j = 0;
        for (; j < colNum - 1; j++)
            result.push_back(matrix[i][j]);

        for (; i < rowNum - 1; i++)
            result.push_back(matrix[i][j]);

        for (; j > 0; j--)
            result.push_back(matrix[i][j]);

        for(; i > 0; i--)
            result.push_back(matrix[i][j]);

        if (rowNum <= 2 || colNum <= 2)
            return; 

        vector<vector<int> > tmpMat;
        for (int i = 1; i < rowNum - 1; i++)
        {
            vector<int> tmpRow;
            for (j = 1; j < colNum - 1; j++)
            {
                tmpRow.push_back(matrix[i][j]); 
            }
            tmpMat.push_back(tmpRow);
        }

        printMatrixHelp(tmpMat, result);
    }
};

int main()
{
    return 0;
}