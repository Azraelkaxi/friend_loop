#pragma once
#include<iostream>
#include<fstream>
using namespace std;

void Post_on_moments(map<string, User> mp, string my_id)
{
	system("cls");
	cout << "请输入您要发布的朋友圈内容：" << endl;
	string _text;
	cin >> _text;
	//写入操作，待定  时间自动获取  点赞默认为0
	string title = my_id + ".txt";
	ofstream ofs(title, ios::app);
	ofs << "0" << endl;
	ofs << _text << endl;
	ofs << "1" << endl;

	ofs.close();
	cout << "发布成功" << endl;
	system("pause");
}