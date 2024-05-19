#include<iostream>
#include<cstdlib>
#include<vector>
#include<string>
using namespace std;

class Television{
public:
	Television() :dimension(0) {};

	Television(string displayType, double dimension, vector<string>connectivitySupport) : displayType(displayType), dimension(dimension), connectivitySupport(connectivitySupport) {};
	Television(const Television& t);

	void setDisplayType(string displatType) {
		this->displayType = displatType;
	}

	void setDimension(double dimension) {
		this->dimension = dimension;
	}

	void setConncetivitySupport(vector<string>connectivitySupport) {
		this->connectivitySupport = connectivitySupport;
	}

	string getDisplayType() {
		return displayType;
	}

	double getDimension() {
		return dimension;
	}

	vector<string>getConnectivitySupport() {
		return connectivitySupport;
	}

	void inputData();
	void outputData();
private:
	string displayType;
	double dimension;
	vector<string> connectivitySupport;
};

Television::Television(const Television& t) {
	displayType = t.displayType;
	dimension = t.dimension;
	connectivitySupport = t.connectivitySupport;
}
void Television::inputData() {
	string mode;

	cout << "Enter the display type of the television=>" << endl;
	cin >> displayType;

	do {
		cout << "Enter the dimension of the televisionin inches=>" << endl;
		cin >> dimension;
	} while (dimension <= 0);

	cout << "Enter the different connectivity modes supported by television(use -9999 to stop)=>" << endl;
	cin >> mode;
	while (mode != "-9999") {
		connectivitySupport.push_back(mode);
		cin >> mode;
	}
}
void Television::outputData() {
	cout << "Display type: " << displayType << endl;
	cout << "Dimension: " << dimension << " inches" << endl;
	cout << "Connectivity modes: " << endl;
	for (int i = 0; i < connectivitySupport.size(); i++) {
		cout << connectivitySupport[i] << endl;
	}
	cout << "-----------------------" << endl;
}

int main(void) {
	Television television1, television2;
	vector<Television> televisionCopy;
	int num, total, part;
	char costomization;
	string displayType, mode;
	double dimension;
	vector<string> connectivitySupport;

	television1.inputData();
	television1.outputData();

	do {
		cout << "Enter how many televisions do you want to copy=>" << endl;
		cin >> total;
	} while (total < 0);

	for (int i = 0; i < total; i++) {
		television2 = television1;
		televisionCopy.push_back(television2);

		cout << "Television " << i + 2 << ":" << endl;
		televisionCopy[i].outputData();
	}

	cout << "Is costomization required for any television? (enter y or n)=>" << endl;
	cin >> costomization;
	while (costomization == 'y') {
		do {
			cout << "Which television do you want to change=>" << endl;
			cin >> num;
		} while (num > total + 1);

		do {
			cout << "Which part do you want to change (display type input 1, dimension input 2, connectivity support input 3=>" << endl;
			cin >> part;
		} while (part < 1 || part>3);

		if (part == 1) {
			cout << "Enter the display type of the television=>" << endl;
			cin >> displayType;
			televisionCopy[num - 2].setDisplayType(displayType);
		}
		else if (part == 2) {
			do {
				cout << "Enter the dimension of the television in inches=>" << endl;
				cin >> dimension;
			} while (dimension <= 0);
			televisionCopy[num - 2].setDimension(dimension);
		}
		else {
			cout << "Enter the different connectivity modes supported by the television(use -9999 to stop)=>" << endl;
			cin >> mode;
			while (mode != "-9999") {
				connectivitySupport.push_back(mode);
				cin >> mode;
			}
			televisionCopy[num - 2].setConncetivitySupport(connectivitySupport);
		}

		cout << "The information for the television " << num << ":" << endl;
		televisionCopy[num - 2].outputData();

		cout << "Is costomization required for any television?(y or n)" << endl;
		cin >> costomization;
	}

	cout << "Television 1:" << endl;
	television1.outputData();
	for (int i = 0; i < total; i++) {
		cout << "Television " << i + 2 << ":" << endl;
		televisionCopy[i].outputData();
	}

	return 0;
}