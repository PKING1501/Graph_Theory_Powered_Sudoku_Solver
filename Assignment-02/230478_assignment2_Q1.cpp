#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxN = 1e5;

struct Edge { int v; ll w; };
struct Node {     //Serves the purpose of custom comparator.
    int id; ll dist;
    friend bool operator<(const Node &a, const Node &b){
        return a.dist > b.dist;
    }
};

int N, M, a, b;
ll dist[maxN+1], c;
vector<Edge> G[maxN+1];
priority_queue<Node> Q;   //Implementing the priority queue as minimum heap with a custom comparator to implement the same.

int main(){
    scanf("%d %d", &N, &M);
    for(int i = 0; i < M; i++){
        scanf("%d %d %lld", &a, &b, &c);
        G[a].push_back({b, c});      //Formation of adjaceny list where the elements are stored as pairs with the positions as node and weights respectively.
    }

    memset(dist, 0x3f, sizeof(dist)); //Filling up all the distance indexes with infinite before starting off.
    dist[1] = 0;      //distance to the source is zero.
    Q.push({1, 0});
    while(!Q.empty()){       
        ll d = Q.top().dist;
        int u = Q.top().id;
        Q.pop();                    //Extracting the elements from the PQ one by one.

        if(d > dist[u]) continue;

        for(Edge e : G[u]){                       //For every neighbour node with its distance, we perform this traversal.
            if(dist[e.v] > d+e.w){
                dist[e.v] = d+e.w;          //On finding a better/ minimum distance to the node, we would update the distance to the newer minimum one.
                Q.push({e.v, d+e.w});        //This update becomes the part of the priority queue itself as well.
            }
        }
    }

    for(int i = 1; i <= N; i++)
        printf("%lld%c", dist[i], (" \n")[i==N]);
}
