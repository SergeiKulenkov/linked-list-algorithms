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
	bool IsValueInList(ListNode<T>* head, T value)
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
	T GetValueAtIndex(ListNode<T>* head, uint32_t index)
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

	// using a stack to preserve the original list
	template<Numeric T>
	ListNode<T>* GetReversedLinkedList(ListNode<T>* head)
	{
		ListNode<T>* reversed = head;
		if (head != nullptr && head->GetNext() != nullptr)
		{
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

	template<Numeric T>
	void RemoveFromEnd(ListNode<T>** head, uint32_t index)
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
	T FindDuplicate(ListNode<T>* head)
	{
		T result = 0;
		if (head != nullptr)
		{
			std::set<T> unique;
			uint32_t count = 0;
			while (head != nullptr)
			{
				if (unique.find(head->GetValue()) != unique.end())
				{
					result = head->GetValue();
					break;
				}

				unique.emplace(head->GetValue());
				head = head->GetNext();
				count++;
			}

			if (unique.size() == count)
			{
				std::cout << "no duplicates found...";
			}
		}

		return result;
	}

	template<Numeric T>
	void InsertNode(ListNode<T>** head, ListNode<T>* newNode, int index = -1)
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

	template<Numeric T>
	void InsertNode(ListNode<T>** head, T value, int index = -1)
	{
		ListNode<T>* newNode = new ListNode(value);
		InsertNode(head, newNode, index);
	}

	template<Numeric T>
	T FindMax(ListNode<T>* head)
	{

	}

	template<Numeric T>
	T FindMin(ListNode<T>* head)
	{

	}
}