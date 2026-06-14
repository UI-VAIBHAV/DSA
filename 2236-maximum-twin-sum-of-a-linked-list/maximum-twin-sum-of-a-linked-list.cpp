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

    int pairSum(ListNode* head) {
        int sum=0;
        ListNode *fast=head,*slow=head;
        while(fast && fast->next){
            slow=slow->next;
            fast = fast->next->next;
        }
        //reverse
        ListNode *curr = slow;
        ListNode *prev = NULL;
        while(curr){
            ListNode *fut = curr->next;
            curr->next=prev;
            prev = curr;
            curr = fut;
        }
        
        //maximum
        curr = head;
        while(prev && curr){
            int val = curr->val + prev->val;
            sum = max(sum,val);
            curr = curr->next;
            prev = prev->next;
        }
        return sum;
    }
};