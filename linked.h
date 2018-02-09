
//STRUCT
struct node{
  int data;
  struct node* next;
};
typedef struct node node_t;

struct list{
  node_t* head;
};
typedef struct list list_t;
//FUNCTIONS
node_t* createNode (int value);

list_t createList();

void printList(list_t list);
 
bool isEmpty(list_t list);

int listLength(list_t list);

void listAppend(list_t* list, int value);

