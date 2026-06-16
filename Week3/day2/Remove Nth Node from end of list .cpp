class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode* temp = head;
        ListNode* prev = head;

        int i = 0;

        while(i < n){
            temp = temp->next;
            i++;
        }

        if(temp == NULL){
            return head->next;
        }

        while(temp->next != NULL){
            temp = temp->next;
            prev = prev->next;
        }

        prev->next = prev->next->next;

        return head;
    }
};