#include <unordered_map>

class Solution {
  private:
    void insertAtTail(Node*& head, Node*& tail, int d) {
        Node* newNode = new Node(d);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
  public:
    Node *cloneLinkedList(Node *head) {
        // Step 1: Create a clone list
        Node* cloneHead = NULL;
        Node* cloneTail = NULL;
        
        Node* temp = head;
        while (temp != NULL) {
            insertAtTail(cloneHead, cloneTail, temp->data);
            temp = temp->next;
        }
        
        // Step 2: Create a map from original to clone
        unordered_map<Node*, Node*> oldToNewNode;
        Node* originalNode = head;
        Node* cloneNode = cloneHead;
        
        while (originalNode != NULL) {
            oldToNewNode[originalNode] = cloneNode;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        // Step 3: Assign random pointers
        originalNode = head;
        cloneNode = cloneHead;
        while (originalNode != NULL) {
            cloneNode->random = (originalNode->random) ? oldToNewNode[originalNode->random] : NULL;
            originalNode = originalNode->next;
            cloneNode = cloneNode->next;
        }
        
        return cloneHead;
    }
};
