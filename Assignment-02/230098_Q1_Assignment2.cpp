#include <iostream>
#include <bits/stdc++.h>

using namespace std;

list<pair<int, int>>* adj;

class Graph{
    public: vector <int> Dijsktra(int V){
        vector<int> dist(V, numeric_limits<int>::max());
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push(make_pair(0,0));
        dist[0]=0;

        while(!pq.empty()){
            int u = pq.top().second;
            int d = pq.top().first;
            pq.pop();

            list<pair<int, int>>::iterator i;
            for(i = adj[u].begin(); i != adj[u].end(); ++i){
                int v = (*i).first;
                int w = (*i).second;

                if(dist[v] > dist[u]+w){
                    dist[v] = dist[u]+w;
                    pq.push(make_pair(dist[v], v));
                }
            }
        }
        return dist;
    }
};

void addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

int main()
{
    int n,m;
    cin >> n;
    cin >> m;
    adj = new list<pair<int, int>>[n];
    for(int i=0; i<m; i++){
        int u,v;
        int w;
        cin >> u;
        cin >> v;
        cin >> w;
        addEdge(u ,v, w);
    }
    Graph g;
    vector <int> ans = g.Dijsktra(n);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] <<" ";
    return 0;
}
