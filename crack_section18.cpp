#include <map>
#include <string>
#include <set>
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

unsigned int sum_without_using_arithmetics(unsigned int a, unsigned int b){
	int num_bits = sizeof(unsigned int) * 8;
	int bit_a;
	int bit_b;
	int result;
	int up = 0;
	unsigned int sum = 0;
	for(int i = 0; i < num_bits; i++) {
		unsigned int mask = 1 << i;
		bit_a = (a & mask) >> i;
		bit_b = (b & mask) >> i;
		result = bit_a ^ bit_b;
		result = result ^ up;
		if((bit_a & bit_b) == 1)
			up = 1;
		else
			up = (bit_a | bit_b) & up;
		sum = sum | (result << i);
	}
	return sum;
}

int main() {

	for(int i = 0; i < 10; i ++)
		for(int j = 0; j < 10; j++)
			cout << i << "+" << j << " = " << sum_without_using_arithmetics(i, j) << endl;
	return 0;
}