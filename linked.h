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
typedef struct list Linkedlist_t;

//FUNCTIONS
node_t* nodeCreate (int value);

Linkedlist_t llCreate();

void llDelete(Linkedlist_t *list);

void llPrint(Linkedlist_t list);
 
bool llisEmpty(Linkedlist_t list);

int listLength(Linkedlist_t list);

void llAppend(Linkedlist_t* list, int value);

void llPush(Linkedlist_t *list, int value);

int llPop(Linkedlist_t *list);

node_t* llFind(Linkedlist_t list, int value);

void llLinkAfter(Linkedlist_t* list, node_t* cur, node_t* newNode);

node_t* llUnlinkAfter(Linkedlist_t* list, node_t* cur);

void llInsert(Linkedlist_t* list, node_t* cur, int data);

void llRemove(Linkedlist_t* list, node_t* cur);

node_t* findPrevNode(Linkedlist_t* list, node_t* cur);
