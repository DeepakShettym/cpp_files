#include<stdio.h>
#include<stdlib.h>

int main(){
    int a = 0x22334455;

    char* p =  (char *)&a;

    *(p + 1)  = 0x88; // pinter moves 1 byte ahead ie 44 -> 88

    printf("%x \n", a);

    for(int i = 0 ; i < 4 ; i++){
        printf("%x ", (unsigned char)*(p + i));
    }


    long long b = 0x9988776655;


    int* p1 = (int*) &b;

    *(p1 + 1) = 0x25;  // pinter moves 4 byte ahead ie 99 -> 25 

     printf("%x \n", b);

      char* p2 = (char*) &b;

       for(int i = 0 ; i < 8 ; i++){
        printf("%x ", (unsigned char)*(p2 + i)); // printing each  byte address value  
     }

     /* sample output : 
        88776655 
        55 66 77 88 25 0 0 0 
     */


     printf("\n  ----------------------------------\n");

     char arr[] = { 0x77 , 0x88 , 0x99 , 0x55};

     int *p3 = (int*) arr;

     printf("%x",*p3);


     // NOV 24 2023

     int xx = 0x12345678;
        char *ptr = (char*)&xx;
        printf("\n  value in hex : %x \n",ptr[0]); 

        printf("\n  value in integer : %d \n",(int)ptr[0]); 

     




    
}