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

Moments::Moments(string t, string d, int l)
{
	text = t;
	date = d;
	likes = l;
	
}


Moments::~Moments() {}

Moments::Moments(const Moments& _t) {
	text = _t.text;
	date = _t.date;
	likes = _t.likes;
	for (auto it = _t.comments.begin(); it != _t.comments.end(); ++it)
	{
		this->comments.push_back(*it);
	}
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

void Moments::setText(string s)
{
	text = s;
}

void Moments::setDate()
{
	time_t now = time(0);
	tm localTime;
	localtime_s(&localTime, &now);
	stringstream ss;
	ss << localTime.tm_year + 1900 << "-" << setfill('0') << setw(2) << localTime.tm_mon + 1 << "-" << setfill('0') << setw(2) << localTime.tm_mday << " " << setfill('0') << setw(2) << localTime.tm_hour << ":" << setfill('0') << setw(2) << localTime.tm_min;
	date = ss.str();
}

void Moments::setDate(string s)
{
	date = s;
}

void Moments::setLikes()
{
	likes = 0;
}

void Moments::setLikes(int x)
{
	likes = x;
}

string Moments::getText()
{
	return text;
}

string Moments::getDate()
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
	comments.push_back({ s });
}

void Moments::writeComment(string s)
{
	comments.push_back({ s });
}

void Moments::writeReply(int num)
{
	string s;
	cout << "请输入回复" << endl;
	cin >> s;
	list<Comment>::iterator it = this->comments.begin();
	while (--num)
	{
		++it;
	}
	it->reply.push_back(s);
	//comments.back().reply.push_back(s);
}

void Moments::writeReply(string s)
{
	comments.back().reply.push_back(s);
}

list<Comment> Moments::getComments()
{
	return this->comments;
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

ostream& operator<<(ostream& o, const Moments& m)
{
	o << "#" << endl;
	o << m.text << endl;
	o << "#" << endl;
	o << m.likes << endl;
	o << m.date << endl;
	o << "#" << endl;
	for (auto commentIt = m.comments.begin(); commentIt != m.comments.end(); ++commentIt)
	{
		const Comment& comment = *commentIt;
		o << comment.text;
		if (!comment.text.empty())
		{
			o << endl;
		}
		if (!comment.reply.empty())
		{
			for (auto replyIt = comment.reply.begin(); replyIt != comment.reply.end(); ++replyIt)
			{
				const string& reply = *replyIt;
				o << reply << endl;
			}
		}
	}
	o << "*" << endl;
	return o;
}
