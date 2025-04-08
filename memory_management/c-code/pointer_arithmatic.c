#include<stdio.h>
struct some_data
{
  int a;

  int b;

  char c;
  
};

void getContainer(char *ptr){

  struct some_data temp;

  int offset = (int)((char*)&temp.c - (char*)&temp);



  struct some_data *data = (struct some_data*)(ptr - offset);

  printf("a = %d ",data->a);
  printf("b = %d ",data->b);
  printf("c = %c ",data->c);


}




int main(){

  struct some_data data1;

  data1.a = 10;
  data1.b = 20;
  data1.c = 'a';

  getContainer(&data1.c);
  return 0;
}