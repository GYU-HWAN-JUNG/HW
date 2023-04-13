#include <iostream>
#include <fstream>
using namespace std;

int main() {
    char header[44];

    ifstream myfile("Beatles-LetItBe-wav_30s.wav", ios::in | ios::binary);
    if (!myfile) return -1;

    myfile.read(header, 44);
    // step 1
    unsigned int* data1 ;
    unsigned short* data2;
    data1 = new unsigned int[9];
    data2 = new unsigned short[4];
    for (int i = 0; i < 5; i++) {
        data1[i] = *((unsigned int*)(header + 4 * i));
        cout << data1[i] << endl;
    }

    for (int j = 0; j < 2; j++) {
        data2[j] = *((unsigned short*)(header + 20 + 2 * j));
        cout << data2[j] << endl;
    }

    for (int i = 5; i < 7; i++){
        data1[i] = *((unsigned int*)(header + 4 + 4 * i));
        cout << data1[i] << endl;
    }

    for (int j = 2; j < 4; j++) {
        data2[j] = *((unsigned short*)(header + 28 + 2 * j));
        cout << data2[j] << endl;
    }

    for (int i = 7; i < 9; i++) {
        data1[i] = *((unsigned int*)(header + 8 + 4 * i));
        cout << data1[i] << endl;
    }
    // step 2
    short data[1000];
    myfile.seekg(data1[5] * 10);
    myfile.read((char*)data, sizeof(data));
    
    ofstream aaa("data.txt");
    float dt = 1. / data1[5];
    for (int i = 0; i < 500; i++) {
        cout << i * dt << " " << data[i * 2] << " " << data[i * 2 + 1] << endl;
    }
    return 1;
   
}