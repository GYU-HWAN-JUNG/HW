#include <iostream>
#include <fstream>
using namespace std;

void mul5(float* xx, int n) {
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
    float num[9] = {1234, 1000, 2000, 3000, 4000, 5000, -0.5, 0.0, 0.5};
    mul5(num+1, 5);
    square(num+6, 3);

    ofstream wr("mybin3.dat", ios::binary | ios::out);
    if (!wr) return 1;

    wr.write((char*)&num, sizeof(num));
    wr.close();

    float rr[9];
    ifstream re("mybin3.dat", ios::binary | ios::in);
    if (!re) return 1;
  
    re.read((char*)&rr, sizeof(rr));
    re.close();

    for (int i = 0; i < 9; i++) {
        cout << rr[i] << endl;
    }
    return 0;
}