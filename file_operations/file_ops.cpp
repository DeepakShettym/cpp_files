#include<iostream>
#include<fstream>
#include<string>
using namespace std;
int main(){

  string arr[5] = {"hey how are u xyz","hey how are u abc" ,"hey how are u pqr","hey how are u qwe","hey how are u mnb"};

  ofstream outFile("textFile.txt");

  if(!outFile){
    cout << "cannot create file" << endl;
  }else{
    cout << "file created sucessfully" << endl;
  }


  for(int i = 0;i<5;i++){
    outFile << arr[i] << endl;
  }

  
  outFile.close();

  ifstream inFile("textFile.txt");

  if(!inFile){
    cout << "file does not exist" << endl;
  }else{
    cout << "file is present";
  }

  string line;

  int targetLine = 3; // read 3rd line
  int startLine = 1;
  cout << "\nReading from the file:" << endl;
  while (getline(inFile, line)) {
      if(startLine == targetLine){
        cout << line << endl;
        break;
      } 
      startLine++; 
  }

  inFile.close();
  
  ifstream inFile1("textFile.txt");  


  int stopLine = 3; // read until 3rd line
  startLine = 0;

  while (getline(inFile1, line)) {
    if(startLine == stopLine){
      break;
    } 
    cout << line << endl;
    startLine++; 
}

inFile1.close();

  return 0;
}


/*  Output : 
 file created sucessfully
 file is present
 Reading from the file:
 hey how are u pqr
 hey how are u xyz
 hey how are u abc
 hey how are u pqr
*/