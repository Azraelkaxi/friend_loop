#pragma once
#include<iostream>
#include<fstream>
using namespace std;

void Post_on_moments(map<string, User> mp, string my_id)
{
	system("cls");
	cout << "��������Ҫ����������Ȧ���ݣ�" << endl;
	string _text;
	cin >> _text;
	//д�����������  ʱ���Զ���ȡ  ����Ĭ��Ϊ0
	string title = my_id + ".txt";
	ofstream ofs(title, ios::app);
	ofs << "0" << endl;
	ofs << _text << endl;
	ofs << "1" << endl;

	ofs.close();
	cout << "�����ɹ�" << endl;
	system("pause");
}