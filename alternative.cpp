#include <math.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
using namespace std;


int main() {
    printf("\x1b[2J");
    for (;;) {
    char output[3200];
    for (int i = 0; i < 3200; i++) {
        output[i] = '.';
    }

    for (int i = 0; i < 3200; i++) {
        int rowindex = i / 80;
        int colindex = i % 80;
        int circmath = pow((colindex - 40),2) + pow((2*rowindex - 20),2);
        int circmath2 = pow((colindex - 30),2) + pow((2*rowindex - 60),2);
        output[79] = 'Y';
       
        output[81] = 'Y';
        output[80 * 39 + 1] = 'Y';
        output[3199] = 'Y';
        if (circmath < 49 || circmath == 49) {
            output[i] = 'B';
        }
        if (2 * rowindex == colindex) {
            output[i] = 'E';
        }
        if (circmath2 < 81 || circmath2 == 81) {
            output[i] = 'G';
        }
    }
    printf("\x1b[2J");
    for (int i = 0; i < 3200; i++) {
        if (i % 80 == 0) {
            cout << endl;
        }
        else {
            cout << output[i];
        }
    }
    usleep(15000);
    
    }
}