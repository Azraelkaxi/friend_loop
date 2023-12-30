#include"tools.h"

//显示信息
void display(map<string, User> mp, string _id_)
{
	for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
	{
		if (it->first == _id_)
		{
			cout << "学号：" << it->first << endl;
			cout << "密码：" << it->second.getMessage() << endl;
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
void deletefriend(map<string, User> &mp, string my_id)
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
//发表评论和回复
//void publication(list<Moments>::iterator& it)
//{
//	while (1)
//	{
//		cout << "1. 发表评论" << endl;
//		cout << "2. 进行点赞" << endl;
//		cout << "3. 进行回复" << endl;
//		cout << ""
//	}
//}
//刷朋友圈
void begin_to_see(map<string, User> &mp, string my_id)
{
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
			for (list<string>::iterator it = _friend.begin(); it != _friend.end(); ++it)
			{
				map<string, User>::iterator is;
				for (is = mp.begin(); is != mp.end(); ++is)
				{
					if (is->first == *it)
					{
						list<Moments> _friend_circle = is->second.getCircle_of_friends();
						for (list<Moments>::iterator it1 = _friend_circle.begin(); it1 != _friend_circle.end(); ++it1)
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
}

//查找某个人发的朋友圈
void query_friend_circle()
{

}

//删除自己发的某条朋友圈
void delete_friend_circle()
{

}

//实现刷朋友圈，待定。
//还可以实现查找某个人特定朋友圈，删除朋友圈等
//发布评论 回复某条评论  进行点赞  进行上述动作的同时，要实时更新文本文件
void see_friend_circle(map<string, User>& mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "---------------------------------" << endl;
		cout << "         欢迎进入朋友圈          " << endl;
		cout << "---------------------------------" << endl;
		cout << "         1. 开始刷朋友圈         " << endl;
		cout << "         2. 查找朋友圈           " << endl;
		cout << "         3. 删除朋友圈           " << endl;
		cout << "         4. 退出                 " << endl;
		cout << "---------------------------------" << endl;
		cout << "请输入您的选择: " << endl;
		int choice;
		cin >> choice;

		switch (choice)
		{
			case 1:
				begin_to_see(mp, my_id);
				break;
			case 2:
				query_friend_circle();
				break;
			case 3:
				delete_friend_circle();
				break;
			case 4:
				return ;
		}
	}
}

//发布评论, 传入参数可更改
void Post_a_review(map<string, User>& mp, string my_id);

//回复某条评论  传入参数可更改
void Reply_to_a_review(map<string, User>& mp, string my_id);

//进行点赞

//实时更新文本文件

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
				cout << "密码：" << it->second.getMessage() << endl;
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
					it->second.setMessage(new_message);
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


