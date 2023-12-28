#define _CRT_SECURE_NO_WARNINGS 
#include"User.h"
#include"login.h"
#include"tools.h"
#include<map>
int main()
{
	map<string, User> mp;

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
