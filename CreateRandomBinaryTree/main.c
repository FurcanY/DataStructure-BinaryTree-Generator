#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"
#include <math.h>
#include "binarytree.h"





int main() {
	srand(time(NULL));

	int* array = NULL;
	struct Node* root = NULL;
	int len = 0;
	int q_num = 0;
	int h = 0;
	printf("Olusturulacak agacin dugum sayisi kac olacak\n");
	scanf("%d", &len);
	struct DataQueue* d_queue = createDataQueue(len);
	char* data = (char*)malloc(sizeof(char));
	getValues(d_queue, len);
	printf("Kac adet soru uretilsin ?\n");
	scanf("%d", &q_num);
	for (int i = 0; i < len; ++i) {
		data[i] = d_queue->array[i];
	}
	for (h = 0; len > pow(2, h); ++h);
	//printf("Height :%d\n", h);
	struct Queue* queue = createQueue(pow(2, h) - 1);

	for (int i = 0; i < q_num; ++i) {
		for (int i = 0; i < (d_queue->capacity); ++i) {
			//printf("%d \n", i);
			generateTree(&root, d_queue);
		}
		int maxHeight = maxDepth(root);

		if (maxHeight > h)
			maxHeight = h;
		//printf("maxheight %d", maxHeight);
		queue = createQueue((int)(pow(2, maxHeight + 1) - 1));
		enqueue(queue, root);
		printf("\n------------Soru %d --------------\n", i + 1);

		printf("\nPreorder siralama\n");
		preorder(root);
		printf("\nInorder siralama\n");
		inorder(root);
		printf("\nPostorder siralama\n");
		postorder(root);
		printf("\n  COZUMU  \n");
		printf("0. yukseklik: ");

		breadthFirst(queue, 0, (int)pow(2, maxHeight + 1) - 1);
		


		free(d_queue);
		d_queue = createDataQueue(len);
		for (int i = 0; i < len; ++i) {
			enqueueData(d_queue, data[i]);
		}
		free(root);
		root = NULL;
		free(queue);
	}








	return 0;
}