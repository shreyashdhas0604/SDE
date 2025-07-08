/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode* ptr1 = node;
        while(ptr1 && ptr1->next){
            if(ptr1->next->next == nullptr){
            ptr1->val = ptr1->next->val;
                ptr1->next = nullptr;
                break;
            }
            ptr1->val = ptr1->next->val;
            ptr1 = ptr1->next;
        }
    }
};