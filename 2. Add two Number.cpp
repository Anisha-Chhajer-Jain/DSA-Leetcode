#include <iostream>
using namespace std;

// Node structure
struct ListNode {
    int val;
    ListNode* next;

    ListNode(int x) {
        val = x;
        next = NULL;
    }
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        ListNode* dummy = new ListNode(0);
        ListNode* temp = dummy;

        int carry = 0;

        while (l1 != NULL || l2 != NULL || carry != 0) {

            int sum = carry;

            if (l1 != NULL) {
                sum = sum + l1->val;
                l1 = l1->next;
            }

            if (l2 != NULL) {
                sum = sum + l2->val;
                l2 = l2->next;
            }

            carry = sum / 10;

            temp->next = new ListNode(sum % 10);
            temp = temp->next;
        }

        return dummy->next;
    }
};

// Print linked list
void print(ListNode* head) {

    while (head != NULL) {
        cout << head->val << " ";
        head = head->next;
    }

    cout << endl;
}

int main() {

    // First number: 342 => 2 4 3
    ListNode* l1 = new ListNode(2);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(3);

    // Second number: 465 => 5 6 4
    ListNode* l2 = new ListNode(5);
    l2->next = new ListNode(6);
    l2->next->next = new ListNode(4);

    Solution s;

    ListNode* result = s.addTwoNumbers(l1, l2);

    cout << "Result: ";
    print(result);

    return 0;
}