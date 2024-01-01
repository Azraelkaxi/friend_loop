#include"login.h"

// ���ص�ʹ����id
string _id_;

// ��¼�˺ŵĵ�ַ
const string URL = "data\\У԰����Ȧ�˺���Ϣ.txt";

// �ж��˺��Ƿ��Ѵ���
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

// �����˺���Ϣ
void save_id_message(string _id, string _message, map<string, User>& mp)
{
	// ���˺���Ϣ����������˺�(׷��д��)
	ofstream ofs(URL, ios::app);
	ofs << _id << endl;
	ofs.close();
	//ʵʱ����map
	list<string> Friend = {};
	list<Moments> Circle_of_friends = {};
	string _message_ = "";
	for (int i = 0; i < _message.size(); i++)
	{
		_message_ += _message[(i + 4) % _message.size()];
	}
	User user(_id, _message_, Friend, Circle_of_friends);
	mp.insert(make_pair(_id, user));

	// ��data�¿�һ���洢���˺ŵ�����
	string file_name = "data\\" + _id + ".txt";
	ofstream outFile(file_name, ios_base::out);
	/*
	д��Ĭ�ϵ�User����Ϣ
	(��ǰ��������)
	*/
	outFile << user;
	outFile.close();

}

// ע��
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
			cout << "��������Ҫע����˺�(ѧ��)��" << endl;
			cin >> _id;
			cout << "����������(��֧����ĸ������)��" << endl;
			while (1)
			{
				char c = _getch();//getch()�������ն˻����ַ�
				if (c == '\r')
				{
					break;
				}
				else if (c == '\b') {  // Backspace��
					if (!_message.empty()) {
						// ɾ�����һ���ַ�
						_message.pop_back();

						// ���ն˻����˸�
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
			cout << "��ȷ������(��֧����ĸ������): " << endl;
			while (1)
			{
				char c = _getch();//getch()�������ն˻����ַ�
				if (c == '\r')
				{
					break;
				}
				else if (c == '\b') {  // Backspace��
					if (!_message.empty()) {
						// ɾ�����һ���ַ�
						_message.pop_back();

						// ���ն˻����˸�
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
					cout << "���˺��Ѵ��ڣ���ֱ�ӵ�¼" << endl;
					system("pause");
					break;
				}
				save_id_message(_id, _message, mp);
				cout << "���ѳɹ�ע�ᣬ���¼" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "������������벻һ�£�������ע��" << endl;
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
			cout << "��������Ҫע����˺�(gly+ѧ��)��" << endl;
			cin >> _id;
			cout << "����������(��֧����ĸ������)��" << endl;
			while (1)
			{
				char c = _getch();//getch()�������ն˻����ַ�
				if (c == '\r')
				{
					break;
				}
				else if (c == '\b') {  // Backspace��
					if (!_message.empty()) {
						// ɾ�����һ���ַ�
						_message.pop_back();

						// ���ն˻����˸�
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
			cout << "��ȷ������(��֧����ĸ������): " << endl;
			while (1)
			{
				char c = _getch();//getch()�������ն˻����ַ�
				if (c == '\r')
				{
					break;
				}
				else if (c == '\b') {  // Backspace��
					if (!_message.empty()) {
						// ɾ�����һ���ַ�
						_message.pop_back();

						// ���ն˻����˸�
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
					cout << "���˺��Ѵ��ڣ���ֱ�ӵ�¼" << endl;
					system("pause");
					break;
				}
				save_id_message(_id, _message, mp);
				cout << "���ѳɹ�ע�ᣬ���¼" << endl;
				system("pause");
				break;
			}
			else
			{
				cout << "������������벻һ�£�������ע��" << endl;
				system("pause");
				continue;
			}
		}
	}
}

// ����˺ź������Ƿ�ƥ��
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

// ��¼
int check_in(map<string, User>& mp)
{
	string _id, _message = "";
	while (1)
	{
		cout << "�����������˺� ��" << endl;
		cin >> _id;
		cout << "�������������� ��" << endl;
		_message = "";
		while (1)
		{
			
			char c = _getch();//getch()�������ն˻����ַ�
			if (c == '\r')
			{
				break;
			}
			else if (c == '\b') {  // Backspace��
				if (!_message.empty()) {
					// ɾ�����һ���ַ�
					_message.pop_back();

					// ���ն˻����˸�
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
			cout << "��½�ɹ�" << endl;
			system("pause");
			return 1;
		}
		else if (check(_id, _message, mp) == 1)
		{
			cout << "�����˺������벻ƥ�䣬����������" << endl;
			system("pause");
			continue;
		}
		else
		{
			cout << "���˺Ų����ڣ�����ע��" << endl;
			system("pause");
			return 0;
		}
	}
}

// �޸ĸ�����Ϣ
void retrieve(map<string, User>& mp)
{
	while (1)
	{
	restart:
		system("cls");
		int flag = 0;
		string _id, _name, _birthday;
		cout << "�����������˺ţ�" << endl;
		cin >> _id;
		cout << "����������������" << endl;
		cin >> _name;
		cout << "�������������գ�" << endl;
		cin >> _birthday;

		map<string, User>::iterator it;
		for (it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == _id)
			{
				if (it->second.getName() == _name && it->second.getBirthday() == _birthday)
				{
					flag = 1;
					cout << "�������µ����룺 " << endl;
					string new_message;
					cin >> new_message;
					string new_message_ = "";
					for (int i = 0; i < new_message.size(); i++)
						new_message_ += new_message[(i + 4) % new_message.size()];
					it->second.setMessage(new_message_);
					cout << "������³ɹ��������µ�¼" << endl;
					system("pause");
					return;
				}
				else
				{
					cout << "�������������������������������" << endl;
					goto restart;
				}
			}
		}
		if (flag == 0)
		{
			cout << "��������˺����󣬿�������δע�ᡣ" << endl;
			cout << "  1. ��������  " << endl;
			cout << "  2. ���ؽ���ע��  " << endl;
			cout << "����������ѡ�� " << endl;
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

// ��¼ҳ��UI
string login(map<string, User>& mp, int flag)
{
	while (1)
	{
		system("cls");
		cout << "====================================" << endl;
		cout << "-        ��ӭ����У԰����Ȧ        -" << endl;
		cout << "====================================" << endl;
		cout << "-                                  -" << endl;
		cout << "-            1. ��¼               -" << endl;
		cout << "-            2. ע��               -" << endl;
		cout << "-            3. ��������           -" << endl;
		cout << "-                                  -" << endl;
		cout << "====================================" << endl;
		cout << "����������ѡ��" << endl;
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
			cout << "�������" << endl;
			break;
		}
		if (ans == 1)
			return _id_;
		else
			continue;
	}
}

//���
string begin(map<string, User> &mp)
{
	while (1)
	{
		cout << "====================================" << endl;
		cout << "         ��ӭ����У԰����Ȧ         " << endl;
		cout << "====================================" << endl;
		cout << "                                    " << endl;
		cout << "          1. ���ǹ���Ա             " << endl;
		cout << "          2. ������ͨ�û�           " << endl;
		cout << "                                    " << endl;
		cout << "====================================" << endl;
		cout << "������������ݣ�" << endl;
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

