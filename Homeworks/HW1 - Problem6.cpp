#include<iostream>
using namespace std;

bool is_perm(int a[],int n){
   int p = 0;
   int ck[n]; //check ck array
   //set the check array to zero
   for(int i=0; i<n; i++){
       ck[i] = 0;
    }
   //keep track of the number in the ck array
   for(int i=0; i<n; i++){
       ck[a[i]] = 1;
   }
   //check to see if the numbers are present
   for(int i=0; i<n; i++){
       if(ck[i] == 0){
           p = 1;
       }
   }
   if(p == 1) return false;
   else return true;
}

int* perm2inverse(int a[],int n){
   //if it is not a permutaion then it wont able to do inverse
   if(!is_perm(a,n))
       return nullptr;
   //if it is permutation then it will return inverse
   int *inver = new int[n];
   for(int i=0; i<n; i++){
       *(inver + a[i]) = i;
   }
   return inver;
}

//Only for Testing
int main(){
    int array1[3] = {2,0,1};
    int array2[3] = {1,2,0};
    int* inver_reslut = perm2inverse(array1,3);
    int* perm_reslut = perm2inverse(array2,3);
    cout<<*inver_reslut<<" "<<*(inver_reslut+1)<<" "<<*(inver_reslut+2)<<endl;
    cout<<*perm_reslut<<" "<<*(perm_reslut+1)<<" "<<*(perm_reslut+2)<<endl;
}
