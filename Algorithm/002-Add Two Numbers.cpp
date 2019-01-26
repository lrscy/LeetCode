static const auto io_sync_off = [] () {
    std::cin.tie(nullptr);
    std::ios::sync_with_stdio(false);
    std::cout.tie(nullptr);
    return nullptr;
}();

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head =  new ListNode( 0 ), *tail = head;
        int d = 0;
        while( l1 || l2 ) {
            int d1 = l1 ? l1->val : 0;
            int d2 = l2 ? l2->val : 0;
            int s = d1 + d2 + d;
            d = s / 10;
            s %= 10;
            ListNode *tmp = new ListNode( s );
            tail->next = tmp;
            tail = tmp;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;
        }
        if( d ) {
            ListNode *tmp = new ListNode( d );
            tail->next = tmp;
        }
        return head->next;
    }
};
