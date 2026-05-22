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
    bool isPalindrome(ListNode* head1) {
        if (head1 == nullptr) return true;
        // 1. Copy the Linked List
        ListNode* head2 = NULL;
        head2 = new ListNode(head1->val);
        ListNode *curr1=head1, *curr2=head2;
        while(curr1->next != NULL){
            curr2->next = new ListNode(curr1->next->val);
            curr1 = curr1->next;
            curr2 = curr2->next;
        }
        // 2. Reverse
        curr2 = head2;
        ListNode *prev = NULL;
        while(curr2 != NULL){
            ListNode *forward = curr2->next;
            curr2->next = prev;
            prev = curr2;
            curr2 = forward;
        }
        // 3. Compare
        curr1=head1;
        curr2=prev;
        while(curr1!=NULL){
            if(curr1->val != curr2->val) return false;
            else {
                curr1 = curr1->next;
                curr2 = curr2->next;
            }
        }
        return true;
    }
};