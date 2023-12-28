#include"tools.h"

//刷新好友列表
void refresh_friend_list(string my_id, string _id);

//加好友，并返回好友网名
string Add_friend(map<string, User> &mp, string my_id)
{
	while (1)
	{
		system("cls");
		cout << "请输入学号" << endl;
		string _id;
		cin >> _id;
		//todo:考虑是否已经加过并反馈信息给用户
		//以下是假设已经考虑过
		for (map<string, User>::iterator it = mp.begin(); it != mp.end(); ++it)
		{
			if (it->first == _id)
			{
				cout << "已经找到该人" << endl;
				Sleep(1000);
				//刷新好友列表
				//refresh_friend_list(my_id, _id);
				return it->second.getName();
			}
		}
		return "NotFound";
	}
}

//发布朋友圈
void Post_on_moments(map<string, User> &mp, string my_id)
{
	system("cls");
	cout << "请输入您要发布的朋友圈内容：" << endl;
	string _text;
	cin >> _text;
	//写入操作，待定  时间自动获取  点赞默认为0
	string title = my_id + ".txt";
	ofstream ofs(title, ios::app);
	ofs << "0" << endl;
	ofs << _text << endl;
	ofs << "1" << endl;

	ofs.close();
	cout << "发布成功" << endl;
	system("pause");
}

//实现刷朋友圈，待定。
//还可以实现查找某条特定朋友圈，删除朋友圈等
//发布评论 回复某条评论  进行点赞  进行上述动作的同时，要实时更新文本文件
void see_friend_circle(map<string, User>& mp, string my_id)
{
}


//查找某条朋友圈

//删除某条朋友圈



//发布评论, 传入参数可更改
void Post_a_review(map<string, User>& mp, string my_id);

//回复某条评论  传入参数可更改
void Reply_to_a_review(map<string, User>& mp, string my_id);

//进行点赞


//实时更新文本文件