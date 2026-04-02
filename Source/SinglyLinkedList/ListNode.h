#pragma once

template<typename T>
concept Numeric = (std::is_integral_v<T> || std::is_floating_point_v<T>) && !std::is_same_v<T, bool>;

/////////////////////

template<Numeric T>
class ListNode
{
public:
	ListNode() = default;
	~ListNode() = default;

	explicit ListNode(const T newValue) : value(newValue) {}

	explicit ListNode(const ListNode* node)
	{
		if (node != nullptr)
		{
			value = node->GetValue();
			next = new ListNode(node->GetNext());
		}
	}

	ListNode(const T newValue, ListNode* newNext) : value(newValue), next(newNext) {}

	T GetValue() const { return value; }
	ListNode* GetNext() const { return next; }

	void SetValue(const T newValue) { value = newValue; }
	void SetNext(ListNode* newNext) { next = newNext; }

private:
	T value = 0;
	class ListNode* next = nullptr;
};