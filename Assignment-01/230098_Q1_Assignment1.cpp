#include <iostream>
#include <vector>
using namespace std;

class Graph{
    private:
        void dfs(int node, vector<int> adj[], int visited[], vector<int> &ls){
            visited[node] = 1;
            ls.push_back(node);
            for(auto it : adj[node]){

                if(!visited[it]){
                    dfs(it, adj, visited, ls);
                }
            }
        }
    
    public:
        vector<int> dfsOfGraph(int V, vector<int> adj[]){
            int visited[V] = {0};
            int start = 8;

            vector<int> ls;

            dfs(start, adj, visited, ls);
            return ls;
        }
};

void addEdge(vector<int> adj[], int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void printAns(vector<int> &ans){
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
}

int main(){

    vector<int> adj[15];

    addEdge(adj, 0, 1);
    addEdge(adj, 0, 2);
    addEdge(adj, 1, 3);
    addEdge(adj, 1, 4);
    addEdge(adj, 2, 5);
    addEdge(adj, 2, 6);
    addEdge(adj, 2, 10);
    addEdge(adj, 3, 7);
    addEdge(adj, 3, 8);
    addEdge(adj, 4, 9);
    addEdge(adj, 5, 10);
    addEdge(adj, 6, 11);
    addEdge(adj, 6, 12);
    addEdge(adj, 9, 13);
    addEdge(adj, 9, 14);

    Graph obj;

    vector<int> ans = obj.dfsOfGraph(15, adj);

    printAns(ans);

    return 0;
}