#include <bits/stdc++.h>
using namespace std;
int v,t, s;
struct edge{
    int from;
    int to;
    int weight;
};

bool visited[100];
int parent[100];
int mg[100][100];
int graph[100][100];


int bfs(){
    memset(visited, false, sizeof(visited));
    parent[s] = -1;
    visited[s] = true;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
            int from = q.front();
            q.pop();
        for(int i = 0; i <v; i++){
            if(visited[i] == false && mg[from][i]>0){
                q.push(i);
                parent[i] = from;
                visited[i] = true;
                //cout<<"comes";
            }
        }
    }
    //cout<<"comes"<<" ";
    return (visited[t] == true);
}
vector<int> vertices;
int bfs2(int s){
    memset(visited, false, sizeof(visited));
    parent[s] = -1;
    visited[s] = true;
    queue<int>q;
    q.push(s);
    while(!q.empty()){
            int from = q.front();
            vertices.push_back(from);
            q.pop();
        for(int i = 0; i <v; i++){
            if(visited[i] == false && mg[from][i]>0){
                q.push(i);
                parent[i] = from;
                visited[i] = true;
            }
        }
    }
}


int algo(){
    memset(mg, 0,sizeof(mg));
    for(int i = 0; i <v; i++){
        for(int j = 0; j <v; j++){
            mg[i][j] = graph[i][j];
        }
    }
    int ans = 0;

    while(bfs()){
            int pathf = INT_MAX;
            for(int y = t; y != s; y = parent[y]){
                int x = parent[y];
                if(mg[x][y]<pathf){
                    pathf = mg[x][y];
                }
                //cout<<"path "<<pathf<<endl;
            }
            for(int y = t; y != s; y = parent[y]){
                int x = parent[y];
                mg[x][y] -= pathf;
                mg[y][x] +=pathf;
            }
            ans+= pathf;
       memset(parent, 0, sizeof(parent));
        memset(visited, false, sizeof(visited));
    }
    return ans;
}

void printall(){
    bfs2(s);
    map<int, int>inside;
    for(int i = 0; i <vertices.size(); i++){
        inside[vertices[i]] = 1;
    }
    vector<edge> edges;
    for(int i = 0; i <v; i++){
        for(int j = 0; j <v; j++){
                if(inside[i] != 0 && inside[j] == 0 && graph[i][j]>0){
                        edge e1;
                        e1.from = i;
                        e1.to = j;
                        e1.weight = graph[i][j];
                        edges.push_back(e1);
                }
        }
    }
    for(int i = 0; i <edges.size(); i++){
        cout<<edges[i].from<<" "<<edges[i].to<<endl;
    }
}

int main()
{
    cout<<"vertices source and sink"<<endl;
    cin>>v>>s>>t;
    cout<<"no of edges"<<endl;
    int d;
    cin>>d;
    cout<<"from to and than weight"<<endl;
    for(int i = 0; i <d; i++){
            int x, y, w;
            cin>>x>>y>>w;
            graph[x][y] = w;
    }

    int ans = 0;
    ans = algo();
    printall();
        cout<<"maximum flow  is "<<ans;
    return 0;
}
