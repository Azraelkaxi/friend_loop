#define _CRT_SECURE_NO_WARNINGS 
#include"User.h"
#include"login.h"
#include"tools.h"
#include<map>

void Init(map<string, User>& mp)
{
	string URL = "data\\校园朋友圈账号信息.txt";
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
				cout << "文件打开失败" << endl;
			}
			else
			{
				//读取基础信息
				string _id, _message, _name, _birthday, line1, line2, line3;
				//读取好友列表
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
				//读取朋友圈
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
		cout << "    欢迎进入校园朋友圈   " << endl;
		cout << "       1. 发朋友圈       " << endl;
		cout << "       2. 看朋友圈       " << endl;
		cout << "       3. 加好友         " << endl;
		cout << "       4. 修改自身信息   " << endl;
		cout << "       5. 退出           " << endl;
		cout << "-------------------------" << endl;
		cout << "请输入您的选择：" << endl;
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
				cout << "该好友的网名为：" << _friend_name_ << endl;
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
