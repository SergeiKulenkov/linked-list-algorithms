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
	ListNode<uint16_t>* a = new ListNode((uint16_t)2);
	ListNode<uint16_t>* b = new ListNode((uint16_t)3);
	ListNode<uint16_t>* c = new ListNode((uint16_t)4);
	ListNode<uint16_t>* d = new ListNode((uint16_t)5);

	(*head)->SetNext(a);
	a->SetNext(b);
	b->SetNext(c);
	c->SetNext(d);
}

// destroy can work for any type
template<typename T>
void DestroyList(ListNode<T>** head)
{
	if (head != nullptr && *head != nullptr)
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
	ListNode<uint16_t>* head = new ListNode((uint16_t)1);
	CreateTestList(&head);

	// testing
	Print(Algorithms::GetLinkedListValues(head));

	std::cout << "number of elements = " << Algorithms::CountElements(head) << '\n';

	std::cout << "sum of all values = " << Algorithms::GetLinkedListSum(head) << '\n';

	std::cout << "is 4 in the list - " << (Algorithms::IsValueInList(head, (uint16_t)4) ? "true" : "false") << '\n';

	std::cout << "value at index 3 = " << Algorithms::GetValueAtIndex(head, 3) << '\n';

	std::cout << "duplicate number is - " << Algorithms::FindDuplicate(head) << '\n';

	ListNode<uint16_t>* reversed = Algorithms::GetReversedLinkedList(head);
	std::cout << "\nreversed" << '\n';
	Print(Algorithms::GetLinkedListValues(reversed));

	// merging
	ListNode<uint16_t>* list1 = new ListNode((uint16_t)0);
	ListNode<uint16_t>* next1 = new ListNode((uint16_t)4);
	ListNode<uint16_t>* next2 = new ListNode((uint16_t)7);
	list1->SetNext(next1);
	next1->SetNext(next2);

	ListNode<uint16_t>* merged = Algorithms::MergeLists(head, list1);
	std::cout << "\nmerged" << '\n';
	Print(Algorithms::GetLinkedListValues(merged));

	Algorithms::RemoveLast(merged);
	std::cout << "\nremoved last" << '\n';
	Print(Algorithms::GetLinkedListValues(merged));

	Algorithms::RemoveFromEnd(&merged, 3);
	std::cout << "\nremoved 3rd from end" << '\n';
	Print(Algorithms::GetLinkedListValues(merged));

	Algorithms::InsertNode(&merged, (uint16_t)6);
	std::cout << "\ninserted last" << '\n';
	Print(Algorithms::GetLinkedListValues(merged));

	Algorithms::InsertNode(&merged, (uint16_t)0, 0);
	std::cout << "\ninserted first" << '\n';
	Print(Algorithms::GetLinkedListValues(merged));

	DestroyList(&reversed);
	DestroyList(&merged);

	return 0;
}