/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
    vector<int> result;
    if (root == NULL) return result;

    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();  // Number of nodes at the current level

        // Traverse all nodes at the current level
        for (int i = 0; i < n; ++i) {
            Node* current = q.front();
            q.pop();

            // If this is the first node of the current level, add it to the result
            if (i == 0) {
                result.push_back(current->data);
            }

            // Add left and right children of the current node to the queue
            if (current->left != NULL) q.push(current->left);
            if (current->right != NULL) q.push(current->right);
        }
    }

    return result;
}