/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* rev(ListNode* head){
        ListNode* curr = head,*prev = nullptr;
        while(curr){
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        return prev;
    }

    ListNode* findknode(ListNode* temp,int k){
        k -= 1;
        while(temp != nullptr && k>0){
            temp = temp->next;
            k--;
        }

        return temp;

    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head,*prevLast = nullptr;

        while(temp != nullptr){
            
            ListNode* kthNode = findknode(temp,k);
            if(kthNode == nullptr){
                if(prevLast) prevLast->next = temp;
                break;
            }

            ListNode* nextNode = kthNode->next;
            kthNode->next = nullptr;
            rev(temp);
            if(temp == head){
                head = kthNode;
            }
            else{
                prevLast->next = kthNode;
            }

            prevLast = temp;
            temp = nextNode;

        }
        
        return head;
    }
};