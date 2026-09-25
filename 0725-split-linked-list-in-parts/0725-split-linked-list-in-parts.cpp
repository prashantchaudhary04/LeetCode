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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int n = 0;
        ListNode* temp = head;

        while (temp != nullptr) {
            n++;
            temp = temp->next;
        }

        int size = n / k;
        int extra = n % k;

        vector<ListNode*> ans;

        ListNode* curr = head;

        for (int i = 0; i < k; i++) {

            int partSize = size;

            if (extra > 0) {
                partSize++;
                extra--;
            }

            ListNode* partHead = curr;

            for (int j = 1; j < partSize; j++) {
                curr = curr->next;
            }

            if (curr != nullptr) {
                ListNode* nextPart = curr->next;
                curr->next = nullptr;
                curr = nextPart;
            }

            ans.push_back(partHead);
        }

        return ans;
    }
};