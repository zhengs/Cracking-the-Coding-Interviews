#include <map>
#include <string>
#include <set>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;


int max(int a, int b) {
	int k = ((a-b) & ((unsigned int) 1 << (sizeof(unsigned int)*8-1))) >> (sizeof(unsigned int)*8 -1);
	cout << (bool)k << endl;
	bool r = (bool) k;
	return a * !r + b * r;
}

int c17_14(string s) {
	map<string, int> h;
	h["i"] = 1;
	h["at"] = 1;
	h["cat"] = 1;
	h["attorney"] = 1;
	h["torn"] = 1;
	vector<int> v;
	for(int i = 0; i < s.size(); i++) {
		int min_unrecognized = 1000000;
		for(int j = i; j >= 0; j--){
			string sub = s.substr(j, i-j+1);
			cout << "sub = " << sub << endl;
			int tmp_count = 0;
			if(h.find(sub) != h.end()) {// found
				if(j == 0) 
					tmp_count = 0;
				else 
					tmp_count = v[j-1];
			} else {	// not found in dictionary
				if(j==0)
					tmp_count = i+1;
				else
					tmp_count = v[j-1] + i - j + 1;
			}
			if(tmp_count < min_unrecognized)
				min_unrecognized = tmp_count;
		}
		v.push_back(min_unrecognized);
	}
	return v[s.size()-1];
}
int main() {
	cout << max(33, 112) << endl;
	string s = "icattoreyy";
	cout << c17_14(s);
	return 0;
}