#ifndef __TOOL_H__
#define __TOOL_H__

#include<fstream>
#include<conio.h>
#include<windows.h>
#include"User.h"
#include <map>

//��ʾ��Ϣ
void display(map<string, User> mp, string _id_);
//ˢ�º����б�
void refresh_friend_list(map<string, User> &mp, string my_id, string _id);
//�Ӻ��ѣ������غ�������
string Add_friend(map<string, User>& mp, string my_id);
//ɾ����
void deletefriend(map<string, User> &mp, string my_id);
//��������Ȧ
void Post_on_moments(map<string, User>& mp, string my_id);
//ˢ����Ȧ
void begin_to_see(map<string, User>& mp, string my_id);
//ʵ��ˢ����Ȧ��������
//������ʵ�ֲ���ĳ���ض�����Ȧ��ɾ������Ȧ��
//�������� �ظ�ĳ������  ���е���  ��������������ͬʱ��Ҫʵʱ�����ı��ļ�
void see_friend_circle(map<string, User>& mp, string my_id);
//����ĳ������Ȧ
void query_friend_circle(map<string, User>& mp, string my_id);
//ɾ��ĳ������Ȧ
void delete_friend_circle(map<string, User>& mp, string my_id);
//�޸���Ϣ
void Change(map<string, User>& mp, string my_id);

void Leaderboard(map<string, User>& mp);
#endif // !__TOOL_H__
