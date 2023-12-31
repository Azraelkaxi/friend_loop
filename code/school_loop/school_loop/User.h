#pragma once
#include"Moment.h"


class User
{
private:
	string id;//ѧ�� �˺�
	string message;//����
	list<string> Friend; //�����б��洢����ѧ��
	list<Moments> Circle_of_friends;//����Ȧ
	string name;//����
	string birthday;//����
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

