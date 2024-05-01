#pragma once
#ifndef queue_h
#define queue_h

// buraya soyur veri yap�lar� ve metot prototipleri yazilir
//node queue soyut veri yapisi
struct Queue {

	unsigned capacity;
	int front;
	int rear;
	int size;
	struct Node** array;

};

// int data tutan soyut veri yapisi
struct DataQueue {
	unsigned capacity;
	int size;
	char* array;
};

// ------ PROTOT�PLER ------------------
struct Queue* createQueue(unsigned cap);

void enqueue(struct Queue* queue, struct Node* data);

struct Node* dequeue(struct Queue* queue);

struct DataQueue* createDataQueue(unsigned _cap);

void enqueueData(struct DataQueue* queue, char data);

char dequeueData(struct DataQueue* queue,int index);




#endif // !queue_h

