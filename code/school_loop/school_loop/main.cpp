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
				getline(is, temp);
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
							content += temp;
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
						while (temp != "*" && !temp.empty())
						{
							getline(is, temp);
							if (temp == "*")
							{
								break;
							}
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

// ����ʱ��mpд�ᵽ���ݿ�
void endWrite(map<string, User>& mp) {

	map<string, User>::iterator pos;
	for (pos = mp.begin(); pos != mp.end(); ++pos)
	{
		string url = (*pos).second.getId();
		url = "data\\" + url + ".txt";

		// ���ļ����������
		ofstream outfile(url, ios::trunc);

		// д���µ�����
		outfile << (*pos).second;

	}

}

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
			case 7:
				endWrite(mp);
				return 0;
		}
	}
}
