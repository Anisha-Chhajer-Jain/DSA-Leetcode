
 class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {

        ListNode* start = list1;
        ListNode* end = list1;

        // Go to node just before a
        for (int i = 0; i < a - 1; i++) {
            start = start->next;
        }

        // Go to node b
        for (int i = 0; i < b; i++) {
            end = end->next;
        }

        // Connect before a to list2
        start->next = list2;

        // Go to end of list2
        while (list2->next != NULL) {
            list2 = list2->next;
        }

        // Connect list2 to node after b
        list2->next = end->next;

        return list1;
    }
};