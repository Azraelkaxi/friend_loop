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
