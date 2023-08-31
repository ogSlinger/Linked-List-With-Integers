#pragma once
#include <vector>
#include <limits>

class LinkedListNode {
public:
	LinkedListNode();
	LinkedListNode(int val);
	~LinkedListNode();
	void setNextNode(LinkedListNode* nextNode);
	LinkedListNode& retAddress();
	LinkedListNode* getNextNodePtr();
	LinkedListNode*& nextNodeAddress();
	int getVal();

private:
	LinkedListNode* nextNode = nullptr;
	int val = std::numeric_limits<int>::min();;
};

class LinkedList {
public:
	LinkedList();
	~LinkedList();
	void addNode(int val);
	void addNodeAfter(int val, LinkedListNode* nodePrior, LinkedListNode* nodeToBeAdded);
	void swapNodes(LinkedListNode* nodeOne, LinkedListNode* nodeTwo);
	LinkedListNode* locateNode(LinkedListNode* node);
	LinkedListNode* locateNextNodePtr(LinkedListNode* node);
	void bubbleSort();
	void printNodes();

private:
	int val = std::numeric_limits<int>::min();
	LinkedListNode* headPtr = nullptr;
	LinkedListNode* leftOff = nullptr;
	std::vector<LinkedListNode*> nodeVec;
};

