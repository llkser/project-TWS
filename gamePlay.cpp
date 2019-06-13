//
// Created by llkser on 2019/6/13.
//
#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
using namespace std;
#include "caseChange.h"
#include "sizeFix.h"
#include "gamePlay.h"
//
void gamePlay(vector<vector<int>>& beginningCase,int delay_t,int loop_t)
{
    vector<vector<int>> nextCase;
    for(int k=0;k<loop_t;k++)
    {
        cout<<to_str(beginningCase);
        cout<<k+1<<" "<<"Current alive cells: "<<countCell(beginningCase)<<endl;
        nextCase=caseChange(beginningCase);
        if(caseCheck(beginningCase,nextCase))
        {
            cout<<"Case ends at loop time "<<k+1<<"!"<<endl;
            break;
        }
        beginningCase=nextCase;
        Sleep(delay_t);
        if(k==loop_t-1)
        {
            cout<<"Case ends!"<<endl;
            break;
        }
        system("cls");
    }
}
//
bool caseCheck(vector<vector<int>>& cellCase1,vector<vector<int>>& cellCase2)
{
    bool bo=true;
    for(int i=0;i<cellCase1.size();i++)
        for(int j=0;j<cellCase1[0].size();j++)
            if(cellCase1[i][j]!=cellCase2[i][j])
            {
                bo=false;
                break;
            }
    return bo;
}
//
int countCell(vector<vector<int>>& cellCase)
{
    int num=0;
    for(int i=0;i<cellCase.size();i++)
        for(int j=0;j<cellCase[0].size();j++)
            if(cellCase[i][j])
                num++;
    return num;
}
//
vector<vector<int>> readfile(string filename)
{
	vector<int> temp_line;
	vector<vector<int>> Vec_Dti;
	string line;
	ifstream in(filename);

	while (getline(in, line))
	{
		for (int i = 0; i < line.length(); ++i)
		{
			temp_line.push_back(line[i]-'0');
		}
		Vec_Dti.push_back(temp_line);
		temp_line.clear();
	}
	return Vec_Dti;
}
