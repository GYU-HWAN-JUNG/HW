#include <iostream>
#include <fstream>
using namespace std;

float getLength(float ii) { return 4. / ii; }
float getfrequency(char a) {
    if (a == 'E') return 164.81;
    else if (a == 'G') return 196.;
    else return 130.81;
}
int getAmplitude(int jj) { return 1000 * jj; }

int main() {
    char header[44];

    ifstream Beatles("Beatles-LetItBe-wav_30s-1.wav", ios::in | ios::binary);
    if (!Beatles) return -1;

    Beatles.read(header, 44);
    // sprint 1
    int* CI, * CS, * F, * SCI, * SCS, * SR, * BR, * SCI2, * SCS2;
    short* AF, * NC, * BA, * BPS;
    CI = (int*)(header);
    cout << "ChunkID : " << *CI << endl;
    CS = (int*)(header + 4);
    cout << "ChunkSize : " << *CS << endl;
    F = (int*)(header + 8);
    cout << "Format : " << *F << endl;
    SCI = (int*)(header + 12);
    cout << "Subchunk1ID : " << *SCI << endl;
    SCS = (int*)(header + 16);
    cout << "Subchunk1size : " << *SCS << endl;
    AF = (short*)(header + 20);
    cout << "AudioFormat : " << *AF << endl;
    NC = (short*)(header + 22);
    cout << "Numchannels : " << *NC << endl;
    SR = (int*)(header + 24);
    cout << "SampleRate : " << *SR << endl;
    BR = (int*)(header + 28);
    cout << "Subchunk1size : " << *SCS << endl;
    BA = (short*)(header + 32);
    cout << "BlockAlign : " << *BA << endl;
    BPS = (short*)(header + 34);
    cout << "BitsPerSample : " << *BPS << endl;
    SCI2 = (int*)(header + 36);
    cout << "Subchunk2ID : " << *SCI2 << endl;
    SCS2 = (int*)(header + 40);
    cout << "Subchunk2size : " << *SCS2 << endl;

    //sprint2
    int N = 100000;
    short* data;
    data = new short[N];
    *NC = 1;
    *BR = NC[0] * SR[0] * sizeof(short);
    Beatles.read((char*)data, N * sizeof(short));
    Beatles.close();

    ofstream yy("my.wav", ios::binary | ios::out);
    if (!yy) return -2;
    yy.write(header, 44 * sizeof(char));
    yy.write((char*)data, N * sizeof(short));
    yy.close();

    //sprint3
    short* data2;
    data2 = new short[SR[0]];

    const float pi = 3.141592;

    float dt = 1. / SR[0], a = 10000.0, f = 440.0;
    for (int i = 0; i < SR[0]; i++)
        data2[i] = (short)(a * sin(2.0 * pi * f * i * dt));

    ofstream tt("my1.wav", ios::binary | ios::out);
    if (!tt) return 666;

    tt.write(header, 44 * sizeof(char));
    tt.write((char*)data2, 44100 * sizeof(short));
    tt.close();

    //sprint 4
    ifstream zz("tokki.txt");
    if (!zz) return -3;
    char hh;
    int n, eu, ss, am[6];
    float fr[6], T[6];
    zz >> n;

    for (int i = 0; i < n; i++) {
        zz >> eu >> hh >> ss;
        fr[i] = getfrequency(hh);
        am[i] = getAmplitude(ss);
        T[i] = getLength(eu);
    }
    ofstream xxx("my3.wav", ios::binary | ios::out);
    if (!xxx) return 777;

    xxx.write(header, 44);
    short* akbo;
    akbo = new short[SR[0]];
    for (int i = 0; i < 44100 * T[0]; i++) {
        akbo[i] = (short)(am[0] * sin(2 * pi * fr[0] * i * dt));
    }
    xxx.write((char*)akbo, 44100 * T[0] * sizeof(short));

    for (int i = 0; i < 44100 * T[1]; i++) {
        akbo[i] = (short)(am[1] * sin(2 * pi * fr[1] * i * dt));
    }
    xxx.write((char*)akbo, 44100 * T[1] * sizeof(short));

    for (int i = 0; i < 44100 * T[2]; i++) {
        akbo[i] = (short)(am[2] * sin(2 * pi * fr[2] * i * dt));
    }
    xxx.write((char*)akbo, 44100 * T[2] * sizeof(short));

    for (int i = 0; i < 44100 * T[3]; i++) {
        akbo[i] = (short)(am[3] * sin(2 * pi * fr[3] * i * dt));
    }
    xxx.write((char*)akbo, 44100 * T[3] * sizeof(short));

    for (int i = 0; i < 44100 * T[4]; i++) {
        akbo[i] = (short)(am[4] * sin(2 * pi * fr[4] * i * dt));
    }
    xxx.write((char*)akbo, 44100 * T[4] * sizeof(short));

    for (int i = 0; i < 44100 * T[5]; i++) {
        akbo[i] = (short)(am[5] * sin(2 * pi * fr[5] * i * dt));
    }
    xxx.write((char*)akbo, 44100 * T[5] * sizeof(short));

    
        
    
    xxx.close();
}