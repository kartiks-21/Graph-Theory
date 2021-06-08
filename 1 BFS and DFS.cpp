#include <stdio.h>
#include <stdlib.h>

struct node
{
    int key;
    struct node *next;
    struct node *prev;
};

struct dll
{
    int size;
    struct node *head;
    struct node *tail;
};

struct adjlist
{
    struct dll **a;
    int size;
	int *vis;
};

struct queue
{
    int a[10000];
    int head;
    int tail;
};

int queue_empty(struct queue *Q)
{
    if (Q->head == Q->tail)
        return 1;
    else
    {
        return 0;
    }
}

void enqueue(struct queue *	Q, int k)
{

    Q->a[Q->tail] = k;
    Q->tail = Q->tail + 1;
    if (queue_empty(Q))
        ++Q->head;
}

int dequeue(struct queue *Q)
{
    int k = Q->a[Q->head];
    if (Q->head == Q->tail)
    {
        Q->head = -1;
        Q->tail = -1;
    }
    else
    {
        ++Q->head;
    }

    return k;
}


struct stack
{
  int top;
  int a[100000];
};

int stack_empty(struct stack *S)
{
  if (S->top == -1)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}

int pop(struct stack *S)
{

  S->top = S->top - 1;
  return S->a[S->top + 1];
}

void push(struct stack *S, int c)
{
  S->top = S->top + 1;
  S->a[S->top] = c;
}


struct node *create_node(int key)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = key;
    temp->next = NULL;
    temp->prev = NULL;
    return temp;
}

struct dll *createll()
{
    struct dll *temp = (struct dll *)malloc(sizeof(struct dll));
    temp->size = 0;
    temp->head = NULL;
    temp->tail = NULL;
    return temp;
}

struct adjlist *createlist(int n)
{
    struct adjlist *temp = (struct adjlist *)malloc(sizeof(struct adjlist));
    temp->a = (struct dll **)malloc(sizeof(struct dll) * n);
	temp->vis = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++)
    {
        temp->a[i] = createll();
		temp->vis[i] = 0;
    }
    temp->size = n;
	
    return temp;
}

struct dll *insert_end(struct dll *dl, int h)
{
    struct node *temp = create_node(h);
    if (dl->head == NULL)
    {
        dl->head = temp;
        dl->tail = temp;
    }
    else
    {
        temp->prev = dl->tail;
        dl->tail->next = temp;
        dl->tail = temp;
    }
    dl->size++;
    return dl;
}

void bfs(struct adjlist *G,int source)
{
	struct queue *Q ;
	Q = (struct queue *)malloc(sizeof(struct queue));
	G->vis[source] = 1;

	enqueue(Q,source);

	while(!queue_empty(Q))
	{
		int temp = dequeue(Q);

		printf("%d ",temp);

		struct node *temp1 = G->a[temp]->head;

		while(temp1)
		{
			int cur = temp1->key;

			if(G->vis[cur] == 0)
			{
				G->vis[cur] = 1;
				enqueue(Q,cur);
			}
			temp1 = temp1->next;
		}

	}
}

void dfs(struct adjlist *G,int source)
{
	struct node* adjList = G->a[source]->head;
  struct node* temp = adjList;

  G->vis[source] = 1;
  printf("%d ", source);

  while (temp != NULL) {
    int cur = temp->key;

    if (G->vis[cur] == 0) {
      dfs(G, cur);
    }
    temp = temp->next;
  }
}

void print_dll(struct dll *h)
{
    struct node *curr;
    curr = h->head;
    if (curr)
    {
        while (curr->next)
        {

            printf("%d ", curr->key);
            curr = curr->next;
        }
        if (curr)
            printf("%d ", curr->key);
    }
}

void print(struct adjlist *A)
{
    for (int i = 0; i < A->size; i++)
    {
        printf("%d ", i);
        print_dll(A->a[i]);
        printf("\n");
    }
}

int main()
{
    int n,m;
    scanf("%d %d", &n,&m);

    struct adjlist *A = createlist(n);

    for(int i=0;i<m;i++)
    {
        int x,y;
        scanf("%d %d",&x,&y);
        insert_end(A->a[x],y);
    }

    int source;
	scanf("%d",&source);
	//print(A);

	for(int i=0;i<n;i++)
	{
		A->vis[i] = 0;
	}

	dfs(A,source);
	printf("\n");
    return 0;
}
