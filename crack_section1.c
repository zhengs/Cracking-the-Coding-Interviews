#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

int isUnique(std::string s) {
	// 1.1
	std::map<char, int> m;
	for(int i = 0; i < s.length(); i++)
		if(m.find(s[i]) == m.end())
			m[s[i]] = 1;
		else
			return 0;
	return 1;
}

int isUniqueBitVector(std::string s) {
	// 1.1
	std::vector<bool> v;
	for(int i = 0; i < 256; i++)
		v.push_back(0);
	for(int i = 0; i < s.length(); i++) {
		if(v[s[i]] != 0)
			return false;
		else
			v[s[i]] = 1;
	}
	return true;
}

void reverse(char* str) {
	// 1.2
	int l = 0;
	while(str[l] != '\0') l++;
	if(l == 1 || l == 0) return;
	for(int i = 0; i < l/2; i++){
		char c = str[i];
		str[i] = str[l-1-i];
		str[l-1-i] = c;
	}
}

int perm2(std::string s1, std::string s2) {
	// 1.3, using STL existing sorting and comparing functions
	std::sort(s1.begin(), s1.end());
	std::sort(s2.begin(), s2.end());
	return std::equal(s1.begin(), s1.end(), s2.begin());
}

int perm(std::string s1, std::string s2){
	// 1.3
	std::map<char, int> m;
	for(int i = 0; i < s1.length(); i++)
		if(m.find(s1[i]) == m.end())
			m[s1[i]] = 1;
		else
			m[s1[i]] ++;
	for(int i = 0; i < s2.length(); i++)
		if(m.find(s2[i]) == m.end())
			return 0;
		else {
			m[s2[i]] --;
			if(m[s2[i]] < 0) return 0;
		}
	return 1;
}

// 1.4 skipped
std::string compress(std::string s) {
	// 1.5
	if(s.length() < 2) return s;
	std::string c;
	char cc = s[0];
	int currentCount = 1;
	for(int i = 1; i < s.length(); i++)
		if(s[i] == cc)
			currentCount++;
		else {
			std::stringstream ss;
		    std::string temp;
		    ss << currentCount;
		    temp = ss.str();
			c += cc + temp;
			currentCount = 1;
			cc = s[i];
		}
	std::stringstream ss;
    std::string temp;
    ss << currentCount;
    temp = ss.str();
	c += cc + temp;
	if(c.length() >= s.length())
		c = s;
	return c;
}
int main(){
	std::string s("abcd");
	std::cout << s << ' ' << isUnique(s) << std::endl;
	reverse(&s[0]);
	std::cout << s << std::endl;
	std::cout << perm("abc", "cba") << std::endl;
	std::cout << compress("aaaaaaazzbcbc") << std::endl;
	std::cout << isUniqueBitVector("abbcd") << std::endl;
	std::cout << perm2("abcd", "acd") << std::endl;
}