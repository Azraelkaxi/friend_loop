#pragma once
#include<iostream>
#include<windows.h>
using namespace std;

//刷新好友列表
void refresh_friend_list(string my_id, string _id)
{

}

string Add_friend(map<string, User>mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "请输入学号" << endl;
		string _id;
		cin >> _id;
		//todo:考虑是否已经加过并反馈信息给用户
		//以下是假设已经考虑过
		for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == _id)
			{
				cout << "已经找到该人" << endl;
				Sleep(1000);
				//刷新好友列表
				refresh_friend_list(my_id, _id);
				return it->second.getName();
			}
		}
		return "NotFound";
	}
}