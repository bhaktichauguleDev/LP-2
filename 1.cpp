#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <algorithm>
using namespace std;
class Graph {
private:
int V; 
vector<vector<int>> adj; 
public:
    Graph(int v) : V(v) {
        adj.resize(V);
    }
void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
void DFS_recursive(int start_node) {
        unordered_set<int> visited; 
        cout << "DFS Traversal (starting from vertex " << start_node << "): ";
        DFS_util(start_node, visited);
        cout << endl;
for (int i = 0; i < V; ++i) {
            if (visited.find(i) == visited.end()) {
                DFS_util(i, visited);
            }
        }
    }

private:
    void DFS_util(int u, unordered_set<int>& visited) {
        visited.insert(u);
        cout << u << " ";

        
        for (int v : adj[u]) {
            if (visited.find(v) == visited.end()) {
                DFS_util(v, visited);
            }
        }
    }

public:
    
    void BFS_traversal(int start_node) {
        queue<int> q;
        unordered_set<int> visited;

       
        visited.insert(start_node);
        q.push(start_node);

        cout << "BFS Traversal (starting from vertex " << start_node << "): ";

        while (!q.empty()) {
            
            int u = q.front();
            q.pop();
            cout << u << " ";

            
            for (int v : adj[u]) {
                if (visited.find(v) == visited.end()) {
                    visited.insert(v);
                    q.push(v);
                }
            }
        }
        cout << endl;
    }
};

int main() {
    
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 5);
    g.addEdge(2, 6);
    g.addEdge(3, 4);
    g.addEdge(5, 6);

    cout << "Graph structure:" << endl;
    
    g.DFS_recursive(0); 

    g.BFS_traversal(0);

    return 0;
}
