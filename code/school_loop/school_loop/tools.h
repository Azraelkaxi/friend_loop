#ifndef __TOOL_H__
#define __TOOL_H__

#include<fstream>
#include<conio.h>
#include<windows.h>
#include"User.h"
#include <map>
using namespace std;

//ˢ�º����б�
void refresh_friend_list(string my_id, string _id);

//�Ӻ��ѣ������غ�������
string Add_friend(map<string, User>& mp, string my_id);

//��������Ȧ
void Post_on_moments(map<string, User>& mp, string my_id);

//ʵ��ˢ����Ȧ��������
//������ʵ�ֲ���ĳ���ض�����Ȧ��ɾ������Ȧ��
//�������� �ظ�ĳ������  ���е���  ��������������ͬʱ��Ҫʵʱ�����ı��ļ�
void see_friend_circle(map<string, User>& mp, string my_id);

//����ĳ������Ȧ

//ɾ��ĳ������Ȧ



//��������, ��������ɸ���
void Post_a_review(map<string, User>& mp, string my_id);

//�ظ�ĳ������  ��������ɸ���
void Reply_to_a_review(map<string, User>& mp, string my_id);

//���е���


//ʵʱ�����ı��ļ�

//�޸���Ϣ
void Change(map<string, User>& mp, string my_id);

#endif // !__TOOL_H__
