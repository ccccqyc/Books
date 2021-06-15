class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

/**
 * 剑指offre18
 * 双指针
 */
public class DeleteNode {
    public ListNode deleteNode(ListNode head, int val) {
        ListNode temp1 = head, temp2 = temp1.next;
        if (temp1.val == val){
            return temp2;
        }
        while (temp2.val != val){
            temp1 = temp2;
            temp2 = temp1.next;
        }
        temp1.next = temp2.next;
        return head;
    }
}