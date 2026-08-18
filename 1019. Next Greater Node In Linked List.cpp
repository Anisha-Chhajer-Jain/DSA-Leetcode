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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;  //empty vector jo store kaega answer haar ek noode ka 
        ListNode* curr = head; //create karega pointer curr, jo head se start hoke haar node meh jayega

        while (curr != nullptr) { //Loop run karega till curr end of nullptr tak nhi pahuch jata
            ListNode* temp = curr->next; //another pointer temp jo start hoga next node after curr
            int check = 0; //as the grater wla ko store karne ke liye

            while (temp != nullptr) {
                if (temp->val > curr->val) { //compares karega value of temp with curr
                    check = temp->val; //agar large value milega to stor ein check
                    break; //stop kar dega search bcz hame chahiye 1st greater node aur largest nhi
                }
                temp = temp->next; //agar nhi mila toh wo continue karte rahega
            }

            ans.push_back(check); //add kar dega aur jo answer liega wo vector form ai it will keep it
            curr = curr->next; //curr point kar dega next node ko
        }
        return ans; //return kar dega answer jo pura hai
    }
};