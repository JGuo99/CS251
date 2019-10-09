#include <iostream>
using namespace std;

void fubar(unsigned int n) {
int i, j;

  for(i=0; i<n; i++){
    cout <<"tick" << endl;
  }
  for(i=0; i<n; i++) {
    for(j=0; j<i; j++) {
        cout <<"tick" << endl;
    }
  }
}
//===========================================
void foo(unsigned int n) {
  if(n==0)
    cout << "tick" << endl;
  else {
    foo(n-1);
    foo(n-1);
    foo(n-1);
  }
}

int main(){
  //fubar(4);
  foo(3);
  // int i;
  // cout<<"Enter Value: (999 to exit) ";
  // cin>>i;
  // while(i != 999){
  //   fubar(i);
  // }
  return 0;
}
