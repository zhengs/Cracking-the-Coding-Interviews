
#include <map>
#include <string>
#include <set>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

void sortStringSet(set<string> ss) {
	map<string, set<string> > m;
	for(set<string>::iterator it = ss.begin(); it!= ss.end(); it++) {
		string s = *it;
		sort(s.begin(), s.end());
		if(m.find(s) == m.end()) {
			set<string> setString;
			setString.insert(*it);
			m[s] = setString;
		} else {
			set<string> setString = m.at(s);
			setString.insert(*it);
			m[s] = setString;
		}
	}

	for(map<string, set<string> >::iterator it = m.begin(); it != m.end(); it++) {
		pair<string, set<string> > p = *it;
		set<string> setString = p.second;
		for(set<string>::iterator it2 = setString.begin(); it2 != setString.end(); it2++) {
			cout << (*it2) << endl;
		}
	}
}
int bSearch(vector<int> a, int start, int end, int b) {
	cout << "b = " << b << endl;
	int m = (start+end)/2;
	int old = 0;
	while(old != m) {
		old = m;
		if(a[m] == b) 
			return m;
		else if(a[m] < b) {
			start = m + 1;
			m = (m + end)/2;
		} else {
			end = m;
			m = (start + m) /2 ;
		}

	}
	return -1;
}
int find(vector<int> a, int b) {
	if(a.size() == 0) return -1;
	if(a.size() == 1) {
		if(a[0] == b) 
			return 0;
		else 
			return -1;
	}
	int len = a.size();
	cout << len << endl;
	int start = 0; 
	int end = start + 1;
	while(start < len) {
		while(a[end] >= a[end-1] && end < len) {
			cout << a[end] << "---" << a[end-1] << endl;
			end++;
		}
			
		cout << start << " " << end << endl;
		int r = bSearch(a, start, end-1, b);
		cout << "r = " << r << endl;
		if(r >= 0) return start+r;
		start=end;
		end = start + 1;
	}
	return -1;
}
int main() {
	srand (time(NULL));
	set<string> ss;
	ss.insert("haha");
	ss.insert("dog");
	ss.insert("aahh");
	ss.insert("lalalal");
	ss.insert("odg");
	sortStringSet(ss);
	vector<int> a;
	for(int i = 0; i < 10; i++) {
		a.push_back(rand() % 3000);
	}
	sort(a.begin(), a.end());
	for(int i = 0; i < 10; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
	cout << find(a, a[5]);
	return 0;
}