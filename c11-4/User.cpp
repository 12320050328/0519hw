#include<iostream>
#include<cstdlib>
#include"User.h"

bool User::Login(string username, string password) {
	//if validate return 1, the person is administrator
	//if validate return 2, the person is user
	if (Security::validate(username, password) == 1 || Security::validate(username, password) == 2) {
		return true;
	}
	return false;
}