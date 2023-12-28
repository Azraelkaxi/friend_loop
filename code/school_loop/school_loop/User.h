#pragma once
#include<iostream>
#include<list>
#include"Moment.h"

using namespace std;

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
	User(string _id, string _message, string _name, string _birthday, list<string> Friend, list<Moments> Circle_of_friends);
	User(const User& s);
	void setId(string newid);
	void setName(string newname);
	void setBirthday(string newbirthday);
	void setMessage(string newmessage);
	void addFriend(string _id);
	void deleteFriend(string _id);
	void addCircle_of_friends(Moments m);
	//void deleteCircle_of_friends(Moments m);
	string getId();
	string getMessage();
	string getName();
	string getBirthday();
	list<string> getFriend();
	list<Moments> getCircle_of_friends();
};

User::~User(){}

User::User()
{
	this->id = "";
	this->message = "";
	this->name = "";
	this->birthday = "";
	this->Friend = {};
	this->Circle_of_friends = {};
}

User::User(const User& s)
{
	this->id = s.id;
	this->birthday = s.birthday;
	this->name = s.name;
	this->message = s.message;
	for (list<string>::const_iterator it = s.Friend.begin(); it != s.Friend.end(); ++it)
		this->Friend.push_back(*it);
	for (list<Moments>::const_iterator it = s.Circle_of_friends.begin(); it != s.Circle_of_friends.end(); ++it)
		this->Circle_of_friends.push_back(*it);
}

User::User(string _id, string _message, string _name, string _birthday, list<string> Friend, list<Moments> Circle_of_friends)
{
	this->id = _id;
	this->message = _message;
	this->name = _name;
	this->birthday = _birthday;
	for (list<string>::iterator it = Friend.begin(); it != Friend.end(); ++it)
		this->Friend.push_back(*it);
	for (list<Moments>::iterator it = Circle_of_friends.begin(); it != Circle_of_friends.end(); ++it)
		this->Circle_of_friends.push_back(*it);
}

void User::setName(string newname)
{
	this->name = newname;
	cout << "�������" << endl;
	system("pause");
}

void User::setBirthday(string newbirthday)
{
	this->birthday = newbirthday;
	cout << "�������" << endl;
	system("pause");
}

void User::setMessage(string newmessage)
{
	this->message = newmessage;
	cout << "�������" << endl;
	system("pause");
}

void User::addFriend(string _id)
{
	list<string>::iterator it;
	for (it = Friend.begin(); it != Friend.end(); ++it)
	{
		if (*it == _id)
		{
			cout << "�����" << endl;
			return ;
		}
	}
	Friend.push_back(_id);
	cout << "��ӳɹ�" << endl;
	system("pause");
}

void User::deleteFriend(string _id)
{
	list<string>::iterator it;
	for (it = Friend.begin(); it != Friend.end(); ++it)
	{
		if (*it == _id)
		{
			list<string>::iterator it2 = ++it;
			if (it2 == Friend.end())
				it2 = Friend.begin();
			Friend.erase(--it);
			it = it2;
			cout << "ɾ���ɹ�" << endl;
			system("pause");
			break;
		}
	}
}

void User::addCircle_of_friends(Moments m)
{
	this->Circle_of_friends.push_back(m);
	cout << "�����ɹ�" << endl;
	system("pause");
}

//void User::deleteCircle_of_friends(Moments m)
//{
//	
//}

string User::getId()
{
	return this->id;
}

string User::getMessage()
{
	return this->message;
}

string User::getBirthday()
{
	return this->birthday;
}

string User::getName()
{
	return this->name;
}

list<string> User::getFriend()
{
	return this->Friend;
}

list<Moments> User::getCircle_of_friends()
{
	return Circle_of_friends;
}