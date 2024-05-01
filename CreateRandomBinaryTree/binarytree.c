#include <stdio.h>
#include <stdlib.h>
#include "binarytree.h"
#include "queue.h"
#include <math.h>
// .h dosyasi include edilmeli
// queue.h dosyasinin eklenme sebebi bir fonksiyonun parametresinde queue veri yapisinin olmasidir.

// node olusturma fonksiyonu
struct Node* createNode(char x) {
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	if (newNode != NULL) {
		newNode->data = x;
		newNode->left = NULL;
		newNode->right = NULL;
	}

	return newNode;
}

//preorder root left right
void preorder(struct Node* root) {
	printf("%c\t", root->data);

	if (root->left != NULL)
		preorder(root->left);

	if (root->right != NULL)
		preorder(root->right);
}
// inorder left root right
void inorder(struct Node* root) {
	if (root->left != NULL)
		inorder(root->left);

	printf("%c\t", root->data);

	if (root->right != NULL)
		inorder(root->right);
}
//postorder left right root
void postorder(struct Node* root) {

	if (root->left != NULL)
		postorder(root->left);

	if (root->right != NULL)
		postorder(root->right);

	printf("%c\t", root->data);
}
//breadth first value
void breadthFirst(struct Queue* queue,int num,int size) {
	struct Node* tmp;
	
	/*if (queue->size == 0)
		return;*/
	if (num == size)
		return;
	tmp = dequeue(queue);
	if (tmp == NULL) {
		printf("--  ");
		getNewLine(++num,size);
		enqueue(queue, NULL);
		enqueue(queue, NULL);
	}
	else {
		printf("%c  ", tmp->data);
		getNewLine(++num,size);
	
		//if (tmp->left != NULL)
		enqueue(queue, tmp->left);
		//if (tmp->right != NULL)
		enqueue(queue, tmp->right);
	}
	

	
	breadthFirst(queue,num,size);
	

}
// len of tree
void getLength(struct Node* root, int* len) {
	//printf("%d\n",*len);
	if (root == NULL) {
		return;
	}
	(*len)++;
	getLength(root->left, len);
	getLength(root->right, len);

}

//rastgele aðaç oluþturma
void generateTree(struct Node** root, struct DataQueue* d_queue) {
	
	if (*root == NULL) {
		char data = getRandom(d_queue);
		*root = createNode(data);
		//printf("Root Data :%d\n", (*root)->data);

		return;
	}
	int choose = rand() % 2;
	//printf("Choose :%d\n", choose);
	if (choose == 0)
		generateTree(&((*root)->left), d_queue);
	else
		generateTree(&((*root)->right), d_queue);

}

//rastgele sayi alma
char getRandom(struct DataQueue* d_queue) {
	if (-1 == d_queue->size)
		return 'x';
	int index = rand() % (d_queue->size+1);
	//printf("index %d",index);
	 char data = dequeueData(d_queue, index);
	//printf("data %d", data);
	return data;
}

//verileri alma  fonskiyonu 
void getValues(struct DataQueue *d_queue, int data_count) {
	char data = ' ';
	if (data_count == 0)
		return;
	printf("Veri girisi yapiniz(char) !\n");
	scanf(" %c",&data);
	enqueueData(d_queue, data);
	//printf("d_queue data : %d\n",d_queue->array[4-data_count]);
	getValues(d_queue, --data_count);
}
void getNewLine(int num,int size) {
	int i = 0;
	if (num == size)
		return;
	while (i<=num) {
		if (num == ((int)pow(2,i)-1)) {
			//printf("pow %d\n", (int)pow(2, num));
			printf("\n");
			printf("%d. yukseklik: ", i);
			return;
		}
		++i;
	}
}

int maxDepth(struct Node* root)
{
	if (root == NULL)
		return -1;
	else {
		int lDepth = maxDepth(root->left);
		int rDepth = maxDepth(root->right);

		/* use the larger one */
		if (lDepth > rDepth)
			return (lDepth + 1);
		else
			return (rDepth + 1);
	}
}

