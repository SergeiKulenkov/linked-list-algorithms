# Linked List Algorithms

<ins>A compilation of singly linked list (numeric template) algorithms with various test cases in Main.cpp:</ins>
* std::vector<T> GetLinkedListValues(const ListNode<T>* head)
* ListNode<T>* CopyLinkedList(const ListNode<T>* head)
* uint32_t CountElements(const ListNode<T>* head)
* T GetLinkedListSum(const ListNode<T>* head) - <ins>gets a sum</ins> of all values
* bool IsValueInList(const ListNode<T>* head, const T value)
* T GetValueAtIndex(const ListNode<T>* head, const uint32_t index)
* ListNode<T>* GetReversedLinkedList(const ListNode<T>* head)
* ListNode<T>* GetPartiallyReversedLinkedList(const ListNode<T>* head, const uint32_t left, const uint32_t right) - <ins>makes a list</ins> with reversed elements between left and right index
* ListNode<T>* MergeLists(ListNode<T>* list1, ListNode<T>* list2) - <ins>makes a merged</ins> list with elements in ascending order
* void RemoveLast(ListNode<T>* head)
* void RemoveFromEnd(ListNode<T>** head, const uint32_t index) - <ins>removes nth value</ins> from the end
* bool FindDuplicate(const ListNode<T>* head, T& value)
* void InsertNode(ListNode<T>** head, ListNode<T>* newNode, const int index = -1) / void InsertNode(ListNode<T>** head, const T value, const int index = -1) - <ins>inserts a new</ins> node at the end or at index
* T FindMax(const ListNode<T>* head)
* T FindMin(const ListNode<T>* head)
