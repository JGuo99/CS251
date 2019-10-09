#include<iostream>
#define N 10     // or some other number...
using namespace std;

void layers(int a[][N]){
  //value (val), column (col), and row (row) are all set to zero;
  int val = 0, col = 0, row = 0;
  int size = N*N; //the total size of the cells
  //loop through the cells
  while(val < size){
    int ctmp = col; //set tmp column equal to column
    int rtmp = row; //set tmp row equal to row
    //row must be larger than zero and column can't be larger than the size
    while(ctmp < N && rtmp > 0){
      a[rtmp][ctmp] = val; //set the value to that location row * column
      val++;
      //to move the row and column
      rtmp--;
      ctmp++;      
    }
    //check if the row is completed or not
    if(row < N-1){
      row++;
    }else{
      //if the row is completed (last), then start moving the column
      col++;
    }
  }
}

int main(){
  //creating an N*N array, layering it and displaying it
  int array[N][N];
  layers(array);
  for(int i=0;i<N;i++){
    for(int j=0;j<N;j++){
      cout<<setw(3)<<array[i][j]<<" ";
    }
    cout<<endl;
  }
  return 0;
}
