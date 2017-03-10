//
// Created by Ailias on 2017/3/10.
//

/**
 * link list node struct
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

/**
 * merge two sorted link list to a new sorted one.
 * 用于两个排好序的连标点的合并并返回排序结果。直接在两个链表上进行比较操作即可。
 * 如果两个链表不是排好序的，那就只能先保存至set中排序之后再依次新建node连接成结果。
 * @param l1
 * @param l2
 * @return
 */
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (l1 == nullptr)//only l2 link list, no need merge
        return l2;
    if (l2 == nullptr)//only l1 link list, no need merge
        return l1;

    ListNode *result_list;//result list
    if (l1->val <= l2->val)//check which first node(the smaller one) should result_list link
        result_list = l1;
    else //l2 is the smaller one
        result_list = l2;

    ListNode *l1_current_node = l1;// l1 current node for traversing l1 link list
    ListNode *l2_current_node = l2;// l2 tmp node for traversing l2 link list
    ListNode *l1_pre_node = nullptr;// l1 previous node which less than l2_current_node
    ListNode *l2_pre_node = nullptr;// l2 previous node which less than l1_current_node
    while (l1_current_node != nullptr && l2_current_node != nullptr) {
        //find which node from l1 > l2_current_node
        //查找l1中大于l2当前节点的值的节点
        while (l1_current_node != nullptr && l2_current_node != nullptr &&
               l1_current_node->val <= l2_current_node->val) {
            l1_pre_node = l1_current_node;
            l1_current_node = l1_current_node->next;
        }
        //link the l1_pre_node->next to l2_current_node result list
        if (l1_pre_node != nullptr && l2_current_node != nullptr)
            l1_pre_node->next = l2_current_node;
        //find which node form l2 >= l1_current_node
        //查找l2中大于等于l1当前节点值的节点
        while (l2_current_node != nullptr && l1_current_node != nullptr &&
               l2_current_node->val < l1_current_node->val) {
            l2_pre_node = l2_current_node;
            l2_current_node = l2_current_node->next;
        }
        //link the l2_pre_node->next to l1_current_node as result list
        if (l2_pre_node != nullptr && l1_current_node != nullptr)
            l2_pre_node->next = l1_current_node;
    }
    return result_list;
};


/**
 * test case
 */
void testLinkListMergeFunction() {
    ListNode *l1 = new ListNode(1);
    ListNode *l1_head = l1;
    unsigned int l1_num = 3;
    unsigned l1_index = 2;
    while (l1_head != nullptr && l1_index <= l1_num) {
        l1_head->next = new ListNode(l1_index * 3);
        l1_head = l1_head->next;
        l1_index++;
    }

    ListNode *l2 = new ListNode(3);
    ListNode *l2_head = l2;
    unsigned int l2_num = 6;
    unsigned l2_index = 4;
    while (l2_head != nullptr && l2_index <= l2_num) {
        l2_head->next = new ListNode(l2_index);
        l2_head = l2_head->next;
        l2_index++;
    }
    ListNode *res = mergeTwoLists(l1, l2);
    while (res != nullptr) {
        std::cout << res->val << std::endl;
        res = res->next;
    }
}
