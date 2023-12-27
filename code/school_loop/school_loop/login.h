#pragma once
#include<iostream>
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<map>
#include"User.h"
using namespace std;

// ��¼�˺ŵĵ�ַ
const string URL = "data\\У԰����Ȧ�˺���Ϣ.txt";

// �ж��˺��Ƿ��Ѵ���
bool queryMessage(string _id)
{
	string str1;
	ifstream ifs(URL, ios_base::in);

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

// �����˺���Ϣ
void save_id_message(string _id)
{
	ofstream ofs(URL, ios_base::out);
	string new_id = "";
	for (int i = 0; i < _id.size(); i++)
		new_id += _id[(i + 4) % _id.size()];
	ofs << new_id;
}

// ע��
void sign_in()
{
	string _id, _message = "", re_message = "";
	while (1)
	{
		system("cls");
		_message = "";
		re_message = "";
		cout << "��������Ҫע����˺�(ѧ��)��" << endl;
		cin >> _id;
		cout << "����������(��֧����ĸ������)��" << endl;
		while (1)
		{
			char c = _getch();//getch()�������ն˻����ַ�
			if (c == '\r')
			{
				break;
			}
			printf("*");
			_message += c;
		}
		cout << endl;
		cout << "��ȷ������(��֧����ĸ������): " << endl;
		while (1)
		{
			char c = _getch();//getch()�������ն˻����ַ�
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
				cout << "���˺��Ѵ��ڣ���ֱ�ӵ�¼" << endl;
				break;
			}
			cout << "���ѳɹ�ע�ᣬ���¼" << endl;
			Sleep(3000);
			goto out;
		}
		else
		{
			cout << "������������벻һ�£�������ע��" << endl;
			continue;
		}
	}
	out:save_id_message(_id);
}

// ����˺ź������Ƿ�ƥ��
int check(string _id, string _message, map<string, User>mp)
{
	string str1;
	ifstream ifs(URL, ios_base::in);
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


// ����
int check_in(map<string, User>mp)
{
	string _id, _message = "";
	while (1)
	{
		cout << "�����������˺� ��" << endl;
		cin >> _id;
		cout << "�������������� ��" << endl;
		while (1)
		{
			char c = _getch();//getch()�������ն˻����ַ�
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
			cout << "��½�ɹ�" << endl;
			system("pause");
			return 1;
		}
		else if (check(_id, _message, mp) == 1)
		{
			cout << "�����˺������벻ƥ�䣬����������" << endl;
			system("pause");
			continue;
		}
		else
		{
			cout << "���˺Ų����ڣ�����ע��" << endl;
			system("pause");
			return 0;
		}
	}
}


// �޸ĸ�����Ϣ
void retrieve(map<string, User>mp)
{
	while (1)
	{
	restart:
		system("cls");
		int flag = 0;
		string _id, _name, _birthday;
		cout << "�����������˺ţ�" << endl;
		cin >> _id;
		cout << "����������������" << endl;
		cin >> _name;
		cout << "�������������գ�" << endl;
		cin >> _birthday;

		map<string, User>::iterator it;
		for (it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == _id)
			{
				if (it->second.getName() == _name && it->second.getBirthday() == _birthday)
				{
					flag = 1;
					cout << "�������µ����룺 " << endl;
					string new_message;
					cin >> new_message;
					it->second.setMessage(new_message);
					cout << "������³ɹ��������µ�¼" << endl;
					system("pause");
					return;
				}
				else
				{
					cout << "�������������������������������" << endl;
					goto restart;
				}
			}
		}
		if (flag == 0)
		{
			cout << "��������˺����󣬿�������δע�ᡣ" << endl;
			cout << "  1. ��������  " << endl;
			cout << "  2. ���ؽ���ע��  " << endl;
			cout << "����������ѡ�� " << endl;
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


// ��¼ҳ��UI
void login(map<string, User> mp)
{
	while (1)
	{
		system("cls");
		cout << "------------------------" << endl;
		cout << "-      У԰����Ȧ      -" << endl;
		cout << "-       1. ��¼        -" << endl;
		cout << "-       2. ע��        -" << endl;
		cout << "-       3.��������     -" << endl;
		cout << "------------------------" << endl;
		cout << "����������ѡ��" << endl;
		int choice = 0, ans = 10;
		cin >> choice;

		switch (choice)
		{
		case 1:
			ans = check_in(mp);
			break;
		case 2:
			sign_in();
			break;
		case 3:
			retrieve(mp);
			break;
		default:
			cout << "�������" << endl;
			break;
		}
		if (ans == 1)
			break;
		else
			continue;
	}
}