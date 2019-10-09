#include <iostream>

int num_distinct(int a[], int n){
  int i, j, ndistinct;
  bool is_dup;
  ndistinct=0;
  for(i=0; i<n; i++) {
    is_dup=false;
    for(j=0; j<i; j++) {
      if(a[j] == a[i])
        is_dup = true;
    }
    if(!is_dup)
      ndistinct++;
  }
  return ndistinct;
}
//==============================================================================
struct node {
  int val;
  node *next;
};

int num_distictLL(node *lst){
  node *i, *j, *dist;
  //Set node i equal to head (lst)
  i = lst;
  //when the head doesn't equal null and head next doesn't equal nullptr set j equal i
  while(i != nullptr && i->next != nullptr){
    j = i;
    //when the next element j  doesn't equal null and if the val of the first node doesn't
    //match the value of the next node then distinct plus 1
    while(j->next != nullptr){
      if(i->val != j->next->val){
        dist++;
      }else{
        j = j->next; //move on to the next set
      }
      i = i->next;
    }
  }
}
