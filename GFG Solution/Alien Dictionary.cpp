class Solution {
  public:
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k];
        
        for (int i = 0; i < n - 1; i++) {
            string word1 = dict[i];
            string word2 = dict[i + 1];
            int len = min(word1.length(), word2.length());
            
            for (int j = 0; j < len; j++) {
                if (word1[j] != word2[j]) {
                    adj[word1[j] - 'a'].push_back(word2[j] - 'a');
                    break; 
                }
            }
        }
        
        // Step 3: Perform topological sorting using Kahn's Algorithm (BFS)
        vector<int> indegree(k, 0);
        for (int i = 0; i < k; i++) {
            for (auto it : adj[i]) {
                indegree[it]++;
            }
        }
        
        queue<int> q;
        for (int i = 0; i < k; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }
        
        string order;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            order += (char)(node + 'a');
            
            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }
        
        // If the order contains all characters, return it
        if (order.size() == k) {
            return order;
        }
        
        // In case of cycle or incomplete topological sort
        return "";
    }
};