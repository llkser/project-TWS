//
// Created by llkser on 2019/6/13.
//
#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;
#include "caseChange.h"
#include "sizeFix.h"
#include "gamePlay.h"

int main(int argc, char **argv)
{
    cout<<"**********************************************************"<<endl;
    cout<<"                     Game of Life          "<<endl;
    cout<<"                                 By Luke&Jack         "<<endl;
    cout<<"**********************************************************"<<endl;
    cout<<"Welcome!"<<endl<<endl;
    string str;
    int flag=0;
    int m,n,delay_t,loop_t;
    vector<vector<int>> beginningCase;
    while(true)
    {
        cout<<"1. Input new datafile."<<endl;
        cout<<"2. Select template datafile."<<endl;
        cout<<" 'q' to quit."<<endl<<endl;
        if(cin>>flag)
        {
            switch(flag){
            case 1:
                cout<<"Please input a date file:"<<endl;
                cin>>str;
                beginningCase=readfile(str);
                cout<<"Please input the size for painting(m*n):"<<endl;
                cin>>m>>n;
                beginningCase=sizeFix(beginningCase,n,m);
                cout<<"Please input the delay time between every two images:"<<endl;
                cin>>delay_t;
                cout<<"Please input the loop time between every two images:"<<endl;
                cin>>loop_t;
                gamePlay(beginningCase,delay_t,loop_t);
                break;
            case 2:
                cout<<"Available template files:"<<endl;
                cout<<"Template file1:"<<endl;
                beginningCase=readfile("cellstate1.txt");
                cout<<to_str(beginningCase,'_');
                cout<<"Template file2:"<<endl;
                beginningCase=readfile("cellstate2.txt");
                cout<<to_str(beginningCase,'_');
                cout<<"Template file3:"<<endl;
                beginningCase=readfile("cellstate3.txt");
                cout<<to_str(beginningCase,'_');
                cout<<"Please choose a template file:"<<endl;
                cin>>flag;
                switch(flag){
                case 1:
                    beginningCase=readfile("cellstate1.txt");
                    beginningCase=sizeFix(beginningCase);
                    gamePlay(beginningCase,200,100);
                    break;
                case 2:
                    beginningCase=readfile("cellstate2.txt");
                    beginningCase=sizeFix(beginningCase);
                    gamePlay(beginningCase,200,100);
                    break;
                case 3:
                    beginningCase=readfile("cellstate3.txt");
                    beginningCase=sizeFix(beginningCase);
                    gamePlay(beginningCase,200,100);
                    break;
                }
                break;
            }
        }
        else
            break;
        cout<<endl;
    }

    return 0;
}
