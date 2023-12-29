#include"tools.h"

//刷新好友列表
void refresh_friend_list(string my_id, string _id);

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
				//refresh_friend_list(my_id, _id);
				return it->second.getName();
			}
		}
		return "NotFound";
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
	int _likes;

	//写入操作，待定  时间自动获取  点赞默认为0
	string title = my_id + ".txt";
	ofstream ofs(title, ios::app);
	ofs << "0" << endl;
	ofs << _text << endl;
	ofs << "1" << endl;

	ofs.close();
	cout << "发布成功" << endl;
	system("pause");
}

//实现刷朋友圈，待定。
//还可以实现查找某条特定朋友圈，删除朋友圈等
//发布评论 回复某条评论  进行点赞  进行上述动作的同时，要实时更新文本文件
void see_friend_circle(map<string, User>& mp, string my_id)
{
}


//查找某条朋友圈

//删除某条朋友圈



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