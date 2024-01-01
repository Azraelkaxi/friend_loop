#include"login.h"

// 返回的使用者id
string _id_;

// 记录账号的地址
const string URL = "data\\校园朋友圈账号信息.txt";

// 判断账号是否已存在
bool queryMessage(string _id)
{
	string str1;
	ifstream ifs(URL, ios_base::in);

	while (ifs >> str1)
	{
		if (str1 == _id)
		{
			ifs.close();
			return true;
		}
	}
	ifs.close();
	return false;
}

// 保存账号信息
void save_id_message(string _id, string _message, map<string, User>& mp)
{
	// 在账号信息表中添加新账号(追加写入)
	ofstream ofs(URL, ios::app);
	ofs << _id << endl;
	ofs.close();
	//实时更新map
	list<string> Friend = {};
	list<Moments> Circle_of_friends = {};
	string _message_ = "";
	for (int i = 0; i < _message.size(); i++)
	{
		_message_ += _message[(i + 4) % _message.size()];
	}
	User user(_id, _message_, Friend, Circle_of_friends);
	mp.insert(make_pair(_id, user));

	// 在data下开一个存储新账号的区域
	string file_name = "data\\" + _id + ".txt";
	ofstream outFile(file_name, ios_base::out);
	/*
	写入默认的User类信息
	(当前仅做测试)
	*/
	outFile << user;
	outFile.close();

}

// 注册
void sign_in(map<string, User>& mp, int flag)
{
	string _id, _message = "", re_message = "";
	if (flag == 2)
	{
		while (1)
		{
			system("cls");
			_message = "";
			re_message = "";
			cout << "请输入您要注册的账号(学号)：" << endl;
			cin >> _id;
			cout << "请输入密码(仅支持字母和数字)：" << endl;
			while (1)
			{
				char c = _getch();//getch()不会向终端回显字符
				if (c == '\r')
				{
					break;
				}
				else if (c == '\b') {  // Backspace键
					if (!_message.empty()) {
						// 删除最后一个字符
						_message.pop_back();

						// 向终端回显退格
						printf("\b \b");
					}
				}
				else
				{
					printf("*");
					_message += c;
				}
			}
			cout << endl;
			cout << "请确认密码(仅支持字母和数字): " << endl;
			while (1)
			{
				char c = _getch();//getch()不会向终端回显字符
				if (c == '\r')
				{
					break;
				}
				else if (c == '\b') {  // Backspace键
					if (!_message.empty()) {
						// 删除最后一个字符
						_message.pop_back();

						// 向终端回显退格
						printf("\b \b");
					}
				}
				else
				{
					printf("*");
					re_message += c;
				}
			}
			cout << endl;
			if (re_message == _message)
			{
				if (queryMessage(_id))
				{
					cout << "该账号已存在，请直接登录" << endl;
					system("pause");
					break;
				}
				save_id_message(_id, _message, mp);
				cout << "您已成功注册，请登录" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "两次输入的密码不一致，请重新注册" << endl;
				system("pause");
				continue;
			}
		}
		return;
	}
	else if (flag == 1)
	{
		while (1)
		{
			system("cls");
			_message = "";
			re_message = "";
			cout << "请输入您要注册的账号(gly+学号)：" << endl;
			cin >> _id;
			cout << "请输入密码(仅支持字母和数字)：" << endl;
			while (1)
			{
				char c = _getch();//getch()不会向终端回显字符
				if (c == '\r')
				{
					break;
				}
				else if (c == '\b') {  // Backspace键
					if (!_message.empty()) {
						// 删除最后一个字符
						_message.pop_back();

						// 向终端回显退格
						printf("\b \b");
					}
				}
				else
				{
					printf("*");
					_message += c;
				}
			}
			cout << endl;
			cout << "请确认密码(仅支持字母和数字): " << endl;
			while (1)
			{
				char c = _getch();//getch()不会向终端回显字符
				if (c == '\r')
				{
					break;
				}
				else if (c == '\b') {  // Backspace键
					if (!_message.empty()) {
						// 删除最后一个字符
						_message.pop_back();

						// 向终端回显退格
						printf("\b \b");
					}
				}
				else
				{
					printf("*");
					re_message += c;
				}
			}
			cout << endl;
			if (re_message == _message)
			{
				if (queryMessage(_id))
				{
					cout << "该账号已存在，请直接登录" << endl;
					system("pause");
					break;
				}
				save_id_message(_id, _message, mp);
				cout << "您已成功注册，请登录" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "两次输入的密码不一致，请重新注册" << endl;
				system("pause");
				continue;
			}
		}
	}
}

// 检查账号和密码是否匹配
int check(string _id, string _message, map<string, User>& mp)
{
	string str1;
	ifstream ifs(URL, ios_base::in);
	while (getline(ifs, str1))
	{
		if (str1 == _id)
		{
			map<string, User>::iterator it;
			for (it = mp.begin(); it != mp.end(); ++it)
			{
				if (it->first == _id)
				{
					string _message_ = "";
					for (int i = 0; i < _message.size(); i++)
						_message_ += _message[(i + 4) % _message.size()];
					if (it->second.getMessage() == _message_)
					{
						ifs.close();
						return 0;
					}
					else
					{
						ifs.close();
						return 1;
					}
				}
			}
		}
	}
	ifs.close();
	return 2;
}

// 登录
int check_in(map<string, User>& mp)
{
	string _id, _message = "";
	while (1)
	{
		cout << "请输入您的账号 ：" << endl;
		cin >> _id;
		cout << "请输入您的密码 ：" << endl;
		_message = "";
		while (1)
		{
			
			char c = _getch();//getch()不会向终端回显字符
			if (c == '\r')
			{
				break;
			}
			else if (c == '\b') {  // Backspace键
				if (!_message.empty()) {
					// 删除最后一个字符
					_message.pop_back();

					// 向终端回显退格
					printf("\b \b");
				}
			}
			else
			{
				printf("*");
				_message += c;
			}
		}
		cout << endl;
		if (check(_id, _message, mp) == 0)
		{
			_id_ = _id;
			cout << "登陆成功" << endl;
			system("pause");
			return 1;
		}
		else if (check(_id, _message, mp) == 1)
		{
			cout << "您的账号与密码不匹配，请重新输入" << endl;
			system("pause");
			continue;
		}
		else
		{
			cout << "该账号不存在，请先注册" << endl;
			system("pause");
			return 0;
		}
	}
}

// 修改个人信息
void retrieve(map<string, User>& mp)
{
	while (1)
	{
	restart:
		system("cls");
		int flag = 0;
		string _id, _name, _birthday;
		cout << "请输入您的账号：" << endl;
		cin >> _id;
		cout << "请输入您的网名：" << endl;
		cin >> _name;
		cout << "请输入您的生日：" << endl;
		cin >> _birthday;

		map<string, User>::iterator it;
		for (it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == _id)
			{
				if (it->second.getName() == _name && it->second.getBirthday() == _birthday)
				{
					flag = 1;
					cout << "请输入新的密码： " << endl;
					string new_message;
					cin >> new_message;
					string new_message_ = "";
					for (int i = 0; i < new_message.size(); i++)
						new_message_ += new_message[(i + 4) % new_message.size()];
					it->second.setMessage(new_message_);
					cout << "密码更新成功，请重新登录" << endl;
					system("pause");
					return;
				}
				else
				{
					cout << "您输入的网名或生日有误，请重新输入" << endl;
					goto restart;
				}
			}
		}
		if (flag == 0)
		{
			cout << "您输入的账号有误，可能您还未注册。" << endl;
			cout << "  1. 重新输入  " << endl;
			cout << "  2. 返回进行注册  " << endl;
			cout << "请输入您的选择： " << endl;
			int choice;
			cin >> choice;

			switch (choice)
			{
			case 1:
				goto restart;
				break;
			case 2:
				return;
			}
		}
	}
}

// 登录页面UI
string login(map<string, User>& mp, int flag)
{
	while (1)
	{
		system("cls");
		cout << "====================================" << endl;
		cout << "-        欢迎来到校园朋友圈        -" << endl;
		cout << "====================================" << endl;
		cout << "-                                  -" << endl;
		cout << "-            1. 登录               -" << endl;
		cout << "-            2. 注册               -" << endl;
		cout << "-            3. 忘记密码           -" << endl;
		cout << "-                                  -" << endl;
		cout << "====================================" << endl;
		cout << "请输入您的选择：" << endl;
		int choice = 0, ans = 10;
		cin >> choice;

		switch (choice)
		{
		case 1:
			ans = check_in(mp);
			break;
		case 2:
			sign_in(mp, flag);
			break;
		case 3:
			retrieve(mp);
			break;
		default:
			cout << "输入错误" << endl;
			break;
		}
		if (ans == 1)
			return _id_;
		else
			continue;
	}
}

//最初
string begin(map<string, User> &mp)
{
	while (1)
	{
		cout << "====================================" << endl;
		cout << "         欢迎进入校园朋友圈         " << endl;
		cout << "====================================" << endl;
		cout << "                                    " << endl;
		cout << "          1. 我是管理员             " << endl;
		cout << "          2. 我是普通用户           " << endl;
		cout << "                                    " << endl;
		cout << "====================================" << endl;
		cout << "请输入您的身份：" << endl;
		int choice;
		string my_id;
		cin >> choice;

		switch (choice)
		{
			case 1:
				my_id = login(mp, choice);
				break;
			case 2:
				my_id = login(mp, choice);
				break;
		}
		return my_id;
	}

}

