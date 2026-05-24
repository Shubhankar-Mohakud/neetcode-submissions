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
using ln = ListNode;
class Solution {
public:
    ln* reverse(ln* head){
        ln* curr = head;
        ln* prev = NULL;
        while(curr != NULL){
            ln* fwd = curr->next;
            curr->next = prev;
            prev = curr;
            curr = fwd;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ln* dummy = new ln(0);
        ln* curr = dummy;
        int carry = 0;
        while(l1 != NULL || l2 != NULL || carry !=0){
            int sum = carry;

            if(l1 != NULL){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                sum += l2->val;
                l2 = l2->next;
            }

            carry = sum/10;
            curr->next = new ln(sum%10);
            curr = curr->next;
        }
        ln* result = dummy->next;
        delete dummy;
        return result;
    }
};