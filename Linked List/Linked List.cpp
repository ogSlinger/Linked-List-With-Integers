#include "Linked List.h"
#include <iostream>
#include <limits>


// =========Linked List Node Definitions ==========
LinkedListNode::LinkedListNode() {
}

LinkedListNode::LinkedListNode(int val) {
	this->val = val;
}

LinkedListNode::~LinkedListNode() {
}

void LinkedListNode::setNextNode(LinkedListNode* nextNode) {
	this->nextNode = nextNode;
}

LinkedListNode& LinkedListNode::retAddress() {
	return *this;
}

LinkedListNode* LinkedListNode::getNextNodePtr() {
	return this->nextNode;
}

LinkedListNode*& LinkedListNode::nextNodeAddress() {
	return this->nextNode;
}

int LinkedListNode::getVal() {
	return this->val;
}

// =========Linked List Definitions ==========
LinkedList::LinkedList() {
	this->headPtr = new LinkedListNode(std::numeric_limits<int>::min());
	this->nodeVec.push_back(headPtr);
	this->leftOff = headPtr;
}

LinkedList::~LinkedList() {
	for (int i = 0; i < nodeVec.size(); i++) {
		delete nodeVec[i];
	}
}

void LinkedList::addNode(int val) {
	LinkedListNode* newNode = new LinkedListNode(val);
	
	this->leftOff->setNextNode(newNode);
	this->leftOff = leftOff->getNextNodePtr();

	this->nodeVec.push_back(newNode);
}

void LinkedList::addNodeAfter(int val, LinkedListNode* nodePrior, LinkedListNode* nodeToBeAdded) {
	LinkedListNode* temp = this->locateNode(nodePrior);
	temp->setNextNode(nodeToBeAdded);
}

void LinkedList::swapNodes(LinkedListNode* nodeOne, LinkedListNode* nodeTwo) {
	LinkedListNode* tempPtrOne = this->locateNextNodePtr(nodeOne);
	LinkedListNode* tempPtrTwo = this->locateNextNodePtr(nodeTwo);

	tempPtrOne->setNextNode(nodeTwo);
	tempPtrTwo->setNextNode(nodeOne);

	tempPtrOne = nodeOne->getNextNodePtr();
	nodeOne->setNextNode(nodeTwo->getNextNodePtr());
	nodeTwo->setNextNode(tempPtrOne);

}

LinkedListNode* LinkedList::locateNode(LinkedListNode* node) {
	LinkedListNode* iteratorPtr = this->headPtr;

	for (int i = 0; i < this->nodeVec.size(); i++) {
		if (iteratorPtr == node) {
			return iteratorPtr;
		}
	}

	return nullptr;
}

LinkedListNode* LinkedList::locateNextNodePtr(LinkedListNode* node) {
	LinkedListNode* iteratorPtr = this->headPtr;

	for (int i = 0; i < this->nodeVec.size() - 1; i++) {
		if (iteratorPtr->getNextNodePtr() == node) {
			return iteratorPtr;
		}
		iteratorPtr = iteratorPtr->getNextNodePtr();
	}

	return nullptr;
}

void LinkedList::bubbleSort() {
	LinkedListNode* iteratorPtr = nullptr;
	LinkedListNode* temp = nullptr;

	for (int i = 0; i < this->nodeVec.size(); i++) {
		iteratorPtr = this->headPtr;
		for (int j = 1; j < this->nodeVec.size() - i; j++) {
			if (iteratorPtr->getVal() > iteratorPtr->getNextNodePtr()->getVal()) {
				temp = iteratorPtr->getNextNodePtr();
				this->swapNodes(iteratorPtr, iteratorPtr->getNextNodePtr());
				iteratorPtr = temp;
			}
			if (iteratorPtr->getNextNodePtr() != nullptr)
				iteratorPtr = iteratorPtr->getNextNodePtr();
		}
	}
}

void LinkedList::printNodes() {
	LinkedListNode* temp = headPtr;
	for (int i = 1; i < this->nodeVec.size(); i++) {
		if (temp->getNextNodePtr() != nullptr) {
			temp = temp->getNextNodePtr();
			std::cout << "Node: " << i << " Value: " << temp->getVal() << std::endl;
		}
	}
}
