
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "list.h"

int main() {
  int x;
  printf("Write your Tests for your linked list implementation\n");

  /** Test functions list_alloc & list_print**/
  list_t *mylist;
  mylist = list_alloc();
  list_print(mylist);

  int i = 0; 
  for(i = 10; i <= 100; i += 10){
    list_add_to_front(mylist, i); 
  }

  if(strcmp("100->90->80->70->60->50->40->30->20->10->NULL",listToString(mylist)) != 0)
  {
        printf("list_add_to_front : FAILED\n");
  }else{
    printf("list_add_to_front : PASSED\n"); 
  }

  /* Test for functions list_free */
  printf("List before list_free: \n"); 
  list_print(mylist);
  list_free(mylist); 
  printf("List after list_free: \n"); 
  list_print(mylist);

  
  /*Test for list_add_to_back*/
  list_add_to_back(mylist, 10);
  list_add_to_back(mylist, 20);
  list_add_to_back(mylist, 30);
  list_print(mylist);
   

  /*Test for list_add_at_index*/
  list_add_at_index(mylist, 25, 2);
  list_add_at_index(mylist, 5, 0);
  list_add_at_index(mylist, 60, 8);
  list_add_at_index(mylist, 50, -1);
  list_add_at_index(mylist, 3, -8);
   if(strcmp("5->10->20->25->30->50->NULL",listToString(mylist)) != 0)
  {
        printf("list_add_at_index: FAILED\n");
  }else{
    printf("list_add_at_index: PASSED\n");
  } 
  printf("List after add at index: \n");
  list_print(mylist);
  
  int listlen = list_length(mylist); 

  if(listlen != 6){
    printf("list_length: FAILED\n"); 
  }else{
    printf("list_length: PASSED\n"); 
  }

  printf("The list length is %d\n", listlen);

  /*Test for the remove functions*/
  list_remove_from_back(mylist);
  
  if(strcmp("5->10->20->25->30->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_from_back: FAILED\n");
  }else{
    printf("list_remove_from_back: PASSED\n");
  } 

  printf("%s", listToString(mylist)); 

  printf("List after remove from back: \n"); 
  list_print(mylist); 
  

  list_remove_from_front(mylist); 
  
  if(strcmp("10->20->25->30->NULL",listToString(mylist)) != 0)
  {
        printf("list_remove_from_front : FAILED\n");
  }else{
    printf("list_remove_from_front : PASSED\n");
  }

  printf("List after remove from front: \n");
  list_print(mylist); 
  
  
  list_remove_at_index(mylist, 2);
  list_remove_at_index(mylist, 0);
  list_remove_at_index(mylist, -1);
  list_remove_at_index(mylist, 7);
  
  if(strcmp("20->NULL",listToString(mylist)) != 0)
  {
    printf("list_remove_at_index : FAILED\n");
  }else{
    printf("list_remove_at_index : PASSED\n");
  }
  printf("List after remove from index: \n");
  list_print(mylist);

  /*Test for the list_is_in */
  bool test1 = list_is_in(mylist, 20);
  bool test2 = list_is_in(mylist, 30);
  printf("Is %d in the list?: %d\n", 20, list_is_in(mylist, 20));
  printf("Is %d in the list?: %d\n", 30, list_is_in(mylist, 30));

  if(test1 == 0 && test2 == 1){
    printf("list_is_in: PASSED\n"); 
  }else{
    printf("list_is_in: FAILED\n"); 
  }
   
  /*Test for the list_get_elem_at*/
  int test3 = list_get_elem_at(mylist, 0); 
  int test4 = list_get_elem_at(mylist, 5); 
  int test5 = list_get_elem_at(mylist, -1); 
  int test6 = list_get_elem_at(mylist, -5); 

  printf("Value at %d in the list?: %d\n", 0, list_get_elem_at(mylist, 0));
  printf("Value at %d in the list?: %d\n", 5, list_get_elem_at(mylist, 5));
  printf("Value at %d in the list?: %d\n", -1, list_get_elem_at(mylist, -1));
  printf("Value at %d in the list?: %d\n", -5, list_get_elem_at(mylist, -5));

  if(test3 == 20 && test4 == -1 && test5 == 20 && test6 == -1){
    printf("list_get_elem_at: PASSED\n"); 
  }else{
    printf("list_get_elem_at: FAILED\n"); 
  }

  
  /*Test for list_get_index_of*/
  int test7 = list_get_index_of(mylist, 20); 
  int test8 = list_get_index_of(mylist, 40); 
  printf("Index of %d?: %d\n", 20, list_get_index_of(mylist, 20));
  printf("Index of %d?: %d\n", 40, list_get_index_of(mylist, 40));
  if(test7 == 0 && test8 == -1){
    printf("list_get_index_of: PASSED\n"); 
  }else{
    printf("list_get_index_of: FAILED\n");
  }

  /**Stress test**/
  list_free(mylist); 

  int j;  
  for(j = 1; j <= 10000; j++){
    if(j % 2 == 0){
      list_add_to_front(mylist, j); 
    }else if(j % 3 == 0){
      list_add_at_index(mylist, j, 1); 
    }else{
      list_add_to_back(mylist, j); 
    }
  }

  if(list_length(mylist) == 10000){
    printf("Stress testing add: PASSED\n");
  }else{
    printf("Stress testing add: FAILED\n"); 
  }

  int k = 0; 
  for(k = 0; k < 10001; k++){
    if(list_length(mylist) == 0){
      printf("Empty list\n"); 
      break; 
    }

    if(i % 2 == 0){
      list_remove_from_back(mylist); 
    }else if(i % 3 == 0){
      list_remove_from_front(mylist); 
    }else{
        list_remove_at_index(mylist, 1); 
    }
  }

  if(list_length(mylist) == 0){
    printf("Stress testing remove: PASSED\n");
  }else{
    printf("Stress testing remove: FAILED\n"); 
  }
  printf("Removed list: \n"); 
  list_print(mylist);
  
  printf("%s", "Cleaning up\n"); 
  list_free(mylist); 
  list_remove_at_index(mylist, 1); 
  list_remove_from_back(mylist); 
  list_remove_from_front(mylist); 

  printf("Final list: \n");
  list_print(mylist);

  return 0;
}