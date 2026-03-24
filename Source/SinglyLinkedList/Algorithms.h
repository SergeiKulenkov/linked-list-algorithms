#pragma once
#include <stack>
#include <vector>

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

	}

	template<Numeric T>
	ListNode<T>* GetReversedLinkedList(ListNode<T>* head)
	{
		//ListNode* reverse = new ListNode();
		//	if (head != nullptr)
		//	{
		//		if (head->next != nullptr)
		//		{
		//			std::stack<int> order;
		//			while (head->next != nullptr)
		//			{
		//				order.push(head->value);
		//				head = head->next;
		//			}
		//
		//			reverse->value = head->value;
		//			reverse->next = new Node();
		//			Node* current = reverse->next;
		//			while (!order.empty())
		//			{
		//				current->value = order.top();
		//				order.pop();
		//				if (!order.empty())
		//				{
		//					current->next = new Node();
		//					current = current->next;
		//				}
		//			}
		//		}
		//		else
		//		{
		//			reverse = head;
		//		}
		//	}
		//
		//return reverse;
	}

	template<Numeric T>
	ListNode<T>* MergeLists(ListNode<T>* list1, ListNode<T>* list2)
	{

	}

	template<Numeric T>
	ListNode<T>* RemoveFromEnd(ListNode<T>* head, uint32_t index)
	{

	}

	template<Numeric T>
	T FindDuplicate(ListNode<T>* head)
	{

	}

	template<Numeric T>
	void InsertNode(ListNode<T>* head, int index = -1)
	{

	}
}