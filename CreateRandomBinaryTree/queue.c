#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "queue.h"	
#include "binarytree.h"

// bu veri yapisi bir metotda parametre olarak kullanildigindan burada olusturulmasi gerek.


//struct Node {
//	int data;
//	struct Node* left;
//	struct Node* right;
//};

//veya binarytree.h da burada include edilebilir.



//queue olusturma fonskiyonu
struct Queue* createQueue(unsigned cap) {
	struct Queue* newQueue = (struct Queue*)malloc(sizeof(struct Queue));
	newQueue->capacity = cap;
	newQueue->front = 0;
	newQueue->rear = cap - 1;
	newQueue->array = (struct Node**)malloc(sizeof(struct Node*) * cap);
	newQueue->size = 0;

	return newQueue;
}

//----------- Node veri tutan queue fonksiyonlari ----------------

//sondan eleman ekleme fonksiyonu
void enqueue(struct Queue* queue, struct Node* data) {
	if (queue->size == queue->capacity)
		return;
	queue->rear = (queue->rear + 1) % queue->capacity;
	queue->array[queue->rear] = data;
	queue->size = queue->size + 1;

}
//bastan eleman alma fonksiyonu
struct Node* dequeue(struct Queue* queue) {
	struct Node* item;
	if (queue->size == 0)
		return NULL;
	item = queue->array[queue->front];
	queue->front = (queue->front + 1) % queue->capacity;
	queue->size = (queue->size) - 1;
	return item;
}

//------------ Ýnt veri tutan queue fonksiyonlari ---------------

struct DataQueue* createDataQueue(unsigned cap) {
	struct DataQueue* d_queue = (struct DataQueue*)malloc(sizeof(struct DataQueue));
	d_queue->capacity = cap;
	d_queue->array = (char*)malloc(sizeof(char) * cap);
	d_queue->size = -1;

	return d_queue;
}
//eleman ekleme
void enqueueData(struct DataQueue* queue, char data) {
	if (queue->size == queue->capacity - 1)
		return;
	queue->array[++(queue->size)] = data;
}
//indisle eleman alma fonksiyonu
char dequeueData(struct DataQueue* queue,int index) {
	char data;
	//printf("queue size : %d", queue->size);
	if (queue->size == -1)
		return -99;
	data = queue->array[index];
	for (int i = index; i <= queue->size; ++i) {
		queue->array[i] = queue->array[i + 1];
	}
	queue->array[(queue->size)--] = ' ';
	return data;
}


