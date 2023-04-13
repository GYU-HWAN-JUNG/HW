#include <iostream>
#include <fstream>
using namespace std;

void mul5(int* xx, int n) {
    for (int i = 0; i < n; i++) {
        xx[i] = xx[i] * 5;
    }
}
void square(float* xx, int n) {
    for (int i = 0; i < n; i++) {
        xx[i] = xx[i] * xx[i];
    }
}

int main() {
    int num1 = 1234;
    int num5[5] = { 1000, 2000, 3000, 4000, 5000 };
    float selfmul[3] = { -0.5, 0.0, 0.5 };

    mul5(num5, 5);
    square(selfmul, 3);

    ofstream wr1("mybin2.dat", ios::binary | ios::out);
    if (!wr1) return 1;
   
    wr1.write((char*)&num1, sizeof(num1));
    wr1.write((char*)&num5, sizeof(num5));
    wr1.write((char*)&selfmul, sizeof(selfmul));
    wr1.close();

    int gg[6];
    float RR[3];

    ifstream re1("mybin2.dat", ios::binary | ios::in);
    if (!re1) return -1;

    re1.read((char*)&gg, sizeof(gg));
    re1.read((char*)&RR, sizeof(RR));
    re1.close();

    for (int i = 0; i < 6; i++) {
        cout << gg[i] << endl;
    }
    for (int i = 0; i < 3; i++) {
        cout << RR[i] << endl;
    }
    return 0;
}