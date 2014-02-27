#include <stack>
#include <list>
#include <stdio.h>
#include <map>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdlib.h>

using namespace std;

class myQueue {
	stack<int> s_main, s_tmp;

public:

	void push_back(int a) {
		s_main.push(a);
	}

	int peek() {
		if(s_main.size() == 0) return -1;
		return s_main.top();
	}
	int size() {
		return s_main.size();
	}
	int pop_front() {
		int m = s_main.size();
		if(m == 0) return -1;
		int i = 0;
		while(i++ < m-1){
			int a = s_main.top();
			s_main.pop();
			s_tmp.push(a);
		}
		int r = s_main.top();
		s_main.pop();
		while(s_tmp.size() >0) {
			int a = s_tmp.top();
			s_tmp.pop();
			s_main.push(a);
		}
		return r;
	}

};


class Hanoi {
private:
	list<int> s1, s2, s3;
public:
	void show() {
		cout << "s1: ";
		list<int>::iterator it;
		for(it = s1.begin(); it != s1.end(); it++)
			cout << *it << "-> ";
		cout << endl;

		cout << "s2: ";
		for(it = s2.begin(); it != s2.end(); it++)
			cout << *it << "-> ";
		cout << endl;

		cout << "s3: ";
		for(it = s3.begin(); it != s3.end(); it++)
			cout << *it << "-> ";
		cout << endl;
		cout << endl;

	}
	void move(int lvls, list<int>& from, list<int>& to, list<int>& via) {
		if(lvls == 1) {
			int o = from.back();
			from.pop_back();
			to.push_back(o);
		} else{
			move(lvls - 1, from, via, to);
			move(1, from, to, via);
			move(lvls - 1, via, to, from);
		}
		show();
	}

	Hanoi(int lvls) {
		for(int i = lvls; i > 0 ; i-- ) {
			this->s1.push_back(i);
		}
	}
	void play() {
		show();
		move(this->s1.size(), this->s1, this->s3, this->s2);
	}
};

class sortStack {
	stack<int> s_main, s_tmp;

public:
	void push(int a) {
		s_main.push(a);
	}
	int pop() {
		int r = s_main.top();
		s_main.pop();
		return r;
	}
	int size() {
		return s_main.size();
	}
	void sortAll() {
		sort(s_main, s_main.size());
	}
	void sort(stack<int>& s, int l) {
		cout << "len = " << l << endl;
		if(l == 2) {
			int a1 = s.top(); s.pop();
			int a2 = s.top();
			cout << "a1:a2 = " << a1 << " " << a2 << endl;
			if (a1 > a2) {
				s.pop();
				s.push(a1);
				s.push(a2);
			} else {
				s.push(a1);
			}
		} else {
			sort(s, l-1);
			cout << "new" << endl;
			int i = 0;
			while(i++ < l-1) {
				int a = s.top(); s.pop();
				cout << "a = " << a << endl;
				s_tmp.push(a);
			}
			cout << "A" << endl;
			int bottom = s.top(); s.pop();
			cout << "B " << bottom << endl;
			while(s_tmp.size() != 0 && bottom < s_tmp.top()){
				int a = s_tmp.top(); s_tmp.pop();
				cout << "a = " << a << endl;
				s.push(a);
			}
			cout << "C" << endl;
			s.push(bottom);
			cout << "D" << endl;
			while(s_tmp.size() != 0) {
				int a = s_tmp.top(); s_tmp.pop();
				s.push(a);
			}
			cout << "E" << endl;
		}
	}
};



int main() {
	Hanoi a(3);
	a.play();
	myQueue m;
	for(int i = 0; i < 5; i++) {
		m.push_back(i);
		cout << "m's top = " << m.peek() << endl;
	}
	while(m.size() != 0) {
		
		cout << "m's pop = " << m.pop_front() << endl;	
	}
	sortStack ss;
	srand (time(NULL));
	for(int i = 0; i < 6; i++) {
		int a = rand() % 20;
		cout << a << " ";
		ss.push(a);
	}
	ss.sortAll();
	while(ss.size() != 0) {
		cout << "ss's pop = " << ss.pop() << endl;
	}
}