#define _CRT_SECURE_NO_WARNINGS 
#include"User.h"
#include"login.h"
#include"tools.h"
#include<map>

// 初始化mp
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
			string File_name = "data\\" + line + ".txt";
			ifstream is(File_name, ios_base::in);
			if (!is.is_open())
			{
				cout << "文件打开失败" << endl;
			}
			else
			{
				User t;
				string temp;
				// 读取基本信息
				getline(is, temp);
				t.setID(temp);
				getline(is, temp);
				t.setMessage(temp);
				getline(is, temp);
				t.setName(temp);
				getline(is, temp);
				t.setBirthday(temp);

				// 读取好友列表
				getline(is, temp);
				if (temp == "#")
				{
					while (getline(is, temp))
					{
						if (temp.empty() || temp == "*")
							break;
						else
						{
							t.getFriend().push_back(temp);
						} 
					}
				}

				// 读朋友圈的信息
				getline(is, temp );
				while (temp == "#")
				{
					Moments moment;
					string content = "";
					
					// 内容
					while (getline(is, temp))
					{
						if (temp.empty() || temp == "#")
							break;
						else
						{
							content += temp + "\n";
						}
					}
					moment.setText(content);

					// 点赞和日期
					getline(is, temp);
					moment.setLikes(atoi(temp.c_str()));
					getline(is, temp);
					moment.setDate(temp);

					// 评论
					getline(is, temp);
					if (temp == "#")
					{
						while (temp != "*")
						{
							getline(is, temp);
							moment.writeComment(temp);
							getline(is, temp);
							while (!temp.empty())
							{
								if (temp == "*")
								{
									break;
								}
								moment.writeReply(temp);
								getline(is, temp);
							}
						}

					}
					t.getCircle_of_friends().push_back(moment);

					// 读出是否有下一条朋友圈
					getline(is, temp);

				}

				// 将读出的user对象放入到mp中
				mp.insert(make_pair(t.getId(), t));

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
				Change(mp, my_id);
				break;
			case 5:
				return 0;
		}
	}
}
