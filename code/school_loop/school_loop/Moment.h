#pragma twice

#include <iostream>
#include <list>
#include <iomanip>
#include <ctime>
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
	// 文本
	string text;
	// 日期
	string date;
	// 点赞
	int likes;
	// 评论(list结构存储)
	list<Comment> comments;
};

class Comment 
{
public:
	// 评论
	string text;
	// 回复
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
	cout << "这一刻的想法:" << endl;
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
	// 字符串流存储日期和时间
	stringstream ss;
	ss << setw(4) << setfill('0') << localTime->tm_year + 1900 << "-";
	ss << setw(2) << setfill('0') << localTime->tm_mon + 1 << "-";
	ss << setw(2) << setfill('0') << localTime->tm_mday << " ";
	ss << setw(2) << setfill('0') << localTime->tm_hour << ":";
	ss << setw(2) << setfill('0') << localTime->tm_min;
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
	cout << "点赞成功" << endl;
}

void Moments::writeComment() 
{
	string s;
	cout << "请输入评论:" << endl;
	cin >> s;
	comments.push_back({s});
}

void Moments::writeReply() 
{
	string s;
	cout << "请输入回复" << endl;
	cin >> s;
	comments.back().reply.push_back(s);
}

void Moments::showComment() 
{
	if (comments.empty()) 
	{
		cout << "暂无评论" << endl;
		return;
	}
	
	cout << "评论列表：" << endl;
	int commentIndex = 1;
	for (auto commentIt = comments.begin(); commentIt != comments.end(); ++commentIt) 
	{
		const Comment& comment = *commentIt;
		cout << "评论" << commentIndex << ": " << comment.text << endl;	
		if (!comment.reply.empty())
		{
			cout << "回复列表：" << endl;
			int replyIndex = 1;
			for (auto replyIt = comment.reply.begin(); replyIt != comment.reply.end(); ++replyIt) 
			{
				const string& reply = *replyIt;
				cout << "回复" << replyIndex << ": " << reply << endl;
				++replyIndex;
			}
		}	
		++commentIndex;
	}
}

