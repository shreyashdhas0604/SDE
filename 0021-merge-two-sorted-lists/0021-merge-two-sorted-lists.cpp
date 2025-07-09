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
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-1);
        ListNode* np = dummy;
        ListNode* n1 = list1,*n2 = list2;
        while(n1 && n2){
            if(n1->val == n2->val){
                ListNode* temp = n1->next;
                np->next = n1;
                n1->next = n2;
                n1 = temp;
                np = n2;
                n2 = n2->next;
            }
            else if(n1->val < n2->val){
                np->next = n1;
                np = np->next;
                n1 = n1->next;
            }
            else{
                np->next = n2;
                np = np->next;
                n2 = n2->next;
            }
        }

        if(n2) np->next = n2;
        if(n1) np->next = n1;
        return dummy->next;
    }
};