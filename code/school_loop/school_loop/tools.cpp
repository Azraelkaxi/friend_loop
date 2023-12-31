#include"tools.h"

//��ʾ��Ϣ
void display(map<string, User> mp, string _id_)
{
	for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
	{
		if (it->first == _id_)
		{
			cout << "ѧ�ţ�" << it->first << endl;
			string _message = it->second.getMessage();
			string new_message = "";
			for (int i = 0; i < _message.size(); i++)
				new_message += _message[(i + _message.size() - 4) % _message.size()];
			cout << "���룺" << new_message << endl;
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
		int a = 0;
		for (it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == my_id)
			{
				it->second.addFriend(_id);
				a++;
			}
			if (it->first == _id)
			{
				it->second.addFriend(my_id);
				a++;
			}
			if (a == 2)
				break;
		}

	}
	else if (flag == 0)
	{
		int b = 0;
		for (it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == my_id)
			{
				it->second.deleteFriend(_id);
				b++;
			}
			if (it->first == _id)
			{
				it->second.deleteFriend(my_id);
				b++;
			}
			if (b == 2)
				break;
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
void deletefriend(map<string, User>& mp, string my_id)
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
	Comment c;
	list<Comment> _comment_;
	_comment_.push_back(c);
	Moments _m(_text, _date, _likes, _comment_);
	ofs << _m;

	ofs.close();
	for (auto it = mp.begin(); it != mp.end(); ++it)
	{
		if (it->first == my_id)
		{
			it->second.addCircle_of_friends(_m);
			break;
		}
	}
}
//ˢ����Ȧ
void begin_to_see(map<string, User>& mp, string my_id)
{
	while (1)
	{
		cout << "----------------------------" << endl;
		cout << "     ��ӭ������������Ȧ     " << endl;
		cout << "----------------------------" << endl;
		cout << "         1. �Լ�            " << endl;
		cout << "         2. ����            " << endl;
		cout << "         3. �˳�            " << endl;
		cout << "----------------------------" << endl;
		cout << "����������ѡ�� " << endl;
		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
				for (map<string, User>::iterator ir = mp.begin(); ir != mp.end(); ++ir)
				{
					if (ir->first == my_id)
					{
						if (ir->second.getCircle_of_friends().empty())
						{
							system("cls");
							cout << "����δ���������Ȧ�� ���ȷ�������Ȧ������" << endl;
							system("pause");
							break;
						}
						else
						{
							for (list<Moments>::iterator ior = ir->second.getCircle_of_friends().begin(); ior != ir->second.getCircle_of_friends().end(); ++ior)
							{
								int fff = 0;
							aaa:
								system("cls");
								cout << "������" << ir->first << endl;
								cout << "���ݣ�" << ior->getText();
								cout << "���ڣ�" << ior->getDate() << endl;
								cout << "��������" << ior->getLikes() << endl;
								ior->showComment();
								while (1)
								{
									cout << "1. ��һ��" << endl;
									cout << "2. ���е���" << endl;
									cout << "3. ��������" << endl;
									cout << "4. ���лظ�" << endl;
									cout << "5. �˳�    " << endl;
									cout << "����������ѡ�� " << endl;
									int _choice;
									cin >> _choice;

									switch (_choice)
									{
										case 1:
											break;
										case 2:
											ior->giveLike();
											goto aaa;
											break;
										case 3:
											ior->writeComment();
											goto aaa;
											break;
										case 4:
										dd:
											cout << "��������Ҫ�ظ������۱�ţ�" << endl;
											int num;
											cin >> num;
											if (num > ior->getComments().size())
											{
												cout << "���޴�������" << endl;
												goto dd;
											}
											else
											{
												ior->writeReply(num);
												goto aaa;
											}
											break;
										case 5:
											fff = 1;
											break;;
									}
									break;
								}
								if (fff == 1)
									break;
							}
						}
					}
				}
				break;
			case 2:
				for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
				{
					if (it->first == my_id)
					{
						list<string> _friend = it->second.getFriend();
						if (_friend.empty())
						{
							cout << "��δ���κκ��ѣ����ȼ�һЩ����������" << endl;
							system("pause");
							return;
						}
						for (list<string>::iterator it2 = _friend.begin(); it2 != _friend.end(); ++it2)
						{
							map<string, User>::iterator is;
							for (is = mp.begin(); is != mp.end(); ++is)
							{
								if (is->first == *it2)
								{
									// list<Moments> _friend_circle = is->second.getCircle_of_friends();
									for (list<Moments>::iterator it1 = is->second.getCircle_of_friends().begin(); it1 != is->second.getCircle_of_friends().end(); ++it1)
									{
									start:
										system("cls");
										cout << "������" << is->first << endl;
										cout << "���ݣ�" << it1->getText();
										cout << "���ڣ�" << it1->getDate() << endl;
										cout << "��������" << it1->getLikes() << endl;
										it1->showComment();
										while (1)
										{
											cout << "1. ��һ��" << endl;
											cout << "2. ���е���" << endl;
											cout << "3. ��������" << endl;
											cout << "4. ���лظ�" << endl;
											cout << "5. �˳�    " << endl;
											cout << "����������ѡ�� " << endl;
											int choice;
											cin >> choice;
											switch (choice)
											{
											case 1:
												break;
											case 2:
												it1->giveLike();
												goto start;
												break;
											case 3:
												it1->writeComment();
												goto start;
												break;
											case 4:
											ss:
												cout << "��������Ҫ�ظ������۱�ţ�" << endl;
												int num;
												cin >> num;
												if (num > it1->getComments().size())
												{
													cout << "���޴�������" << endl;
													goto ss;
												}
												else
												{
													it1->writeReply(num);
													goto start;
												}
												break;
											case 5:
												return;
											}
											break;
										}
									}

								}
							}
						}
						cout << "�Ѿ�������" << endl;
						cout << "��0�˳�" << endl;
						int y;
						cin >> y;
						if (y == 0)
							return;
					}
				}
				break;
			case 3:
				return;
		}
	}
	
}
//����ĳ���˷�������Ȧ
void query_friend_circle(map<string, User>& mp, string my_id)
{
	while (true) {
		system("cls");
		cout << "������Ҫ��������Ȧ��ѧ�ţ�" << endl;
		string target_id;
		cin >> target_id;

		map<string, User>::iterator it;
		for (it = mp.begin(); it != mp.end(); ++it) {
			if (it->first == target_id) {
				int flag = 0;
				list<Moments> friend_moments = it->second.getCircle_of_friends();
				if (friend_moments.empty()) {
					cout << "���û���û�з�������Ȧ" << endl;
					flag = 1;
				}
				else {
					list<Moments>::iterator it_m;
					for (it_m = friend_moments.begin(); it_m != friend_moments.end(); ++it_m) {
						cout << "���ݣ�" << it_m->getText();
						cout << "���ڣ�" << it_m->getDate() << endl;
						cout << "��������" << it_m->getLikes() << endl;
						cout << endl;
					}
					flag = 1;
				}
				if (flag) {
					system("pause");
					break;
				}
			}
		}

		if (it == mp.end()) {
			cout << "δ�ҵ���ѧ�Ŷ�Ӧ���û�" << endl;
			system("pause");
		}
		else {
			break;
		}
	}
}
//ɾ������Ȧ
void delete_friend_circle(map<string, User>& mp, string my_id)
{
	string flag = my_id.substr(0, 3);
	//����Աɾ������Ȧ
	if (flag == "gly")
	{
		while (1)
		{
			system("cls");
			cout << "�𾴵Ĺ���Ա������" << endl;
			cout << "1. ɾ��Υ������Ȧ" << endl;
			cout << "2. ɾ���Լ�����Ȧ" << endl;
			cout << "3. ����          " << endl;
			cout << "����������ѡ��" << endl;
			int choice;
			cin >> choice;

			switch (choice)
			{
				case 1:
				{
					cout << "������Υ���ѧ��ѧ�ţ�" << endl;
					string stu_id;
					cin >> stu_id;
					map<string, User>::iterator it1;
					for (it1 = mp.begin(); it1 != mp.end(); ++it1)
					{
						if (it1->first == stu_id)
						{
							if (it1->second.getCircle_of_friends().empty())
							{
								cout << "��ͬѧδ��������Ȧ" << endl;
								system("pause");
								break;
							}
							cout << "���ҵ���ѧ��,������������Ȧ" << endl;
							Sleep(1000);
							for (list<Moments>::iterator it2 = it1->second.getCircle_of_friends().begin(); it2 != it1->second.getCircle_of_friends().end(); ++it2)
							{
								system("cls");
								cout << "������" << it1->first << endl;
								cout << "���ݣ�" << it2->getText();
								cout << "���ڣ�" << it2->getDate() << endl;
								cout << "��������" << it2->getLikes() << endl;
								it2->showComment();
								cout << "�Ƿ�ɾ��(0��1)��" << endl;
								int x;
								cin >> x;
								if (x == 0)
									continue;
								else if (x == 1)
								{
									list<Moments>::iterator it3 = ++it2;
									if (it3 == it1->second.getCircle_of_friends().end())
										it3 = it1->second.getCircle_of_friends().begin();
									it1->second.getCircle_of_friends().erase(--it2);
									it2 = it3;
									cout << "ɾ���ɹ�" << endl;
									system("pause");
									if (it2 == it1->second.getCircle_of_friends().begin())
										break;
								}
							}
							cout << "�Ѿ�������" << endl;
							system("pause");
							break;
						}
					}
					break;
				}
				case 2:
				{
					map<string, User>::iterator is;
					for (is = mp.begin(); is != mp.end(); ++is)
					{
						if (is->first == my_id)
						{
							if (is->second.getCircle_of_friends().empty())
							{
								cout << "����δ��������Ȧ" << endl;
								system("pause");
								return;
							}
							cout << "��������������Ȧ" << endl;
							Sleep(1000);
							for (list<Moments>::iterator it4 = is->second.getCircle_of_friends().begin(); it4 != is->second.getCircle_of_friends().end(); ++it4)
							{
								system("cls");
								cout << "������" << my_id << endl;
								cout << "���ݣ�" << it4->getText();
								cout << "���ڣ�" << it4->getDate() << endl;
								cout << "��������" << it4->getLikes() << endl;
								it4->showComment();
								cout << "�Ƿ�ɾ��(0��1)��" << endl;
								int x;
								cin >> x;
								if (x == 0)
									continue;
								else if (x == 1)
								{
									list<Moments>::iterator it5 = ++it4;
									if (it5 == is->second.getCircle_of_friends().end())
										it5 = is->second.getCircle_of_friends().begin();
									is->second.getCircle_of_friends().erase(--it4);
									it4 = it5;
									cout << "ɾ���ɹ�" << endl;
									if (it4 == is->second.getCircle_of_friends().begin())
										break;
								}
							}
							cout << "�Ѿ�������" << endl;
							system("pause");
							break;
						}
					}
					break;
				}
				case 3:
					return;
			}
		}
	}

	//��ͨ�û�ɾ������Ȧ
	system("cls");
	map<string, User>::iterator iit;
	for (iit = mp.begin(); iit != mp.end(); ++iit)
	{
		if (iit->first == my_id)
		{
			if (iit->second.getCircle_of_friends().empty())
			{
				cout << "����δ��������Ȧ" << endl;
				system("pause");
				return;
			}
			for (list<Moments>::iterator iit1 = iit->second.getCircle_of_friends().begin(); iit1 != iit->second.getCircle_of_friends().end(); ++iit1)
			{
				system("cls");
				cout << "������" << my_id << endl;
				cout << "���ݣ�" << iit1->getText();
				cout << "���ڣ�" << iit1->getDate() << endl;
				cout << "��������" << iit1->getLikes() << endl;
				iit1->showComment();
				cout << "�Ƿ�ɾ��(0��1)��" << endl;
				int x;
				cin >> x;
				if (x == 0)
					continue;
				else if (x == 1)
				{
					list<Moments>::iterator iit2 = ++iit1;
					if (iit2 == iit->second.getCircle_of_friends().end())
						iit2 = iit->second.getCircle_of_friends().begin();
					iit->second.getCircle_of_friends().erase(--iit1);
					iit1 = iit2;
					cout << "ɾ���ɹ�" << endl;
					system("pause");
					if (iit1 == iit->second.getCircle_of_friends().begin())
						break;
				}
			}
			cout << "�Ѿ�������" << endl;
			system("pause");
			break;
		}
	}
}
//ʵ��ˢ����Ȧ��������
//������ʵ�ֲ���ĳ�����ض�����Ȧ��ɾ������Ȧ��
//�������� �ظ�ĳ������  ���е���  ��������������ͬʱ��Ҫʵʱ�����ı��ļ�
void see_friend_circle(map<string, User>& mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
		cout << "�U            ��ӭ��������Ȧ              �U" << endl;
		cout << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�U             1. ˢ����Ȧ                �U" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�U             2. ��������Ȧ              �U" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�U             3. ɾ������Ȧ              �U" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�U             4. �˳�                    �U" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
		cout << "����������ѡ��: " << endl;
		int choice;
		cin >> choice;

		switch (choice)
		{
		case 1:
			begin_to_see(mp, my_id);
			break;
		case 2:
			query_friend_circle(mp, my_id);
			break;
		case 3:
			delete_friend_circle(mp, my_id);
			break;
		case 4:
			return;
		}
	}
}
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
				string _message = it->second.getMessage();
				string new_message = "";
				for (int i = 0; i < _message.size(); i++)
					new_message += _message[(i + _message.size() - 4) % _message.size()];
				cout << "���룺" << new_message << endl;
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
					string new_message_ = "";
					for (int i = 0; i < new_message.size(); i++)
						new_message_ += new_message[(i + 4) % new_message.size()];
					it->second.setMessage(new_message_);
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

