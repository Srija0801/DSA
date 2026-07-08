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

        ListNode* curr1 = l1;
        ListNode* curr2 = l2;
        ListNode dummy(-1);
        ListNode* temp = &dummy;
        int carry = 0;

        // Step 2: Add 1 and propagate carry
        while (curr1 != nullptr || curr2 != nullptr || carry) {

            int sum=carry;

            if(curr1!=nullptr){
                sum+=curr1->val;
                curr1=curr1->next;
            }
            if(curr2!=nullptr){
                sum+=curr2->val;
                curr2=curr2->next;
            }


            carry=sum/10;
            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy.next;
    }
};