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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //brute force approach - 2 pass

        // ListNode* temp = head;
        // int size = 0;
        // while(temp){
        //     temp = temp->next;
        //     size++;
        // }

        // int req = size - n + 1;
        // temp = head;
        // if(req == 1){
        //     return head->next;
        // }
        // else{
        //     for(int i = 1;i<req-1;i++){
        //         temp = temp->next;
        //     }
        //     if(temp->next){
        //         temp->next = temp->next->next;
        //     }
        // }

        // return head;

        //optimal approach - single pass

        ListNode* ptr1 = head,*ptr2 = head;
            while(ptr1 && n--){
                ptr1 = ptr1->next;
            }

            if(!ptr1) return ptr2->next;

            while(ptr1 && ptr1->next){
                ptr1 = ptr1->next;
                ptr2 = ptr2->next;
            }

        if(ptr2->next) ptr2->next = ptr2->next->next;

        return head;
    }
};