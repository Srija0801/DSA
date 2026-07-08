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
    ListNode* reverse(ListNode* head){
        ListNode* prev=nullptr;
        ListNode* curr=head;

        while(curr){
            ListNode* next=curr->next;
            curr->next = prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }

    ListNode* divideintoK(ListNode* head,int k){
        ListNode* temp=head;
        k--;
        while(temp && k>0){
            temp=temp->next;
            k--;
        }
        return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
         if (head == nullptr || k == 1)
            return head;

        ListNode* temp = head;
        ListNode* prevGroupTail=nullptr;

        while(temp){
            ListNode* kthNode=divideintoK(temp,k);

            if (kthNode == nullptr) {

                if (prevGroupTail != nullptr)
                    prevGroupTail->next = temp;
                break;
            }

            ListNode* nextNode=kthNode->next;
            kthNode->next=nullptr;

            reverse(temp);

            if(temp==head){
                head=kthNode;
            }else{
                prevGroupTail->next=kthNode;
            }
            prevGroupTail=temp;
            temp=nextNode;

       }
       return head;
    }
};