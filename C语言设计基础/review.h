typedef struct Node *node;
struct Node
{
	int data;
	node next;
};

void ptr(node h);

node cre_nega();

node cre_posi();

void appand(node h,int n);

void insert(node *h,int n);

node reverse(node h);