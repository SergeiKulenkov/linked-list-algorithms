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

/////////////////////

int main()
{
	ListNode<int>* head = new ListNode(1);
	ListNode<int>* a = new ListNode(2);
	ListNode<int>* b = new ListNode(3);
	ListNode<int>* c = new ListNode(3);
	ListNode<int>* d = new ListNode(5);

	head->SetNext(a);
	a->SetNext(b);
	b->SetNext(c);
	c->SetNext(d);

	// testing
	Print(Algorithms::GetLinkedListValues(head));

	std::cout << "number of elements = " << Algorithms::CountElements(head) << '\n';

	std::cout << "sum of all values = " << Algorithms::GetLinkedListSum(head) << '\n';

	std::cout << "is 4 in the list - " << (Algorithms::IsValueInList(head, 4) ? "true" : "false") << '\n';

	return 0;
}