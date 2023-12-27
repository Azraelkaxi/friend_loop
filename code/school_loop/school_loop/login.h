#pragma once
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<map>
#include"User.h"
using namespace std;

string _id_;
bool queryMessage(string _id)
{
	string str1;
	ifstream ifs("校园朋友圈账号信息.txt", ios_base::in);

	while (ifs >> str1)
	{
		string str2 = "";
		for (int i = 0; i < str1.size(); i++)
			str2 += str1[(i + str1.size() - 4) % str1.size()];
		if (str2 == _id)
		{
			ifs.close();
			return true;
		}
	}
	ifs.close();
	return false;
}

void save_id_message(string _id)
{
	ofstream ofs("校园朋友圈账号信息.txt", ios_base::out);
	string new_id = "";
	for (int i = 0; i < _id.size(); i++)
		new_id += _id[(i + 4) % _id.size()];
	ofs << new_id;
}

void sign_in()
{
	string _id, _message = "", re_message = "";
	while (1)
	{
		system("cls");
		_message = "";
		re_message = "";
		cout << "请输入您要注册的账号(学号)：" << endl;
		cin >> _id;
		cout << "请输入密码(仅支持字母和数字)：" << endl;
		while (1)
		{
			char c = _getch();//getch()不会向终端回显字符
			if (c == '\r')
			{
				break;
			}
			printf("*");
			_message += c;
		}
		cout << endl;
		cout << "请确认密码(仅支持字母和数字): " << endl;
		while (1)
		{
			char c = _getch();//getch()不会向终端回显字符
			if (c == '\r')
			{
				break;
			}
			printf("*");
			re_message += c;
		}
		cout << endl;
		if (re_message == _message)
		{
			if (queryMessage(_id))
			{
				cout << "该账号已存在，请直接登录" << endl;
				break;
			}
			cout << "您已成功注册，请登录" << endl;
			Sleep(3000);
			goto out;
		}
		else
		{
			cout << "两次输入的密码不一致，请重新注册" << endl;
			continue;
		}
	}
	out:save_id_message(_id);
}

int check(string _id, string _message, map<string, User>mp)
{
	string str1;
	ifstream ifs("校园朋友圈账号信息.txt", ios_base::in);
	while (ifs >> str1)
	{
		string str2 = "";
		for (int i = 0; i < str1.size(); i++)
			str2 += str1[(i + str1.size() - 4) % str1.size()];
		if (str2 == _id)
		{
			map<string, User>::iterator it;
			for (it = mp.begin(); it != mp.end(); ++it)
			{
				if (it->first == _id)
				{
					if (it->second.getMessage() == _message)
					{
						ifs.close();
						return 0;
					}
					else
					{
						ifs.close();
						return 1;
					}
				}
			}
		}
	}
	ifs.close();
	return 2;
}



int check_in(map<string, User>mp)
{
	string _id, _message = "";
	while (1)
	{
		cout << "请输入您的账号 ：" << endl;
		cin >> _id;
		cout << "请输入您的密码 ：" << endl;
		while (1)
		{
			char c = _getch();//getch()不会向终端回显字符
			if (c == '\r')
			{
				break;
			}
			printf("*");
			_message = c;
		}
		cout << endl;
		if (check(_id, _message, mp) == 0)
		{
			_id_ = _id;
			cout << "登陆成功" << endl;
			system("pause");
			return 1;
		}
		else if (check(_id, _message, mp) == 1)
		{
			cout << "您的账号与密码不匹配，请重新输入" << endl;
			system("pause");
			continue;
		}
		else
		{
			cout << "该账号不存在，请先注册" << endl;
			system("pause");
			return 0;
		}
	}
}



void retrieve(map<string, User>mp)
{
	while (1)
	{
	restart:
		system("cls");
		int flag = 0;
		string _id, _name, _birthday;
		cout << "请输入您的账号：" << endl;
		cin >> _id;
		cout << "请输入您的网名：" << endl;
		cin >> _name;
		cout << "请输入您的生日：" << endl;
		cin >> _birthday;

		map<string, User>::iterator it;
		for (it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == _id)
			{
				if (it->second.getName() == _name && it->second.getBirthday() == _birthday)
				{
					flag = 1;
					cout << "请输入新的密码： " << endl;
					string new_message;
					cin >> new_message;
					it->second.setMessage(new_message);
					cout << "密码更新成功，请重新登录" << endl;
					system("pause");
					return;
				}
				else
				{
					cout << "您输入的网名或生日有误，请重新输入" << endl;
					goto restart;
				}
			}
		}
		if (flag == 0)
		{
			cout << "您输入的账号有误，可能您还未注册。" << endl;
			cout << "  1. 重新输入  " << endl;
			cout << "  2. 返回进行注册  " << endl;
			cout << "请输入您的选择： " << endl;
			int choice;
			cin >> choice;

			switch (choice)
			{
				case 1:
					goto restart;
					break;
				case 2:
					return;
			}
		}
	}
}


string login(map<string, User> mp)
{
	while (1)
	{
		system("cls");
		cout << "------------------------" << endl;
		cout << "-      校园朋友圈      -" << endl;
		cout << "-       1. 登录        -" << endl;
		cout << "-       2. 注册        -" << endl;
		cout << "-       3.忘记密码     -" << endl;
		cout << "------------------------" << endl;
		cout << "请输入您的选择：" << endl;
		int choice = 0, ans = 10;
		cin >> choice;

		switch (choice)
		{
		case 1:
			ans = check_in(mp);
			return _id_;
		case 2:
			sign_in();
			break;
		case 3:
			retrieve(mp);
			break;
		default:
			cout << "输入错误" << endl;
			break;
		}
		if (ans == 1)
			break;
		else
			continue;
	}
}