/*
The structure of linked list is the following

struct Node {
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution {
  private:
    Node* findMid(Node* head){
        Node* slow = head;
        Node* fast = head -> next;
        
        while(fast != NULL && fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next -> next; // fixed semicolon
        }
        return slow;
    }
    
    Node* merge(Node* left, Node* right){ // fixed name
        if(left == NULL)
           return right;
        if(right == NULL)
           return left;
           
        Node* ans = new Node(-1); // fixed class name
        Node* temp = ans;
        
        while(left != NULL && right != NULL){
            if(left -> data < right -> data){
                temp -> next = left;
                temp = left;
                left = left -> next;
            }
            else{
                temp -> next = right;
                temp = right;
                right = right -> next;
            }
        }
        while(left != NULL){
            temp -> next = left;
            temp = left;
            left = left -> next;
        }
        while(right != NULL){
            temp -> next = right;
            temp = right;
            right = right -> next;
        }
        
        return ans -> next; // cleaner return
    }
    
  public:
    // Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        // base case
        if(head == NULL || head -> next == NULL){
            return head;
        }
        // Break LL into 2 halves after finding mid
        Node* mid = findMid(head);
        
        Node* left = head;
        Node* right = mid -> next;
        mid -> next = NULL;
        
        // recursive calls to sort both halves 
        left = mergeSort(left);
        right = mergeSort(right);
        
        // merge right and left
        return merge(left, right);
    }
};
