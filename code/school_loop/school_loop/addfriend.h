#pragma once
#include<iostream>
#include<windows.h>
using namespace std;

//ˢ�º����б�
void refresh_friend_list(string my_id, string _id)
{

}

string Add_friend(map<string, User>mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "������ѧ��" << endl;
		string _id;
		cin >> _id;
		//todo:�����Ƿ��Ѿ��ӹ���������Ϣ���û�
		//�����Ǽ����Ѿ����ǹ�
		for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == _id)
			{
				cout << "�Ѿ��ҵ�����" << endl;
				Sleep(1000);
				//ˢ�º����б�
				refresh_friend_list(my_id, _id);
				return it->second.getName();
			}
		}
		return "NotFound";
	}
}