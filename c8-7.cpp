#include<iostream>
#include<cstdio>
#include<cmath>

using namespace std;

class PrimeNumber {
public:
	PrimeNumber() :prime(1) {};

	PrimeNumber(int prime) :prime(prime) {};

	void setPrime(int prime) {
		this->prime = prime;
	}

	int getPrime() {
		return prime;
	}

	PrimeNumber operator ++();
	PrimeNumber operator --();
	bool isPrime(int num);

private:
	int prime;
};

PrimeNumber PrimeNumber::operator++() {
	int next_num = prime;

	do {
		next_num++;
	} while (!isPrime(next_num));

	return next_num;
}

PrimeNumber PrimeNumber::operator--() {
	int next_num = prime;

	do {
		next_num--;
	} while (!isPrime(next_num) && next_num >= 0);
	if (next_num == 0) {
		cout << "The prime number is the smallest one." << endl;
	}
	return next_num;
}

bool PrimeNumber::isPrime(int num) {
	bool is_prime = true;
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0) {
			is_prime = false;
			break;
		}
	}
	return is_prime;
}

int main(void) {
	PrimeNumber prime_number;
	int prime;

	cout << "Enter a prime number=>" << endl;
	cin >> prime;
	prime_number.setPrime(prime);

	PrimeNumber large = ++prime_number;
	cout << "The next largest prime number is " << large.getPrime() << endl;

	PrimeNumber small = --prime_number;
	if (small.getPrime() != 0) {
		cout << "The next smallest prime number is " << small.getPrime() << endl;
	}

	return 0;
}
