#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
const float pi = 3.141592;

int main() {
    int n = 200;
    float f = 1000;
    short a = 30, p = 10;
    float* samples, *samples2, *rr, *RR;
    rr = new float[n];
    RR = new float[n];
    samples = new float[n];
    samples2 = new float[n];
    float dt = 1. / f / 20.0;

    //assignment1
    for (int i = 0; i < n; i++) {
        samples[i] = (float)a * sin(2 * pi * f * i * dt);
    }
    ofstream ao("a.dat", ios::binary | ios::out);
    if (!ao) return -1;
    ao.write((char*)samples, n * sizeof(float));
    ao.close();

    //assingment2
    ifstream ai("a.dat", ios::binary | ios::in);
    if (!ai) return -2;
    ai.read((char*)rr, 12);
    for (int i = 0; i < 3; i++) {
        cout << rr[i] << endl;
    }
    ai.close();
    
    f = 200;
    for (int i = 0; i < n; i++) {
        samples2[i] = (float)a * sin(2 * pi * f * i * dt);
    }
    ofstream bo("b.dat", ios::binary | ios::out);
    if (!bo) return -3;
    ao.write((char*)samples2, n * sizeof(float));
    ao.close();
    
    //assingment3
    ifstream ai_2("a.dat", ios::binary | ios::in);
    if (!ai_2) return -4;
    ai_2.read((char*)rr, sizeof(rr));

    ifstream bi_2("b.dat", ios::binary | ios::in);
    if (!bi_2) return -5;
    bi_2.read((char*)RR, sizeof(RR));
    
    ofstream co("c.txt");
    if (!co) return -6;
    for (int i = 0; i < n; i++) {
        co << i << "    " << rr[i] << "    " << RR[i] << endl;
    }
    co.close();
    return 123;
    
}

