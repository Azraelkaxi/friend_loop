#include"tools.h"

//ˢ�º����б�
void refresh_friend_list(string my_id, string _id);

//�Ӻ��ѣ������غ�������
string Add_friend(map<string, User> &mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "������ѧ��" << endl;
		string _id;
		cin >> _id;
		//todo:�����Ƿ��Ѿ��ӹ���������Ϣ���û�
		//�����Ǽ����Ѿ����ǹ�
		for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == _id)
			{
				cout << "�Ѿ��ҵ�����" << endl;
				Sleep(1000);
				//ˢ�º����б�
				//refresh_friend_list(my_id, _id);
				return it->second.getName();
			}
		}
		return "NotFound";
	}
}

//��������Ȧ
void Post_on_moments(map<string, User> &mp, string my_id)
{
	system("cls");
	cout << "��������Ҫ����������Ȧ���ݣ�" << endl;
	string _text;
	cin >> _text;
	//д�����������  ʱ���Զ���ȡ  ����Ĭ��Ϊ0
	string title = my_id + ".txt";
	ofstream ofs(title, ios::app);
	ofs << "0" << endl;
	ofs << _text << endl;
	ofs << "1" << endl;

	ofs.close();
	cout << "�����ɹ�" << endl;
	system("pause");
}

//ʵ��ˢ����Ȧ��������
//������ʵ�ֲ���ĳ���ض�����Ȧ��ɾ������Ȧ��
//�������� �ظ�ĳ������  ���е���  ��������������ͬʱ��Ҫʵʱ�����ı��ļ�
void see_friend_circle(map<string, User>& mp, string my_id)
{
}


//����ĳ������Ȧ

//ɾ��ĳ������Ȧ



//��������, ��������ɸ���
void Post_a_review(map<string, User>& mp, string my_id);

//�ظ�ĳ������  ��������ɸ���
void Reply_to_a_review(map<string, User>& mp, string my_id);

//���е���


//ʵʱ�����ı��ļ�