// Definition for singly-linked list:
// template<typename T>
// struct ListNode {
//   ListNode(const T &v) : value(v), next(nullptr) {}
//   T value;
//   ListNode *next;
// };
//
ListNode<int> * mergeTwoLinkedLists(ListNode<int> * l1, ListNode<int> * l2) {
    // Check to see which is the lower of the two linked lists as we iterate
    if(l1 == nullptr)
        return l2;
    if(l2 == nullptr)
        return l1;
    
    ListNode<int> * head;
    if(l1->value <= l2-> value){
        head = l1;
        l1 = l1->next;
    }
    else{
        head = l2;
        l2 = l2->next;
    }
    
    // Which one is smaller? 
    // Add that one to the list
    // Increment that one's number
    ListNode<int> * current = head;
    bool l1good = true;
    bool l2good = true;
    
    while(l1good || l2good){                
        if(l1 == nullptr)
            l1good = false;
        if(l2 == nullptr)
            l2good = false;  
        if(l1good && l2good){
            if(l1->value <= l2->value){
                current->next = l1;
                l1 = l1->next;
            } else {
                current->next = l2;
                l2 = l2->next;
            }
        } else{
            if(l1good){
                current->next = l1;
                l1 = l1->next;
            }
            if(l2good){
                current->next = l2;
                l2 = l2->next;
            }
        }
        current = current->next;
    }
    
    return head;
}
