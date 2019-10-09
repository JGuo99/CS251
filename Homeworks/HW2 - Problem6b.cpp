#include<iostream>
//returns index i minimizing max(f[i], g[i])
int minimax(double f[], double g[], const int n){
  double min = 0;
  int current = n / 2;
  int last = current;
  int min = -1;
  int max = n;
  while (current >= 0 && current < n){ //when the current index is greater not zero or greater than n
    if (f[current] > g[current]){ //check if the f array is greater than g array
      if (f[current] < min){ //if f array is less than minimum
        min = f[current]; //set it to f array
        min = current; //set to current index
        max = current; //set max to current index too
      }
      current = current / 2;
    }else{
      if (g[current] < min){ //if g array is less than minimum
        min = g[current]; //set minimum to g array
        min = current; //set to current index
      }
      current = (current + max) / 2;
    }
    if (last == current) //if the the index are the same
        break;
    last = current; //set the last index to the current index
  }
  return min; //return minimum index
}

int main(int argc, char* argv[]){
  const int n = 10;
  double f[] = { 2,4,6,6,8,10,12,14,16,18 },
  g[] = { 17,16,16,10,9,9,8,7,6,5 };
  std::cout << minimax(f, g, n);
  return 1;
}
