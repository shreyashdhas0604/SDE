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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* p1 = headA, *p2 = headB;
        
        while(p1){
            ListNode* temp = p1;
            p2 = headB;
            while(p2){
                if(p2 == p1){
                    return p1;
                }
                p2 = p2->next;
            }
            p1 = p1->next;
        }

        return nullptr;

        return nullptr;
    }
};