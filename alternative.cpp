#include <math.h>
#include <iostream>
#include <cstdlib>
#include <unistd.h>
using namespace std;

int main() {
    printf("\x1b[2J");
    for (;;) {
    char output[800];
    for (int i = 0; i < 800; i++) {
        output[i] = '.';
    }
    int corr = 0;
    int counter = 0;
    for (int i = 0; i < 800; i++) {
        /*if (i % 10 == 0 && i != 0) {
            corr = (i + counter) % 10;
            counter++;
            output[i] = '4';
        }*/
        int colno = i % 40;
        int rowno = i % 20;
        if (i % 20 == 0) {
            output[i] = 'N';
        }
        else if (i > 400 && i < 440 || i > 360 && i < 400) {
            output[i] = 'M';
        }
    }
    printf("\x1b[2J");
    for (int i = 0; i < 800; i++) {
        if (i % 40 == 0) {
            cout << endl;
        }
        else {
            cout << output[i];
        }
    }
    usleep(15000);
    
    }
}