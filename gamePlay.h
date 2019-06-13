//
// Created by llkser on 2019/6/13.
//

#ifndef PROJECT_TWS_GAMEPLAY_H
#define PROJECT_TWS_GAMEPLAY_H

void gamePlay(vector<vector<int>>& beginningCase,int delay_t,int loop_t);
bool caseCheck(vector<vector<int>>& cellCase1,vector<vector<int>>& cellCase2);
int countCell(vector<vector<int>>& cellCase);
vector<vector<int>> readfile(string filename);

#endif //PROJECT_TWS_GAMEPLAY_H
