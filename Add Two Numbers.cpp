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
        ListNode* sumHead = new ListNode((l1->val+l2->val)%10);
        int carry = (l1->val+l2->val)/10;
        ListNode* sumCurr = sumHead;
        l1 = l1->next;
        l2 = l2->next;
        while(l1 || l2){
            if(!l1 && l2){
                sumCurr->next = new ListNode((0 + l2->val + carry)%10);
                carry = (0 + l2->val + carry)/10;
                l2 = l2->next;
            } else if(!l2 && l1){
                sumCurr->next = new ListNode((l1->val + 0 + carry)%10);
                carry = (l1->val + 0 + carry)/10;  
                l1 = l1->next;
            } else{
                cout<<(l1->val + l2->val + carry)%10<<" ";
                sumCurr->next = new ListNode((l1->val + l2->val + carry)%10);
                carry = (l1->val + l2->val + carry)/10;
                l1 = l1->next;
                l2 = l2->next;
            }
            sumCurr = sumCurr->next;
        }
        if(carry){
           sumCurr->next = new ListNode(carry);
        }
        return sumHead;
    }
};
