#pragma once
#include"Moment.h"


class User
{
private:
	string id;//学号 账号
	string message;//密码
	list<string> Friend; //好友列表，存储好友学号
	list<Moments> Circle_of_friends;//朋友圈
	string name;//网名
	string birthday;//生日
public:
	User();
	~User();
	User(string _id, string _message, list<string> Friend, list<Moments> Circle_of_friends);
	User(const User& s);
	void setID(string newid);
	void setName(string newname);
	void setBirthday(string newbirthday);
	void setMessage(string newmessage);
	void addFriend(string _id);
	void deleteFriend(string _id);
	void addCircle_of_friends(Moments m);
	//void deleteCircle_of_friends(Moments m);
	string& getId();
	string& getMessage();
	string& getName();
	string& getBirthday();
	list<string>& getFriend();
	list<Moments>& getCircle_of_friends();
	friend ostream& operator<<(ostream& o, const User &m);
};

