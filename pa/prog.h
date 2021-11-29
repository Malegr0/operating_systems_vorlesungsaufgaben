// definition file
// includes


// key definition
#define MAX_FN_LEN 80


// datatypes
typedef struct Node
{
	char file_name[MAX_FN_LEN];
	bool mutex;
	int thrd_number = 0;
	Node* next;
}
Node;