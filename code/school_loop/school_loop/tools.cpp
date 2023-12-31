#include"tools.h"

//显示信息
void display(map<string, User> mp, string _id_)
{
	for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
	{
		if (it->first == _id_)
		{
			cout << "学号：" << it->first << endl;
			string _message = it->second.getMessage();
			string new_message = "";
			for (int i = 0; i < _message.size(); i++)
				new_message += _message[(i + _message.size() - 4) % _message.size()];
			cout << "密码：" << new_message << endl;
			cout << "网名：" << it->second.getName() << endl;
			cout << "生日：" << it->second.getBirthday() << endl;
			break;
		}
	}
}
//刷新好友列表
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
//加好友，并返回好友网名
string Add_friend(map<string, User>& mp, string my_id)
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
				refresh_friend_list(mp, my_id, _id, 1);
				return it->second.getName();
			}
		}
		return "NotFound";
	}
}
//删好友
void deletefriend(map<string, User>& mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "请输入您要删的好友学号(输入out返回)： " << endl;
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
						cout << "已找到该人, 以下是其信息：" << endl;
						display(mp, _id);
						cout << "请确认是否删除(0或1)： " << endl;
						int choice;
						cin >> choice;
						if (choice == 0)
						{
							break;
						}
						else
						{
							refresh_friend_list(mp, my_id, _id, 0);
							cout << "删除成功" << endl;
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
//发布朋友圈
void Post_on_moments(map<string, User>& mp, string my_id)
{
	system("cls");
	cout << "请输入您要发布的朋友圈内容：" << endl;
	//获取文本
	string _text;
	cin >> _text;
	//获取时间
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
	//获取点赞
	int _likes = 0;

	//写入操作，待定  时间自动获取  点赞默认为0
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
//刷朋友圈
void begin_to_see(map<string, User>& mp, string my_id)
{
	while (1)
	{
		cout << "----------------------------" << endl;
		cout << "     欢迎进入您的朋友圈     " << endl;
		cout << "----------------------------" << endl;
		cout << "         1. 自己            " << endl;
		cout << "         2. 朋友            " << endl;
		cout << "         3. 退出            " << endl;
		cout << "----------------------------" << endl;
		cout << "请输入您的选择： " << endl;
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
							cout << "您还未发表过朋友圈， 请先发表朋友圈再来吧" << endl;
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
								cout << "网名：" << ir->first << endl;
								cout << "内容：" << ior->getText();
								cout << "日期：" << ior->getDate() << endl;
								cout << "点赞数：" << ior->getLikes() << endl;
								ior->showComment();
								while (1)
								{
									cout << "1. 下一条" << endl;
									cout << "2. 进行点赞" << endl;
									cout << "3. 进行评论" << endl;
									cout << "4. 进行回复" << endl;
									cout << "5. 退出    " << endl;
									cout << "请输入您的选择： " << endl;
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
											cout << "请输入您要回复的评论编号：" << endl;
											int num;
											cin >> num;
											if (num > ior->getComments().size())
											{
												cout << "并无此条评论" << endl;
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
							cout << "您未加任何好友，请先加一些好友再来吧" << endl;
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
										cout << "网名：" << is->first << endl;
										cout << "内容：" << it1->getText();
										cout << "日期：" << it1->getDate() << endl;
										cout << "点赞数：" << it1->getLikes() << endl;
										it1->showComment();
										while (1)
										{
											cout << "1. 下一条" << endl;
											cout << "2. 进行点赞" << endl;
											cout << "3. 进行评论" << endl;
											cout << "4. 进行回复" << endl;
											cout << "5. 退出    " << endl;
											cout << "请输入您的选择： " << endl;
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
												cout << "请输入您要回复的评论编号：" << endl;
												int num;
												cin >> num;
												if (num > it1->getComments().size())
												{
													cout << "并无此条评论" << endl;
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
						cout << "已经到底了" << endl;
						cout << "按0退出" << endl;
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
//查找某个人发的朋友圈
void query_friend_circle(map<string, User>& mp, string my_id)
{
	while (true) {
		system("cls");
		cout << "请输入要查找朋友圈的学号：" << endl;
		string target_id;
		cin >> target_id;

		map<string, User>::iterator it;
		for (it = mp.begin(); it != mp.end(); ++it) {
			if (it->first == target_id) {
				int flag = 0;
				list<Moments> friend_moments = it->second.getCircle_of_friends();
				if (friend_moments.empty()) {
					cout << "该用户还没有发布朋友圈" << endl;
					flag = 1;
				}
				else {
					list<Moments>::iterator it_m;
					for (it_m = friend_moments.begin(); it_m != friend_moments.end(); ++it_m) {
						cout << "内容：" << it_m->getText();
						cout << "日期：" << it_m->getDate() << endl;
						cout << "点赞数：" << it_m->getLikes() << endl;
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
			cout << "未找到该学号对应的用户" << endl;
			system("pause");
		}
		else {
			break;
		}
	}
}
//删除朋友圈
void delete_friend_circle(map<string, User>& mp, string my_id)
{
	string flag = my_id.substr(0, 3);
	//管理员删除朋友圈
	if (flag == "gly")
	{
		while (1)
		{
			system("cls");
			cout << "尊敬的管理员，您好" << endl;
			cout << "1. 删除违规朋友圈" << endl;
			cout << "2. 删除自己朋友圈" << endl;
			cout << "3. 返回          " << endl;
			cout << "请输入您的选择：" << endl;
			int choice;
			cin >> choice;

			switch (choice)
			{
				case 1:
				{
					cout << "请输入违规的学生学号：" << endl;
					string stu_id;
					cin >> stu_id;
					map<string, User>::iterator it1;
					for (it1 = mp.begin(); it1 != mp.end(); ++it1)
					{
						if (it1->first == stu_id)
						{
							if (it1->second.getCircle_of_friends().empty())
							{
								cout << "该同学未发过朋友圈" << endl;
								system("pause");
								break;
							}
							cout << "已找到该学生,以下是其朋友圈" << endl;
							Sleep(1000);
							for (list<Moments>::iterator it2 = it1->second.getCircle_of_friends().begin(); it2 != it1->second.getCircle_of_friends().end(); ++it2)
							{
								system("cls");
								cout << "网名：" << it1->first << endl;
								cout << "内容：" << it2->getText();
								cout << "日期：" << it2->getDate() << endl;
								cout << "点赞数：" << it2->getLikes() << endl;
								it2->showComment();
								cout << "是否删除(0或1)：" << endl;
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
									cout << "删除成功" << endl;
									system("pause");
									if (it2 == it1->second.getCircle_of_friends().begin())
										break;
								}
							}
							cout << "已经到底了" << endl;
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
								cout << "您还未发过朋友圈" << endl;
								system("pause");
								return;
							}
							cout << "以下是您的朋友圈" << endl;
							Sleep(1000);
							for (list<Moments>::iterator it4 = is->second.getCircle_of_friends().begin(); it4 != is->second.getCircle_of_friends().end(); ++it4)
							{
								system("cls");
								cout << "网名：" << my_id << endl;
								cout << "内容：" << it4->getText();
								cout << "日期：" << it4->getDate() << endl;
								cout << "点赞数：" << it4->getLikes() << endl;
								it4->showComment();
								cout << "是否删除(0或1)：" << endl;
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
									cout << "删除成功" << endl;
									if (it4 == is->second.getCircle_of_friends().begin())
										break;
								}
							}
							cout << "已经到底了" << endl;
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

	//普通用户删除朋友圈
	system("cls");
	map<string, User>::iterator iit;
	for (iit = mp.begin(); iit != mp.end(); ++iit)
	{
		if (iit->first == my_id)
		{
			if (iit->second.getCircle_of_friends().empty())
			{
				cout << "您还未发过朋友圈" << endl;
				system("pause");
				return;
			}
			for (list<Moments>::iterator iit1 = iit->second.getCircle_of_friends().begin(); iit1 != iit->second.getCircle_of_friends().end(); ++iit1)
			{
				system("cls");
				cout << "网名：" << my_id << endl;
				cout << "内容：" << iit1->getText();
				cout << "日期：" << iit1->getDate() << endl;
				cout << "点赞数：" << iit1->getLikes() << endl;
				iit1->showComment();
				cout << "是否删除(0或1)：" << endl;
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
					cout << "删除成功" << endl;
					system("pause");
					if (iit1 == iit->second.getCircle_of_friends().begin())
						break;
				}
			}
			cout << "已经到底了" << endl;
			system("pause");
			break;
		}
	}
}
//实现刷朋友圈，待定。
//还可以实现查找某个人特定朋友圈，删除朋友圈等
//发布评论 回复某条评论  进行点赞  进行上述动作的同时，要实时更新文本文件
void see_friend_circle(map<string, User>& mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "╔════════════════════════════════════════╗" << endl;
		cout << "║            欢迎进入朋友圈              ║" << endl;
		cout << "╠════════════════════════════════════════╣" << endl;
		cout << "║                                        ║" << endl;
		cout << "║             1. 刷朋友圈                ║" << endl;
		cout << "║                                        ║" << endl;
		cout << "║             2. 查找朋友圈              ║" << endl;
		cout << "║                                        ║" << endl;
		cout << "║             3. 删除朋友圈              ║" << endl;
		cout << "║                                        ║" << endl;
		cout << "║             4. 退出                    ║" << endl;
		cout << "║                                        ║" << endl;
		cout << "╚════════════════════════════════════════╝" << endl;
		cout << "请输入您的选择: " << endl;
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
//修改信息
void Change(map<string, User>& mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "--------------------------------" << endl;
		cout << "      欢迎进入信息修改界面      " << endl;
		cout << "--------------------------------" << endl;
		cout << "您的个人信息如下：" << endl;
		for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == my_id)
			{
				cout << "学号：" << it->first << endl;
				string _message = it->second.getMessage();
				string new_message = "";
				for (int i = 0; i < _message.size(); i++)
					new_message += _message[(i + _message.size() - 4) % _message.size()];
				cout << "密码：" << new_message << endl;
				cout << "网名：" << it->second.getName() << endl;
				cout << "生日：" << it->second.getBirthday() << endl;
				cout << "1. 改密码 " << "      " << "2. 改网名 " << "      " << "3. 改生日 " << "      " << "4. 退出 " << endl;
				cout << "请输入您的选择：" << endl;
				int choice;
				cin >> choice;

				switch (choice)
				{
				case 1:
				{
				restart:
					system("cls");
					cout << "请输入新密码：" << endl;
					string new_message, flag;
					while (1)
					{
						char c = _getch();//getch()不会向终端回显字符
						if (c == '\r')
						{
							break;
						}
						printf("*");
						new_message += c;
					}
					cout << endl;
					cout << new_message << endl;
					cout << "请确认密码是否正确(0或1): " << endl;
					cin >> flag;
					if (flag == "0")
						goto restart;
					string new_message_ = "";
					for (int i = 0; i < new_message.size(); i++)
						new_message_ += new_message[(i + 4) % new_message.size()];
					it->second.setMessage(new_message_);
					cout << "密码修改成功" << endl;
					system("pause");
					break;
				}
				case 2:
				{
				restart1:
					system("cls");
					cout << "请输入新网名：" << endl;
					string new_name, flag;
					cin >> new_name;
					cout << endl;
					cout << "请确认网名是否正确(0或1): " << endl;
					cin >> flag;
					if (flag == "0")
						goto restart1;
					it->second.setName(new_name);
					cout << "网名修改成功" << endl;
					system("pause");
					break;
				}
				case 3:
				{
				restart2:
					system("cls");
					cout << "请输入新生日(XXXX-XX-XX)：" << endl;
					string new_birthday, flag;
					cin >> new_birthday;
					cout << endl;
					cout << "请确认生日是否正确(0或1): " << endl;
					cin >> flag;
					if (flag == "0")
						goto restart2;
					it->second.setBirthday(new_birthday);
					cout << "生日修改成功" << endl;
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

