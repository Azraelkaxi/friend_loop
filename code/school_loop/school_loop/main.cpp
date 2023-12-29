#define _CRT_SECURE_NO_WARNINGS 
#include"User.h"
#include"login.h"
#include"tools.h"
#include<map>

// ��ʼ��mp
void Init(map<string, User>& mp)
{
	string URL = "data\\У԰����Ȧ�˺���Ϣ.txt";
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
				cout << "�ļ���ʧ��" << endl;
			}
			else
			{
				User t;
				string temp;
				// ��ȡ������Ϣ
				getline(is, temp);
				t.setID(temp);
				getline(is, temp);
				t.setMessage(temp);
				getline(is, temp);
				t.setName(temp);
				getline(is, temp);
				t.setBirthday(temp);

				// ��ȡ�����б�
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

				// ������Ȧ����Ϣ
				getline(is, temp );
				while (temp == "#")
				{
					Moments moment;
					string content = "";
					
					// ����
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

					// ���޺�����
					getline(is, temp);
					moment.setLikes(atoi(temp.c_str()));
					getline(is, temp);
					moment.setDate(temp);

					// ����
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

					// �����Ƿ�����һ������Ȧ
					getline(is, temp);

				}

				// ��������user������뵽mp��
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
				Change(mp, my_id);
				break;
			case 5:
				return 0;
		}
	}
}
