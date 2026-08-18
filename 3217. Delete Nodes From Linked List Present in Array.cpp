// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* modifiedList(vector<int>& nums, ListNode* head) {  
//         for (int i = 0; i < nums.size(); i++) {
//             while (head != nullptr && head->val == nums[i]) {
//                 head = head->next;
//             }

//             for (ListNode* temp = head;
//                  temp != nullptr && temp->next != nullptr; ) {

//                 if (temp->next->val == nums[i]) {
//                     temp->next = temp->next->next;
//                 }
//                 else {
//                     temp = temp->next;
//                 }
//             }
//         }
//         return head;
//     }
// };


class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_set<int> st;

        for (int i = 0; i < nums.size(); i++) {
            st.insert(nums[i]);
        }
        while (head != nullptr && st.count(head->val)) {
            head = head->next;
        }
        ListNode* curr = head;

        for (; curr != nullptr && curr->next != nullptr; ) {

            if (st.count(curr->next->val)) {
                curr->next = curr->next->next;
            }
            else {
                curr = curr->next;
            }
        }

        return head;
    }
};