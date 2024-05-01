#ifndef binarytree_h
#define binarytree_h

//binary tree soyut veri yapisi
struct Node {
	char data;
	struct Node* left;
	struct Node* right;
};
// ---------- PROTOTIPLER ------------
struct Node* createNode(char x);

void preorder(struct Node* root);

void inorder(struct Node* root);

void postorder(struct Node* root);

void breadthFirst(struct Queue* queue,int num,int size);

void getLength(struct Node* root, int* len);

void generateTree(struct Node** root, struct DataQueue* d_queue);

char getRandom(struct DataQueue* d_queue);

void getValues(struct DataQueue* d_queue, int data_count);

void getNewLine(int num,int size);

int maxDepth(struct Node* root);



#endif // !binarytree_h

