#include <set>

#include <iostream>
#include <string>
using namespace std;

void subsets(string str, set<char> s) {
	if(s.size() != 0) {
		char c = *(s.begin());
		string strNew = str;
		strNew += c;
		strNew += ' ';
		set<char> s1 = s;
		
		s1.erase(c);
		
		subsets(strNew, s1);
		strNew = str;
		subsets(strNew, s1);
	}
	else{
		cout << str << endl;
	}
}

void perm(string cur, string s) {
	if(s.size() == 0)
		cout << cur << endl;
	else {
		for(int i = 0; i < s.size(); i++) {
			string newCur = cur + s[i];
			string snew = "";
			snew += s.substr(0, i);
			snew += s.substr(i+1, s.size()-i-1);
			cout << "   " << snew  << ";" << newCur << endl;
			perm(newCur, snew);
		}
	}
}

void parentheses(int sum, string s, int n) {
	// cout << "s = " << s << endl;
	if(s.size() == n) {
		if(sum == 0)
			cout << s << endl;
		return;
	}
	if(sum > 0) {
		string s1 = s;
		s1 += ')';
		parentheses(sum-1, s1, n);
	}
	string s2 = s;
	s2 += '(';
	parentheses(sum+1, s2, n);
	return;
}
void parentheses_main(int n) {
	parentheses(0, "", n*2);
}

int f_coins(int n, int base_n) {
	const int base[4] = {1, 5, 10, 25};

	if(base_n == 0) return 1;
	
	int sum = 0;
	for(int i = 0; i <= n/base[base_n]; i++){
		sum += f_coins(n - i*base[base_n], base_n-1);
	}
	return sum;
}
int main() {
	set<char> s;
	// for(int i = 0; i < 2; i++ )
	// 	s.insert('a' + i);
	s.insert('6');
	s.insert('7');
	s.insert('8');
	string str = "";
	cout << &s << endl;
	subsets(str, s);

	string str2 = "abc";
	// perm(str, str2);
	parentheses_main(3);
	int n  = 10;
	cout << "f_coins(" << n << ") = " << f_coins(n, 3) << endl;
	for(n = 1; n < 30; n++)
		cout << "f_coins(" << n << ") = " << f_coins(n, 3) << endl;
	return 0;
}