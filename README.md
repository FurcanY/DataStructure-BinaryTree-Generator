
# DataStructure BinaryTree  Generator

### *Bu programda istenilen sayı kadar, rastgele BinaryTree oluşturulur ve bu BinaryTree'lerin şemasını şekillendirerek console'da gösterir.*




![image](https://github.com/FurcanY/CSharp-Form-LabirentCozenProgram/assets/114299899/c23e725e-b6ca-4825-a3d3-742263b4f29e)

    Örnek ağaç şekili ve sıralamaları:
   
	Preorder siralama
	E       G       F       D       C       A       I       B       H       J
	Inorder siralama
	D       F       G       C       A       I       E       H       B       J
	Postorder siralama
	D       F       I       A       C       G       H       J       B       E
	
	  COZUMU( Ağacın Şekli)
	0. yukseklik: E(ana kök)
	1. yukseklik: G(sol kök)  B (sağ kök)
	2. yukseklik: F  C  H  J
	3. yukseklik: D  --  --  A  --  --  --  --(boş kök)
	4. yukseklik: --  --  --  --  --  --  --  I  --  --  --  --  --  --  --  --
	
 
> Yukarıdaki  fotoğrafta görüldüğü gibi girilen kök verilerinden sonra üretilmek istenen soru sayısı girilir.  Programımız her soruda ağacı rastgele olacak şekilde dizer. 
> Daha sonra bu ağacın sıralamalarını yazar. En sonda  ise bu ağacın şekil olarak nasıl gözükeceğini gösterir. Bu işlemi istenilen soru sayısına ulaşıncaya kadar devam ettirir.
>  Bu programı yazma sebebim, veri yapıları ve algoritmaları dersinde sıralamaları verilip şekil çizilmesi istenen sorulardan sınavda çıkacak olmasındandır. İnternette bu tarz soruları bulmak kısıtlı olduğundan, C dilinde soru üretip cevabını da gösteren bir program yazmak istedim :D
 
 
## Bu Projeden Öğrendiklerim
 - Binary Search Tree ,Queue ,Linked List veri yapılarına hakimiyet kazandım.
 - Bu veri yapılarının bir programda nerelerde kullanılabileceğine dair fikir kazanarak, algoritmik olarak düşünmede gelişim sağladım.
 - Binary Search Tree'de sıralama algoritmalarına hakimiyet kazandım.
 - C dilinde bellek tahsisi , bellek yönetiminde deneyim kazandım.
 - C dilinde kendi kütüphanemi oluşturmayı öğrendim.
 -  Recursive fonksiyonunu kavradım.
 
  ## Proje İçerisinden Örnek Kodlar
  

	//-----------------------------------------------------------------   
	// [queue.c dosyasından örnek kodlar]

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
	//-------------------------------------------------------------------
    //[binarytree.c dosyasından örnek kodlar]
    
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

 

## :rose: Belki Bakarsın Diye Bırakıyorum :rose:
####  GitHub adresime [buradan](https://github.com/FurcanY) ulaşabilirsiniz.
####  İnstagram adresime [buradan](https://www.instagram.com/y.furcan/) ulaşabilirsiniz.
####  Youtube adresime [buradan](https://www.youtube.com/channel/UCQRXjt0lg2jCnp2NqOAO2Ig) ulaşabilirsiniz.
####  Itch.io adresime [buradan](https://furcany.itch.io/) ulaşabilirsiniz.



