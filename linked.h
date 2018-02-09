
//STRUCT
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

node_t* listFind(list_t list, int value);
