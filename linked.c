/*
* Keaton Armstrong
* Lab 5
*
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>

#include "linked.h"


node_t* createNode (int value)
{
  node_t* node = malloc(sizeof(node_t));
  node->data = value;
  node->next = NULL;
  return node;
}

list_t createList()
{
  list_t list = {NULL,NULL};
  return list;
}

void listAppend(list_t *list, int value)
{
  
  if(isEmpty(*list)){
    list->head = createNode(value);
  }
  else{
    
      node_t* p = list->head;

      while(p->next != NULL){
        p = p->next;
      }
      p->next = createNode(value);
      list->tail = p->next;
  }
}


bool isEmpty(list_t list)
{
   return list.head == NULL;
}

/*int listLength(list_t* list)
{
  int i; 
  while (list->)
}*/
void printList(list_t list){
  node_t* p = list.head;
  
  while(p != NULL){
    if (p == list.head) {
      printf("h");
    }
    
    printf("[%d]", p->data);
    
    if (p == list.tail) {
      printf("t");
    }
    if (p->next ==NULL) {
      printf("-|");
    }
    else {
      printf("-->");
    }
    p = p->next;
  }
  printf("\n");
}

void deleteList(list_t *list)
{
  node_t* q = list->head;
  
  printf("\n");
  
  while(q != NULL){
    q = q->next;
    printf("Freeing the node [%d]\n",list->head->data);
    free(list->head);
    list->head = q;
  }
}

void main()
{
  int v;
  list_t list = createList();
  assert(isEmpty(list));
  //assert(listLength(list) == 0);
  
  
  
  
  listAppend(&list, 1);
  listAppend(&list, 2);
  listAppend(&list, 3);
  printList(list);
 // printList(listtail);
  deleteList(&list);
  assert(isEmpty(list));
 /* node_t *head = NULL;
  head = createNode(42);
  head->next = createNode(24);
  head->next->next = createNode(9000);
  printNode(head);
  
  node_t *p = head;
  
  while(p != NULL){
    printf("[%d]-->", p->data);
    
    if(p->next == NULL){
      printf("|||");
    }
    p = p->next;
  }
  
  node_t* q = head;
  
  printf("\n");
  
  while(q != NULL){
    q = q->next;
    printf("Freeing the node [%d]\n",head->data);
    free(head);
    head = q;
  }*/
}

