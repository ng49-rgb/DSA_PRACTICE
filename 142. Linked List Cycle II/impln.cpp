class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr) return nullptr;

        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect if a cycle exists
        bool hasCycle = false;
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (fast == slow) {
                hasCycle = true;
                break;
            }
        }
        if (!hasCycle) return nullptr;

        // Step 2: Find the exact start node of the cycle
        ListNode* entry = head;
        while (entry != slow) {
            entry = entry->next;
            slow = slow->next;
        }

        return entry; // Returns the ListNode* where the cycle begins
    }
};
