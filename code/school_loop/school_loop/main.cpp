#define _CRT_SECURE_NO_WARNINGS 1

#include"User.h"
#include"login.h"
#include"Postonmoments.h"
#include"Seefriendcircle.h"
#include"addfriend.h"
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
		cout << "    »¶Ó­½øÈëÐ£Ô°ÅóÓÑÈ¦   " << endl;
		cout << "       1. ·¢ÅóÓÑÈ¦       " << endl;
		cout << "       2. ¿´ÅóÓÑÈ¦       " << endl;
		cout << "       3. ¼ÓºÃÓÑ         " << endl;
		cout << "       4. ÍË³ö           " << endl;
		cout << "-------------------------" << endl;
		cout << "ÇëÊäÈëÄúµÄÑ¡Ôñ£º" << endl;
		int choice;
		cin >> choice;

		switch(choice)
		{
			case 1:
				Post_on_moments(mp, my_id);
				break;
			case 2:
				see_friend_circle(mp, my_id);
				break;
			case 3:
				Add_friend(mp, my_id);
				break;
			case 4:
				return 0;
		}
	}
}
