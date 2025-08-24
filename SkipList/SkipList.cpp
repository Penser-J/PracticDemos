#include "SkipList.h"
#include <random>
#include <iostream>

SkipList::SkipList()
{
	m_currentMaxLevel = 1;
	m_head = new SkipListNode<int>(0, MAX_LEVEL);
}

SkipList::~SkipList()
{
	if (m_head) {
		SkipListNode<int> *curnode = m_head->next[0];
		while (curnode != nullptr) {
			SkipListNode<int>* temp = curnode;
			curnode = curnode->next[0];
			delete temp;
			temp = nullptr;
		}
		delete m_head;
		m_head = nullptr;
	}
}

int SkipList::getRandomLevel()
{
	int level = 1;
	// 生成均匀分布的浮点数
	std::random_device rd;  // 用于获取随机种子
	std::mt19937 gen(rd()); // 使用Mersenne Twister算法
	std::uniform_real_distribution<> real_dist(0.0, 1.0);
	while (real_dist(gen) < PROBABILITY && level < MAX_LEVEL) {
		level++;
	}
	return level;
}

void SkipList::insertListNode(int value)
{
	// 记录每一层需要更新的节点
	std::vector<SkipListNode<int>*> update(MAX_LEVEL, nullptr);
	SkipListNode<int> *current = m_head;
	// 寻找插入位置，记录需要更新的节点，从高层往低层
	for (int i = m_currentMaxLevel - 1; i >= 0; i--) {
		while (current->next[i] != nullptr && current->next[i]->value < value) {
			// 下一个节点
			current = current->next[i];
		}
		// 记录第i层最后访问的节点，即新节点在第i层的前驱
		update[i] = current; 
	}
	// 生成随机层数
	int newLevel = getRandomLevel();
	// 如果新节点层级高于头节点，更新头节点最大层级
	if (newLevel > m_currentMaxLevel) {
		for (int i = m_currentMaxLevel; i < newLevel; i++) {
			update[i] = m_head;
		}
		m_currentMaxLevel = newLevel;
	}
	// 创建新节点并在各层插入
	SkipListNode<int> *newNode = new SkipListNode<int>(value, newLevel);
	for (int i = 0; i < newLevel; i++) {
		newNode->next[i] = update[i]->next[i];
		update[i]->next[i] = newNode;
	}
}

bool SkipList::searchListNode(int value)
{
	SkipListNode<int>* current = m_head;
	// 从最高层开始搜索
	for (int i = m_currentMaxLevel - 1; i >= 0; i--) {
		// 在当前层向右移动，直到下一个节点值大于或等于目标值
		while (current->next[i] != nullptr && current->next[i]->value < value) {
			current = current->next[i];
		}
	}
	// 现在current处于第0层，那么它的下一个目标可能就是目标
	current = current->next[0];

	return (current != nullptr && current->value == value);
}

void SkipList::display()
{
	std::cout << "SkipList Structure (level:" << m_currentMaxLevel << "):" << std::endl;
	for (int i = m_currentMaxLevel - 1; i >= 0; i--) {
		SkipListNode<int>* node = m_head->next[i];
		std::cout << "level " << i << ":";
		while (node != nullptr) {
			std::cout << node->value << " ";
			node = node->next[i];
		}
		std::cout << std::endl;
	}
}

bool SkipList::eraseListNode(int value)
{
	// 记录每一层需要更新的节点
	std::vector<SkipListNode<int>*> update(MAX_LEVEL, nullptr);
	SkipListNode<int>* current = m_head;
	bool found = false;
	// 寻找要删除的节点，并记录需要更新的节点
	for (int i = m_currentMaxLevel - 1; i >= 0; i--) {
		while (current->next[i] != nullptr && current->next[i]->value < value) {
			current = current->next[i];
		}
		update[i] = current;
	}
	// 检查第0层是否存在该节点
	SkipListNode<int>* nodeToDelete = current->next[0];
	if (nodeToDelete != nullptr && nodeToDelete->value == value) {
		found = true;
		// 从各层删除该节点
		for (int i = 0; i < m_currentMaxLevel; i++) {
			// 如果update[i]在第i层的下一个节点不是要删除的节点，就不需要再继续向上处理了
			if (update[i]->next[i] != nodeToDelete) {
				break;
			}
			update[i]->next[i] = nodeToDelete->next[i];
		}
		delete nodeToDelete;
		nodeToDelete = nullptr;
		// 可能需要更新最大层级
		while (m_currentMaxLevel > 1 && m_head->next[m_currentMaxLevel - 1] == nullptr) {
			m_currentMaxLevel--;
		}
	}
	return found;
}
