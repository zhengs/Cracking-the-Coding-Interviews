#include <iostream>
#include <string>
#include <unordered_map>
#include <list>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

unordered_map<string, unordered_set<string> > graph;

pair<bool, vector<string> > route(string a, string b, unordered_set<string> visited, vector<string> path) {
	unordered_set<string> vs = graph[a];
	if(vs.find(b) != vs.end()) {
		path.push_back(b);
		return pair<bool, vector<string> >(true, path);
	}
	for(auto it = vs.begin(); it != vs.end(); it++) {
		string s = *it;
		if(visited.find(s) == visited.end()) {
			unordered_set<string> tmpvisited(visited);
			tmpvisited.insert(s);
			vector<string> vpath(path);
			vpath.push_back(s);
			pair<bool, vector<string> > r = route(s, b, tmpvisited, vpath);
			if(r.first == true) {
				return r;
			}
		} else {
			continue;
		}
	}
	return pair<bool, vector<string> >(false, vector<string>());
}

int main() {

}