#include<iostream>
#include<cstdlib>
#include<cmath>

using namespace std;

class MyInteger {
private:
	int integer;
public:
	MyInteger() :integer(0) {};  //
	MyInteger(int integer) :integer(integer) {};
	void setInteger(int integer) {
		this->integer = integer;
	}
	int getInteger() {
		return integer;
	}
	int operator[](int index);
};
int MyInteger::operator[](int index) {
	int size = 0;
	int replace = integer;
	int target = 0;
	int left, right;

	do {
		replace = replace / 10;
		size++;
	} while (replace != 0);

	if (index >= size) {
		cout << "It's not in the range." << endl;
		return -1;  
	}

	left = pow(10, index + 1);
	target = integer % left;

	right = pow(10, index);
	target = target / right;

	return target;
}
int main(void) {
	MyInteger integer1;
	int num, index;

	cout << "Enter the integer=>" << endl;
	cin >> num;
	integer1.setInteger(num);

	cout << "Enter the index of the digit=>" << endl;
	cin >> index;

	if (integer1[index] != -1) {
		cout << "The digit of the index is " << integer1[index] << endl;
	}

	return 0;
}