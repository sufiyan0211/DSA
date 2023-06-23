class Comp {
public:
    bool operator()(ListNode *a, ListNode *b) {
        return (a->val > b->val);
    }
};

class Solution {
public:
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        int k = lists.size();
        if (k == 0) return NULL;
        if (k == 1) return lists[0];

        priority_queue <ListNode*, vector <ListNode*>, Comp> pq;

        for (int i = 0; i < k; i++) {
            if (lists[i] != NULL)
                pq.push(lists[i]);
        }

        ListNode *dummy = new ListNode(-1);
        ListNode *tail = dummy;

        while (!pq.empty()) {
            ListNode *minimumNodeList = pq.top();
            pq.pop();

            if (minimumNodeList->next != NULL) {
                pq.push(minimumNodeList->next);
            }

            tail->next = minimumNodeList;
            tail = minimumNodeList;

        }
        return dummy->next;
    }
};