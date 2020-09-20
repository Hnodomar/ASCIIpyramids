#include <math.h>
#include <iostream>
#include <cstdio>
#include <string.h>
#include <Windows.h>
#include <cstdlib>
#include <unistd.h>

using namespace std;

int main() {
    float z[1760];
    char b[1760];
    float i, j;
    printf("\x1b[2J");  //ANSI escape sequence, \x1b is next, [ is control sequence introducer
                        //and 2J following the CSI clears the screen, leaving cursor where it is.
                        //WHOLE EFFECT IS SIMPLY TO CLEAR THE SCREEN
    //for(;;) {   //Infinite loop
        memset(b, 32, 1760); //Set first 1760 bytes of b block of memory to ascii 32 - space character.. each element is 1 byte (expected)
        memset(z, 0, 7040);  //Set first 7040 bytes of z block of memory to ascii 0 - NULL.. each element is 4 bytes (expected)
        /*for (int v = 0; v < 22; v++) {
            for (int r = 0; r < 80; r++) {
                    int numberrand2 = rand() % 22;
                    int numberrand = rand() % 126 + 33;
                    char randomshit = char(numberrand);
                    for (int k = 0; k < 81; k++) {
                        b[v * r] = randomshit;
                    }
                    
                   
            }
        }*/
        for (int i = 0; i < 1760; i++) {
            double rowindex = (i % 22);
            double colindex = (i % 80) * 0.275;
            if (i % 79 == 0) {
                b[i] = '.';   //char(rand() % 126 + 33);
            }
            else if (i % 78 == 0) {
                b[i] = 'G';
            }
            else if (i % 77 == 0) {
                b[i] = 'Y';
            }
            else if (i % 76 == 0) {
                b[i] = 'V';
            }
        }
        printf("\x1b[H");
        for (int k = 0; k < 1761; k++) {
            putchar(k % 80 ? b[k] : 10); //Each line is 80 wide
        }
                


              
            
        
    //}
}

// row 1 [1 * ra ]