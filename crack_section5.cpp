

#include <list>
#include <iostream>
#include <string>
using namespace std;

string toBinary(float f) {
	if (f < 0 || f > 1) return "N/A";
	string s = "0.";
	float r = f;
	int i = 1;
	float base = 1;
	while(i < 32 && r > 0.000000001) {
		base = base/2;
		if(r >= base) {
			s += "1";
			r = r - base;
		}
		else
			s += "0";
		i++;
	}
	return s;
}


int main() {
	cout << toBinary(0.9) << endl;
}