/*
* Keaton Armstrong
* Lab 5
*
*
*
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
  int data;
  struct node* next;
};
typedef struct node node_t;

node_t* createNode (int value){
  node_t* node = malloc(sizeof(node_t));
  node->data = value;
  node->next = NULL;
  return node;
}


void printNode(node_t *node){
  node_t * p = node;
  
  while(p != NULL)
  {
    printf("%d\n", p->data);
    p = p->next;
  }
}

void main(){
  node_t *head = NULL;
  head = createNode(42);
  head->next = createNode(24);
  head->next->next = createNode(9000);
  printNode(head);
  
  node_t *p = head;
  
  while(p != NULL)
  {
    printf("[%d]-->", p->data);
    p = p->next;
  }
  
}

