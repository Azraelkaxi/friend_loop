#pragma twice
#include <iostream>
#include <list>
#include <iomanip>
#include <time.h>
#include <sstream>
using namespace std;

class Comment;

class Moments
{
public:
	Moments();
	~Moments();
	void setText();
	void setDate();
	void setLikes();
	auto getText();
	auto getDate();
	int getLikes();
	void giveLike();
	void writeComment();
	void writeReply();
	void showComment();
private:
	// �ı�
	string text;
	// ����
	string date;
	// ����
	int likes;
	// ����(list�ṹ�洢)
	list<Comment> comments;
};

class Comment
{
public:
	// ����
	string text;
	// �ظ�
	list<string> reply = {};
};

Moments::Moments()
{

}

Moments::~Moments()
{

}

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
	time_t now = time(nullptr);
	tm* localTime = localtime(&now);
	// �ַ������洢���ں�ʱ��
	stringstream ss;
	ss << setw(4) << setfill('0') << localTime->tm_year + 1900 << "-";
	ss << setw(2) << setfill('0') << localTime->tm_mon + 1 << "-";
	ss << setw(2) << setfill('0') << localTime->tm_mday << " ";
	ss << setw(2) << setfill('0') << localTime->tm_hour << ":";
	ss << setw(2) << setfill('0') << localTime->tm_min;
	time_t now;
	time(&now);
	struct tm localTimeInfo;
	localtime_s(&localTimeInfo, &now);

	stringstream ss;
	ss << setw(4) << std::setfill('0') << localTimeInfo.tm_year + 1900 << "-";
	ss << setw(2) << std::setfill('0') << localTimeInfo.tm_mon + 1 << "-";
	ss << setw(2) << std::setfill('0') << localTimeInfo.tm_mday << " ";
	ss << setw(2) << std::setfill('0') << localTimeInfo.tm_hour << ":";
	ss << setw(2) << std::setfill('0') << localTimeInfo.tm_min;

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
