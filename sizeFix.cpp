//
// Created by llkser on 2019/6/12.
//

#include <iostream>
#include <vector>
using namespace std;

#include "sizeFix.h"

vector<vector<int>> sizeFix(vector<vector<int>>& userCase,int width,int high)
{
    vector<vector<int>> cellCase;
    vector<int> rowNum;
    int m,n;
    for(int i=0;i<width;i++)
        rowNum.push_back(0);
    for(int i=0;i<high;i++)
        cellCase.push_back(rowNum);
    m=(width-userCase[0].size())/2;
    n=(high-userCase.size())/2;
    for(int i=0;i<userCase.size();i++)
        for(int j=0;j<userCase[0].size();j++)
            cellCase[i+n][j+m]=userCase[i][j];
    return cellCase;
}
