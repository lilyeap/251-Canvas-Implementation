/*canvaslist.h*/

/*  Project 4 Shape List
  Course: CS 251, Spring 2023
  Author: Lily Eap
  NetID: leap2
  UIN: 67697798
  File: canvaslist.h, code for CanvasList class
  Description: implementation for a canvaslist class that holds a linked list of shapes (using shape class from "shape.h"), 
                including different functions to modify and view the linked list
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
        //default constructor, sets up both variables and allocates space for the shape list
        CanvasList(){ 
            listSize = 0;
            listFront = new ShapeNode; 
            listFront = nullptr;
        };

        //copy constructor, deep copies the "other" canvaslist
        CanvasList(const CanvasList &other){
            listSize = other.size(); //update the list size to the other canvaslist

            if(other.listFront == nullptr){ //if the other list is empty
                listFront = nullptr;
            
            } else { //if the other list is not empty
                listFront = new ShapeNode; //allocate new space for the header node
                listFront->value = other.listFront->value;
                listFront->next = nullptr;

                //deep copy of the other shape list
                ShapeNode* traverseNew = listFront;
                ShapeNode* traverseOG = other.listFront->next;
                while (traverseOG != nullptr){
                    traverseNew->next = new ShapeNode; // allocate space for the next node
                    traverseNew = traverseNew->next; //advance to the next node, then set the same values as the other list
                    traverseNew->value = traverseOG->value; 
                    traverseOG = traverseOG->next;
                }
                traverseNew->next = nullptr; // set the last shape's next pointer to nullptr
            }
        };

        //assignment operator 
        CanvasList operator=(const CanvasList &other){
            //delete the previously existing shape list
            ShapeNode* current = listFront;
            while (current != nullptr){
                ShapeNode* delNode = current;
                current = current->next;
                delete delNode;
            }

            listSize = other.size(); // update the new size  

            if(other.listFront == nullptr){ // if the other list is empty
                listFront = nullptr;
            } else { // if the other list is not empty
                // allocate new space for the header node
                listFront = new ShapeNode;
                listFront->value = other.listFront->value;
                listFront->next = nullptr;

                //deep copy of the other shape list
                ShapeNode* traverseNew = listFront;
                ShapeNode* traverseOG = other.listFront->next;
                while (traverseOG != nullptr){
                    traverseNew->next = new ShapeNode; // allocate space for the next node
                    traverseNew = traverseNew->next; //advance to the next node, then set same values as the other list
                    traverseNew->value = traverseOG->value; 
                    traverseOG = traverseOG->next;
                }
                // set the last node's next pointer to nullptr
                traverseNew->next = nullptr;
            }

            return *this;
        };
        
        // destructor
        virtual ~CanvasList(){
            //reset listSize
            listSize = 0;

            //delete the shape list
            ShapeNode* current = listFront;
            while (current != nullptr){
                ShapeNode* delNode = current;
                current = current->next;
                delete delNode;
            }
        };

        // essentially the same as a destructor but it is prompted by the user instead
        void clear(){
            //reset listSize
            listSize = 0;

            //delete the shape list
            while (listFront != nullptr){
                ShapeNode* next = listFront->next;
                delete listFront; 
                listFront = next;
            }
        };
         
        // insert after a certain index
        void insertAfter(int idx, Shape *newShape){
            //if index is not within range + also checks if list is empty
            if (idx < 0 || idx >= listSize){
                return;
            }

            //update counter
            listSize++;

            //allocate space for a node that will hold the desired shape
            ShapeNode* newNode = new ShapeNode;
            newNode->value = newShape;
            newNode->next = nullptr;

            //traverse until the desired index
            ShapeNode* findIDX = listFront;
            for(int i = 0; i < idx; i++){
                findIDX = findIDX->next;
            }

            //store the next pre-existing node on the list and update the new pointers accordingly
            ShapeNode* nextNode = findIDX->next;
            findIDX->next = newNode;
            newNode->next = nextNode;
    
        };

        // push to the front of the list
        void push_front(Shape *newShape){
            //update counter
            listSize++;
            
            //allocate space for a node that will hold the desired shape and point it to the beginning of the existing shape list
            ShapeNode* newNode = new ShapeNode;
            newNode->value = newShape;
            newNode->next = listFront;
            listFront = newNode;
        };
        
        // push to the back of the list
        void push_back(Shape *newShape){
            //update counter
            listSize++;

            //allocate space for a node that will hold the desired shape 
            ShapeNode* newNode = new ShapeNode;
            newNode->value = newShape;
            newNode->next = nullptr;

            //if the list is empty, make the node the only element in the list
            if (listFront == nullptr){
                listFront = newNode;
                return;
            }

            //if the list is not empty, traverse until the end of the list and append to the next node
            ShapeNode* current = listFront;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        };
        
        //remove a node at a certain index
        void removeAt(int idx){
            //if index is not within range + checks if list is empty
            if (idx < 0 || idx >= listSize){
                return;
            }
            
            //update counter
            listSize--;

            //traverse until the index
            ShapeNode* findIDX = listFront;
            ShapeNode* nodeBeforeIDX = nullptr;

            for(int i = 0; i < idx; i++){
                nodeBeforeIDX = findIDX;
                findIDX = findIDX->next;
            }

            //remove the desired shape and update the node before it
            //if we want to remove the first shape
            if (nodeBeforeIDX == nullptr){
                listFront = listFront->next;
            } else {
                //update the "next" pointer of the previous shape to the "next" pointer of the shape we will delete
                nodeBeforeIDX->next = findIDX->next;
            }
            
            //delete the desired node
            delete findIDX;
            return;
        };


        //remove the node at the front and return the shape at that node
        Shape* pop_front(){
            //the list is empty
            if (listFront == nullptr){
                return nullptr;
            }

            //update counter
            listSize--;

            //make listFront point to the second element
            ShapeNode* removeNode = listFront;
            listFront = listFront->next;

            //keep the shape & release the node memory
            Shape* deleteShape = removeNode->value;
            delete removeNode;

            return deleteShape;
        };

        //remove the node at the back and return the shape at that node
        Shape* pop_back(){
            //the list is empty
            if (listFront == nullptr){
                return nullptr;
            }

            //update counter
            listSize--;

            //if the list only has one shape
            if (listFront->next == nullptr){
                //make listFront point to the second element, and hold onto the node we want to remove
                ShapeNode* removeNode = listFront;
                listFront = nullptr;

                //keep the shape & release that node's memory
                Shape* deleteShape = removeNode->value;
                delete removeNode;

                return deleteShape;
            }

            //if the list has 2 or more shapes
            //find the second-to-last node
            ShapeNode* beforeLast = listFront;
            while (beforeLast->next->next != nullptr){
                beforeLast = beforeLast->next;
            }

            //update the second-to-last node's next pointer and store the last node into a separate pointer
            ShapeNode* last = beforeLast->next;
            beforeLast->next = nullptr;

            //keep the shape of last node & remove last node, release node memory
            Shape* deleteShape = last->value;
            delete last;

            return deleteShape;
        };


        //return the address of the front of the list
        ShapeNode* front() const{
            return listFront;
        };

        //checks if the list is empty
        bool isempty() const{
            if (listFront == 0){
                return true;
            }
            return false;
        };

        //returns the size of the list
        int size() const {
            return listSize;
        };

        //find the index of the shape in the list that matches the x & y's given
        int find(int x, int y) const{
            int counter = 0;
            ShapeNode* findIDX = listFront;
            while (findIDX != nullptr){ //traverse until we find the first matching X and Y.
                if ((findIDX->value->getX() == x) && (findIDX->value->getY() == y)){
                    return counter;
                }
                counter++;
                findIDX = findIDX->next;
            }

            return -1; //if we didn't find a matching X and Y
        };

        //find the shape at a given index
        Shape* shapeAt(int idx) const{
            //if idx is not in range + also accounts for if list is empty
            if (idx < 0 || idx >= listSize){
                return nullptr;
            }

            //traverse until the index
            ShapeNode* findIDX = listFront;
            for(int i = 0; i < idx; i++){
                findIDX = findIDX->next;
            }

            return findIDX->value;
        };
        
        //print out all contents of the list
        void draw() const{
            ShapeNode* current = listFront;
            while (current != nullptr) { //traverse through the whole list and print at each value
                current->value->printShape();
                current = current->next;
            }
        };

        //prints addresses of the front of the list
        void printAddresses() const{
            cout << "Node Address: " << listFront
                << "	Shape Address: " << listFront->value
                << endl;
        };
};