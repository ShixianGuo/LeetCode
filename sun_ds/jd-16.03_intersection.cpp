// @File   : jd-16.03_intersection.cpp
// @Source : https://leetcode-cn.com/problems/intersection-lcci/
// @Title  : 面试题 16.03. 交点
// @Auther : sun_ds
// @Date   : 2020/5/2

/**  题目描述：
    给定两条线段（表示为起点start = {X1, Y1}和终点end = {X2, Y2}），如果它们有交点，请计算其交点，没有交点则返回空值。

    要求浮点型误差不超过10^-6。若有多个交点（线段重叠）则返回 X 值最小的点，X 坐标相同则返回 Y 值最小的点。

     

    示例 1：

    输入：
    line1 = {0, 0}, {1, 0}
    line2 = {1, 1}, {0, -1}
    输出： {0.5, 0}
    示例 2：

    输入：
    line1 = {0, 0}, {3, 3}
    line2 = {1, 1}, {2, 2}
    输出： {1, 1}
    示例 3：

    输入：
    line1 = {0, 0}, {1, 1}
    line2 = {1, 0}, {2, 1}
    输出： {}，两条线段没有交点
     

    提示：

    坐标绝对值不会超过 2^7
    输入的坐标均是有效的二维坐标

    来源：力扣（LeetCode）
    链接：https://leetcode-cn.com/problems/intersection-lcci
    著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/

/**
 *
 * 数学劝退。。
 *
 * https://leetcode-cn.com/problems/intersection-lcci/solution/c-yi-ban-shi-qiu-jiao-dian-by-time-limit/
 *
 * 判断两条直线是否平行，斜率是否相等
 * 1.平行 两条线重合或没有交点
 *   不重合，没有交点返回空。
 *   重合，返回重合点中x坐标最小的值。那么返回值必定在两条线段的四个端点处取得。
 *   分别判断当前端点是否在另一个线段之间。
 *   最终按x坐标排序返回结果。
 *
 * 2.不平行 肯定有交点
 *   判断交点是否在同时在两条线段之间，如果是返回结果，否则返回空。
 *
 * 判断两条线是否平行：
 *   斜率k1 = dy1/dx1; 斜率k2 = dy2/dx2;
 *   平行时，k1==k2.
 *   防止斜率不存在情况。转换成乘法
 *   判断dx1*dy2 == dx2*dy1是否满足
 *
 * 判断点是否在另一个线段之间：
 *   求当前点到线段两端点的线段和，如果线段和与线段长度相等，那么三个点共线且当前点在线段之间。
 *
 * 由线段上两个点求直线一般式方程参数：
 *   直线一般式方程 Ax + By + C = 0;
 *   直线上两个点P1(x1,y1),P2(x2,y2)
 *   则有，A = y2 - y1; B = x1 - x2; C = x2*y1 - x1*y2;
 *
 * 不平行的两条线使用一般式方程参数求交点：
 *   设交点为(x,y)
 *   两条线段的一般式满足：
 *   A1*x + B1*y + C1 = 0;-----------(1)
 *   A2*x + B2*y + C2 = 0;-----------(2)
 *   对(1)式乘A2，对(2)式乘A1,得：
 *   A2*A1*x + A2*B1*y + A2*C1 = 0;
 *   A1*A2*x + A1*B2*y + A1*C2 = 0;
 *   两式相减得：
 *   y = (A2*C1 - A1*C2)/(A1*B2 - A2*B1);
 *   同理可得：
 *   x = (B1*C2 - B2*C1)/(A1*B2 - A2*B1);
 *
 *
 */


class Solution {
public:
    const double EPS = 1e-7;
    template<typename T1, typename T2, typename T3>
    bool isPointInLine(const T1 &p, const T2 &s, const T3 &e) {
        // p点坐标 s和e为线段起点和终点
        // 判断 dist(s,p) + dist(p,e) == dist(s,e) 是否满足。若点p在线段s-e上，则符合条件
        double d1 = sqrt((p[0] - s[0])*(p[0] - s[0]) + (p[1] - s[1])*(p[1] - s[1]));
        double d2 = sqrt((p[0] - e[0])*(p[0] - e[0]) + (p[1] - e[1])*(p[1] - e[1]));
        double d3 = sqrt((s[0] - e[0])*(s[0] - e[0]) + (s[1] - e[1])*(s[1] - e[1]));
        if(fabs(d1 + d2 - d3) <= EPS) {
            return true;
        }
        return false;
    }
    vector<double> getIntersectionOfParallelLine(vector<int> &s1, vector<int> &e1, vector<int> &s2, vector<int> &e2) {
        vector<vector<double>> res;
        //分别判断四个端点是否在另一个线段之间
        if(isPointInLine(s1, s2, e2)) {
            res.push_back(vector<double>{double(s1[0]), double(s1[1])});
        }
        if(isPointInLine(e1, s2, e2)) {
            res.push_back(vector<double>{double(e1[0]), double(e1[1])});
        }
        if(isPointInLine(s2, s1, e1)) {
            res.push_back(vector<double>{double(s2[0]), double(s2[1])});
        }
        if(isPointInLine(e2, s1, e1)) {
            res.push_back(vector<double>{double(e2[0]), double(e2[1])});
        }
        if(res.size() == 0) {
            return vector<double>{};
        }
        //若有多个交点（线段重叠）则返回 X 值最小的点，X 坐标相同则返回 Y 值最小的点
        sort(res.begin(), res.end(), [](const vector<double> &l, const vector<double> &r)->bool {
            return l[0] < r[0];
        });
        return res[0];
    }
    vector<double> getParam(const vector<int> &point1, const vector<int> &point2) {
        //A = y2-y1, B = x1-x2, C = x2y1-x1y2
        double a = point2[1] - point1[1];
        double b = point1[0] - point2[0];
        double c = point2[0]*point1[1] - point1[0]*point2[1];
        return vector<double>{a, b, c};
    }
    vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
        int dx1 = end1[0] - start1[0];
        int dy1 = end1[1] - start1[1];

        int dx2 = end2[0] - start2[0];
        int dy2 = end2[1] - start2[1];

        //斜率k1 = dy1/dx1;
        //斜率k2 = dy2/dx2;
        //平行时，k1==k2.
        //防止斜率不存在情况。转换成乘法，判断dx1*dy2 == dx2*dy1是否满足
        if(dx1*dy2 == dx2*dy1) {    //平行
            return getIntersectionOfParallelLine(start1, end1, start2, end2);
        }

        //获得直线方程一般式三个参数 A,B,C
        vector<double> p1 = getParam(start1, end1);
        vector<double> p2 = getParam(start2, end2);

        //根据方程一般式参数A,B,C，求交点
        double x = double(p2[2]*p1[1] - p1[2]*p2[1]) / double(p1[0]*p2[1] - p2[0]*p1[1]);
        double y = double(p1[2]*p2[0] - p2[2]*p1[0]) / double(p1[0]*p2[1] - p2[0]*p1[1]);

        //交点即在线段1上又在线段2上
        vector<double> point{x, y};
        if(isPointInLine(point, start1, end1) && isPointInLine(point, start2, end2)) {
            return point;
        }
        return vector<double> {};
    }
};
