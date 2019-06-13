//
// Created by llkser on 2019/6/12.
//
#include <iostream>
#include <vector>
using namespace std;
#include "caseChange.h"
//
vector<vector<int>> caseChange(vector<vector<int>>& cellCase)
{
    vector<vector<int>> next_cellCase;
    int num;
    vector<int> rowNum;
    for(int i=0;i<cellCase.size();i++)
    {
        rowNum.clear();
        for(int j=0;j<cellCase[i].size();j++)
        {
            num=countNum(cellCase,i,j);
            if(cellCase[i][j])
            {
                if(num>3||num<2)
                    rowNum.push_back(0);
                else
                    rowNum.push_back(1);
            }
            else{
                if(num==3)
                    rowNum.push_back(1);
                else
                    rowNum.push_back(0);
            }
        }
        next_cellCase.push_back(rowNum);
    }
    return next_cellCase;
}
//Count
int countNum(vector<vector<int>>& cellCase,int i,int j)
{
    int result=0;
    if(cellCase.size()==1)
    {
        if(j==0)
            result+=cellCase[0][j+1];
        else if(j==cellCase[0].size()-1)
            result+=cellCase[0][j-1];
        else
            result+=cellCase[0][j-1]+cellCase[0][j+1];
    }
    else if(cellCase[0].size()==1)
    {
        if(i==0)
            result+=cellCase[i+1][0];
        else if(i==cellCase.size()-1)
            result+=cellCase[i-1][0];
        else
            result+=cellCase[i+1][0]+cellCase[i-1][0];
    }
    else{
        if(i==0)
        {
            if(j==0)
                result+=cellCase[i][j+1]+cellCase[i+1][j]+cellCase[i+1][j+1];
            else if(j==cellCase[i].size()-1)
                result+=cellCase[i][j-1]+cellCase[i+1][j]+cellCase[i+1][j-1];
            else
                result+=cellCase[i][j+1]+cellCase[i+1][j]+cellCase[i+1][j+1]+cellCase[i][j-1]+cellCase[i+1][j-1];
        }
        else if(i==cellCase.size()-1)
        {
            if(j==0)
                result+=cellCase[i][j+1]+cellCase[i-1][j]+cellCase[i-1][j+1];
            else if(j==cellCase[i].size()-1)
                result+=cellCase[i][j-1]+cellCase[i-1][j]+cellCase[i-1][j-1];
            else
                result+=cellCase[i][j+1]+cellCase[i-1][j]+cellCase[i-1][j+1]+cellCase[i][j-1]+cellCase[i-1][j-1];
        }
        else if(j==0)
        {
            if(i==0)
                result+=cellCase[i][j+1]+cellCase[i+1][j]+cellCase[i+1][j+1];
            else if(i==cellCase.size()-1)
                result+=cellCase[i][j+1]+cellCase[i-1][j]+cellCase[i-1][j+1];
            else
                result+=cellCase[i][j+1]+cellCase[i-1][j]+cellCase[i-1][j+1]+cellCase[i+1][j]+cellCase[i+1][j+1];
        }
        else if(j==cellCase[i].size()-1)
        {
            if(i==0)
                result+=cellCase[i][j-1]+cellCase[i+1][j]+cellCase[i+1][j-1];
            else if(i==cellCase.size()-1)
                result+=cellCase[i][j-1]+cellCase[i-1][j]+cellCase[i-1][j-1];
            else
                result+=cellCase[i][j-1]+cellCase[i-1][j]+cellCase[i-1][j-1]+cellCase[i+1][j]+cellCase[i+1][j-1];
        }
        else
            result+=cellCase[i][j+1]+cellCase[i-1][j]+cellCase[i-1][j+1]+cellCase[i][j-1]+cellCase[i-1][j-1]+cellCase[i+1][j]+cellCase[i+1][j+1]+cellCase[i+1][j-1];
    }
    return result;
}
//
string to_str(vector<vector<int>>& cellCase,char ch)
{
    string str;
    for(int i=0;i<cellCase.size();i++)
    {
        for(int j=0;j<cellCase[0].size();j++)
        {
            if(cellCase[i][j])
                str.push_back('*');
            else
                str.push_back(ch);
        }
        str.push_back('\n');
    }
    return str;
}
