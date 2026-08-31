class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        int first = -1;       // first critical point
        int last = -1;        // previous critical point
        int minDist = INT_MAX;

        ListNode* prev = head;
        ListNode* curr = head->next;

        int index = 1;

        while (curr->next != nullptr) {
            
            // Check if curr is a critical point
            bool critical =
                (curr->val > prev->val && curr->val > curr->next->val) ||
                (curr->val < prev->val && curr->val < curr->next->val);

            if (critical) {
                if (first == -1) {
                    // First critical point
                    first = index;
                } else {
                    // Distance from previous critical point
                    minDist = min(minDist, index - last);
                }

                last = index;
            }

            prev = curr;
            curr = curr->next;
            index++;
        }

        // Fewer than 2 critical points
        if (first == last)
            return {-1, -1};

        // Maximum distance = last critical - first critical
        int maxDist = last - first;

        return {minDist, maxDist};
    }
};