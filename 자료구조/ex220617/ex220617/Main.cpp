#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	Node* prev;
	Node* next;
};
struct List
{
	Node* head;
	Node* tail;
};
Node* AllocNode(int data)
{
	Node* n = (Node*)malloc(sizeof(Node));
	n->prev = n->next = NULL;
	n->data = data;

	return n;
}
void InitList(List* plt)
{
	plt->head = AllocNode(0);
	plt->tail = AllocNode(0);
	plt->head->next = plt->tail;
	plt->tail->prev = plt->head;
}
void UninitList(List* plt)
{

		//free()
		//free() //
		//free()
		//free()
		//free()
}
void AddNextList(List* plt, int data)
{
	Node* t = plt->tail;
	Node* pt = plt->tail->prev;
	Node* n = AllocNode(data);

	pt->next = n;
	n->prev = pt;
	n->next = t;
	t->prev = n;
}
void PrintNextList(List* plt)
{
	for (Node* p = plt->head->next; p != plt->tail; p = p->next)
		printf("%d ", p->data);
	printf("\n");
}
int main()
{
	List lt;
	InitList(&lt);
	AddNextList(&lt, 10);
	AddNextList(&lt, 20);
	AddNextList(&lt, 30);
	AddNextList(&lt, 40);
	AddNextList(&lt, 50);

	PrintNextList(&lt);

	UninitList(&lt);
}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* prev;
//	Node* next;
//};
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->prev = n->next = NULL;
//	n->data = data;
//
//	return n;
//}
//int main()
//{
//	Node* head = NULL;
//	Node* tail = NULL;
//	head = AllocNode(0);
//	tail = AllocNode(0);
//	head->next = tail;
//	tail->prev = head;
//}


//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//void PrintNode(Node* head)
//{
//	for (Node* p = head; p != NULL; p = p->link)
//		printf("%d\n", p->data);
//}
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->data = data;
//	n->link = NULL;
//
//	return n;
//}
//void AddNode(Node** phead, int data)
//{
//	Node* n = AllocNode(data);
//	n->link = *phead;
//	*phead = n;
//}
//int main()
//{
//	Node* head = NULL;
//
//	AddNode(&head, 10);
//	AddNode(&head, 20);
//	AddNode(&head, 30);
//	AddNode(&head, 40);
//	AddNode(&head, 50);
//
//	PrintNode(head);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//void PrintNode(Node* head)
//{
//	for (Node* p = head->link; p != NULL; p = p->link)
//		printf("%d\n", p->data);
//}
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->data = data;
//	n->link = NULL;
//
//	return n;
//}
//void AddNode(Node* head, int data)
//{
//	Node* n = AllocNode(data);
//	Node* tail = head;
//
//	while (tail->link)
//		tail = tail->link;
//
//	tail->link = n;
//}
//int main()
//{
//	Node* head = NULL;
//
//	head = AllocNode(0);  // dummy 코드의 효율성을 위해 임의로 삽입한 노드 더미노드
//
//	AddNode(head, 10);
//	AddNode(head, 20);
//	AddNode(head, 30);
//	AddNode(head, 40);
//	AddNode(head, 50);
//
//	PrintNode(head);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//void PrintNode(Node* head)
//{
//	for (Node* p = head; p != NULL; p = p->link)
//		printf("%d\n", p->data);
//}
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->data = data;
//	n->link = NULL;
//
//	return n;
//}
//void AddNode(Node** phead, int data)
//{
//	Node* n = AllocNode(data);
//	Node* tail = *phead;
//
//	if (*phead == NULL)
//	{
//		*phead = n;
//		return;
//	}
//
//	while (tail->link)
//		tail = tail->link;
//
//	tail->link = n;
//}
//int main()
//{
//	Node* head = NULL;
//
//	AddNode(&head, 10);
//	AddNode(&head, 20);
//	AddNode(&head, 30);
//	AddNode(&head, 40);
//	AddNode(&head, 50);
//
//	PrintNode(head);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//void PrintNode(Node* head)
//{
//	for (Node* p = head; p != NULL; p = p->link)
//		printf("%d\n", p->data);
//}
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->data = data;
//	n->link = NULL;
//
//	return n;
//}
//void AddNode(Node* head, int data)
//{
//	Node* n = AllocNode(data);
//	Node* tail = head;
//
//	while (tail ->link )
//		tail = tail->link;
//
//	tail->link = n;
//}
//int main()
//{
//	Node* head = NULL;
//	Node* p = AllocNode(10);
//	head = p;
//
//	AddNode(head, 20);
//	AddNode(head, 30);
//	AddNode(head, 40);
//	AddNode(head, 50);
//
//	PrintNode(head);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//void PrintNode(Node* head)
//{
//	for (Node* p = head; p != NULL; p = p->link)
//		printf("%d\n", p->data);
//}
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->data = data;
//	n->link = NULL;
//
//	return n;
//}
// 
//int main()
//{
//	Node* head = NULL;
//	Node* p = AllocNode(10);
//	head = p;
//
//	p = AllocNode(20);
//	head->link = p;
//
//	p = AllocNode(30);
//	head->link -> link= p;
//	p = AllocNode(40);
//	head->link -> link->link = p;
//	p = AllocNode(50); 
//	head->link->link->link->link = p;
//
//	PrintNode(head);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//void PrintNode(Node* head)
//{
//	for (Node* p = head; p != NULL; p = p->link)
//		printf("%d\n", p->data);
//}
//Node* AllocNode(int data)
//{
//	Node* n = (Node*)malloc(sizeof(Node));
//	n->data = data;
//	n->link = NULL;
//
//	return n;
//}
//int main()
//{
//	Node* head = NULL;
//	Node* p = AllocNode(10);
//	head = p;
//
//	p = AllocNode(20);
//	head->link = p;
//
//	Node n3 = { 30, NULL };
//	Node n4 = { 40, NULL };
//	Node n5 = { 50, NULL };
//
//	n1.link = &n2;
//	n2.link = &n3;
//	n3.link = &n4;
//	n4.link = &n5;
//
//	Node* head = &n1;
//
//	Node* p = head;
//
//	PrintNode(head);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//void PrintNode(Node* head)
//{
//	for (Node* p = head; p != NULL; p = p->link)
//		printf("%d\n", p->data);
//}
//int main()
//{
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//	Node n4 = { 40, NULL };
//	Node n5 = { 50, NULL };
//
//	n1.link = &n2;
//	n2.link = &n3;
//	n3.link = &n4;
//	n4.link = &n5;
//
//	Node* head = &n1;
//
//	Node* p = head;
//
//	PrintNode(head);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//int main()
//{
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//	Node n4 = { 40, NULL };
//	Node n5 = { 50, NULL };
//
//	n1.link = &n2;
//	n2.link = &n3;
//	n3.link = &n4;
//	n4.link = &n5;
//
//	Node* head = &n1;
//
//	Node* p = head;
//	for (Node* p = head; p != NULL; p = p->link)
//		//for(Node* p = head; p ; p = p->link) //위와 같은 코드임
//		printf("%d\n", p->data);
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//int main()
//{
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//	Node n4 = { 40, NULL };
//	Node n5 = { 50, NULL };
//
//	n1.link = &n2;
//	n2.link = &n3;
//	n3.link = &n4;
//	n4.link = &n5;
//
//	Node* head = &n1;
//
//	Node* p = head;
//	printf("%d\n", p->data);
//	p = p->link;
//	printf("%d\n", p->data);
//	p = p->link;
//	printf("%d\n", p->data);
//	p = p->link;
//	printf("%d\n", p->data);
//	p = p->link;
//	printf("%d\n", p->data);
//	p = p->link;
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//int main()
//{
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//	Node n4 = { 40, NULL };
//	Node n5 = { 50, NULL };
//
//	n1.link = &n2;
//	n2.link = &n3;
//	n3.link = &n4;
//	n4.link = &n5;
//
//	Node* head = &n1;
//
//	printf("%d\n", head->data);
//	printf("%d\n", head->link->data);
//	printf("%d\n", head->link->link->data);
//	printf("%d\n", head->link->link-> link -> data);
//	printf("%d\n", head->link->link-> link-> link-> data);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//int main()
//{
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//
//	n1.link = &n2;
//	n2.link = &n3;
//
//	Node* head = &n1;
//
//	printf("%d\n", head -> data);
//	printf("%d\n", head -> link -> data);
//	printf("%d\n", head -> link -> link -> data);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Node
//{
//	int data;
//	Node* link;
//};
//int main()
//{
//	Node n1 = { 10, NULL };
//	Node n2 = { 20, NULL };
//	Node n3 = { 30, NULL };
//
//	printf("%d\n", n1.data);
//	printf("%d\n", n2.data);
//	printf("%d\n", n3.data);
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Queue
//{
//	int* queue;
//	int front;
//	int rear;
//	int capacity;
//
//};
//void Push(Queue* pq, int data)
//{
//	if ((pq->rear + 1) % pq->capacity == pq->front)
//		throw "큐가 꽉 찬 상태입니다";
//		pq->queue[pq->rear = (pq->rear+1)%pq->capacity] = data;
//}
//int Pop(Queue* pq)
//{
//		if (pq->front == pq->rear)
//			throw"큐가 빈 상태입니다.";
//	return pq->queue[pq->front = (pq -> front + 1) % pq->capacity];
//void InitQueue(Queue* pq, int cap = 100)
//{
//	pq->capacity = cap;
//	pq->front = pq->rear = 0;
//	pq->queue = (int*)malloc(sizeof(int) * pq->capacity);
//	pq->top = 0;
//}
//void UnInitQueue(Queue* pq)
//{
//	free(pq->queue);
//}
//int main()
//{
//	Queue q1 = { 0 };
//	InitQueue(&q1);
//	Push(&q1, 10);
//	Push(&q1, 20);
//	Push(&q1, 30);
//
//	printf("%d\n", Pop(&q1));
//	printf("%d\n", Pop(&q1));
//	printf("%d\n", Pop(&q1));
//
//	Push(&q1, 100);
//	Push(&q1, 200);
//	printf("%d\n", Pop(&q1));
//	printf("%d\n", Pop(&q1));
//
//	UnInitQueue(&q1);
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Stack
//{
//	int* stack;
//	int top;
//	int capacity;
//
//};
//void Push(Stack* ps, int data)
//{
//	if (ps->top < ps->capacity)
//		ps->stack[ps->top++] = data;
//}
//int Pop(Stack* ps)
//{
//	if (ps->top > 0)
//		return ps->stack[--ps->top];
//	else
//		throw("top 0보다 작을 수 없다!");
//}
//void InitStack(Stack* ps, int cap = 100)
//{
//	ps->capacity = cap;
//	ps->stack = (int*)malloc(sizeof(int) * ps->capacity);
//	ps->top = 0;
//}
//void UnInitStack(Stack* ps)
//{
//	free(ps->stack);
//}
//int main()
//{
//	Stack s1 = { 0 };
//	InitStack(&s1);
//	Push(&s1, 10);
//	Push(&s1, 20);
//	Push(&s1, 30);
//
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//	UnInitStack(&s1);
//
//	Stack s2 = { 0 };
//	InitStack(&s2);
//	Push(&s2, 100);
//	Push(&s2, 200);
//	printf("\n");
//	printf("%d\n", Pop(&s2));
//	printf("%d\n", Pop(&s2));
//
//	UnInitStack(&s2);
//
//}

//#include <stdio.h>
//#include <stdlib.h>
//struct Stack
//{
//	int* stack;
//	int top;
//	int capacity;
//
//};
//void Push(Stack* ps, int data)
//{
//	if(ps->top < ps->capacity)
//	ps->stack[ps->top++] = data;
//}
//int Pop(Stack* ps)
//{
//	if (ps->top > 0)
//		return ps->stack[--ps->top];
//	else
//		throw("top 0보다 작을 수 없다!");
//}
//void InitStack(Stack* ps, int cap = 100)
//{
//	ps->capacity = cap;
//	ps->stack = (int*)malloc(sizeof(int) * ps->capacity);
//	ps->top = 0;
//}
//void UnInitStack(Stack* ps)
//{
//	free(ps->stack);
//}
//int main()
//{
//	Stack s1 = { 0 };
//	InitStack(&s1);
//	Push(&s1, 10);
//	Push(&s1, 20);
//	Push(&s1, 30);
//
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//	UnInitStack(&s1);
//
//	Stack s2 = { 0 };
//	InitStack(&s2);
//	Push(&s2, 100);
//	Push(&s2, 200);
//	printf("\n");
//	printf("%d\n", Pop(&s2));
//	printf("%d\n", Pop(&s2));
//
//	UnInitStack(&s2);
//
//}


//#include <stdio.h>
//#include <stdlib.h>
//struct Stack
//{
//	int* stack;
//	int top;
//	int capacity;
//
//};
//void Push(Stack* ps, int data)
//{
//	ps->stack[ps->top++] = data;
//}
//int Pop(Stack* ps)
//{
//	return ps->stack[--ps->top];
//}
//void InitStack(Stack* ps, int cap = 100)
//{
//	ps->capacity = cap;
//	ps->stack = (int*)malloc(sizeof(int) * ps->capacity);
//	ps->top = 0;
//}
//void UnInitStack(Stack* ps)
//{
//	free(ps->stack);
//}
//int main()
//{
//	Stack s1 = { 0 };
//	InitStack(&s1);
//	Push(&s1, 10);
//	Push(&s1, 20);
//	Push(&s1, 30);
//
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//	UnInitStack(&s1);
//
//	Stack s2 = { 0 };
//	InitStack(&s2);
//	Push(&s2, 100);
//	Push(&s2, 200);
//	printf("\n");
//	printf("%d\n", Pop(&s2));
//	printf("%d\n", Pop(&s2));
//
//	UnInitStack(&s2);
//
//}

//#include <stdio.h>
//
//struct Stack
//{
//	int stack[100];
//	int top;
//
//};
//void Push(Stack* ps, int data)
//{
//	ps->stack[ps->top++] = data;
//}
//int Pop(Stack* ps)
//{
//	return ps->stack[--ps->top];
//}
//void InitStack(Stack* ps)
//{
//	ps->top = 0;
//}
//void UnInitStack(Stack* ps)
//{
//	ps->top = 0;
//}
//int main()
//{
//	Stack s1 = { 0 };
//	InitStack(&s1);
//	Push(&s1, 10);
//	Push(&s1, 20);
//	Push(&s1, 30);
//
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//	UnInitStack(&s1);
//
//	Stack s2 = { 0 };
//	InitStack(&s2);
//	Push(&s2, 100);
//	Push(&s2, 200);
//	printf("\n");
//	printf("%d\n", Pop(&s2));
//	printf("%d\n", Pop(&s2));
//
//	UnInitStack(&s2);
//
//}

//#include <stdio.h>
//
//struct Stack
//{
//	int stack[100];
//	int top;
//
//};
//void Push(Stack* ps, int data)
//{
//	ps->stack[ps->top++] = data;
//}
//int Pop(Stack* ps)
//{
//	return ps->stack[--ps->top];
//}
//int main()
//{
//	Stack s1 = { 0 };
//
//	Push(&s1, 10);
//	Push(&s1, 20);
//	Push(&s1, 30);
//
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//
//	Stack s2 = { 0 };
//	Push(&s2, 100);
//	Push(&s2, 200);
//	printf("\n");
//	printf("%d\n", Pop(&s2));
//	printf("%d\n", Pop(&s2));
//}

//#include <stdio.h>
//
//struct Stack
//{
//	int stack[100];
//	int top;
//
//};
//void Push(Stack* ps, int data)
//{
//	ps->stack[ps->top++] = data;
//}
//int Pop(Stack* ps)
//{
//	return ps->stack[--ps->top];
//}
//int main()
//{
//	Stack s1 = { 0 };
//
//	Push(&s1, 10);
//	Push(&s1, 20);
//	Push(&s1, 30);
//
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//	printf("%d\n", Pop(&s1));
//
//	Stack s2= { 0 };
//	Push(&s2, 100);
//	Push(&s2, 200);
//	printf("\n");
//	printf("%d\n", Pop(&s2));
//	printf("%d\n", Pop(&s2));
//}

//#include <stdio.h>
//void Push(int* stack, int* ptop, int data)
//{
//	stack[(*ptop)++] = data;
//}
//int Pop(int* stack, int* ptop)
//{
//	return stack[-- * ptop];
//}
//int main()
//{
//	int stack[100];
//	int top = 0;
//
//	Push(stack, &top, 10);
//	Push(stack, &top, 20);
//	Push(stack, &top, 30);
//
//	printf("%d\n", Pop(stack, &top));
//	printf("%d\n", Pop(stack, &top));
//	printf("%d\n", Pop(stack, &top));
//
//	int s2[1000];
//	int top2;
//	Push(s2, &top2, 100);
//	Push(s2, &top2, 200);
//	printf("\n");
//	printf("%d\n", Pop(s2, &top2));
//	printf("%d\n", Pop(s2, &top2));
//}



//#include <stdio.h>
//void Push(int* stack, int* ptop,int data)
//{
//	stack[(*ptop)++] = data;
//}
//int Pop(int* stack, int* ptop)
//{
//	return stack[--*ptop];
//}
//int main()
//{
//	int stack[100];
//	int top = 0;
//
//	Push(stack, &top, 10);
//	Push(stack, &top, 20);
//	Push(stack, &top, 30);
//
//	printf("%d\n", Pop(stack, &top));
//	printf("%d\n", Pop(stack, &top));
//	printf("%d\n", Pop(stack, &top));
//}

//#include <stdio.h>
//int stack[100];  //전역 변수
//int top = 0;
//void Push(int data)
//{
//	stack[top++] = data;
//}
//int Pop()
//{
//	return stack[--top];
//}
//int main()
//{
//	Push(10);
//	Push(20);
//	Push(30);
//
//	printf("%d\n", Pop());
//	printf("%d\n", Pop());
//	printf("%d\n", Pop());
//}
