#include<stdio.h>
#include<stdlib.h>


union mydata
{
    int data;

    char arr[4];
};

int main()
{
    union mydata d;

    d.data = 0x11223344;

    d.arr[2] = 0x00;


    for(int i = 0 ; i < 4 ;i++){
        printf("%x ",d.arr[i]);
    }
    
    return 0;
}

/* sample output : 
    44 33 0 11 
*/

