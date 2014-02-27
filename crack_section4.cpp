
#include <vector>
// #include <stdio>
#include <iostream>
using namespace std;

#define M 10

class matrix{
public:
	int m[M][M];
public:
	matrix() {
		for(int i = 0; i < M; i++)
			for(int j = 0; j < M; j++)
				m[i][j] = 0;
	}
	bool findRoute(int a, int b, vector<bool> f) {
		if(m[a][b] == 1) return true;
		vector<bool> f2= f;
		for(int i = 0; i < M; i++ ) {
			if(m[a][i] == 1 && f2[i] != true) {
				f2[i] = true;
				if(findRoute(i, b, f2) == true) return true;
			}
		}
		return false;
	}
};

int main() {
	matrix mm;
	mm.m[2][4] = 1;
	mm.m[4][2] = 1;
	mm.m[2][9] = 1;
	vector<bool> f(M, false);
	cout << mm.findRoute(2, 9, f) << endl;
}