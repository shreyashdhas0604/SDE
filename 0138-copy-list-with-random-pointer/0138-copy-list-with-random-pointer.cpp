/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* ans = new Node(-1);
        unordered_map<Node*,Node*> mp1;
        Node* temp = head;
        while(temp != nullptr){
            Node* temp2 = ans;
            Node* newnode = new Node(temp->val);
            while(temp2->next){
                temp2 = temp2->next;
            }        
            temp2->next = newnode;

            mp1[temp] = newnode;
            temp = temp->next;
        }

        temp = head;
        Node* temp2 = ans->next;
        while(temp){
            Node* randomnode1 = temp->random;
            temp2->random = mp1[randomnode1];
            temp = temp->next;
            temp2 = temp2->next;
        }

        return ans->next;
    }
};