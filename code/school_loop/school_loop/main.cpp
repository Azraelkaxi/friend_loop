#include"User.h"
#include"login.h"
#include<map>
int main()
{
	map<string, User> mp;

	while (1)
	{
		login(mp);
	}
}
