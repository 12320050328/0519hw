#include<iostream>
#include<cstdlib>
#include "Administrator.h"
#include "User.h"

using namespace std;

int main(void) {
	string username, password;
	char choose;
	Administrator admin;
	User user;

	cout << "Choose A administrator or B user or any other key to exit=>" << endl;
	cin >> choose;
	while (choose == 'A' || choose == 'B') {
		cout << "Enter the username=>" << endl;
		cin >> username;
		cout << "Enter the password=>" << endl;
		cin >> password;

		if (choose == 'A') {
			if (admin.Login(username, password)) {
				cout << "Input correct." << endl;
			}
			else {
				cout << "The username or password is incorrect." << endl;
			}
		}
		else {
			if (user.Login(username, password)) {
				cout << "Input correct." << endl;
			}
			else {
				cout << "The username or password is incorrect." << endl;
			}
		}

		cout << "Choose A administrator or B user or any other key to exit=>" << endl;
		cin >> choose;
	}

	return 0;
}