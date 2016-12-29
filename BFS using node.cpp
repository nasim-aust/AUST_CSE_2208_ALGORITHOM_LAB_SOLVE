#include<bits/stdc++.h>
#define size 1001
using namespace std;

struct Queue* Q[size];
struct Queue* MQ;
int qq[size];
bool visited[size];


struct node
{
    int data;
    struct node* next;
};

struct Queue
{
    struct node* front;
    struct node* rear;
};

bool isEmpty(Queue* q)
{
    if(q->front==NULL)
        return true;
    else
        return false;
}

void enqueue(int x, Queue* q)
{
    struct node* top = (struct node*) malloc(sizeof(struct node));
    top->data = x;
    top->next = NULL;

    if(isEmpty(q))
    {
        q->front = q->rear = top;
        //cout << "queue is empty" << endl;
    }
    else
    {
        q->rear->next = top;
        q->rear = top;
        //cout << "Enqueue done" << endl;
    }
}

void dequeue(Queue* q)
{
    if(isEmpty(q))
    {
        cout << "Queue is already empty" << endl;
        return;
    }
   else if(q->front == q->rear)
    {
        struct node* top = q->front;
        q->front = q->rear = NULL;
        delete top;
    }
    else
    {
        struct node* top = q->front;
        q->front = q->front->next;
        delete top;
    }
}

int peek(Queue *q)
{
    return q->front->data;
}

void traversal(Queue *q)
{
    struct node* i = q->front;
    while(i!=NULL){
        cout << i->data << endl;
        i = i->next;
    }
}

TreeBFS(int r)
 {
   enqueue(r,MQ);
  // cout <<"enqueue " << r <<endl;
   while(!isEmpty(MQ))
   {
       int v= peek(MQ);

       dequeue(MQ);
       visited[v]=1;
       cout << v <<" " ;

       for(int i=1;i<=qq[v];i++)
       {   int m;

            if(!isEmpty(Q[v]))
               {    m=  peek( Q[v]);
                   dequeue(Q[v]);
               }

            // cout <<"visited m "<<m <<" "  <<visited[m] <<endl;
            if(visited[m]!=1)
            {

                enqueue(m,MQ);
                visited[m]=1;
                //cout <<"enqueue " << m <<endl;
            }
       }
   }
}


int main(){
    //freopen("input.txt","r",stdin);

     MQ = (struct Queue*) malloc(sizeof(struct Queue));
     memset(qq,0,sizeof(qq));
     memset(visited,0,sizeof(visited));
    int N;
    int s, d, root;

    cin >> N;
    cin >> root;
    for(int i=1; i<=N; i++)
        Q[i] = (struct Queue*)malloc(sizeof(struct Queue));

     cout <<"input s=-1 and d=-1 to break " <<endl;
    while(cin>>s>>d){
            if((s==-1)&&(d==-1))break;
        enqueue(d,Q[s]);
        enqueue(s,Q[d]);
        qq[s]++;
        qq[d]++;

    }
   /*
    for(int i=1; i<=N; i++){
        cout << "Traversing Lists for vertex: " << i << endl;
        traversal(Q[i]);
        cout <<"qq " << qq[i] <<endl;
    }
    */
    TreeBFS(root);

    return 0;
}
