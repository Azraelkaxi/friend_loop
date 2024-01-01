#define _CRT_SECURE_NO_WARNINGS 
#include"User.h"
#include"login.h"
#include"tools.h"
#include<map>




int main()
{
	map<string, User> mp;

	Init(mp);

	string my_id;

	my_id = begin(mp);

	system("cls");
	while (1)
	{
		system("cls");
		cout << "╔════════════════════════════════════════╗" << endl;
		cout << "║          欢迎进入校园朋友圈            ║" << endl;
		cout << "╠════════════════════════════════════════╣" << endl;
		cout << "║                                        ║" << endl;
		cout << "║             1. 发朋友圈                ║" << endl;
		cout << "║                                        ║" << endl;
		cout << "║             2. 看朋友圈                ║" << endl;
		cout << "║                                        ║" << endl;
		cout << "║             3. 添加好友                ║" << endl;
		cout << "║                                        ║" << endl;
		cout << "║             4. 删除好友                ║" << endl;
		cout << "║                                        ║" << endl; 
		cout << "║             5. 修改自身信息            ║" << endl;
		cout << "║                                        ║" << endl;
		cout << "║             6. 查看热门榜单            ║" << endl;
		cout << "║                                        ║" << endl;
		cout << "║             7. 退出                    ║" << endl;
		cout << "║                                        ║" << endl;
		cout << "╚════════════════════════════════════════╝" << endl;
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
				deletefriend(mp, my_id);
				break;
			case 5:
				Change(mp, my_id);
				break;
			case 6:
				Leaderboard(mp);
				break;
			case 7:
				endWrite(mp);
				return 0;
		}
	}
}
