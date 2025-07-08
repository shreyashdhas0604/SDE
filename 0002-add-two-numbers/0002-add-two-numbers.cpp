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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry = 0;
        ListNode* p1 = l1,*p2 = l2;
        ListNode* ans = nullptr;
        while(p1 || p2 || carry){
            int num1 = (p1) ? (p1->val) : (0);
            int num2 = (p2) ? (p2->val) : (0);
            int sum = (num1) + (num2);
            sum = (carry) ? (sum + carry) : (sum);
            carry = sum / 10;
            sum = sum % 10;
            ListNode* newnode = new ListNode(sum);
            if(ans == nullptr){
                ans = newnode;
            }
            else{
                ListNode *temp = ans;
                while(temp && temp->next){
                    temp = temp->next;
                }
                temp->next = newnode;
            }

            if(p1) p1 = p1->next;
            if(p2) p2 = p2->next;
        }

        return ans;
    }
};