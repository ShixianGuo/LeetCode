/*给定一个已按照升序排列 的有序数组，找到两个数使得它们相加之和等于目标数。

函数应该返回这两个下标值 index1 和 index2，其中 index1 必须小于 index2。
*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> twoSum(vector<int>& numbers, int target){
    int n = numbers.size();
    int head = 0;
    int tail = n - 1;
    while(head < tail){
        int temp = numbers[head] + numbers[tail];
        if(temp < target)
            head++;
        else if(temp > target){
            tail--;
        }
        else{
            vector<int> temp(2);
            temp.push_back(head);
            temp.push_back(tail);
            return temp;
        }
        
    }
    return {-1, -1};
}

int main(){
    
}

