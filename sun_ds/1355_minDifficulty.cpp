// @File   : 1355_minDifficulty.cpp
// @Source : https://leetcode-cn.com/problems/minimum-difficulty-of-a-job-schedule/
// @Title  : 1335. 工作计划的最低难度
// @Auther : sun_ds
// @Date   : 2020/5/20

/**  题目描述：
    你需要制定一份 d 天的工作计划表。工作之间存在依赖，要想执行第 i 项工作，你必须完成全部 j 项工作（ 0 <= j < i）。

    你每天 至少 需要完成一项任务。工作计划的总难度是这 d 天每一天的难度之和，而一天的工作难度是当天应该完成工作的最大难度。

    给你一个整数数组 jobDifficulty 和一个整数 d，分别代表工作难度和需要计划的天数。第 i 项工作的难度是 jobDifficulty[i]。

    返回整个工作计划的 最小难度 。如果无法制定工作计划，则返回 -1 。

     

    示例 1：



    输入：jobDifficulty = [6,5,4,3,2,1], d = 2
    输出：7
    解释：第一天，您可以完成前 5 项工作，总难度 = 6.
    第二天，您可以完成最后一项工作，总难度 = 1.
    计划表的难度 = 6 + 1 = 7
    示例 2：

    输入：jobDifficulty = [9,9,9], d = 4
    输出：-1
    解释：就算你每天完成一项工作，仍然有一天是空闲的，你无法制定一份能够满足既定工作时间的计划表。
    示例 3：

    输入：jobDifficulty = [1,1,1], d = 3
    输出：3
    解释：工作计划为每天一项工作，总难度为 3 。
    示例 4：

    输入：jobDifficulty = [7,1,7,1,7,1], d = 3
    输出：15
    示例 5：

    输入：jobDifficulty = [11,111,22,222,33,333,44,444], d = 6
    输出：843
     

    提示：

    1 <= jobDifficulty.length <= 300
    0 <= jobDifficulty[i] <= 1000
    1 <= d <= 10


    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/minimum-difficulty-of-a-job-schedule
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 1.dp
 * dp[i][j]表示在 i 天内完成 j 项工作的最小难度。
 * 由于每天的难度是当前内难度的最大值。所以，首先使用max_job统计每个区间内的最大值。
 *
 * 转移方程：
 * 下降规模。
 *  即在 i 天内完成 j 项任务的最小难度 = 前 i-1 天完成 k 项任务的难度 + (k+1 到 j 项)任务组成一天的难度.
 *  其中 k  = [0,j).
 *  不知道选哪个 k，所以遍历所有的 k。
 *  dp[i][j] = min(dp[i][j],dp[i-1][k] + max_job[k+1][j]);
 *  max_job[k+1][j]为区间 k+1 - j 直接的最大值，即将他们组成一天后的难度。
 *
 *  特殊情况，当 i=0，即天数只有一天时，j 项任务的难度就是max_job[0][j]
 *
 *  最终得到结果 dp[d-1][num-1]
 *
 *
 *
 */

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int num = jobDifficulty.size();
        if(d>num) return -1;
        vector<vector<int>> dp(d,vector<int>(num,INT_MAX/2));
        vector<vector<int>> max_job(num,vector<int>(num,0));
        for(int i=0;i<num;i++){
            for(int j=i;j<num;j++){
                if(j==i) max_job[i][j] = jobDifficulty[i];
                else max_job[i][j] = max(max_job[i][j-1],jobDifficulty[j]);
            }
        }
        for(int i=0;i<d;i++){
            for(int j=0;j<num;j++){
                if(i==0) dp[i][j] = max_job[i][j];
                else{
                    for(int k=0;k<j;k++){
                        dp[i][j] = min(dp[i][j],dp[i-1][k] + max_job[k+1][j]);
                    }
                }
            }
        }
        return dp[d-1][num-1];
    }
};


