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
public:
    bool isPalindrome(ListNode* head) {
        ListNode* ptr1 = head;
        ListNode* slow = head,*fast = head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }

        }
        slow = rev(slow);            
        while(slow){
            if(ptr1->val != slow->val){
                return false;
            }
            slow = slow->next;
            ptr1 = ptr1->next;
        }

        return true;
    
    }
};