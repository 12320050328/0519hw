#include<iostream>
#include<cstdlib>
#include<cctype>
#include<string>

using namespace std;

int main(void) {
	string sentence;
	char answer;
	int count = 0;

	do {
		cout << "Enter a sentence and it will replace four-letter words for all with 'love'.=>" << endl;
		getline(cin, sentence);
		for (int i = 0; i < sentence.length(); i++) {
			if (isalpha(sentence[i])) {
				count++;
			}
			else {
				if (count == 4) {
					if (isupper(sentence[i - 4])) {
						sentence[i - 4] = 'L';
					}
					else {
						sentence[i - 4] = 'l';
					}
					sentence[i - 3] = 'o';
					sentence[i - 2] = 'v';
					sentence[i - 1] = 'e';
				}
				count = 0;
			}
		}
		cout << sentence << endl;

		cout << "Enter 'y' to continue or any other key word to quit=>" << endl;
		cin >> answer;

		char clear;
		do {
			cin.get(clear);
		} while (clear != '\n');
	} while (answer == 'y' || answer == 'Y');

	return 0;
}