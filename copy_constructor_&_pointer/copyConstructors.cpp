#include<iostream>
using namespace std;


class Book{
  public :
  int id;
  string auther;
  int* rates;


  Book(int id, string auther ,int* rates){
    this->auther = auther;
    this->id = id;
    this->rates = rates;
  }

  Book(const Book &original){
    this->auther = original.auther;
    this->id = original.id;
    // this->rates = original.rates  // this is shallow copy where both the objects will be pointing to same menory location of the array
    this->rates = new int[5];
    for(int i=0;i<5;i++){
      this->rates[i] = original.rates[i];
    }
  }
};

int main(){
  int* rates = new int[5];
  for(int i=0;i<5;i++){
    rates[i] = i;
  }  
  Book book(101,"deepak",rates);
  Book book1(book);

  cout << book1.auther << endl << book1.id << endl ;

  for(int i=0;i<5;i++){
      cout << book1.rates[i] <<endl;
  }

  book1.id = 102;
  book1.auther = "nabeel";
  for(int i=0;i<5;i++){
    book1.rates[i]=i*2;
  }

  cout << book.auther << endl << book.id << endl ;
  cout << book1.auther << endl << book1.id << endl ;

  
  for(int i=0;i<5;i++){
      cout << book1.rates[i];
  }
    for(int i=0;i<5;i++){
      cout << book.rates[i];
  }

  return 0;
}