#pragma once
#include <vector>

template<typename T>
struct SkipListNode
{
	SkipListNode(T val, int level) 
	: value(val), next(level, nullptr)
	{
	}
	~SkipListNode() {
	}
	T value;
	std::vector<SkipListNode*> next;
};
