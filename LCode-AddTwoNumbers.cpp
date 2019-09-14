/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode * head;
    ListNode * tail;
    
    Solution() {
        setHead(nullptr);
    }
    
    ~Solution() {
        std::cout << "Deleting List";
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode * l1TmpNode = l1;
        ListNode * l2TmpNode = l2;
        int carryVal = 0;
        while (l1TmpNode != nullptr && l2TmpNode != nullptr) {
            ListNode * sum = new ListNode(l1TmpNode->val + l2TmpNode->val);
            if (carryVal != 0) {
                sum->val = sum->val + carryVal;
                // Carry is now zero as it has been added.
                carryVal = 0;
            }
            if (sum->val >= 10) {
                // Carry of the sum.
                carryVal = sum->val / 10;
                // Part of the sum.
                sum->val = sum->val % 10;
            }
            addNode(sum);
            l1TmpNode = l1TmpNode->next;
            l2TmpNode = l2TmpNode->next;
        }
        return getHead();
    }
    
    void addNode(ListNode * nodeToBeAdded) {
        if (getHead() == nullptr || getTail() == nullptr) {
            setHead(nodeToBeAdded);
            setTail(getHead());
        } else {
            ListNode * tmpNode = getHead();
            while (tmpNode->next != nullptr) {
                tmpNode = tmpNode->next;
            }
            tmpNode->next = nodeToBeAdded;
            setTail(tmpNode->next);
        }
    }
    
    // Getters
    ListNode * getHead() {
        return this->head;
    }
    
    ListNode * getTail() {
        return this->tail;
    }
    
    // Setters
    void setHead(ListNode * headNode) {
        if (headNode == nullptr) {
            this->head = headNode;
        } else {
            this->head = headNode;
            this->head->val = headNode->val;
            this->head->next = headNode->next;
        }
    }
    
    void setTail(ListNode * tailNode) {
        this->tail = tailNode;
    }
};