class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;

        int c = 0;

        ListNode *tail1 = NULL, *tail2 = NULL, *k = NULL;
        ListNode *temp = head;

        while (temp != NULL) {
            ListNode* nextNode = temp->next;

            if (c % 2 == 0) {
                if (tail1 == NULL) {
                    tail1 = temp;
                }
                else { 
                    tail1->next = temp;
                    tail1 = temp;
                }

                tail1->next = NULL;
            }
            else {
                if (tail2 == NULL) {
                    tail2 = temp;
                    k = tail2;
                }
                else {
                    tail2->next = temp;
                    tail2 = temp;
                }

                tail2->next = NULL;  // = instead of ==
            }

            temp = nextNode;
            c++;
        }

        tail1->next = k;

        return head;  // not tail1
    }
};