/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;

    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/

class Solution {
  public:
    // Function to remove a loop in the linked list.
    void removeLoop(Node* head) {
        if (head == NULL || head->next == NULL)
            return;

        Node *slow = head, *fast = head;

        // Detect loop using Floyd's Cycle Detection algorithm
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;  
            }
        }

        // If no loop is found, return
        if (slow != fast) {
            return;
        }

        // If the loop starts at the head
        if (slow == head) {
            while (fast->next != slow) {
                fast = fast->next;
            }
        } else {
            // If the loop doesn't start at the head
            slow = head;
            while (slow->next != fast->next) {
                slow = slow->next;
                fast = fast->next;
            }
        }

        // Remove the loop
        fast->next = NULL;
    }
};