/*Structure of the linked list node is as
struct Node {
  int data;
  struct Node * next;
  Node(int x) {
    data = x;
    next = NULL;
  }
}; */

class Solution {
  public:
    Node *insertAtEnd(Node *head, int x) {
        Node* newNode = new Node(x);
        
        if (!head) {
            return newNode;
        }
        
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        
        current->next = newNode;
        
        return head;
        
    }
};