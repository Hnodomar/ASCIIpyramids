#include <math.h>
#include <iostream>
#include <cstdlib>
#include <string>
#include <unistd.h>
using namespace std;

int circmath(int ycoordinate, int xcoordinate, int xdisplacement, int ydisplacement) {
    return pow((xcoordinate - xdisplacement), 2) + pow((2*ycoordinate - ydisplacement), 2);
}

int main() {
    printf("\x1b[2J");
    for (;;) {
    char output[3200];
    for (int i = 0; i < 3200; i++) {
        output[i] = ' ';
    }
    int intersection_one, intersection_two, intersection_three = 0;
    for (int i = 0; i < 3200; i++) {
        int rowindex = i / 80;
        int colindex = i % 80;
        bool line_intersection_one = 2 * rowindex == 80 - (2*rowindex) && colindex == 2*rowindex;
        bool line_intersection_two = (80 - colindex) / 2 == 30 && rowindex == 30;
        bool line_intersection_three = colindex / 2 == 30 && rowindex == 30;
        if (line_intersection_one || line_intersection_two || line_intersection_three) {
            if (line_intersection_one) {
                intersection_one = i / 80;
            }
            else if (line_intersection_two) {
                intersection_two = i / 80;
            }
            else if (line_intersection_three) {
                intersection_three = i / 80;
            }
        }
        if (circmath(rowindex, colindex, 40, 30) == 81 || circmath(rowindex, colindex, 40, 30) < 81) {
            output[i] = 'V';
        }
    }
    for (int i = 0; i < 3200; i++) {
        int rowindex = i / 80;
        int colindex = i % 80;
        bool draw_y_condition = rowindex > intersection_one && rowindex < intersection_two;
        bool draw_x_condition = colindex > 80 - 2*rowindex && colindex < 2*rowindex;
        bool draw_y_border = rowindex == intersection_one && rowindex == intersection_two;
        bool draw_x_border = colindex == 80 - 2 * rowindex && colindex == 2*rowindex;
        if (draw_y_condition && draw_x_condition || draw_y_border && draw_x_border) {
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