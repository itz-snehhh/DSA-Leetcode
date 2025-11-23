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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL || k==0) return head;

        int n= 1;
        ListNode* temp = head;
        while(temp->next!=NULL){
            n++;
            temp= temp->next;
        }
        temp->next=head;//circular
        
        k= k%n;
        int stepsToEnd = n-k; // tail of list
        while(stepsToEnd--){
            temp= temp->next;
        }
        head= temp->next;
        temp->next = NULL;

        return head;

        
    }
};