#include<iostream>
#include<cstdlib>
#include"Administrator.h"

bool Administrator::Login(string username, string password) {
	if (Security::validate(username, password) == 1) {
		return true;
	}
	return false;
}