#pragma once
#include "Tile.h"
#include <iostream>

using namespace std;

template<typename T>
class Node
{
public:
	
	Node<T>* _next = nullptr;
	T _data;
};

template<typename T>
class LinkedList
{
public:
	Node<T>* _head = nullptr;

	bool Contains(T data)
	{
		Node<T>* current = _head;
		for (; current->_next != nullptr;)
		{
			if (current->_data == data)
				return true;
			current = current->_next;
		}
		return false;
	}

	void InsertHeadNode(T data)
	{
		Node<T>* node = new Node<T>();
		node->_data = data;
		node->_next = _head;
		_head = node;
	}
	void InsertHeadNode(Node<T>* node, T data)
	{
		node->_next = _head;
		node->_data = data;
		_head = node;
	}
	void InsertBackNode(T data)
	{
		if (_head == nullptr)
		{
			_head == new Node<T>();
			_head->_data = data;
			return;
		}
		Node<T>* currentNode = _head;
		while (currentNode->_next != nullptr)
		{
			currentNode->_next;
		}
		currentNode->_next = new Node<T>();
		currentNode->_next->_data = data;

	}
	Node<T>* PopTailNode()
	{
		Node<T>* currentNode = _head;
		while (currentNode->_next->_next != nullptr)
		{
			currentNode =  currentNode->_next;
		}
		Node<T>* temp =  currentNode->_next;
		temp->_next = nullptr;
		currentNode->_next = nullptr;
		return temp;
	}
	/*
	void DeleteNode(T _data)
	{
		Node<T>* currentNode = _head;
		Node<T>* prevNode = _head;;
		while (currentNode->_next != nullptr)
		{
			if (currentNode->_data == _data)
			{
				if (currentNode == _head)
				{
					_head = currentNode->_next;
				}
				else
				{
					prevNode->_next = currentNode->_next;
				}
				currentNode->_next = nullptr;
				
				delete currentNode;
				break;
			}
			prevNode = currentNode;
			currentNode = currentNode->_next;
		}
	}
	*/
	void DeleteList()
	{
		Node<T>* currentNode = _head;
		Node<T>* prevNode;
		while (currentNode->_next != nullptr)
		{
			prevNode = currentNode;
			currentNode = currentNode->_next;
			prevNode->_next = nullptr;
			delete prevNode;
		}
	}
};

