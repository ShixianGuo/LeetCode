/*给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/insert-interval
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。*/

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval){
    int i;
    for(i = 0; i < intervals.size(); i++){
        if(intervals[i][0] > newInterval[0])
            break;
    }
    intervals.insert(intervals.begin() + i, newInterval);
    stack<vector<int>> s;
    s.push(intervals[0]);
   
    for(int i = 1; i < intervals.size(); i++){
        vector<int> temp = s.top();
        s.pop();
        if(intervals[i][0] > temp[1]){
            s.push(temp);
            s.push(intervals[i]);
        } 
        else{
            int lower = min(temp[0], intervals[i][0]);
            int upper = max(temp[1], intervals[i][1]);
            s.push({lower, upper});
        }
    }
    vector<vector<int>> res;
    while(!s.empty()){
        res.push_back(s.top());
        s.pop();
    }
    reverse(res.begin(), res.end());
    return res;
}

int main(){
    vector<vector<int>> intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}};
    vector<int>  newInterval = {4, 8};
    vector<vector<int>> res = insert(intervals, newInterval);
    for(auto nums : res){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}