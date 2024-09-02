/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
        Node* findTarget(Node* root, int target, unordered_map<Node*, Node*>& parentMap) {
        queue<Node*> q;
        q.push(root);
        Node* targetNode = NULL;
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            if (current->data == target) {
                targetNode = current;
            }
            
            if (current->left) {
                parentMap[current->left] = current;
                q.push(current->left);
            }
            if (current->right) {
                parentMap[current->right] = current;
                q.push(current->right);
            }
        }
        
        return targetNode;
    }

    int minTime(Node* root, int target) {
        if (!root) return 0;
        
        unordered_map<Node*, Node*> parentMap;  
        Node* targetNode = findTarget(root, target, parentMap);
        
        // BFS to simulate the burning process
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        while (!q.empty()) {
            int size = q.size();
            bool flag = false;  // To check if any node got burned in this second
            
            for (int i = 0; i < size; i++) {
                Node* current = q.front();
                q.pop();
                
                // Burn the left child
                if (current->left && !visited[current->left]) {
                    visited[current->left] = true;
                    q.push(current->left);
                    flag = true;
                }
                
                // Burn the right child
                if (current->right && !visited[current->right]) {
                    visited[current->right] = true;
                    q.push(current->right);
                    flag = true;
                }
                
                // Burn the parent
                if (parentMap[current] && !visited[parentMap[current]]) {
                    visited[parentMap[current]] = true;
                    q.push(parentMap[current]);
                    flag = true;
                }
            }
            
            if (flag) {
                time++;
            }
        }
        
        return time;
    }
};