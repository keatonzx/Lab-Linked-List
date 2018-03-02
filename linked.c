/*
* Keaton Armstrong
* Lab 5 and 6 
*Implementation of a list ADT usuing linked list data structure 
*
*
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
#include <limits.h>

#include "linked.h"


node_t* nodeCreate (int value)
{
  node_t* node = malloc(sizeof(node_t));
  node->data = value;
  node->next = NULL;
  return node;
}

Linkedlist_t llCreate()
{
  node_t* dummy = nodeCreate(INT_MIN);
  Linkedlist_t list = {dummy,dummy};
  return list;
}

void llLinkAfter(Linkedlist_t* list, node_t* cur, node_t* newNode)
{
  //node_t* newNode = createNode(data);
  if(cur == list->tail){
    list->tail = newNode;
  }
  newNode->next = cur->next;
  cur->next = newNode;
}

node_t* llUnlinkAfter(Linkedlist_t* list, node_t* cur)
{
 node_t* p = cur->next;
 
  if(p != NULL){
    cur->next = p->next;
  }
  if(cur->next==NULL){
    list->tail = cur;
  }
  return p;
}

void llInsert(Linkedlist_t* list, node_t* cur, int data)
{
  node_t* newNode = nodeCreate(data);
  llLinkAfter(list,cur,newNode);
}

void llAppend(Linkedlist_t *list, int value)
{
  node_t *newNode = nodeCreate(value);
  llInsert(list,list->tail,value);
  /*
  if(isEmpty(*list)){
    listPush(list,value);
  } else{
      node_t* p = list->head;

      while(p->next != NULL){
        p = p->next;
      }
      p->next = createNode(value);
      list->tail = p->next;
  }*/
}

void llPush(Linkedlist_t *list, int value)
{
  //llInsert(list,list->tail,value);
  
  node_t *newNode = nodeCreate(value);
  llInsert(list,list->head,value);
/*
  if(list->head->next == NULL){
    list->head->next = newNode;
    list->tail = newNode;
  } else{
    newNode->next = list->head->next;
    list->head->next = newNode;
  }*/
}

int llPop(Linkedlist_t *list)
{
  assert(list->head->next != NULL);
  
  node_t* p = list->head->next;
  int value = p->data;
  llRemove(list,p);
  
  return value;
}

node_t* llFind(Linkedlist_t list, int value)
{
  node_t* p = list.head->next;
  if(p == NULL){
    return p;
  }
  while (p != NULL){
    if (p->data == value){
      return p;
    } else{
      p = p->next;
    }
  }
}

node_t* findInsertionPoint(Linkedlist_t *list, int value)
{
  node_t* p = list->head;
  
  while(p->next != NULL && p->next->data <= value){
    p = p->next;
  }
  
  return p;
}

void llInsertSorted(Linkedlist_t *list, int value)
{
  llInsert(list,findInsertionPoint(list,value),value); 
}

  
bool llIsEmpty(Linkedlist_t list)
{
   return list.head->next == NULL;
}

int llLength(Linkedlist_t list)
{
  int i = 0; 
  node_t* p = list.head->next;
  while (p != NULL){
    i++;
    p = p->next;
  }
  return i;
}

void llPrint(Linkedlist_t list){
  node_t* p = list.head->next;
  
  while(p != NULL){
    if (p == list.head->next) {
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
void llRemove(Linkedlist_t* list, node_t* cur)
{
  node_t* p = findPrevNode(list,cur);
  free(llUnlinkAfter(list,p));
  
}
node_t* findPrevNode(Linkedlist_t* list, node_t* cur)
{
  node_t* p = list->head;
  
  while(p->next != cur)
  {
    if(p->next == list->tail){
      return p;
    }    
    p = p->next;
  } 
  return p;
}

void llDelete(Linkedlist_t *list)
{
  node_t* q = list->head->next;
  
  printf("\n");
  
  while(q != NULL){
    q = q->next;
    printf("Freeing the node [%d]\n",list->head->next->data);
    free(list->head->next);
    list->head->next = q;
  }
}

void main()
{
   int v;
   node_t* tmp;

   // Basic tests for Lab 5 List ADT
   Linkedlist_t list = llCreate();
   assert(llIsEmpty(list));
   assert(llLength(list) == 0);
   assert(llFind(list, 1) == NULL);
   llAppend(&list, 1);
   llAppend(&list, 2);
   llAppend(&list, 3);
   llPrint(list);
   assert(!llIsEmpty(list));
   assert(llLength(list) == 3);
   assert(llFind(list, 2) != NULL);
   assert(llFind(list, 42) == NULL);
   llPush(&list, 99);
   llPush(&list, 98);
   llPush(&list, 97);
   llPrint(list);
   assert(llLength(list) == 6);
   assert(llFind(list, 2) != NULL);
   assert(llFind(list, 99) != NULL);
   v = llPop(&list);
   assert(v == 97);
   v = llPop(&list);
   assert(v == 98);
   llPrint(list);
   llDelete(&list);
   assert(llIsEmpty(list));
   
   // Ex. 1 Tests:  Link / Unlink (white-box tests)
   printf("\nLink / Unlink tests... \n");
   llLinkAfter(&list, list.head, nodeCreate(100));
   llLinkAfter(&list, list.head->next, nodeCreate(102));
   llLinkAfter(&list, list.head->next, nodeCreate(101));
   llLinkAfter(&list, list.tail, nodeCreate(103));
   llPrint(list);
   assert(llLength(list) == 4);
   assert(llUnlinkAfter(&list, list.tail) == NULL);
   assert(llLength(list) == 4);
   tmp = llUnlinkAfter(&list, list.head->next);
   llPrint(list);
   assert(llLength(list) == 3);
   assert(tmp->data == 101);
   free(tmp);
   
   tmp = llUnlinkAfter(&list, list.head->next->next);
   llPrint(list);
   assert(llLength(list) == 2);
   assert(tmp->data == 103);
   free(tmp);
 
   tmp = llUnlinkAfter(&list, list.head);
   llPrint(list);
   assert(llLength(list) == 1);
   assert(tmp->data == 100);
   free(tmp);
   llDelete(&list);
   assert(llIsEmpty(list));
   
   
   // Ex. 3 Tests: Insert / Remove  
   printf("\nInsert / Remove tests... \n");
   llInsert(&list, list.head, 100);
   llInsert(&list, list.head->next, 102);
   llInsert(&list, list.head->next, 101);
   llInsert(&list, list.tail, 103);
   llPrint(list);
   assert(llLength(list) == 4);
   llRemove(&list, list.head->next->next);
   llPrint(list);
   assert(llLength(list) == 3);
   llRemove(&list, list.tail);
   llPrint(list);
   assert(llLength(list) == 2);
   llRemove(&list, list.head->next);
   llPrint(list);
   assert(llLength(list) == 1);
   llDelete(&list);
   assert(llIsEmpty(list));
   
   
   // Ex. 4 Tests: Insert Sorted  
   printf("\nInsert Sorted tests... \n");
   llInsertSorted(&list, 203);
   llInsertSorted(&list, 204);
   llInsertSorted(&list, 201);
   llInsertSorted(&list, 202);
   llPrint(list);
   assert(llLength(list) == 4);
   v = llPop(&list);
   assert(v == 201);
   v = llPop(&list);
   assert(v == 202);
   llDelete(&list);
   assert(llIsEmpty(list));
   
  
}

