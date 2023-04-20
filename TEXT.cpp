#include <iostream>
#include <fstream>
using namespace std;

int main() {
	ofstream sing("tokki.txt");
	if (!sing) return 123;

	int n = 6;
	int eu[] = { 4, 8, 8, 8, 8, 4 };
	char hh[] = { 'G', 'E', 'E', 'G', 'E', 'C' };
	int ss[] = { 10, 5, 5, 10, 5, 8 };
	
	sing << n << endl;
	for (int i = 0; i < n; i++) {
		sing << eu[i]<< " " << hh[i] << " " << ss[i] << endl;
	}
	sing.close();
	return 1;

		


}