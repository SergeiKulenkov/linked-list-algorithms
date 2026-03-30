#include <iostream>

#include "SinglyLinkedList/ListNode.h"
#include "SinglyLinkedList/Algorithms.h"

/////////////////////

template<Numeric T>
void Print(std::vector<T> values)
{
	std::cout << "Printing - ";
	for (const T value : values)
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
	ListNode<uint16_t>* c = new ListNode((uint16_t)3);
	ListNode<uint16_t>* d = new ListNode((uint16_t)5);

	(*head)->SetNext(a);
	a->SetNext(b);
	b->SetNext(c);
	c->SetNext(d);
}

template<Numeric T>
void CreateTestList2(ListNode<T>** head)
{
	ListNode<uint16_t>* next1 = new ListNode((uint16_t)4);
	ListNode<uint16_t>* next2 = new ListNode((uint16_t)7);
	(*head)->SetNext(next1);
	next1->SetNext(next2);
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

	const uint16_t valueToFinde = 4;
	std::cout << valueToFinde << " in the list - " << (Algorithms::IsValueInList(head, valueToFinde) ? "true" : "false") << '\n';

	const uint32_t indexToCheck = 3;
	std::cout << "value at index " << indexToCheck << " = " << Algorithms::GetValueAtIndex(head, indexToCheck) << '\n';

	uint16_t duplicate = 0;
	if (Algorithms::FindDuplicate(head, duplicate))
	{
		std::cout << "duplicate number = " << duplicate << '\n';
	}
	else
	{
		std::cout << "duplicate number not found\n";
	}

	ListNode<uint16_t>* reversed = Algorithms::GetReversedLinkedList(head);
	std::cout << "\nreversed" << '\n';
	Print(Algorithms::GetLinkedListValues(reversed));

	const uint32_t leftIndex = 0;
	const uint32_t rightIndex = 2;
	ListNode<uint16_t>* partiallyReversed = Algorithms::GetPartiallyReversedLinkedList(head, leftIndex, rightIndex);
	std::cout << "\npartially reversed between indexes " << leftIndex << " and " << rightIndex << '\n';
	Print(Algorithms::GetLinkedListValues(partiallyReversed));

	// merging
	ListNode<uint16_t>* list2 = new ListNode((uint16_t)0);
	CreateTestList2(&list2);

	ListNode<uint16_t>* merged = Algorithms::MergeLists(head, list2);
	std::cout << "\nmerged" << '\n';
	Print(Algorithms::GetLinkedListValues(merged));

	Algorithms::RemoveLast(merged);
	std::cout << "\nremoved last" << '\n';
	Print(Algorithms::GetLinkedListValues(merged));

	const uint32_t indexFromEnd = 3;
	Algorithms::RemoveFromEnd(&merged, indexFromEnd);
	std::cout << "\nremoved number " << indexFromEnd << " from end" << '\n';
	Print(Algorithms::GetLinkedListValues(merged));

	const uint16_t nodeValue = 6;
	Algorithms::InsertNode(&merged, nodeValue);
	std::cout << "\ninserted " << nodeValue << " at the end" << '\n';
	Print(Algorithms::GetLinkedListValues(merged));

	const uint16_t nodeValue2 = 0;
	const int newNodeIndex = 0;
	Algorithms::InsertNode(&merged, nodeValue2, newNodeIndex);
	std::cout << "\ninserted " << nodeValue2 << " at index " << newNodeIndex << '\n';
	Print(Algorithms::GetLinkedListValues(merged));

	std::cout << "\nmax value = " << Algorithms::FindMax(merged) << '\n';
	std::cout << "min value = " << Algorithms::FindMin(merged) << '\n';

	DestroyList(&reversed);
	DestroyList(&partiallyReversed);
	DestroyList(&merged);

	return 0;
}