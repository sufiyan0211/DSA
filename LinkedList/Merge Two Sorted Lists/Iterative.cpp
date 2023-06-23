class Solution {
public:
    ListNode *merge(ListNode *list1, ListNode *list2) {
        if (list1 == NULL) return list2;
        if (list2 == NULL) return list1;

        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;
        while (list1 != NULL && list2 != NULL) {
            if (list1->val <= list2->val) {
                tail->next = list1;
                tail = tail->next;
                list1 = list1->next;
            } else {
                tail->next = list2;
                tail = tail->next;
                list2 = list2->next;
            }
        }
        if (list1 != NULL) {
            tail->next = list1;
        } else if (list2 != NULL) {
            tail->next = list2;
        }
        return dummy->next;

    }

    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        return merge(list1, list2);
    }
};