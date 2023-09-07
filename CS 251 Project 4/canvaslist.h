/*CanvasList:

clear() releases all allocations of memory (all Nodes and their internal Shapes)

front() returns the private data member that points to the front of the list.

find() returns -1 or the index of the first shape with the given x, y values.

insertAfter() returns and does nothing to the list when the index is out of range

pop_front() and pop_back() returns a nullptr or the pointer to the shape if one exists, and releases the node's memory but not the shape's memory.

printAddresses() has a tab character separating the two printouts

shapeAt() returns nullptr or a pointer to the shape at the given linked list index.

removeAt() returns and does nothing to the list when the index is out of range

All functions that take a pointer to a Shape are taking a Shape that already exists. You can see the main.cpp for examples.*/


// memory leak could be at insert after and in 
//------------------------------------------------------------------------------------
/* Name: Esat Duman
   UIN: 662726641
   Course: Data Structures
   Project 4 Shape List
   -----------------------------------------------------------------------------------
*/
#pragma once

#include "shape.h"
#include <iostream>

using namespace std;

class ShapeNode
{
    public:
        Shape *value;
        ShapeNode *next;
};

class CanvasList
{
    private:
        int listSize;
        ShapeNode *listFront;

    public:
        CanvasList()
        {
            listSize = 0;
            listFront = nullptr;
        }
        CanvasList(const CanvasList &other)
        {
            listSize = 0;
            listFront = nullptr;
            for (ShapeNode *node = other.listFront; node != nullptr; node = node ->next) {
                push_back(node->value->copy());
            }
        }
        CanvasList operator=(const CanvasList &other)
        {
             if (this == &other) {
                return *this;
            }
            clear(); // clear the current list
            for (ShapeNode* node = other.listFront; node != nullptr; node = node->next) {
                push_back(node->value->copy());
            }
            return *this;
         
        }
        
        virtual ~CanvasList()
        {
            clear();
        }

        void clear()
        {
        while (listFront != nullptr) {
        ShapeNode *node = listFront;
        listFront = listFront->next;
        delete node->value;
        delete node;
        listSize--;
            }
        }
        
        void insertAfter(int index, Shape *shape)
        {
            if (index < 0 || index >= listSize) {
        return;
        }
        ShapeNode *node = new ShapeNode();
        node->value = shape;
        if (index == listSize - 1) {
        push_back(shape);
        }   else {
        ShapeNode *prevNode = listFront;
        for (int i = 0; i < index; i++) {
            prevNode = prevNode->next;
        }
        node->next = prevNode->next;
        prevNode->next = node;
        listSize++;
        }
        }
        void push_front(Shape *shape)
        {
            ShapeNode* node = new ShapeNode(); // creating new node 
            node->value = shape;
            node->next = listFront;
            listFront = node;
            // Update the size of the list
            listSize++;
            
        }

        void push_back(Shape *shape)
        {
            ShapeNode *node = new ShapeNode();
            node->value = shape;
            node->next = nullptr;
            
            if (listFront == nullptr) {
                listFront = node;
            } else {
                ShapeNode *tail = listFront;
                while (tail->next != nullptr) {
                    tail = tail->next;
                }
                tail->next = node;
            }
        
                listSize++;
        }
        
        void removeAt(int index)
        {
            if (index < 0 || index >= listSize) {
                return;
            }
            ShapeNode *node = listFront;
            if (index == 0){
                listFront = listFront->next;
            } else {
                ShapeNode *prevNode = listFront;
                for (int i = 0; i < index; i++) {
                    prevNode = node;
                    node = node->next;
                }
                prevNode->next = node->next;
            }
            delete node->value;
            delete node;
            listSize--;
        }
        Shape* pop_front() 
        {
            if (listFront == nullptr) {
                return nullptr;
        }
            Shape *shape = listFront->value;
            ShapeNode *node = listFront;
            listFront = listFront->next;
            delete node;
            listSize--;
            return shape;

        }
        Shape* pop_back()
        {
            if (listFront == nullptr) {
                return nullptr;
        }
            ShapeNode *tail = listFront;
            ShapeNode *prev = nullptr;
            while (tail->next != nullptr) {
                prev = tail;
                tail = tail->next;
            }
            if (prev == nullptr) {
                listFront = nullptr;
            } else {
                prev->next = nullptr;
            }
            Shape *result = tail->value;
            delete tail;
            listSize--;
            return result;
        }

        ShapeNode* front() const
        {
            return listFront;
        }
        bool isempty() const
        {
             return listSize == 0;
        }
        int size() const 
        {
            return listSize;
        }

        int find(int x, int y) const 
        {
            ShapeNode *node = listFront;
            int index = 0;
            while (node != nullptr) {
                if (node->value->getX() == x && node->value->getY() == y) {
                return index;
            }
            node = node->next;
            index++;
        }
            return -1;
        }
        
        Shape* shapeAt(int index) const
        {
           if (index < 0 || index >= size()) {  // index out of range
            return nullptr;
        }
        ShapeNode* current = listFront;
        for (int i = 0; i < index; i++) {  // traverse to the desired node
            current = current->next;
        }
        return current->value;  // return the shape at the desired node
            }
        
        void draw() const
        {
            ShapeNode* current = listFront;
    while (current != nullptr)
    {
        current->value->printShape();
        current = current->next;
    }
        }
        void printAddresses() const
        {
             for (ShapeNode *node = listFront; node != nullptr; node = node->next) {
             cout << &node->value << endl;
            }
        }
};
