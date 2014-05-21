#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int> > minHeap;
priority_queue<int, vector<int>, less<int> > maxHeap;

double median(int a) {
	if(minHeap.size() == 0 && maxHeap.size() == 0) {
		cout << "case 1" << endl;
		minHeap.push(a);
		return a;
	}
	if(minHeap.size() > maxHeap.size()) {
		if(a > minHeap.top()) {
			minHeap.push(a);
			int tmp = minHeap.top();
			minHeap.pop();
			maxHeap.push(tmp);
			cout << "case 2" << endl;
			return (maxHeap.top()+minHeap.top())/2.0;
		} else {
			maxHeap.push(a);
			cout << "case 3" << endl;
			return (maxHeap.top()+minHeap.top())/2.0;
		}
	} else if(minHeap.size() < maxHeap.size()) {
		if(a < maxHeap.top()) {
			maxHeap.push(a);
			int tmp = maxHeap.top();
			maxHeap.pop();
			cout << "case 4" << endl;
			return (maxHeap.top()+minHeap.top())/2.0;
		} else {
			minHeap.push(a);
			cout << "case 5" << endl;
			return (maxHeap.top()+minHeap.top())/2.0;
		}
	} else {
		if(a < maxHeap.top()) {
			maxHeap.push(a);
			cout << "case 6" << endl;
			return maxHeap.top();
		} else if (a > minHeap.top()) {
			minHeap.push(a);
			cout << "case 7" << endl;
			return minHeap.top();
		} else {
			minHeap.push(a);
			cout << "case 8" << endl;
			return a;
		}
	}
}

int main() {
	for(int i = 0; i < 10; i++) {
		// if(i%2) {
        cout << "i = " << i << ": " << median(i) << endl;
		// } else {
		// 	cout << "i = " << i << ": " << median(10-i) << endl;
		// }
	}
}