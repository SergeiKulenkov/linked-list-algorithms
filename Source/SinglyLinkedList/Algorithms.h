#pragma once
#include <stack>
#include <vector>
#include <set>
#include <assert.h>
#include <limits>
#include <iostream>

#include "ListNode.h"

/////////////////////

namespace Algorithms
{
	template<Numeric T>
	std::vector<T> GetLinkedListValues(ListNode<T>* head)
	{
		std::vector<T> result;
		while (head != nullptr)
		{
			result.emplace_back(head->GetValue());
			head = head->GetNext();
		}

		return result;
	}

	template<Numeric T>
	ListNode<T>* CopyLinkedList(ListNode<T>* head)
	{
		ListNode<T>* result = new ListNode<T>();
		if (head != nullptr)
		{
			ListNode<T>* current = result;
			while (head != nullptr)
			{
				current->SetValue(head->GetValue());
				if (head->GetNext() == nullptr)
				{
					break;
				}
				current->SetNext(new ListNode<T>());
				current = current->GetNext();
				head = head->GetNext();
			}
		}

		return result;
	}

	template<Numeric T>
	uint32_t CountElements(ListNode<T>* head)
	{
		uint32_t sum = 0;
		while (head != nullptr)
		{
			sum++;
			head = head->GetNext();
		}

		return sum;
	}

	template<Numeric T>
	T GetLinkedListSum(ListNode<T>* head)
	{
		T sum = 0;
		while (head != nullptr)
		{
			sum += head->GetValue();
			head = head->GetNext();
		}

		return sum;
	}

	template<Numeric T>
	bool IsValueInList(ListNode<T>* head, const T value)
	{
		bool present = false;
		while (head != nullptr)
		{
			if (value == head->GetValue())
			{
				present = true;
				break;
			}
			head = head->GetNext();
		}

		return present;
	}

	template<Numeric T>
	T GetValueAtIndex(ListNode<T>* head, const uint32_t index)
	{
		T value = 0;
		uint32_t count = 0;
		while (head != nullptr)
		{
			if (index == count)
			{
				value = head->GetValue();
				break;
			}

			count++;
			head = head->GetNext();
		}

		assert(index <= count && "index out of bounds");
		return value;
	}

	template<Numeric T>
	ListNode<T>* GetReversedLinkedList(ListNode<T>* head)
	{
		ListNode<T>* reversed = head;
		if (head != nullptr && head->GetNext() != nullptr)
		{
			// using a stack to preserve the original list
			std::stack<int> order;
			while (head->GetNext() != nullptr)
			{
				order.push(head->GetValue());
				head = head->GetNext();
			}

			reversed = new ListNode(head->GetValue());
			reversed->SetNext(new ListNode<T>());
			ListNode<T>* current = reversed->GetNext();

			while (!order.empty())
			{
				current->SetValue(order.top());
				order.pop();

				if (!order.empty())
				{
					current->SetNext(new ListNode<T>());
					current = current->GetNext();
				}
			}
		}

		return reversed;
	}

	// left and right are 0-based index values
	template<Numeric T>
	ListNode<T>* GetPartiallyReversedLinkedList(ListNode<T>* head, const uint32_t left, const uint32_t right)
	{
		assert(left <= right && "right must be greater than or equals to left");
		ListNode<T>* result = new ListNode<T>();

		if (head != nullptr && head->GetNext() != nullptr)
		{
			// need a copy as in the previous functiins, but in the original order
			result = CopyLinkedList(head);
			ListNode<T>* current = result;
			ListNode<T>* leftPrevious = new ListNode<T>(0 ,result);

			// reach node at index left
			for (uint32_t i = 0; i < left; i++)
			{
				leftPrevious = current;
				current = current->GetNext();
			}

			ListNode<T>* previous = nullptr;
			ListNode<T>* next = nullptr;
			// reverse nodes between left and right
			// current = left, leftPrevious = before left
			for (uint32_t i = 0; i < (right - left + 1); i++)
			{
				next = current->GetNext();
				current->SetNext(previous);
				previous = current;
				current = next;
			}

			leftPrevious->GetNext()->SetNext(current); // current = after right
			leftPrevious->SetNext(previous); // previous = right
			result = leftPrevious->GetNext(); // left previous starts with a 0 node
		}

		return result;
	}

	template<Numeric T>
	ListNode<T>* MergeLists(ListNode<T>* list1, ListNode<T>* list2)
	{
		ListNode<T>* result = new ListNode<T>();
		ListNode<T>* tail = result;

		while (list1 != nullptr && list2 != nullptr)
		{
			if (list1->GetValue() < list2->GetValue())
			{
				tail->SetNext(list1);
				list1 = list1->GetNext();
			}
			else
			{
				tail->SetNext(list2);
				list2 = list2->GetNext();
			}

			tail = tail->GetNext();
		}

		if (list1 != nullptr)
		{
			tail->SetNext(list1);
		}
		else if (list2 != nullptr)
		{
			tail->SetNext(list2);
		}

		return result->GetNext();
	}

	template<Numeric T>
	void RemoveLast(ListNode<T>* head)
	{
		if (head != nullptr)
		{
			ListNode<T>* next = head->GetNext();
			assert(next != nullptr && "trying to delete head.");

			while (next->GetNext() != nullptr)
			{
				head = head->GetNext();
				next = head->GetNext();
			}

			delete next;
			head->SetNext(nullptr);
		}
	}

	// removes at position size - index
	template<Numeric T>
	void RemoveFromEnd(ListNode<T>** head, const uint32_t index)
	{
		if (head != nullptr && *head != nullptr)
		{
			uint32_t size = 0;
			ListNode<T>* current = *head;
			while (current != nullptr)
			{
				size++;
				current = current->GetNext();
			}

			assert(index <= size && "index out of bounds.");
			if (size == index)
			{
				// remove the first node
				ListNode<T>* save = *head;
				*head = (*head)->GetNext();
				delete save;
			}
			else
			{
				uint32_t count = 1;
				current = *head;
				ListNode<T>* next = current->GetNext();

				while (count <= size - index)
				{
					if (count == size - index)
					{
						current->SetNext(next->GetNext());
						delete next;
						break;
					}

					current = current->GetNext();
					next = next->GetNext();
					count++;
				}
			}
		}
	}

	// returns 0 if no duplicates found and prints a log message
	template<Numeric T>
	bool FindDuplicate(ListNode<T>* head, T& value)
	{
		bool found = false;
		if (head != nullptr)
		{
			std::set<T> unique;
			while (head != nullptr)
			{
				if (unique.find(head->GetValue()) != unique.end())
				{
					value = head->GetValue();
					found = true;
					break;
				}

				unique.emplace(head->GetValue());
				head = head->GetNext();
			}
		}

		return found;
	}

	// inserts at the end if no index is provided
	template<Numeric T>
	void InsertNode(ListNode<T>** head, ListNode<T>* newNode, const int index = -1)
	{
		if (head != nullptr && *head != nullptr)
		{
			if (index == 0)
			{
				newNode->SetNext(*head);
				*head = newNode;
			}
			else
			{
				uint32_t count = 1;
				ListNode<T>* current = *head;
				while (count < index && current->GetNext() != nullptr)
				{
					current = current->GetNext();
					count++;
				}

				ListNode<T>* next = current->GetNext();
				current->SetNext(newNode);
				current->GetNext()->SetNext(next);
			}
		}
	}

	// inserts at the end if no index is provided
	template<Numeric T>
	void InsertNode(ListNode<T>** head, T value, const int index = -1)
	{
		ListNode<T>* newNode = new ListNode(value);
		InsertNode(head, newNode, index);
	}

	template<Numeric T>
	T FindMax(ListNode<T>* head)
	{
		T max = std::numeric_limits<T>::min();
		while (head != nullptr)
		{
			if (head->GetValue() > max)
			{
				max = head->GetValue();
			}
			head = head->GetNext();
		}

		return max;
	}

	template<Numeric T>
	T FindMin(ListNode<T>* head)
	{
		T min = std::numeric_limits<T>::max();
		while (head != nullptr)
		{
			if (head->GetValue() < min)
			{
				min = head->GetValue();
			}
			head = head->GetNext();
		}

		return min;
	}
}