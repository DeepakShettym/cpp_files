#include<stdio.h>

struct inside_data
{
  int d1;

  char d2;
};
 
struct data
{
    int a;

    int b;

    struct inside_data d;
};

struct car_spec 
{
  int seat;
  char *color;
};


struct car {
  char *name;
  int price;
  struct car_spec *spec;
};





int main(){

  struct data my_data = {
    .a = 1,
    .b = 2,
    .d = {
      .d1 = 11,
      .d2 = 'a'
    }
  };

  printf("%d\n",my_data.d.d1);
  printf("%c\n",my_data.d.d2);


  struct car_spec my_spec = {
    .seat = 4,
    .color = "red"
  };

  
  struct car_spec my_spec_BMW = {
    .seat = 5,
    .color = "black"
  };

  struct car my_car ={
    .name = "lamborgini",
    .price = 200000,
    .spec = &my_spec,
  };

  
  struct car my_car2 ={
    .name = "BMW",
    .price = 100000,
    .spec = &my_spec_BMW,
  };

struct car more_car[2] = {
  my_car , my_car2
};

printf("name1 = %s\n",more_car[0].name);
printf("name2 = %s\n",more_car[1].name);



  

  
  printf("%s\n",my_car.name);
  printf("%d\n",my_car.price);
  
  printf("%d\n",my_car.spec->seat);
  printf("%s\n",my_car.spec->color);





  return 0;
}
