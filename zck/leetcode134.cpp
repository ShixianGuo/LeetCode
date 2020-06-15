#include <iostream>
#include <vector>
/*
*
输入: 
gas  = [1,2,3,4,5]
cost = [3,4,5,1,2]
*
*/ 

using namespace std;

int canCompleteCircuit(vector<int>& gas, vector<int>& cost){
    int n = gas.size();
    int total_tank = 0;
    int cur_tank = 0;
    int start_station = 0;
    for(int i = 0; i < n; i++){
        total_tank += gas[i] - cost[i]; 
        cur_tank += gas[i] - cost[i];
        if(cur_tank < 0){
            start_station = i + 1;
            cur_tank = 0;
        }
    }
    return total_tank >= 0? start_station : -1;
}
