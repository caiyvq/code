//样例
/*
K.Weng  5       5       5
T.Dixon 4       3       2
V.Chu   3       4       5
L.Tson  4       3       4
L.Lee   3       4       3
I.Young 4       2       5
K.Hiro  4       2       1
G.Ping  4       4       4
H.Gu    2       3       4
J.Jon   5       4       3
*/
#include<iostream>
using namespace std;

//定义 students类
static class  student
{
public:
	string name;
	float score1, score2, score3;
};
int main()
{
	//定义处理后分数数组
	float sum_stu[11] = { 0 }, sum_sco[4] = { 0 }, min[4] = { 100,100,100,100 }, max[4] = { 0 };
	//定义学生类数组
	student students[11];
	for (int i = 1; i <= 10; i++)
	{
		//输入
		cin >> students[i].name>>students[i].score1>> students[i].score2>> students[i].score3;
		//求每个学生分数和
		sum_stu[i] = students[i].score1 + students[i].score2 + students[i].score3;
		//求每个科目分数和
		sum_sco[1] += students[i].score1;
		sum_sco[2] += students[i].score2;
		sum_sco[3] += students[i].score3;
		//求最小分数
		if (min[1] > students[i].score1)
			min[1] = students[i].score1;
		if (min[2] > students[i].score2)
			min[2] = students[i].score2;
		if (min[3] > students[i].score3)
			min[3] = students[i].score3;
		//求最大分数
		if (max[1] < students[i].score1)
			max[1] = students[i].score1;
		if (max[2] < students[i].score2)
			max[2] = students[i].score2;
		if (max[3] < students[i].score3)
			max[3] = students[i].score3;
	}
	//定义平均分数组
	float ave_stu[11] = { 0 }, ave_sco[4] = { 0 };
	//计算每个学生平均分
	for (int i = 1; i <= 10; i++)
	{
		ave_stu[i] = sum_stu[i] / 3;;
	}
	//计算每个科目平均分
	for (int i = 1; i <= 3; i++)
	{
		ave_sco[i] = sum_sco[i] / 10;
	}
	//输出表头
	cout << "no\tname\tscore1\tscore2\tscore3\taverage" << endl;
	//输出数据
	for (int i = 1; i <= 10; i++)
	{
		cout << i << "\t" << students[i].name << "\t" << students[i].score1 << "\t" << students[i].score2 << "\t" << students[i].score3 << "\t" << ave_stu[i] << endl;
	}
	//输出数据
	cout << "\t" << "average\t" << ave_sco[1] << "\t" << ave_sco[2] << "\t" << ave_sco[3] << endl;
	cout << "\tmin\t" << min[1] << "\t" << min[2] << "\t" << min[3] << endl;
	cout << "\tmax\t" << max[1] << "\t" << max[2] << "\t" << max[3] << endl;
	return 0;
}