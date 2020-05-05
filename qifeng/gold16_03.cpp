/*
金牌面试宝典16.03题
给定两条线段（表示为起点start = {X1, Y1}和终点end = {X2, Y2}），如果它们有交点，请计算其交点，没有交点则返回空值。

要求浮点型误差不超过10^-6。若有多个交点（线段重叠）则返回 X 值最小的点，X 坐标相同则返回 Y 值最小的点。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/intersection-lcci
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
*/



class Solution {
public:
	double distance(vector<int>& p1, vector<int>& p2) {
		return sqrt((p1[0] - p2[0])*(p1[0] - p2[0]) + (p1[1] - p2[1])*(p1[1] - p2[1]));
	}
	void update(vector<int>& tmp, vector<int> p) {
		//如果x小
		if (p[0] < tmp[0]) {
			tmp[0] = p[0];
			tmp[1] = p[1];
		}
		else if (p[0] == tmp[0]) {
			//x相同取y小
			if (p[1] < tmp[1]) {
				tmp[0] = p[0];
				tmp[1] = p[1];
			}
		}
	}
	vector<double> intersection(vector<int>& start1, vector<int>& end1, vector<int>& start2, vector<int>& end2) {
		vector<double> ans;
		//不平行
		int x1 = start1[0], y1 = start1[1];
		int x2 = end1[0], y2 = end1[1];
		int x3 = start2[0], y3 = start2[1];
		int x4 = end2[0], y4 = end2[1];

		int dx1 = x2 - x1;
		int dx3 = x4 - x3;
		int dy1 = y2 - y1;
		int dy3 = y4 - y3;

		//t1,t2表示交点在线段上距离起点的比例
		int down = dx1 * dy3 - dx3 * dy1;
		double up1 = (y1 - y3)*dx3 + (x3 - x1)*dy3;//t1=up1/down
		double up2 = (y1 - y3)*dx1 + (x3 - x1)*dy1;//t2-up2/down
		double t1, t2;
		//有唯一解或无解
		if (down != 0) {
			t1 = up1 / down;
			t2 = up2 / down;
			if (t1>=0 && t1<=1 & t2 >= 0 & t2 <= 1) {
				ans.push_back(x1 + t1 * dx1);
				ans.push_back(y1 + t1 * dy1);
			}
			//如果t1,t2超出范围，无解
			return ans;
		}
		//down==0
		if (int(up1) != 0 || int(up2) != 0) {
			return ans;//无解
		}
		//up1=up2=down=0有无穷多解
		//从四个端点中选择
		double distance1 = distance(start1, end1);
		double distance2 = distance(start2, end2);
		vector<int> tmp(2, 0x7fffffff);//取最大值
		bool f1 = false, f2 = false, f3 = false, f4 = false;
		if (abs(distance(start1, start2) + distance(start1, end2) - distance2) < 10e-6) {
			//如果该端点在另一直线上，比较大小，如果更小就更新
			update(tmp, start1);
			f1 = true;
		}
		if (abs(distance(end1, start2) + distance(end1, end2) - distance2) < 10e-6) {
			update(tmp, end1);
			f2 = true;
		}
		if (abs(distance(start2, start1) + distance(start2, end1) - distance1) < 10e-6) {
			update(tmp, start2);
			f3 = true;
		}
		if (abs(distance(end2, start1) + distance(end2, end1) - distance1) < 10e-6) {
			update(tmp, end2);
			f4 = true;
		}
		//如果四个都无效，则说明线段没有真正相交
		if (f1 || f2 || f3 || f4) {
			ans.push_back((double)tmp[0]);
			ans.push_back((double)tmp[1]);
			//return ans;
		}
		return ans;
	}
};