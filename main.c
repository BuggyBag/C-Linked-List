#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 1

typedef struct node{
  char info;
  struct node * link;
} NODE;

void insert (NODE ** headPointer, char info){    //head or list; its the same because the head is
                                                 //the 1st element in a list.
  //check for free memory
  NODE * node = (NODE *) malloc(sizeof(NODE));
  if (node == NULL){
    printf("\n MEMORY OVERFLOW. \n");
    exit(SUCCESS);
  } else {
    node -> info = info;
    node -> link = *headPointer;
    *headPointer = node;
  }
  
}

void delete (NODE ** list, NODE * x){

  NODE * node, * pred = NULL;
  
  //check if list is empty
  if (*list == NULL){
    printf("Empty list \n");
    return;
  }

  //start search for node x
  node = *list;
  
  while (node != NULL && node != x){
    //go to the next node
    pred = node;
    node = node -> link;
  }
  
  // node was found?
  if (node == NULL){
    printf("Node was not found \n");
    return;
  }

  //delete node
  if (*list == x){
    *list = (*list) -> link;  
  } else {
    pred -> link = x -> link;
  }
  
  // Return node to free memory
  free(x);
}

NODE * find (NODE * list, char info){

  NODE * node;
  
  //Initialize the node find with info
  node = list;
  while (node != NULL) {
    //Check if it is the node
    if (node -> info == info)
      return node;
    //Go to the next node
    node = node -> link;
  }
  // The node with info is not in the list

  return NULL;
}

NODE * get(NODE * list, int p) {

  // precondition validation
  if (p < 1){
    return NULL;
  }

  NODE * node;
  
  // Initialize the node search
  node = list;
  
  for(int i = 1; i < p; i++) {
    // Check if there are more nodes
  
    if (node == NULL){
      printf(" The position is not in the list. \n");
      return NULL;
    }
    
    // Go to the next node
    node = node -> link;
  }
  
  // Return node at position P
  return node;
}

int main(void) {
  printf("\n\n\t Linked Lists \n\n");

  NODE * list = NULL;

  //insert in the list
  insert(&list, 'a');
  insert(&list, 'b');
  insert(&list, 'c');
  insert(&list, 'd');
  insert(&list, 'e');
  insert(&list, 'f');

  NODE * temp = list;

  printf("\n");

  //search in the list
  //NODE * foundNode = find(&list, 'b'); //find b in the list
  printf("Search for b: %c \n", find(list, 'b') -> info); 
  printf("Search for d: %c \n", find(list, 'd') -> info);
  if (find(list, 'z') != NULL)
    printf("Search for z: %c \n", find(list, 'z') -> info);
  else
    printf(" This value does not exist.\n");
  
  //access the list
  //NODE * newValue = get(&list, 3); //get the 3th node
  printf("Third node in list: %c \n", get(list, 3) -> info);
  printf("Second node in list: %c \n", get(list, 2) -> info);
  if (get(list, 6) != NULL)
    printf("Sixth node in list: %c \n", get(list, 6) -> info);
  else
    printf(" The position is not in the list. \n");

  printf("\n");
  
  if (get(list, 7) != NULL)
    printf("Seventh node in list: %c \n", get(list, 7) -> info);
  else
    printf(" The position is not in the list. \n");

  if (get(list, -10) != NULL)
    printf("Seventh node in list: %c \n", get(list, -10) -> info);
  else
    printf(" The position is not in the list. \n");

  printf("\n");
  
  temp = list;
  while (temp != NULL){
    printf("%c \n", temp -> info);
    temp = temp -> link;
  }

printf("\n");
  
  delete(&list, find(list, 'a'));
  delete(&list, get(list, 1));
  delete(&list, find(list, 'c'));

  temp = list;
  
  while (temp != NULL){
    printf("%c \n", temp -> info);
    temp = temp -> link;
  }
  
  return SUCCESS;
}