#ifndef __MOMENT_H__
#define __MOMENT_H__
#include<vector>
#include <iostream>
#include <list>
#include <iomanip>
#include <time.h>
#include <sstream>
#include<windows.h>
using namespace std;
class Comment;

class Moments
{
public:
	Moments();
	Moments(string t, string d, int l, list<Comment> comments);
	Moments(string t, string d, int l);
	~Moments();
	Moments(const Moments& t);
	void setText();
	void setText(string s);
	void setDate();
	void setDate(string s);
	void setLikes();
	void setLikes(int x);
	string getText();
	string getDate();
	list<Comment> getComments();
	int getLikes();
	void giveLike();
	void writeComment();
	void writeComment(string s);
	void writeReply(int num);
	void writeReply(string s);
	void showComment();
	friend ostream& operator<<(ostream& o, const Moments &m);
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
	string text = "";
	// 回复
	list<string> reply = {};
};




#endif // !__MOMENT_H__;


