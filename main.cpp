#include <math.h>
#include <iostream>
#include <cstdio>
#include <string.h>
using namespace std;

int main() {
    float z[1760];
    char b[1760];
    float i, j;
    printf("\x1b[2J");  //ANSI escape sequence, \x1b is next, [ is control sequence introducer
                        //and 2J following the CSI clears the screen, leaving cursor where it is.
                        //WHOLE EFFECT IS SIMPLY TO CLEAR THE SCREEN
    for(;;) {   //Infinite loop
        memset(b, 32, 1760); //Set first 1760 bytes of b block of memory to ascii 32 - space character.. each element is 1 byte (expected)
        memset(z, 0, 7040);  //Set first 7040 bytes of z block of memory to ascii 0 - NULL.. each element is 4 bytes (expected)
        for (j = 0; j < 5.0; j += 0.05) {
            for (i = 0; i < 5.0; i += 0.02) {
                
            }
        }
    }
}