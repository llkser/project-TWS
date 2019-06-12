//
// Created by llkser on 2019/6/12.
//
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
#include "sizeFix.h"
#include "caseChange.h"
int main(int argc, char **argv)
{
    vector<int> nums1={0,1,1,0,0};
    vector<int> nums2={1,1,1,1,0};
    vector<int> nums3={1,1,0,1,1};
    vector<int> nums4={0,0,1,1,0};
    vector<vector<int>> test;
    test.push_back(nums1);
    test.push_back(nums2);
    test.push_back(nums3);
    test.push_back(nums4);
    vector<vector<int>> result(sizeFix(test,5,4));
    while(true)
    {
        for(int i=0;i<result.size();i++)
        {
            for(int j=0;j<result[0].size();j++)
            {
                if(result[i][j])
                    cout<<"*";
                else
                    cout<<"_";
            }
            cout<<endl;
        }
        result=caseChange(result);
        Sleep(500);
        system("cls");
    }

    return 0;
}
