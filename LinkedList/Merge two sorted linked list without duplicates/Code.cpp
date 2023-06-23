
ListNode *merge(ListNode *list1, ListNode *list2) {
    if (list1 == NULL) return list2;
    if (list2 == NULL) return list1;
    if (list1->val <= list2->val) {
        list1->next = merge(list1->next, list2);
        return list1;
    } else {
        list2->next = merge(list1, list2->next);
        return list2;
    }
}


ListNode *removeDuplicates(ListNode *list) {
    if (list == NULL) return list;
    ListNode *current = list->next, *prev = list;
    while (current != NULL) {
        if (current->val == prev->val) {
            ListNode *nextNode = current->next;
            // previous node will be same just update it's next to current->next
            prev->next = current->next;
            free(current);
            current = nextNode;
        } else {
            prev = current;
            current = current->next;
        }
    }

    return list;
}

// Add Code here
ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
    list1 = merge(list1, list2);
    list1 = removeDuplicates(list1);
    return list1;
}
