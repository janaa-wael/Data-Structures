/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;        // Value stored in the node
 *     ListNode *next; // Pointer to the next node in the list
 *     ListNode() : val(0), next(nullptr) {} // Default constructor
 *     ListNode(int x) : val(x), next(nullptr) {} // Constructor to initialize the node with value
 *     ListNode(int x, ListNode *next) : val(x), next(next) {} // Constructor to initialize node with value and next pointer
 * };
 */
class Solution {
public:
    /**
     * @brief Removes the nth node from the end of the list and returns the head of the list.
     * 
     * This approach uses the two-pointer technique. We move the second pointer `ptr2`
     * n nodes ahead of the first pointer `ptr1`. After that, both pointers are moved in tandem 
     * until `ptr2` reaches the end of the list. At that point, `ptr1` will be just before the 
     * node that needs to be deleted. We then adjust the pointers to remove the nth node.
     * 
     * @param head The head of the linked list.
     * @param n The index (from the end of the list) of the node to be removed.
     * @return The head of the modified linked list.
     */
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Create two pointers, both starting at the head of the list
        ListNode* ptr1 = head;
        ListNode* ptr2 = head;
        
        // Move ptr2 n steps ahead in the list
        while(n--) {
            // If ptr2 becomes NULL before n steps, it means n is larger than the length of the list
            // In such case, we return the head (no node to remove)
            if(ptr2 == NULL) 
                return head;
            ptr2 = ptr2->next;
        }

        // If ptr2 is NULL, it means we are removing the first node from the list
        if(ptr2 == NULL) {
            // Return the next node of head (effectively removing the head node)
            return head->next;
        }

        // Move both pointers until ptr2 reaches the last node (ptr2->next == NULL)
        while(ptr2->next != NULL) {
            ptr2 = ptr2->next;
            ptr1 = ptr1->next;
        }

        // Now, ptr1 is just before the node we need to delete
        // Remove the nth node by skipping it: point ptr1's next to the next of its next node
        ptr1->next = ptr1->next->next;

        // Return the modified head of the list
        return head;
    }
};
