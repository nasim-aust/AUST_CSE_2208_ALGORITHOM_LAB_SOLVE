#include<bits/stdc++.h>
#define size 1001
using namespace std;

struct node* top;
struct Queue* Q[size];
struct Queue* MQ;
int qq[size],l=0;
bool visited[size];
int st[size];

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
        //cout << "queue is empty " << endl;
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

void stacktraversal(struct node* D)
{
    while(D->next!=NULL)
    {
        cout <<D->data <<" ";
        D=D->next;
    }
    cout <<endl;
}

void push(int n)
{
    struct node* newnode=(struct node*)malloc(sizeof(node));
    newnode->data=n;
    newnode->next=top;
    top=newnode;
}


int stackpeek()
{
   return top->data;
}
bool stackisEmpty()
{
    if(top==NULL)
        return 1;
    else return 0;
}
void pop()
{
    if(stackisEmpty()==0)
    top=top->next;

}

void TreeDFS(int r)
{
    push(r);
    //cout <<stackpeek() <<endl;
    while(!stackisEmpty())
    {
        int v=stackpeek();
        pop();
        visited[v]=1;
        st[l++]=v;
       // cout << v <<" " ;

       for(int i=1;i<=qq[v];i++)
       {   int m;
            if(!isEmpty(Q[v]))
               {    m=  peek( Q[v]);
                   dequeue(Q[v]);
               }
            // cout <<"visited m "<<m <<" "  <<visited[m] <<endl;
            if(visited[m]!=1)
            {
                push(m);
                visited[m]=1;
                //cout <<"enqueue " << m <<endl;
            }
       }
    }
    for(int i=l-1;i>=0;i--)
        cout <<st[i] <<" ";
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

     //cout <<"input s=-1 and d=-1 to break " <<endl;
    while(cin>>s>>d)
    {
            if((s==-1)&&(d==-1))break;
        enqueue(d,Q[s]);
        enqueue(s,Q[d]);
        qq[s]++;
        qq[d]++;
    }

  /*
   for(int i=1; i<=N; i++){
        cout << "Traversing Lists for vertex: " << i << endl;
        qtraversal(Q[i]);
        cout <<"qq " << qq[i] <<endl;
    }
*/
    TreeDFS(root);

    return 0;
}
