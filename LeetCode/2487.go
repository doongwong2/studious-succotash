/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func removeNodes(head *ListNode) *ListNode {
    if head.Next == nil{
        return head
    }

    next := removeNodes(head.Next)
    if next.Val > head.Val {
        return next
    }

    head.Next = next
    return head
}
