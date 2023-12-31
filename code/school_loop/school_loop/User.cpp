#include"User.h"
#include<stdlib.h>

User::~User() {}

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

User::User(string _id, string _message, list<string> Friend, list<Moments> Circle_of_friends)
{
	string _birthday = "XXXX-XX-XX";
	this->id = _id;
	this->message = _message;
	vector<string> v = { "0", "1", "2", "3", "4", "5", "6", "7", "8", "9" };
	string _name = "";
	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++)
	{
		int index = rand() % 10;
		_name += v[index];
	}
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
}

void User::setBirthday(string newbirthday)
{
	this->birthday = newbirthday;
}

void User::setMessage(string newmessage)
{
	this->message = newmessage;
}

void User::setID(string newid)
{
	this->id = newid;
}

void User::addFriend(string _id)
{
	list<string>::iterator it;
	for (it = Friend.begin(); it != Friend.end(); ++it)
	{
		if (*it == _id)
		{
			cout << "您已经添加过对方" << endl;
			system("pause");
			return;
		}
	}
	Friend.push_back(_id);
	cout << "添加成功" << endl;
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
			cout << "删除成功" << endl;
			system("pause");
			break;
		}
	}
}

void User::addCircle_of_friends(Moments m)
{
	this->Circle_of_friends.push_back(m);
	cout << "发布成功" << endl;
	system("pause");
}


string& User::getId()
{
	return this->id;
}

string& User::getMessage()
{
	return this->message;
}

string& User::getBirthday()
{
	return this->birthday;
}

string& User::getName()
{
	return this->name;
}

list<string>& User::getFriend()
{
	return this->Friend;
}

list<Moments>& User::getCircle_of_friends()
{
	return Circle_of_friends;
}

ostream& operator<<(ostream& o, const User &m)
{
	o << m.id << endl;
	o << m.message << endl;
	o << m.name << endl;
	o << m.birthday << endl;
	o << "#" << endl;
	list<string> str = m.Friend;
	list<string>::iterator it;
	for (it = str.begin(); it != str.end(); ++it)
	{
		o << *it << endl;
	}
	o << "*" << endl;
	list<Moments> moments = m.Circle_of_friends;
	list<Moments>::iterator mm;
	for (mm = moments.begin(); mm != moments.end(); ++mm)
	{
		o << *mm;
	}
	return o;
}