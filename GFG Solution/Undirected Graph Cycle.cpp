
class Solution {
  public:
    
    bool dfs(int node, int parent, vector<int> adj[], vector<bool>& visited) {
        visited[node] = true;
        
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                // If the neighbor is not visited, recurse with the current node as parent
                if (dfs(neighbor, node, adj, visited)) {
                    return true;
                }
            } else if (neighbor != parent) {
                // If the neighbor is visited and is not the parent, a cycle is detected
                return true;
            }
        }
        
        return false;
    }
    
    // Function to detect cycle in an undirected graph
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                // Start DFS from each unvisited node
                if (dfs(i, -1, adj, visited)) {
                    return true;
                }
            }
        }
        
        return false;
    }
};