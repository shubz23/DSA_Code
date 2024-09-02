/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    Node* reverse(Node* head) {
        if (!head || !head->next) return head;

        Node* prev = nullptr;
        Node* current = head;
        Node* next = head->next;
        
        while (next) {
            current->next = prev;
            prev = current;
            current = next;
            next = current->next;
        }
        
        current->next = prev;

        return current;
    }

    Node* addTwoNumbers(Node* l1, Node* l2) {
        if (!l1) return l2;
        if (!l2) return l1;

        Node* resultHead = l1;
        Node* resultTail = nullptr;
        int carry = 0;

        while (l1 && l2) {
            l1->data += carry + l2->data;
            carry = l1->data / 10;
            l1->data %= 10;
            resultTail = l1;
            l1 = l1->next;
            l2 = l2->next;
        }

        if (l2) {
            resultTail->next = l2;
            l1 = l2;
        }

        while (l1) {
            l1->data += carry;
            carry = l1->data / 10;
            l1->data %= 10;
            resultTail = l1;
            l1 = l1->next;
        }

        while (carry) {
            resultTail->next = new Node(carry % 10);
            carry /= 10;
            resultTail = resultTail->next;
        }

        return resultHead;
    }

    Node* addTwoLists(Node* num1, Node* num2) {
        while (num1->next && num1->data == 0) {
            num1 = num1->next;
        }
        while (num2->next && num2->data == 0) {
            num2 = num2->next;
        }

        num1 = reverse(num1);
        num2 = reverse(num2);

        return reverse(addTwoNumbers(num1, num2));
    }
};
