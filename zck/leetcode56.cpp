#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/*输入: [[1,3],[2,6],[8,10],[15,18]]
输出: [[1,6],[8,10],[15,18]]
解释: 区间 [1,3] 和 [2,6] 重叠, 将它们合并为 [1,6].
*/

vector<vector<int>> merge(vector<vector<int>>& intervals){
    if(intervals.size() == 0)
        return intervals;
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> res;
    res.push_back(intervals[0]);
    for(int i = 1; i < intervals.size(); i++){
        vector<int> temp = intervals[i];
        vector<int> last = res.back();
        res.pop_back();
        if(temp[0] > last[1]){
            res.push_back(last);
            res.push_back(temp);
        }
        else{
            int lower = min(temp[0], last[0]);
            int upper = max(temp[1], last[1]);
            vector<int> t = {lower, upper};
            res.push_back(t);
        }
    }
    return res;
}


int main(){
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    vector<vector<int>> res = merge(intervals);
    for(auto nums : res){
        for(auto num : nums){
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;

}