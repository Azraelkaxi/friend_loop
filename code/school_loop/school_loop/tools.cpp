#include"tools.h"

//��ʾ��Ϣ
void display(map<string, User> mp, string _id_)
{
	for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
	{
		if (it->first == _id_)
		{
			cout << "ѧ�ţ�" << it->first << endl;
			cout << "���룺" << it->second.getMessage() << endl;
			cout << "������" << it->second.getName() << endl;
			cout << "���գ�" << it->second.getBirthday() << endl;
			break;
		}
	}
}
//ˢ�º����б�
void refresh_friend_list(map<string, User>& mp, string my_id, string _id, int flag)
{
	map<string, User>::iterator it;
	if (flag == 1)
	{
		for (it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == my_id)
			{
				it->second.addFriend(_id);
			}
		}
	}
	else if (flag == 0)
	{
		for (it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == my_id)
			{
				it->second.deleteFriend(_id);
			}
		}
	}
}
//�Ӻ��ѣ������غ�������
string Add_friend(map<string, User>& mp, string my_id)
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
				refresh_friend_list(mp, my_id, _id, 1);
				return it->second.getName();
			}
		}
		return "NotFound";
	}
}
//ɾ����
void deletefriend(map<string, User> &mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "��������Ҫɾ�ĺ���ѧ��(����out����)�� " << endl;
		string _id;
		cin >> _id;
		if (_id == "out")
			return;
		for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == my_id)
			{
				list<string> _friend_ = it->second.getFriend();
				list<string>::iterator is;
				for (is = _friend_.begin(); is != _friend_.end(); ++is)
				{
					if (*is == _id)
					{
						cout << "���ҵ�����, ����������Ϣ��" << endl;
						display(mp, _id);
						cout << "��ȷ���Ƿ�ɾ��(0��1)�� " << endl;
						int choice;
						cin >> choice;
						if (choice == 0)
						{
							break;
						}
						else
						{
							refresh_friend_list(mp, my_id, _id, 0);
							cout << "ɾ���ɹ�" << endl;
							system("pause");
							break;
						}
					}
				}
				break;
			}
		}
	}
}
//��������Ȧ
void Post_on_moments(map<string, User>& mp, string my_id)
{
	system("cls");
	cout << "��������Ҫ����������Ȧ���ݣ�" << endl;
	//��ȡ�ı�
	string _text;
	cin >> _text;
	//��ȡʱ��
	time_t currentTime = time(nullptr);
	struct tm localTime;
	localtime_s(&localTime, &currentTime);

	ostringstream formattedTime;
	formattedTime << localTime.tm_year + 1900 << "-"
		<< std::setfill('0') << std::setw(2) << localTime.tm_mon + 1 << "-"
		<< std::setfill('0') << std::setw(2) << localTime.tm_mday << " "
		<< std::setfill('0') << std::setw(2) << localTime.tm_hour << ":"
		<< std::setfill('0') << std::setw(2) << localTime.tm_min;

	string _date = formattedTime.str();
	//��ȡ����
	int _likes = 0;

	//д�����������  ʱ���Զ���ȡ  ����Ĭ��Ϊ0
	string title = "data\\" + my_id + ".txt";
	ofstream ofs(title, ios::app);
	ofs << "#" << endl;
	ofs << _text << endl;
	ofs << "#" << endl;

	ofs.close();
	cout << "�����ɹ�" << endl;
	system("pause");
}

//ʵ��ˢ����Ȧ��������
//������ʵ�ֲ���ĳ���ض�����Ȧ��ɾ������Ȧ��
//�������� �ظ�ĳ������  ���е���  ��������������ͬʱ��Ҫʵʱ�����ı��ļ�
void see_friend_circle(map<string, User>& mp, string my_id)
{
}


//����ĳ������Ȧ

//ɾ��ĳ������Ȧ



//��������, ��������ɸ���
void Post_a_review(map<string, User>& mp, string my_id);

//�ظ�ĳ������  ��������ɸ���
void Reply_to_a_review(map<string, User>& mp, string my_id);

//���е���

//ʵʱ�����ı��ļ�

//�޸���Ϣ
void Change(map<string, User>& mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "--------------------------------" << endl;
		cout << "      ��ӭ������Ϣ�޸Ľ���      " << endl;
		cout << "--------------------------------" << endl;
		cout << "���ĸ�����Ϣ���£�" << endl;
		for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == my_id)
			{
				cout << "ѧ�ţ�" << it->first << endl;
				cout << "���룺" << it->second.getMessage() << endl;
				cout << "������" << it->second.getName() << endl;
				cout << "���գ�" << it->second.getBirthday() << endl;
				cout << "1. ������ " << "      " << "2. ������ " << "      " << "3. ������ " << "      " << "4. �˳� " << endl;
				cout << "����������ѡ��" << endl;
				int choice;
				cin >> choice;

				switch (choice)
				{
				case 1:
				{
				restart:
					system("cls");
					cout << "�����������룺" << endl;
					string new_message, flag;
					while (1)
					{
						char c = _getch();//getch()�������ն˻����ַ�
						if (c == '\r')
						{
							break;
						}
						printf("*");
						new_message += c;
					}
					cout << endl;
					cout << new_message << endl;
					cout << "��ȷ�������Ƿ���ȷ(0��1): " << endl;
					cin >> flag;
					if (flag == "0")
						goto restart;
					it->second.setMessage(new_message);
					cout << "�����޸ĳɹ�" << endl;
					system("pause");
					break;
				}
				case 2:
				{
				restart1:
					system("cls");
					cout << "��������������" << endl;
					string new_name, flag;
					cin >> new_name;
					cout << endl;
					cout << "��ȷ�������Ƿ���ȷ(0��1): " << endl;
					cin >> flag;
					if (flag == "0")
						goto restart1;
					it->second.setName(new_name);
					cout << "�����޸ĳɹ�" << endl;
					system("pause");
					break;
				}
				case 3:
				{
				restart2:
					system("cls");
					cout << "������������(XXXX-XX-XX)��" << endl;
					string new_birthday, flag;
					cin >> new_birthday;
					cout << endl;
					cout << "��ȷ�������Ƿ���ȷ(0��1): " << endl;
					cin >> flag;
					if (flag == "0")
						goto restart2;
					it->second.setBirthday(new_birthday);
					cout << "�����޸ĳɹ�" << endl;
					system("pause");
					break;
				}
				case 4:
					return;
				}
			}
			break;
		}
	}
}