#define _CRT_SECURE_NO_WARNINGS 
#include"User.h"
#include"login.h"
#include"tools.h"
#include<map>

void Init(map<string, User>& mp)
{
	string URL = "data\\У԰����Ȧ�˺���Ϣ.txt";
	string line;
	ifstream ifs(URL, ios_base::in);
	while (getline(ifs, line))
	{
		if (line.empty())
		{
			ifs.close();
			break;
		}
		else
		{
			string File_name = line;
			ifstream is(File_name, ios_base::in);
			if (!is.is_open())
			{
				cout << "�ļ���ʧ��" << endl;
			}
			else
			{
				//��ȡ������Ϣ
				string _id, _message, _name, _birthday, line1, line2, line3;
				//��ȡ�����б�
				list<string> _Friend;
				is >> _id >> _message >> _name >> _birthday >> line1 >> line2 >> line3;
				string line4;
				while (getline(is, line4))
				{
					if (line4.empty())
						break;
					else
					{
						_Friend.push_back(line4);
					}
				}
				//��ȡ����Ȧ
				string _text, _date;
				int _likes;
				while (getline(is, line4))
				{
					if (line4.empty())
						break;
					else if (line4 == "#" || line4 == "*")
						continue;
					else
					{

					}
				}
			}
		}
	}
}

int main()
{
	map<string, User> mp;

	Init(mp);

	string my_id;

	my_id = login(mp);

	system("cls");
	while (1)
	{
		cout << "-------------------------" << endl;
		cout << "    ��ӭ����У԰����Ȧ   " << endl;
		cout << "       1. ������Ȧ       " << endl;
		cout << "       2. ������Ȧ       " << endl;
		cout << "       3. �Ӻ���         " << endl;
		cout << "       4. �޸�������Ϣ   " << endl;
		cout << "       5. �˳�           " << endl;
		cout << "-------------------------" << endl;
		cout << "����������ѡ��" << endl;
		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
				Post_on_moments(mp, my_id);
				break;
			case 2:
				see_friend_circle(mp, my_id);
				break;
			case 3:
			{
				string _friend_name_ = Add_friend(mp, my_id);
				cout << "�ú��ѵ�����Ϊ��" << _friend_name_ << endl;
				break;
			}
			case 4:
				//change_infomation(mp, my_id);
				break;
			case 5:
				return 0;
		}
	}
}
