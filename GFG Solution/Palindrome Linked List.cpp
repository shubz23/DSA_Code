/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        
        return prev;
    }

    bool isPalindrome(Node* head) {
        if (head == NULL || head->next == NULL) {
            return true; 
        }
        
        Node *slow = head, *fast = head;
        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        Node* second_half = reverse(slow);
        Node* first_half = head;
        
        while (second_half != NULL) {
            if (first_half->data != second_half->data) {
                return false; 
            }
            first_half = first_half->next;
            second_half = second_half->next;
        }
        
        return true;
    }
};
