#include <iostream>
#include <fstream>
using namespace std;

void All(float* xx, int n) {
    for (int i = 0; i < n; i++) {
        xx[i] = xx[i] * xx[i];
    }
}
void All(float* xx, int n, int x) {
    for (int i = 0; i < n; i++) {
        xx[i] = xx[i] * x;
    }
}
int main() {
    float num[9] = { 1234, 1000, 2000, 3000, 4000, 5000, -0.5, 0.0, 0.5 };
    All(num + 1, 5, 5);
    All(num + 6, 3);

    ofstream wr("mybin4.dat", ios::binary | ios::out);
    if (!wr) return 1;

    wr.write((char*)&num, sizeof(num));
    wr.close();

    float rr[9];
    ifstream re("mybin4.dat", ios::binary | ios::in);
    if (!re) return 1;

    re.read((char*)&rr, sizeof(rr));
    re.close();

    for (int i = 0; i < 9; i++) {
        cout << rr[i] << endl;
    }
    return 0;
}