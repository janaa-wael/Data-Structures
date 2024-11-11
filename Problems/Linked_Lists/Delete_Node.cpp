/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;        // Value stored in the node
 *     ListNode *next; // Pointer to the next node in the list
 *     ListNode(int x) : val(x), next(NULL) {} // Constructor to initialize the node
 * };
 */
class Solution {
public:
    /**
     * @brief Deletes the node in a singly linked list, given only access to that node.
     *
     * This function works by copying the value of the next node into the current node,
     * then bypassing the next node by updating the current node's `next` pointer to 
     * point to the next node's next node.
     * 
     * @param node Pointer to the node to be deleted. The node is guaranteed not to be 
     * the last node in the list, so the function will always be able to access the next node.
     */
    void deleteNode(ListNode* node) {
        // Copy the value of the next node into the current node
        node->val = node->next->val;

        // Bypass the next node by updating the current node's next pointer
        node->next = node->next->next;

        // No need to delete the next node explicitly since we have bypassed it,
        // but in a real scenario, we'd delete the next node if we had direct access to it.
    }
};
