/**
*	file   : BST_Shortest.cpp
*	date   : 01.26.2017
*	author : Hyungjun Lee
*	mail   : hjlee1765@gmail.com
*	refer  : Hacker Rank
**/


#include <cmath>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>
#include <algorithm> 
#include <queue>
using namespace std;

class Graph {
    private:
        int n;
        vector<vector<int>> adj;
    public:
        Graph(int n) {
            this->n = n;
            for(int i=0; i<n+1; i++)
                adj.push_back(vector<int>(n+1));
        }
    
        void add_edge(int u, int v) {
            adj[u][v] = 1;
            //that important
            //for문돌때 d[]!=-1 이면 이미 visit한것이므로, 알아서 걸러진다.
            adj[v][u] = 1;
        }
    
        vector<int> shortest_reach(int start) {
            //d벡터는 d[v]=x; 라고 한다면 시작부터 v노드까지의 거리를 x라 한다. 또한 x가-1일경우, unvisit으로 처리한다.
            vector<int> d(n+1,-1);
            vector<int> before(n+1);
            queue<int> q;
            
            int u = start;
           //d[1] = 0;
            //시작지점에 1이 아닐수도 있다. 시작지점의 d[시작]값을 0으로 놓아야 한다.
            d[u] = 0 ;
            
            q.push(start);
            while(!q.empty()){
                int u = q.front();
                q.pop();
                for(int i=1; i<n+1; i++){
                    //if adjacen and unvisted
                    if(adj[u][i] == 1 && d[i] == -1){
                     //   cout << "i:" << i << " u:" << u;
                        //u is beforeNode
                        d[i] = d[u] + 6;
                        before[i] = u;
                        q.push(i);
                    }     
                }
                
            }
            return d;
        }
    
};

int main() {
    int queries;
    cin >> queries;
        
    for (int t = 0; t < queries; t++) {
      
      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6: 
        Graph graph(n);
        cin >> m;
        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            //u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        //startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 1; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }
    
    return 0;
}
