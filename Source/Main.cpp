#include <iostream>

#include "SinglyLinkedList/ListNode.h"
#include "SinglyLinkedList/Algorithms.h"

/////////////////////

template<Numeric T>
void Print(std::vector<T> values)
{
	std::cout << "Printing - ";
	for (T value : values)
	{
		std::cout << value << " ";
	}

	std::cout << '\n';
}

template<Numeric T>
void CreateTestList(ListNode<T>** head)
{
	ListNode<int>* a = new ListNode(2);
	ListNode<int>* b = new ListNode(3);
	ListNode<int>* c = new ListNode(3);
	ListNode<int>* d = new ListNode(5);

	(*head)->SetNext(a);
	a->SetNext(b);
	b->SetNext(c);
	c->SetNext(d);
}

template<Numeric T>
void DestroyList(ListNode<T>** head)
{
	if (*head != nullptr)
	{
		ListNode<T>* current = *head;
		ListNode<T>* next = nullptr;
		while (current != nullptr)
		{
			next = current->GetNext();
			delete current;
			current = next;
		}

		*head = nullptr;
	}
}

/////////////////////

int main()
{
	ListNode<int>* head = new ListNode(1);
	CreateTestList(&head);

	// testing
	Print(Algorithms::GetLinkedListValues(head));

	std::cout << "number of elements = " << Algorithms::CountElements(head) << '\n';

	std::cout << "sum of all values = " << Algorithms::GetLinkedListSum(head) << '\n';

	std::cout << "is 4 in the list - " << (Algorithms::IsValueInList(head, 4) ? "true" : "false") << '\n';

	std::cout << "value at index 3 = " << Algorithms::GetValueAtIndex(head, 3) << '\n';

	ListNode<int>* reversed = Algorithms::GetReversedLinkedList(head);
	Print(Algorithms::GetLinkedListValues(reversed));

	// merging
	ListNode<int>* list1 = new ListNode(0);
	ListNode<int>* next1 = new ListNode(4);
	ListNode<int>* next2 = new ListNode(7);
	list1->SetNext(next1);
	next1->SetNext(next2);

	ListNode<int>* merged = Algorithms::MergeLists(head, list1);
	Print(Algorithms::GetLinkedListValues(merged));

	////
	DestroyList(&merged);
	return 0;
}