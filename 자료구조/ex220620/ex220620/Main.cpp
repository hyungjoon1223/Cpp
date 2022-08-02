#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include <algorithm>

struct Node
{
    int data;
    Node* lChild;
    Node* rChild;
};
struct Queue
{
    Node** queue;
    int front;
    int rear;
    int capacity;
};
void Push(Queue* pq, Node* data)
{
    if ((pq->rear + 1) % pq->capacity == pq->front)
        return;

    pq->queue[pq->rear = (pq->rear + 1) % pq->capacity] = data;
}
Node* Pop(Queue* pq)
{
    if (pq->front == pq->rear)
        throw "front 0보다 작을 수 없다!";
    else
        return pq->queue[pq->front = (pq->front + 1) % pq->capacity];
}
int IsEmpty(Queue* pq)
{
    return pq->front == pq->rear;
}
void InitQueue(Queue* pq, int cap = 100)
{
    pq->capacity = cap;
    pq->front = pq->rear = 0;
    pq->queue = (Node**)malloc(sizeof(Node*) * pq->capacity);
}
void UninitQueue(Queue* pq)
{
    free(pq->queue);
}

Node* AllocNode(int data)
{
    Node* n = (Node*)malloc(sizeof(Node));
    n->data = data;
    n->lChild = n->rChild = NULL;

    return n;
}
void Inorder(Node* root)
{
    if (root == NULL)
        return;

    Inorder(root->lChild);
    printf("%d ", root->data);
    Inorder(root->rChild);
}
void Preorder(Node* root)
{
    if (root)
    {
        printf("%d ", root->data);
        Preorder(root->lChild);
        Preorder(root->rChild);
    }
}
void Postorder(Node* root)
{
    if (root)
    {
        Postorder(root->lChild);
        Postorder(root->rChild);
        printf("%d ", root->data);
    }
}
void Levelorder(Node* root)
{
    if (root == NULL)
        return;
    Queue q;
    InitQueue(&q, 20);
    Push(&q, root);

    while (!IsEmpty(&q))
    {
        Node* cur = Pop(&q);
        printf("%d ", cur->data);
        if (cur->lChild)
            Push(&q, cur->lChild);
        if (cur->rChild)
            Push(&q, cur->rChild);
    }

    UninitQueue(&q);
}
int main()
{
    Node* root = NULL;

    root = AllocNode(50);
    root->lChild = AllocNode(30);
    root->rChild = AllocNode(70);
    root->lChild->lChild = AllocNode(20);
    root->lChild->rChild = AllocNode(40);
    root->rChild->lChild = AllocNode(60);
    root->rChild->rChild = AllocNode(100);

    Inorder(root); printf("\n");
    Preorder(root); printf("\n");
    Postorder(root); printf("\n");
    Levelorder(root); printf("\n");
}
//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//#include <algorithm>
//
//struct Node
//{
//	int data;
//	Node* lchiled;
//	Node* rchiled;
//};
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->data = data;
//	n->lchiled = n->rchiled = NULL;
//
//	return n;
//}
//void Inorder(Node* root)
//{
//	if (root == NULL)
//		return;
//
//	Inorder(root->lchiled);
//	printf("%d ", root->data);
//	Inorder(root->rchiled);
//
//}
//void Preorder(Node* root)
//{
//	if (root)
//	{
//		printf("%d ", root->data);
//		Preorder(root->lchiled);
//		Preorder(root->rchiled);
//	}
//}
//void Postorder(Node* root)
//{
//	if (root)
//	{
//		Preorder(root->lchiled);
//		Preorder(root->rchiled);
//		printf("%d ", root->data);
//	}
//}
//void Levelorder(Node* root)
//{
//	if (root)
//	{
//		Preorder(root->lchiled);
//		Preorder(root->rchiled);
//		printf("%d ", root->data);
//	}
//}
//int main()
//{
//	Node* root = NULL;
//	root = AllocNode(50);
//	root->lchiled = AllocNode(30);
//	root->rchiled = AllocNode(70);
//	root->lchiled->lchiled = AllocNode(20);
//	root->lchiled->rchiled = AllocNode(40);
//	root->rchiled->lchiled = AllocNode(60);
//	root->rchiled->rchiled = AllocNode(100);
//
//	Inorder(root);
//	printf("\n");
//	Preorder(root);
//	printf("\n");
//	Postorder(root);
//	printf("\n");
//	Levelorder(root);
//	printf("\n");
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//#include <algorithm>
//
//struct Node
//{
//   int data;
//   Node* lChild;
//   Node* rChild;
//};
//Node* AllocNode(int data)
//{
//   Node* n = (Node*)malloc(sizeof(Node));
//   n->data = data;
//   n->lChild = n->rChild = NULL;
//
//   return n;
//}
//void Inorder(Node* root)
//{
//   if (root == NULL)
//      return;
//
//   Inorder(root->lChild);
//   printf("%d ", root->data);
//   Inorder(root->rChild);
//}
//void Preorder(Node* root)
//{
//   if (root)
//   {
//      printf("%d ", root->data);
//      Preorder(root->lChild);
//      Preorder(root->rChild);
//   }
//}
//void Postorder(Node* root)
//{
//   if (root)
//   {
//      Preorder(root->lChild);
//      Preorder(root->rChild);
//      printf("%d ", root->data);
//   }
//}
//int main()
//{
//   Node* root = NULL;
//
//   root = AllocNode(50);
//   root->lChild = AllocNode(30);
//   root->rChild = AllocNode(70);
//   root->lChild->lChild = AllocNode(20);
//   root->lChild->rChild = AllocNode(40);
//   root->rChild->lChild = AllocNode(60);
//   root->rChild->rChild = AllocNode(100);
//
//   Inorder(root); printf("\n");
//   Preorder(root); printf("\n");
//   Postorder(root); printf("\n");
//}
//struct Queue
//{
//   int* queue;
//   int front;
//   int rear;
//   int capacity;
//};
//void Push(Queue* pq, int data)
//{
//   if (pq->rear < pq->capacity)
//      pq->queue[pq->rear++] = data;
//}
//int Pop(Queue* pq)
//{
//   if (pq->front >= 0)
//      return pq->queue[pq->front++];
//   else
//      throw "front 0보다 작을 수 없다!";
//}
//void InitQueue(Queue* pq, int cap = 100)
//{
//   pq->capacity = cap;
//   pq->front = pq->rear = 0;
//   pq->queue = (int*)malloc(sizeof(int) * pq->capacity);
//}
//void UninitQueue(Queue* pq)
//{
//   free(pq->queue);
//}
//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//#include <algorithm>
//
//struct Node
//{
//	int data;
//	Node* lchiled;
//	Node* rchiled;
//};
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->data = data;
//	n->lchiled = n->rchiled = NULL;
//
//	return n;
//}
//void Inorder(Node* root)
//{
//	if (root == NULL)
//		return;
//
//	Inorder(root->lchiled);
//	printf("%d ", root->data);
//	Inorder(root->rchiled);
//
//}
//void Preorder(Node* root)
//{
//	if (root)
//	{
//		printf("%d ", root->data);
//		Preorder(root->lchiled);
//		Preorder(root->rchiled);
//	}
//}
//int main()
//{
//	Node* root = NULL;
//	root = AllocNode(50);
//	root->lchiled = AllocNode(30);
//	root->rchiled = AllocNode(70);
//	root->lchiled->lchiled = AllocNode(20);
//	root->lchiled->rchiled = AllocNode(40);
//	root->rchiled->lchiled = AllocNode(60);
//	root->rchiled->rchiled = AllocNode(100);
//
//	Preorder(root);
//	printf("\n");
//	Preorder(root);
//	printf("\n");	
//	Preorder(root);
//	printf("\n");
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//#include <algorithm>
//
//struct Node
//{
//	int data;
//	Node* lchiled;
//	Node* rchiled;
//};
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->data = data;
//	n->lchiled = n->rchiled = NULL;
//
//	return n;
//}
//void Inorder(Node* root)
//{
//	if (root == NULL)
//		return;
//
//	Inorder(root->lchiled);
//	printf("%d ", root->data);
//	Inorder(root->rchiled);
//
//}
//int main()
//{
//	Node* root = NULL;
//	root = AllocNode(50);
//	root->lchiled = AllocNode(30);
//	root->rchiled = AllocNode(70);
//	root->lchiled->lchiled = AllocNode(20);
//	root->lchiled->rchiled = AllocNode(40);
//	root->rchiled->lchiled = AllocNode(60);
//	root->rchiled->rchiled = AllocNode(100);
//
//	Inorder(root);
//	printf("\n");
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//#include <algorithm>
//
//void PrintArray(int list[], int size)
//{
//	for (int i = 0; i < size; ++i)
//		printf("%d ", list[i]);
//	printf("\n");
//}
//int _Search(int list[], int left, int right, int key)
//{
//	if (left <= right)
//	{
//		int middle = (left + right) / 2;
//		if (key < list[middle])
//			return _Search(list, left, middle - 1, key);
//		else if (key > list[middle])
//			return _Search(list, middle + 1, right, key);
//		else
//			return middle;
//	}
//	return -1;
//}
//int Search(int list[], int size, int key)
//{
//	return _Search(list, 0, size - 1, key);
//}
//int main()
//{
//	//int list[10] = { 60,65,45,39,79,82,20,21,94,37 };
//	int list[10] = { 60,65,45,39,79,82,20,21,94,37 };
//	std::sort(list, list + 10);
//
//	int idx = Search(list, 10, 45);
//	if (idx != -1)
//		printf("[%d] : %d\n", idx, list[idx]);
//	PrintArray(list, 10);
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//#include <algorithm>
//
//void PrintArray(int list[], int size)
//{
//	for (int i = 0; i < size; ++i)
//		printf("%d ", list[i]);
//	printf("\n");
//}
//int _Search(int list[], int left, int right, int key)
//{
//	if (left <= right)
//	{
//		int middle = (left + right) / 2;
//		if (key < list[middle])
//			return _Search(list, left, middle - 1, key);
//		else if (key > list[middle])
//			return _Search(list, middle + 1, right, key);
//		else
//			return middle;
//	}
//	return -1;
//}
//int Search(int list[], int size, int key)
//{
//	return _Search(list, 0, size - 1, key);
//}
//int main()
//{
//	//int list[10] = { 60,65,45,39,79,82,20,21,94,37 };
//	int list[10] = { 60,65,45,39,79,82,20,21,94,37 };
//	std::sort(list, list + 10);
//
//	int idx = Search(list, 10, 45);
//	if (idx != -1)
//		printf("[%d] : %d\n", idx, list[idx]);
//	PrintArray(list, 10);
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//#include <algorithm>
//
//void PrintArray(int list[], int size)
//{
//	for (int i = 0; i < size; ++i)
//		printf("%d ", list[i]);
//	printf("\n");
//}
//int Search(int list[], int size, int key)
//{
//	int left = 0;
//	int right = size - 1;
//	
//	while (left <= right)
//	{
//		int middle = (left + right) / 2;
//		if (key < list[middle])
//			right = middle - 1;
//		else if (key > list[middle])
//			left = middle + 1;
//		else
//			return middle;
//	}
//	return -1;
//}
//int main()
//{
//	//int list[10] = { 60,65,45,39,79,82,20,21,94,37 };
//	int list[10] = { 60,65,45,39,79,82,20,21,94,37 };
//	std::sort(list, list + 10);
//
//	int idx = Search(list, 10,45);
//	if (idx != -1)
//		printf("[%d] : %d\n", idx, list[idx]);
//	PrintArray(list, 10);
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//#include <algorithm>
//
//void PrintArray(int list[], int size)
//{
//	for (int i = 0; i < size; ++i)
//		printf("%d ", list[i]);
//	printf("\n");
//}
//int main()
//{
//	//int list[10] = { 60,65,45,39,79,82,20,21,94,37 };
//	int list[10] = { 60,65,45,39,79,82,20,21,94,37 };
//	std::sort(list, list + 10);
//
//	PrintArray(list, 10);
//}

//#include <stdio.h>
//#include <stdlib.h>
//#include <Windows.h>
//
//int image[10][10] = {
//   0,1,0,0,0,2,2,2,0,0,
//   0,1,0,0,0,2,2,2,0,0,
//   0,0,0,0,0,2,0,2,0,0,
//   0,1,1,1,1,0,0,2,0,0,
//   0,2,0,1,1,0,0,2,0,0,
//   0,2,0,1,1,2,2,2,2,0,
//   0,2,2,1,1,2,2,2,2,0,
//   0,2,2,1,1,2,2,0,0,0,
//   0,0,2,2,2,2,2,0,0,0,
//   0,0,0,0,0,0,0,0,0,0
//};
//void PrintImage()
//{
//	system("cls");
//	for (int i = 0; i < 10; ++i)
//	{
//		for (int j = 0; j < 10; ++j)
//			printf("%2d", image[i][j]);
//		printf("\n");
//	}
//	Sleep(300); //0.3초 정도
//}
//void _Fill(int row, int col, int oldColor, int newColor)
//{
//	if (!(0 <= row && row <= 9 && 0 <= col && col <= 9))
//		return;
//	if (oldColor != image[row][col])
//		return;
//	image[row][col] = newColor;
//	PrintImage();
//
//	_Fill(row - 1, col, oldColor, newColor);
//	_Fill(row , col+1, oldColor, newColor);
//	_Fill(row+1, col, oldColor, newColor);
//	_Fill(row, col-1, oldColor, newColor);
//}
//void Fill(int row, int col, int newColor)
//{
//	_Fill(row, col, image[row][col], newColor);
//}
//int main()
//{
//	Fill(2, 3, 9);
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int image[10][10] = {
//   0,1,0,0,0,2,2,2,0,0,
//   0,1,0,0,0,2,2,2,0,0,
//   0,1,0,0,0,2,0,2,0,0,
//   0,1,1,1,1,0,0,2,0,0,
//   0,2,0,1,1,0,0,2,0,0,
//   0,2,0,1,1,2,2,2,2,0,
//   0,2,2,1,1,2,2,2,2,0,
//   0,2,2,1,1,2,2,0,0,0,
//   0,0,2,2,2,2,2,0,0,0,
//   0,0,0,0,0,0,2,2,0,0
//};
//void PrintImage()
//{
//	for (int i = 0; i < 10; ++i)
//	{
//		for (int j = 0; j < 10; ++j)
//			printf("%2d", image[i][j]);
//		printf("\n");
//	}
//}
//int main()
//{
//	PrintImage();
//	PrintImage();
//	PrintImage();
//}

//#include <stdio.h>
//#include <stdlib.h>
//int Fibonacci(int n)
//{
//	//return n == 1 ? 1 : Factorial(n - 1) * n;
//	if (n == 1)
//		return 1;
//	else if (n == 2)
//		return 2;
//	else
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//int main()
//{
//	int result = Fibonacci(5);
//
//	printf("result : %d\n", result);
//}

//#include <stdio.h>
//#include <stdlib.h>
//int Fibonacci(int n)
//{
//	//return n == 1 ? 1 : Factorial(n - 1) * n;
//	if (n == 1)
//		return 1;
//	else if (n == 2)
//		return 2;
//	else
//		return Fibonacci(n - 1) + Fibonacci(n - 2);
//}
//int main()
//{
//	int result = Fibonacci(5);
//
//	printf("result : %d\n", result);
//}

//#include <stdio.h>
//#include <stdlib.h>
//int Factorial(int n)
//{
//	//return n == 1 ? 1 : Factorial(n - 1) * n;
//	if (n == 1)
//		return 1;
//	else
//		return Factorial(n - 1) * n;
//}
//int main()
//{
//	int result = Factorial(5);
//
//	printf("result : %d\n", result);
//}

//#include <stdio.h>
//#include <stdlib.h>
//int Factorial(int n)
//{
//	//return n == 1 ? 1 : Factorial(n - 1) * n;
//	if (n == 1)
//		return 1;
//	else
//		return Factorial(n - 1) * n;
//}
//int main()
//{
//	int result = Factorial(5);
//
//	printf("result : %d\n", result);
//}

//#include <stdio.h>
//#include <stdlib.h>
//void Print(int n)
//{
//	printf("+%d\n", n);
//	if (n-1 >= 0)
//		Print(n - 1);
//	if (n-2 >= 0)
//		Print(n - 2);
//	printf("-%d\n", n);
//
//}
//int main()
//{
//	Print(3);
//}

//#include <stdio.h>
//#include <stdlib.h>
//void Print(int n)
//{
//	printf("+%d\n", n);
//	if (n > 0)
//	{
//		Print(n - 1);
//		Print(n - 1);
//	}
//	printf("-%d\n", n);
//
//}
//int main()
//{
//	Print(2);
//}

//#include <stdio.h>
//#include <stdlib.h>
//void Print(int n)
//{
//	printf("+%d\n", n);
//	if (n > 0)
//	{
//		Print(n - 1);
//		Print(n - 1);
//	}
//	printf("-%d\n", n);
//
//}
//int main()
//{
//	Print(5);
//}

//#include <stdio.h>
//#include <stdlib.h>
//void Print(int n)
//{
//	printf("+%d\n", n);
//	if (n > 0)
//		Print(n - 1);
//	printf("-%d\n", n);
//
//}
//int main()
//{
//	Print(5);
//}

//#include <stdio.h>
//#include <stdlib.h>
//void Print(int n)
//{
//	printf("%d\n", n);
//	if (n > 0)
//		Print(n - 1);
//}
//int main()
//{
//	Print(5);
//}

//#include <stdio.h>
//#include <stdlib.h>
//void Print(int n)
//{
//	printf("%d\n", n);
//	if (n > 0)
//		Print(n + 1);
//}
//int main()
//{
//	Print(5);
//}

//#include <stdio.h>
//#include <stdlib.h>
//void Print(int n)
//{
//	printf("%d\n",n);
//	Print(n - 1);
//}
//int main()
//{
//	Print(5);
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//void a()
//{
//	printf("a()\n");
//}
//void b()
//{
//	printf("b()\n");
//	a();
//}
//void c()
//{
//	printf("c()\n");
//	b();
//}
//int main()
//{
//	//재귀함수
//	a();
//	b();
//	c();
//}

////이중연결 리스트
//#include <stdio.h>
//
//#include <stdlib.h>
//struct Node
//{
//    int data;
//    Node* prev;
//    Node* next;
//};
//
//struct List
//{
//    Node* head;
//    Node* tail;
//};
//
//Node* AllockNode(int data)
//{
//    Node* n = (Node*)malloc(sizeof(Node));
//    n->prev = n->next = NULL;
//    n->data = data;
//
//    return n;
//}
//
//void InitList(List* plt)
//{
//    plt->head = AllockNode(0);
//    plt->tail = AllockNode(0);
//    plt->head->next = plt->tail;
//    plt->tail->prev = plt->head;
//}
//
//void UninitList(List* plt)
//{
//    Node* pn;
//    for (Node* p = plt->head; p != NULL; p = pn)
//    {
//        pn = p->next;
//        free(p);
//    }
//}
//
//void AddNextList(List* plt, int data)
//{
//    Node* t = plt->tail;
//    Node* pt = plt->tail->prev;
//    Node* n = AllockNode(data);
//
//    pt->next = n;
//    n->prev = pt;
//    n->next = t;
//    t->prev = n;
//}
//
//void PrintNextList(List* plt)
//{
//    for (Node* p = plt->head->next; p != plt->tail; p = p->next)
//    {
//        printf("%d ", p->data);
//    }
//    printf("\n");
//}
//void EraseList(List* plt, Node* p)
//{
//    Node* pp = p->prev;
//    Node* pn = p->next;
//
//    pp->next = pn;
//    pn->prev = pp;
//    free(p);
//}
//void InsertList(List* plt, Node* p, int data)
//{
//    Node* pp = p->prev;
//    Node* n = AllockNode(data);
//    pp->next = n;
//    n->prev = pp;
//    n->next = p;
//    p->prev = n;
//}
////
//Node* GetHead(List* plt)
//{
//    return plt->head->next;
//}
//int HasNext(List* plt, Node* p)
//{
//    return plt->tail != p;
//}
//Node* Next(List* plt, Node* p)
//{
//    return p->next;
//}
//int GetData(List* plt, Node* p)
//{
//    return p->data;
//}
//
//int main(void)
//{
//    List lt;
//    InitList(&lt);
//    AddNextList(&lt, 10);
//    AddNextList(&lt, 20);
//    AddNextList(&lt, 30);
//    AddNextList(&lt, 40);
//    AddNextList(&lt, 50);
//
//
//    Node* p = GetHead(&lt);
//    p = Next(&lt, p);
//    p = Next(&lt, p);
//    InsertList(&lt, p, 100);
//    PrintNextList(&lt);
//
//    UninitList(&lt);
//    return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* prev;
//	Node* next;
//};
//struct List
//{
//	Node* head;
//	Node* tail;
//};
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->prev = n->next = NULL;
//	n->data = data;
//
//	return n;
//}
//void InitList(List* plt)
//{
//	plt->head = AllocNode(0);
//	plt->tail = AllocNode(0);
//	plt->head->next = plt->tail;
//	plt->tail->prev = plt->head;
//}
//void UninitList(List* plt)
//{
//	for (Node* p = plt->head; p; )
//	{
//		Node* pn = p->next;
//		free(p);
//		p = pn;
//	}
//}
//void AddNextList(List* plt, int data)
//{
//	Node* t = plt->tail;
//	Node* pt = plt->tail->prev;
//	Node* n = AllocNode(data);
//
//	pt->next = n;
//	n->prev = pt;
//	n->next = t;
//	t->prev = n;
//}
//void PrintNextList(List* plt)
//{
//	for (Node* p = plt->head->next; p != plt->tail; p = p->next)
//		printf("%d ", p->data);
//	printf("\n");
//}
////원소를 순회하는데 돌리는 향수
//Node* GetHead(List* plt)
//{
//	return plt->head->next;
//}
//int HasNext(List* plt, Node* p)
//{
//	return plt->tail != p!;
//}
//Node* Next(List* plt, Node* p)
//{
//	return p->next;
//}
//Node Getdata(List* plt, Node* p)
//{
//	return p->data;
//}
//int main()
//{
//	List lt;
//	InitList(&lt);
//	AddNextList(&lt, 10);
//	AddNextList(&lt, 20);
//	AddNextList(&lt, 30);
//	AddNextList(&lt, 40);
//	AddNextList(&lt, 50);
//
//	//PrintNextList(&lt);
//	for (Node* p = getHead(&lt);HasNext(&lt,p); p = Next(&lt,p))
//		if (20 == GetData(&lt, p))
//		{
//			//printf("%d ", GetData(&lt,p));
//			SetData(&lt, P, 50);
//		}	break;
//		}
//	printf("\n");
//
//	UninitList(&lt);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* prev;
//	Node* next;
//};
//struct List
//{
//	Node* head;
//	Node* tail;
//};
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->prev = n->next = NULL;
//	n->data = data;
//
//	return n;
//}
//void InitList(List* plt)
//{
//	plt->head = AllocNode(0);
//	plt->tail = AllocNode(0);
//	plt->head->next = plt->tail;
//	plt->tail->prev = plt->head;
//}
//void UninitList(List* plt)
//{
//	for (Node* p = plt->head; p; )
//	{
//		Node* pn = p->next;
//		free(p);
//		p = pn;
//	}
//}
//void AddNextList(List* plt, int data)
//{
//	Node* t = plt->tail;
//	Node* pt = plt->tail->prev;
//	Node* n = AllocNode(data);
//
//	pt->next = n;
//	n->prev = pt;
//	n->next = t;
//	t->prev = n;
//}
//void PrintNextList(List* plt)
//{
//	for (Node* p = plt->head->next; p != plt->tail; p = p->next)
//		printf("%d ", p->data);
//	printf("\n");
//}
//int main()
//{
//	List lt;
//	InitList(&lt);
//	AddNextList(&lt, 10);
//	AddNextList(&lt, 20);
//	AddNextList(&lt, 30);
//	AddNextList(&lt, 40);
//	AddNextList(&lt, 50);
//
//	//PrintNextList(&lt);
//	for (Node* p = lt.head->next; p != lt.tail; p = p->next)
//		if (20 == p->data)
//		{
//			printf("%d ", p->data);
//			break;
//		}
//	printf("\n");
//
//	UninitList(&lt);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* prev;
//	Node* next;
//};
//struct List
//{
//	Node* head;
//	Node* tail;
//};
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->prev = n->next = NULL;
//	n->data = data;
//
//	return n;
//}
//void InitList(List* plt)
//{
//	plt->head = AllocNode(0);
//	plt->tail = AllocNode(0);
//	plt->head->next = plt->tail;
//	plt->tail->prev = plt->head;
//}
//void UninitList(List* plt)
//{
//	for (Node* p = plt->head; p; )
//	{
//		Node* pn = p->next;
//		free(p);
//		p = pn;
//	}
//}
//void AddNextList(List* plt, int data)
//{
//	Node* t = plt->tail;
//	Node* pt = plt->tail->prev;
//	Node* n = AllocNode(data);
//
//	pt->next = n;
//	n->prev = pt;
//	n->next = t;
//	t->prev = n;
//}
//void PrintNextList(List* plt)
//{
//	for (Node* p = plt->head->next; p != plt->tail; p = p->next)
//		printf("%d ", p->data);
//	printf("\n");
//}
//int main()
//{
//	List lt;
//	InitList(&lt);
//	AddNextList(&lt, 10);
//	AddNextList(&lt, 20);
//	AddNextList(&lt, 30);
//	AddNextList(&lt, 40);
//	AddNextList(&lt, 50);
//
//	//PrintNextList(&lt);
//	for (Node* p = lt.head->next; p != lt.tail; p = p->next)
//		if (20 == p->data)
//		{
//			printf("%d ", p->data);
//			break;
//		}
//	printf("\n");
//
//	UninitList(&lt);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* prev;
//	Node* next;
//};
//struct List
//{
//	Node* head;
//	Node* tail;
//};
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->prev = n->next = NULL;
//	n->data = data;
//
//	return n;
//}
//void InitList(List* plt)
//{
//	plt->head = AllocNode(0);
//	plt->tail = AllocNode(0);
//	plt->head->next = plt->tail;
//	plt->tail->prev = plt->head;
//}
//void UninitList(List* plt)
//{
//	for (Node* p = plt->head; p; )
//	{
//		Node* pn = p->next;
//		free(p);
//		p = pn;
//	}
//}
//void AddNextList(List* plt, int data)
//{
//	Node* t = plt->tail;
//	Node* pt = plt->tail->prev;
//	Node* n = AllocNode(data);
//
//	pt->next = n;
//	n->prev = pt;
//	n->next = t;
//	t->prev = n;
//}
//void PrintNextList(List* plt)
//{
//	for (Node* p = plt->head->next; p != plt->tail; p = p->next)
//		printf("%d ", p->data);
//	printf("\n");
//}
//int main()
//{
//	List lt;
//	InitList(&lt);
//	AddNextList(&lt, 10);
//	AddNextList(&lt, 20);
//	AddNextList(&lt, 30);
//	AddNextList(&lt, 40);
//	AddNextList(&lt, 50);
//
//	PrintNextList(&lt);
//
//	UninitList(&lt);
//}
