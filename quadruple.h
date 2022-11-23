#include<string>
#include<iostream>
using namespace std;
class quad {
public:
	string q[4];
	quad(string a[4]) {
		for (int i = 0; i < 4; i++) {
			q[i] = a[i];
		}
	}
	void show() {
		cout << "(";
		for (int i = 0; i < 4; i++) {
			if (i != 3)
				cout << q[i] << ",";
			else cout << q[i] << ")" << endl;
		}
	}
};
