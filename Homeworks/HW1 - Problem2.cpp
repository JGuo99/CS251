#include <iostream>

unsigned int n_choose_2(unsigned int n){
  //Base Case
  if(n == 0){
    return 0;
  }else{
    //adding n-1 to 1
    return n_choose_2(n-1) + (n-1);
  }
}

//Code Below is only for testing n_choose_2 function
using namespace std;
int main() {
  int i;
  cout<<"Enter value: ";
  cin >>i;
  cout<< n_choose_2(i) << endl;
  return 0;
}
