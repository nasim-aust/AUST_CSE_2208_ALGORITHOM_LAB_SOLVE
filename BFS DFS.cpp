#include <iostream>
#include <list>
#include <stack>

using namespace std;

int starttime = 0, endtime = 0;

list <int> starttimes;
list <int> endtimes;

class Graph{
    int V;
    list <int> *adj;

public:

    Graph(){
    }

    ~Graph(){
        V = 0;
        adj = NULL;
    }


    Graph(int V){
        this->V = V;
        adj = new list <int> [V];
    }

    void addedge(int from, int to){
        adj[from].push_back(to);
        adj[to].push_back(from);
    }

    void bfs(int n){
        bool visited[V];
        for(int i = 0; i <V; i++){
            visited[i] = false;
        }

        list <int > q;
        list <int>::iterator p;

        q.push_front(n);
        p = q.begin();
        visited[n] = true;
        while(!q.empty()){
            int s = q.front();
            //visited[s] = true;
            q.pop_front();
            cout<<s<<"  ";
            for(p = adj[s].begin(); p!=adj[s].end();p++){
                if(visited[*p] == false){
                    q.push_back(*p);
                    visited[*p] = true;
                }
            }
        }
    }

    void dfsutil(int n, bool visited[]){
        visited[n] = true;
        cout<<n<<" ";
        list<int>::iterator i;
        for(i = adj[n].begin(); i != adj[n].end(); i++){
            if(visited[*i] == false){
                dfsutil(*i, visited);
            }
        }
    }

    void dfs(int n){
        bool visited[V];
        for(int i = 0; i <V; i++){
            visited[i] = false;
        }

        visited[n] = true;
        dfsutil(n, visited);
    }


    void dfsandtimeutil(int n, bool visited[]){
        visited[n] = true;
        cout<<n<<" ";
        list<int>::iterator i;
        for(i = adj[n].begin(); i != adj[n].end(); i++){
            if(visited[*i] == false){
                    starttime++;
            starttimes.push_back(starttime);
                dfsandtimeutil(*i, visited);
                starttime++;
                endtimes.push_back(starttime);
            }
        }
    }


    void dfsandtime(int n){
        bool visited[V];
        for(int i = 0; i < V; i++){
            visited[i] = false;
        }
        visited[n] = true;
        starttimes.push_back(starttime++);
        dfsandtimeutil(n, visited);
        endtimes.push_back(starttime++);

        for(int i = 0; i < V; i++){
            if(visited[i] == false && i != 0){
                dfsandtimeutil(i, visited);
            }
        }
    }


    void topsortutil(int n, bool visited[], stack<int > &stacka){
        visited[n] = true;
        list <int> ::iterator p;
        for(p = adj[n].begin();p != adj[n].end(); p++){
            if(visited[*p] == false){
                topsortutil(*p, visited, stacka);
            }
        }
        stacka.push(n);
    }

    void topsort(){
        bool visited[V];
        for(int i = 0; i <V; i++){
            visited[i] = false;
        }
        stack<int>stacka;
        for(int i = 0; i <V; i++){
            if(visited[i] == false){
                    topsortutil(i, visited, stacka);
        }
        }
        while(!stacka.empty()){
            cout<<stacka.top();
            stacka.pop();
        }
    }
};

int main(){
    Graph g(8);
    int V = 8;
   g.addedge(1, 2);
   g.addedge(1, 4);
   g.addedge(2, 3);
   g.addedge(2, 5);
   g.addedge(3, 5);
   g.addedge(4, 3);
   g.addedge(4, 5);
   g.addedge(5, 4);
   g.addedge(6, 3);
   g.addedge(7, 3);
   g.addedge(6, 7);
    g.addedge(1, 3);
    g.addedge(1, 2);
    g.addedge(2, 1);
    g.addedge(2, 3);
    g.addedge(3, 3);
    g.addedge(2, 4);
    g.addedge(3, 4);
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.bfs(3);
    cout<<endl;
    g.dfsandtime(3);
    cout<<endl;
    list <int >::iterator p;
    cout<<"start times"<<endl;
    for(    p = starttimes.begin();p != starttimes.end() ; p++){
        cout<< *p <<"  ";
    }
    cout<<"end times"<<endl;
    for(    p = endtimes.begin();p != endtimes.end(); p++){
        cout<< *p <<"  ";
    }
//    list <int> p;

    g.topsort();
    return 0;
}

    /*
    g.addedge(0, 2);
    g.addedge(1, 2);
    g.addedge(2, 0);
    g.addedge(2, 3);
    g.addedge(3, 3);
    g.addedge(0, 4);
    g.addedge(3, 4);

   // Graph g(6);
    g.addedge(5, 2);
    g.addedge(5, 0);
    g.addedge(4, 0);
    g.addedge(4, 1);
    g.addedge(2, 3);
    g.addedge(3, 1);
*/
