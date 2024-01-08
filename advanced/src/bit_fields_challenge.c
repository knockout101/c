/*
Bit Fields Challenge

- write a program that contains the following bit fields in a structure (onscreen box)
    - the box can be opaque or transparent
    - a fill color is selected from the following pallete of colors: black, red, green, yellow, blue, magenta, cyan, and white 
    - a border can be shown or hidden 
    - a border color is selected from the same palette used for the fill color 
    - a border can use one of three line styles - solid, dotted, or dashed 

- your program should utilize the structure that contains the bitfields as described in the previous slides 

- first, create a variable of the structure type and initialize the bitfields with some default values 
    - display these default values 

- second, modify the strructures contents by accessing each bitfield and changing the default value to another value 
    - display these modified values
*/
#include <stdio.h>

struct packed_struct
{
    unsigned int opacity :1;
    unsigned int color :3;
    unsigned int border :1;
    unsigned int border_color :3;
    unsigned int border_style : 2;
};


int main(void)
{
    char border_styles[3][15] = {
        [0] = "solid",
        [1] = "dotted",
        [2] = "dashed",
    };

    const char * colors[8] = {
        "black", "red", "green", "yellow", "blue", "magenta", "cyan", "white"
    };

    for(int i = 0; i < 8; i++)
        printf("[%d] = %s\n", i, colors[i]);
    
    return 0;
}