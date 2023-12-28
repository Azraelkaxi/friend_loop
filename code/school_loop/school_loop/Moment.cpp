#include "Moment.h"
#define _CRT_SECURE_NO_WARNINGS 1

Moments::Moments() {}

Moments::Moments(string t, string d, int l, list<Comment> comments)
{
	text = t;
	date = d;
	likes = l;
	for (list<Comment>::iterator it = comments.begin(); it != comments.end(); ++it)
	{
		this->comments.push_back(*it);
	}
}

Moments::~Moments() {}

void Moments::setText()
{
	cout << "��һ�̵��뷨:" << endl;
	string s;
	cin >> s;
	text = s;
	setLikes();
	setDate();
}

void Moments::setDate()
{
	time_t now = time(0);
	tm* localTime = localtime(&now);
	stringstream ss;
	ss << localTime->tm_year + 1900 << "-" << setfill('0') << setw(2) << localTime->tm_mon + 1 << "-" << setfill('0') << setw(2) << localTime->tm_mday << " " << setfill('0') << setw(2) << localTime->tm_hour << ":" << setfill('0') << setw(2) << localTime->tm_min;
	date = ss.str();
}

void Moments::setLikes()
{
	likes = 0;
}

auto Moments::getText()
{
	return text;
}

auto Moments::getDate()
{
	return date;
}

int Moments::getLikes()
{
	return likes;
}

void Moments::giveLike()
{
	likes++;
	cout << "���޳ɹ�" << endl;
}

void Moments::writeComment()
{
	string s;
	cout << "����������:" << endl;
	cin >> s;
	comments.push_back({ s });
}

void Moments::writeReply()
{
	string s;
	cout << "������ظ�" << endl;
	cin >> s;
	comments.back().reply.push_back(s);
}

void Moments::showComment()
{
	if (comments.empty())
	{
		cout << "��������" << endl;
		return;
	}

	cout << "�����б�" << endl;
	int commentIndex = 1;
	for (auto commentIt = comments.begin(); commentIt != comments.end(); ++commentIt)
	{
		const Comment& comment = *commentIt;
		cout << "����" << commentIndex << ": " << comment.text << endl;
		if (!comment.reply.empty())
		{
			cout << "�ظ��б�" << endl;
			int replyIndex = 1;
			for (auto replyIt = comment.reply.begin(); replyIt != comment.reply.end(); ++replyIt)
			{
				const string& reply = *replyIt;
				cout << "�ظ�" << replyIndex << ": " << reply << endl;
				++replyIndex;
			}
		}
		++commentIndex;
	}
}
ostream& operator<<(ostream& o, const Moments& m)
{
	o << "#" << endl;
	o << m.text << endl;
	o << "#" << endl;
	o << m.likes << endl;
	o << m.date << endl;
	o << "#" << endl;
	int commentIndex = 1;
	for (auto commentIt = m.comments.begin(); commentIt != m.comments.end(); ++commentIt)
	{
		const Comment& comment = *commentIt;
		o << "����" << commentIndex << ": " << comment.text << endl;
		if (!comment.reply.empty())
		{
			int replyIndex = 1;
			for (auto replyIt = comment.reply.begin(); replyIt != comment.reply.end(); ++replyIt)
			{
				const string& reply = *replyIt;
				o << "�ظ�" << replyIndex << ": " << reply << endl;
				++replyIndex;
			}
			o << endl;
		}
		++commentIndex;
	}
	o << "*" << endl;
	return o;
}
int main()
{
	Moments m1;
	m1.setText();
	m1.writeComment();
	m1.writeReply();
	m1.giveLike();
	cout << m1;
	m1.showComment();
}