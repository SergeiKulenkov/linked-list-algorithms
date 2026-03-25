#pragma once

template<typename T>
concept Numeric = (std::is_integral_v<T> || std::is_floating_point_v<T>) && !std::is_same_v<T, bool>;

/////////////////////

template<Numeric T>
class ListNode
{
public:
	ListNode() : value(0), next(nullptr)
	{
		static_assert(Numeric<T>, "only numbers are allowed.");
	}

	~ListNode() = default;

	ListNode(T newValue) : value(newValue), next(nullptr)
	{
		static_assert(Numeric<T>, "only numbers are allowed.");
	}

	ListNode(T newValue, ListNode* newNext) : value(newValue), next(newNext)
	{
		static_assert(Numeric<T>, "only numbers are allowed.");
	}

	ListNode(ListNode* node) : value(node->GetValue()), next(node->GetNext()) {}

	T GetValue() const { return value; }
	ListNode* GetNext() const { return next; }

	void SetValue(T newValue) { value = newValue; }
	void SetNext(ListNode* newNext) { next = newNext; }

private:
	T value;
	class ListNode* next;
};