#ifndef __TOOL_H__
#define __TOOL_H__

#include<fstream>
#include<conio.h>
#include<windows.h>
#include"User.h"
#include <map>
using namespace std;

//刷新好友列表
void refresh_friend_list(string my_id, string _id);

//加好友，并返回好友网名
string Add_friend(map<string, User>& mp, string my_id);

//发布朋友圈
void Post_on_moments(map<string, User>& mp, string my_id);

//实现刷朋友圈，待定。
//还可以实现查找某条特定朋友圈，删除朋友圈等
//发布评论 回复某条评论  进行点赞  进行上述动作的同时，要实时更新文本文件
void see_friend_circle(map<string, User>& mp, string my_id);

//查找某条朋友圈

//删除某条朋友圈



//发布评论, 传入参数可更改
void Post_a_review(map<string, User>& mp, string my_id);

//回复某条评论  传入参数可更改
void Reply_to_a_review(map<string, User>& mp, string my_id);

//进行点赞


//实时更新文本文件

//修改信息
void Change(map<string, User>& mp, string my_id);

#endif // !__TOOL_H__
