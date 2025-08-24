#pragma once
#include "CommonStruct.h"

class SkipList
{
public:
	SkipList();
	~SkipList();

	// 生成随机层级
	int getRandomLevel();
	// insertNode
	void insertListNode(int value);
	// eraseNode
	bool eraseListNode(int value);
	// search
	bool searchListNode(int value);
	// display
	void display();
private:
	SkipListNode<int>* m_head{ nullptr }; // 链表头，不存储数据，作为索引的起点
	int m_currentMaxLevel{ 1 };	// 当前跳表最大层级
	const int MAX_LEVEL{ 16 }; // 允许的最大层数，防止无限增长
	const float PROBABILITY{ 0.5 };	// 节点晋升至下一层的概率
};

