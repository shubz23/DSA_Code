class Solution {
  public:
    bool isBSTUtil(Node* node, int min, int max) {
        if (node == NULL) 
        return true;

        if (node->data <= min || node->data >= max) 
        return false;

        return isBSTUtil(node->left, min, node->data) && isBSTUtil(node->right, node->data, max);
    }

    bool isBST(Node* root) {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
};