#include<iostream>
#include<cstdlib>
#include"Security.h"

int Security::validate(string username, string password) {
	//if username is abbott and password is monday, this person is an administrator
	if ((username == "abbott") && (password == "monday")) {
		return 1;
	}
	//if username is costello and password is tuesday, this person is a user
	if ((username == "costello") && (password == "tuesday")) {
		return 2;
	}
	return 0;
}