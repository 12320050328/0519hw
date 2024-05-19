#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include"Security.h"
#include<string>
using namespace std;

class Administrator {
public:
	bool Login(string username, string password);
};
#endif