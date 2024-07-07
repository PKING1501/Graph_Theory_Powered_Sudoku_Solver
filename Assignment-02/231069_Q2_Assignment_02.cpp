// By SWAPNIL GARG, Roll no. 231069

#include<bits/stdc++.h>
using namespace std;

class graph{
    public :
    vector<int> visited;
    map<int, list<vector<int>> > adj_city;

    int num;
    graph(int n, int m){
        num = m;
        for(int i=0; i<n; i++)
            visited.push_back(0);
    }
    
    
    int a, b;
    
    void enter_graph(){
        for(int i=0; i<num; i++){
            vector<int> vec(3, 0);
            cin >> vec[0] >> vec[1] >> vec[2];
            adj_city[vec[0]-1].push_back(vec);
        }
    }

};

class distance_table{
    public :
    vector<int> table;
    int num;

    distance_table(graph g, int n)
    {
        num=n;
        for(int i=0; i<n; i++)
            table.push_back(INT_MAX);
    
        table[0] = 0;
    }

    void traverse(graph &g, int node);
    void display_distance();

};

void distance_table :: traverse(graph &g, int node)
{
    int node_min_dist=-1, min_dist=INT_MAX;

    list<vector<int>>::iterator i;
    for(i=g.adj_city[node].begin(); i!=g.adj_city[node].end(); i++)
        if(!g.visited[(*i)[1]-1])
        {
            int dist = table[node] + (*i)[2];
            if(dist<table[(*i)[1]-1])
                table[(*i)[1]-1] = dist;
            if(dist<min_dist)
                node_min_dist=(*i)[1]-1;
        }

    g.visited[node] = 1;
    if(node_min_dist!=-1)
    traverse(g, node_min_dist);
}

void distance_table :: display_distance()
{
    for(int i=0; i<num; i++)
        cout << table[i] << endl;
}  

int main()
{
    int m, n;
    // n = no. of cities
    // m = no. of flight connections
    cin >> n >> m;

    graph g(n, m);
    g.enter_graph();

    distance_table result(g, n);
    result.traverse(g, 0);

    result.display_distance();


    return 0;
}
