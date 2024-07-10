#include <iostream>
#include <bits/stdc++.h>

using namespace std;

list<pair<int, long>>* adj;

class Graph{
    public: vector <long> Dijsktra(int V){
    vector<long> dist(V, numeric_limits<long>::max());
    priority_queue<pair<long, int>, vector<pair<long, int>>, greater<pair<long, int>>> pq;
    pq.push(make_pair(0,0));
    dist[0]=0;

    while(!pq.empty()){
        int u = pq.top().second;
        long d = pq.top().first;
        pq.pop();

        if(dist[u] < d)
            continue;

        list <pair<int, long>>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); ++i){
            int v = (*i).first;
            long w = (*i).second;

            if(dist[v] > dist[u]+w){
                dist[v] = dist[u]+w;
                pq.push(make_pair(dist[v], v));
            }
        }
    }
    return dist;
}

};

void addEdge(int u, int v, long w){
    adj[u].push_back(make_pair(v, w));
}
int main(){
    int n,m;
    cin >> n;
    cin >> m;
    adj = new list<pair<int, long>>[n];
    for(int i=0; i<m; i++){
        int u,v;
        long w;
        cin >> u;
        cin >> v;
        cin >> w;
        addEdge(u-1 ,v-1, w);
    }
    Graph g;
    vector <long> ans = g.Dijsktra(n);
    for(int i=0; i<ans.size(); i++)
        cout << ans[i] <<" ";
    return 0;
}

