#include<stdio.h>


int main(){

    char x = 0b10110010;


    printf(" The value of x is : %x \n", x); // prints b2
    int y = 0x22334455;

    char* p =  (char *)&y;

    p[2] |= 1 << 7; // setting 7th bit of 3rd byte ie 33 -> B3

    printf(" The value of y is : %x \n", y); // prints 22B34455  0010 0010 1011 0011 0100 0100 0101 0101

    y &= ~(1 << 2); 

    printf(" The value of y after resetting 5th bit of LSB is : %x \n", y);

    int a = 0x12345678; // 0001 0010 0011 0100 0101 0110 0111 1000

    // convert to 0x12005678 
    
    a &= ~(0XFFF << 12);

    printf("y0 The value of a after masking is : %x \n", a); // prints 12000678

    a &= ~(0xFF << 16);

    printf(" The value of a after masking is : %x \n", a); // prints 12005678


    a &= 0XFF; 

    printf(" The value of a after masking LSB is : %x \n", a); // prints 78


    a &= (0x1FF << 12) ; 

    printf(" The value of a after masking is : %x \n", a); 

   
    
  

}