#ifndef __LOGIN_H__
#define __LOGIN_H__
#include<conio.h>
#include<windows.h>
#include<fstream>
#include<map>
#include"User.h"


bool queryMessage(string _id);

void save_id_message(string _id, string _message, map<string, User>& mp);

void sign_in(map<string, User>& mp, int flag);

int check(string _id, string _message, map<string, User>& mp);

int check_in(map<string, User>& mp);

void retrieve(map<string, User>& mp);

string login(map<string, User>& mp, int flag);

string begin(map<string, User>& mp);


#endif // !__LOGIN_H__

