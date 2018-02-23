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


node_t* createNode (int value)
{
  node_t* node = malloc(sizeof(node_t));
  node->data = value;
  node->next = NULL;
  return node;
}

list_t createList()
{
  node_t* dummy = createNode(INT_MIN);
  list_t list = {dummy,dummy};
  return list;
}

void llLinkAfter(list_t* list, node_t* cur, node_t* newNode)
{
  //node_t* newNode = createNode(data);
  if(cur == list->tail){
    list->tail = newNode;
  }
  newNode->next = cur->next;
  cur->next = newNode;
}

node_t* llUnlinkAfter(list_t* list, node_t* cur)
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

void llInsert(list_t* list, node_t* cur, int data)
{
  node_t* newNode = createNode(data);
  llLinkAfter(list,cur,newNode);
}

void listAppend(list_t *list, int value)
{
  node_t *newNode = createNode(value);
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

void listPush(list_t *list, int value)
{
  //llInsert(list,list->tail,value);
  
  node_t *newNode = createNode(value);
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

int listPop(list_t *list)
{
  assert(list->head->next != NULL);
  
  node_t* p = list->head->next;
  int value = p->data;
  llRemove(list,p);
  
  return value;
}

node_t* listFind(list_t list, int value)
{
  node_t* p = list.head->next;
  
  while (p != NULL){
    if (p->data == value){
      return p;
    } else{
      p = p->next;
    }
  }
}

bool isEmpty(list_t list)
{
   return list.head->next == NULL;
}

int listLength(list_t list)
{
  int i = 0; 
  node_t* p = list.head->next;
  while (p != NULL){
    i++;
    p = p->next;
  }
  return i;
}

void printList(list_t list){
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
void llRemove(list_t* list, node_t* cur)
{
  node_t* p = findPrevNode(list,cur);
  free(llUnlinkAfter(list,p));
  
}
node_t* findPrevNode(list_t* list, node_t* cur)
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

void deleteList(list_t *list)
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
  
  list_t list = createList();
  assert(isEmpty(list));
  assert(listLength(list) == 0);
  assert(listFind(list, 1) == NULL);
  
  
  listAppend(&list, 1);
  listAppend(&list, 2);
  listAppend(&list, 3);
  printList(list);
  printf("%d\n", listLength(list));
  assert(!isEmpty(list));
  assert(listLength(list) == 3);
  assert(listFind(list, 2) != NULL);
  assert(listFind(list, 42) == NULL);
 
  
  listPush(&list, 99);
  listPush(&list, 98);
  listPush(&list, 97);
  printList(list);
  printf("%d\n", listLength(list));

  assert(listLength(list) == 6);
  assert(listFind(list, 2) != NULL);
  assert(listFind(list, 99) != NULL);
  
  
  v = listPop(&list);
  assert(v == 97);
  v = listPop(&list);
  assert(v == 98);
 
  printList(list);
  deleteList(&list);
  assert(isEmpty(list));
  
  // Ex. 1 Tests: Link / Unlink (white-box tests)
  printf("\nLink/ Unlink tests... \n");
  llLinkAfter(&list, list.head, createNode(100));
  llLinkAfter(&list, list.head->next, createNode(102));
  llLinkAfter(&list, list.head->next, createNode(101));
  llLinkAfter(&list, list.tail, createNode(103));
  printList(list);
  
  assert(listLength(list) == 4);
  assert(llUnlinkAfter(&list, list.tail) == NULL);
  assert(listLength(list) == 4);
  tmp = llUnlinkAfter(&list, list.head->next);
  printList(list);
  
  assert(listLength(list) == 3);
  assert(tmp->data == 101);
  free(tmp);
  tmp = llUnlinkAfter(&list, list.head->next->next);
  printList(list);
  
  assert(listLength(list) == 2);
  assert(tmp->data == 103);
  free(tmp);
  tmp = llUnlinkAfter(&list, list.head);
  printList(list);
  
  assert(listLength(list) == 1);
  assert(tmp->data == 100);
  free(tmp);
  deleteList(&list);
  assert(isEmpty(list));
  
  // Ex. 3 Tests:  Insert / Remove  (white-box tests)
printf("\nInsert / Remove tests... \n");
llInsert(&list, list.head, 100);
llInsert(&list, list.head->next, 102);
llInsert(&list, list.head->next, 101);
llInsert(&list, list.tail, 103);
printList(list);
  
assert(listLength(list) == 4);
llRemove(&list, list.head->next->next);
printList(list);
  
assert(listLength(list) == 3);
llRemove(&list, list.tail);
printList(list);
  
assert(listLength(list) == 2);
llRemove(&list, list.head->next);
printList(list);
  
assert(listLength(list) == 1);
deleteList(&list);
assert(isEmpty(list));
  
}

