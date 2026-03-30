# Linked List Algorithms

A compilation of singly linked list algorithms (numeric template):
* std::vector<T> GetLinkedListValues(const ListNode<T>* head)
* ListNode<T>* CopyLinkedList(const ListNode<T>* head)
* uint32_t CountElements(const ListNode<T>* head)
* T GetLinkedListSum(const ListNode<T>* head) - gets a sum of all values
* bool IsValueInList(const ListNode<T>* head, const T value)
* T GetValueAtIndex(const ListNode<T>* head, const uint32_t index)
* ListNode<T>* GetReversedLinkedList(const ListNode<T>* head)
* ListNode<T>* GetPartiallyReversedLinkedList(const ListNode<T>* head, const uint32_t left, const uint32_t right) - makes a list with reversed values between left and right index
* ListNode<T>* MergeLists(ListNode<T>* list1, ListNode<T>* list2)
* void RemoveLast(ListNode<T>* head) - removes last element
* void RemoveFromEnd(ListNode<T>** head, const uint32_t index) - removes nth value from the end
* bool FindDuplicate(const ListNode<T>* head, T& value)
* void InsertNode(ListNode<T>** head, ListNode<T>* newNode, const int index = -1)
  void InsertNode(ListNode<T>** head, const T value, const int index = -1) - inserts a new node at the end or at index
* T FindMax(const ListNode<T>* head)
* T FindMin(const ListNode<T>* head)