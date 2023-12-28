#include "Moment.h"


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
	struct tm localTime;
	time_t now = time(0);
	localtime_s(&localTime, &now);
	stringstream ss;
	ss << localTime.tm_year + 1900 << "-" << setfill('0') << setw(2) << localTime.tm_mon + 1 << "-" << setfill('0') << setw(2) << localTime.tm_mday << " " << setfill('0') << setw(2) << localTime.tm_hour << ":" << setfill('0') << setw(2) << localTime.tm_min;
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

	cout << "�����б���" << endl;
	int commentIndex = 1;
	for (auto commentIt = comments.begin(); commentIt != comments.end(); ++commentIt)
	{
		const Comment& comment = *commentIt;
		cout << "����" << commentIndex << ": " << comment.text << endl;
		if (!comment.reply.empty())
		{
			cout << "�ظ��б���" << endl;
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