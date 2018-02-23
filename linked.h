//Header file for an implementation of a basic list ADT usuing the linked list data structure
//Keaton Armstrong 

//STRUCTS
struct node{
  int data;
  struct node* next;
};
typedef struct node node_t;

struct list{
  node_t* head;
  node_t* tail;
};
typedef struct list list_t;

//FUNCTIONS
node_t* createNode (int value);

list_t createList();

void deleteList(list_t *list);

void printList(list_t list);
 
bool isEmpty(list_t list);

int listLength(list_t list);

void listAppend(list_t* list, int value);

void listPush(list_t *list, int value);

int listPop(list_t *list);

node_t* listFind(list_t list, int value);

void llLinkAfter(list_t* list, node_t* cur, node_t* newNode);

node_t* llUnlinkAfter(list_t* list, node_t* cur);

void llInsert(list_t* list, node_t* cur, int data);

void llRemove(list_t* list, node_t* cur);

node_t* findPrevNode(list_t* list, node_t* cur);
