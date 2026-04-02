#include <iostream>

#include "SinglyLinkedList/ListNode.h"
#include "SinglyLinkedList/Algorithms.h"

using ListType = uint16_t;

/////////////////////

template<Numeric T>
void Print(const std::vector<T>& values)
{
	//std::cout << "Printing - ";
	size_t count = values.size();
	for (const T& value : values)
	{
		if constexpr (!std::is_same_v<T, uint8_t>) std::cout << value;
		else std::cout << static_cast<unsigned>(value);

		count--;
		if (count != 0) std::cout << " - ";
	}

	std::cout << '\n';
}

template<Numeric T>
void CreateTestList(ListNode<T>** head)
{
	ListNode<T>* a = new ListNode<T>(2);
	ListNode<T>* b = new ListNode<T>(3);
	ListNode<T>* c = new ListNode<T>(3);
	ListNode<T>* d = new ListNode<T>(5);

	(*head)->SetNext(a);
	a->SetNext(b);
	b->SetNext(c);
	c->SetNext(d);
}

template<Numeric T>
void CreateTestList2(ListNode<T>** head)
{
	ListNode<T>* next1 = new ListNode<T>(4);
	ListNode<T>* next2 = new ListNode<T>(7);
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

template<Numeric T>
void TestQueries(const ListNode<T>* head)
{
	std::cout << '\n';
	std::cout << "number of elements = " << Algorithms::CountElements(head) << '\n';

	if constexpr (!std::is_same_v<T, uint8_t>) std::cout << "sum of all values = " << Algorithms::GetLinkedListSum(head) << '\n';
	else std::cout << "sum of all values = " << static_cast<unsigned>(Algorithms::GetLinkedListSum(head)) << '\n';

	constexpr T valueToFinde = 4;
	std::cout << valueToFinde << " in the list - " << (Algorithms::IsValueInList(head, valueToFinde) ? "true" : "false") << '\n';

	constexpr uint32_t indexToCheck = 3;
	if constexpr (!std::is_same_v<T, uint8_t>) std::cout << "value at index " << indexToCheck << " = " << Algorithms::GetValueAtIndex(head, indexToCheck) << '\n';
	else std::cout << "value at index " << indexToCheck << " = " << static_cast<unsigned>(Algorithms::GetValueAtIndex(head, indexToCheck)) << '\n';

	T duplicate = 0;
	if (Algorithms::FindDuplicate(head, duplicate))
	{
		if constexpr (!std::is_same_v<T, uint8_t>) std::cout << "duplicate number = " << duplicate << '\n';
		else std::cout << "duplicate number = " << static_cast<unsigned>(duplicate) << '\n';
	}
	else std::cout << "duplicate number not found\n";

	if constexpr (!std::is_same_v<T, uint8_t>)
	{
		std::cout << "\nmax value = " << Algorithms::FindMax(head) << '\n';
		std::cout << "min value = " << Algorithms::FindMin(head) << '\n';
	}
	else
	{
		std::cout << "\nmax value = " << static_cast<unsigned>(Algorithms::FindMax(head)) << '\n';
		std::cout << "min value = " << static_cast<unsigned>(Algorithms::FindMin(head)) << '\n';
	}

	std::cout << "has cycle - " << (Algorithms::HasCycle(head) ? "true" : "false") << '\n';
}

template<Numeric T>
void TestReverse(const ListNode<T>* head)
{
	ListNode<T>* reversed = Algorithms::GetReversedLinkedList(head);
	std::cout << "\nreversed: ";
	Print(Algorithms::GetLinkedListValues(reversed));

	constexpr uint32_t leftIndex = 0;
	constexpr uint32_t rightIndex = 2;
	ListNode<T>* partiallyReversed = Algorithms::GetPartiallyReversedLinkedList(head, leftIndex, rightIndex);
	std::cout << "partially reversed between indexes " << leftIndex << " and " << rightIndex << " : ";
	Print(Algorithms::GetLinkedListValues(partiallyReversed));

	std::cout << "is reversed same as the partially reversed - " << (Algorithms::IsSameList(reversed, partiallyReversed) ? "true" : "false") << '\n';

	DestroyList(&reversed);
	DestroyList(&partiallyReversed);
}

template<Numeric T>
void TestModify(ListNode<T>* head)
{
	//Algorithms::RemoveLast(head);
	//std::cout << "\nremoved last\n";
	//Print(Algorithms::GetLinkedListValues(head));

	constexpr uint32_t indexFromEnd = 3;
	Algorithms::RemoveFromEnd(&head, indexFromEnd);
	std::cout << "removed number " << indexFromEnd << " from end" << '\n';

	constexpr T nodeValue = 2;
	Algorithms::InsertNode(&head, nodeValue);
	std::cout << "inserted " << nodeValue << " at the end" << '\n';

	constexpr T nodeValue2 = 0;
	constexpr int newNodeIndex = 5;
	Algorithms::InsertNode(&head, nodeValue2, newNodeIndex);
	std::cout << "inserted " << nodeValue2 << " at index " << newNodeIndex << '\n';

	constexpr T nodeValue3 = 3;
	constexpr int newNodeIndex2 = 0;
	Algorithms::InsertNode(&head, nodeValue3, newNodeIndex2);
	std::cout << "inserted " << nodeValue3 << " at index " << newNodeIndex2 << '\n';

	std::cout << "\nend result: ";
	Print(Algorithms::GetLinkedListValues(head));

	ListNode<T>* sorted = Algorithms::SortLinkedList(head);
	std::cout << "sorted: ";
	Print(Algorithms::GetLinkedListValues(sorted));

	DestroyList(&sorted);
}

/////////////////////

int main()
{
	constexpr ListType headValue = 1;
	ListNode<ListType>* head = new ListNode(headValue);
	CreateTestList(&head);
	std::cout << "original list: ";
	Print(Algorithms::GetLinkedListValues(head));

	constexpr ListType headValue2 = 0;
	ListNode<ListType>* list2 = new ListNode(headValue2);
	CreateTestList2(&list2);
	std::cout << "list2: ";
	Print(Algorithms::GetLinkedListValues(list2));

	ListNode<ListType>* merged = Algorithms::MergeLists(head, list2);
	TestQueries(head);
	TestReverse(head);

	std::cout << "\nmerged original and 2nd lists: ";
	Print(Algorithms::GetLinkedListValues(merged));
	TestModify(merged);

	DestroyList(&merged);
	return 0;
}