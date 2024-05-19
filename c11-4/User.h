#ifndef USER_H
#define USER_H

#include "Security.h"
#include<string>
using namespace std;

class User {
public:
	bool Login(string username, string password);

};

#endif