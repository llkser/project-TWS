//
// Created by llkser on 2019/6/12.
//
#include <iostream>
#include <vector>
using namespace std;
#include "caseChange.h"
int main(int argc, char **argv)
{
    vector<int> nums1={1,1,1};
    vector<int> nums2={1,1,1};
    vector<int> nums3={1,1,1};
    vector<vector<int>> test;
    test.push_back(nums1);
    test.push_back(nums2);
    test.push_back(nums3);
    vector<vector<int>> result(caseChange(test));
    for(int i=0;i<result.size();i++)
    {
        for(int j=0;j<result[i].size();j++)
            cout<<result[i][j]<<" ";
        cout<<endl;
    }

    return 0;
}
