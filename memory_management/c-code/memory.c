#include<stdio.h>
#include<stdlib.h>


int main(){
    char* a = calloc(5 , sizeof(int)); // will craete a 20 bytes of memory 




    for(int j = 0 ; j < 5 ; j++){
        a[j] = j; // will store j values in each consicutive bytes since char pointer
    }

  

       for(int i = 0 ; i < 20  ; i++){
        printf("%d \n ", *(a + i));
         printf("%p \n ", (a + i));

    } // will print first 5 bytes value as : 0 - 5 and remaining as 0 since calloc

    /* sample output :
        0 
        0000025EE26902E0 
        1 
        0000025EE26902E1 
        2 
        0000025EE26902E2 
        3 
        0000025EE26902E3 
        4 
        0000025EE26902E4 
        0 
        0000025EE26902E5 
        0 
        0000025EE26902E6 
        0 
        0000025EE26902E7 
        0 
        0000025EE26902E8 
        0 
        0000025EE26902E9 
        0 
        0000025EE26902EA 
        0 
        0000025EE26902EB 
        0 
        0000025EE26902EC 
        0 
        0000025EE26902ED 
        0 
        0000025EE26902EE 
        0 
        0000025EE26902EF 
        0 
        0000025EE26902F0 
        0 
        0000025EE26902F1 
        0 
        0000025EE26902F2 
        0 
        0000025EE26902F3 
 
    */


    
}