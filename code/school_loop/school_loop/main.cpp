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
		cout << "�X�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�[" << endl;
		cout << "�U          ��ӭ����У԰����Ȧ            �U" << endl;
		cout << "�d�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�g" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�U             1. ������Ȧ                �U" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�U             2. ������Ȧ                �U" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�U             3. ��Ӻ���                �U" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�U             4. ɾ������                �U" << endl;
		cout << "�U                                        �U" << endl; 
		cout << "�U             5. �޸�������Ϣ            �U" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�U             6. �鿴���Ű�            �U" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�U             7. �˳�                    �U" << endl;
		cout << "�U                                        �U" << endl;
		cout << "�^�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�T�a" << endl;
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
