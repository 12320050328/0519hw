#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>

using namespace std;

class Subscriber {
public:
	Subscriber() :numChannels(0) { channalList = new vector<string>(); }
	Subscriber(string name) :name(name), numChannels(0) { channalList = new vector<string>(); }
	~Subscriber() { delete channalList; }
	string getName() {
		return name;
	}

	int getNumChannels() {
		return numChannels;
	}
	vector<string>* getChannalList() {
		return channalList;
	}
	void setName(string name) {
		this->name = name;
	}
	void setNumChannels(int numChannels) {
		this->numChannels = numChannels;
	}
	void setChannelList(vector<string>channalList) {
		this->channalList = &channalList;
	}
	void inputData();
	void outputData();
	void resetData();
	vector<string> operator =(vector<string> newList);
private:
	string name;
	int numChannels;
	vector<string>* channalList;
};

void Subscriber::inputData() {
	string temp;

	cout << "Enter the subscriber's name=>" << endl;
	getline(cin, name);

	cout << "Enter the name of the channels which the subscriber subscribes to (use -9999 to stop)=>" << endl;
	getline(cin, temp);

	while (temp != "-9999") {
		channalList->push_back(temp);
		getline(cin, temp);
	}

	numChannels = channalList->size();
}
void Subscriber::outputData() {
	cout << "The subscriber's name: " << name << endl;
	cout << "The number of channels which the subscriber subscribers to: " << numChannels << endl;
	cout << "The channel names which the subscriber subscribes to: " << endl;
	for (int i = 0; i < numChannels; i++) {
		cout << channalList->at(i) << endl;
	}
}
void Subscriber::resetData() {
	numChannels = 0;
	channalList->clear();
}
vector<string> Subscriber::operator =(vector<string> newList) {
	string tmp;
	for (int i = 0; i < numChannels; i++) {
		tmp = channalList->at(i);
		channalList->push_back(tmp);
	}
	return newList;
}

int main(void) {
	Subscriber subs;
	char copy;
	vector <string>* list;

	subs.inputData();

	subs.outputData();
	cout << endl;

	cout << "Do you want to copy the channel list(enter y or n)=>" << endl;
	cin >> copy;
	if (copy == 'y') {
		list = subs.getChannalList();

		cout << "The new channel list is: " << endl;
		for (int i = 0; i < list->size(); i++) {
			cout << list->at(i) << endl;
		}
	}

	subs.resetData();

	return 0;
}