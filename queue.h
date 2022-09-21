//
// Created by Jacob on 9/21/2022.
//

#ifndef HW5_QUEUE_H
#define HW5_QUEUE_H

#include <iostream>
#include <fstream>

namespace queue {
class FullQueue : public std::exception{};
class EmptyQueue : public std::exception{};
    template <class T> class Queue {
        struct Node{
            T data;
            Node* next;
        };
    public:
        explicit Queue(int userSize){
            front = nullptr;
            back = nullptr;
            maxSize = userSize;
            length = 0;
        }
        ~Queue(){
            makeEmpty();
        }
        void makeEmpty();
        void enqueue(T newItem);
        void dequeue();
        bool isEmpty();
        bool isFull();
        void printQueue();
        void printQueue(std::ofstream& outFile);
    private:
        Node* front;
        Node* back;
        //Node* currentPos;
        int length;
        int maxSize;
    };

    template<class T>
    void Queue<T>::makeEmpty() {
        Node* tempPtr;
        while (front != nullptr){
            tempPtr = front;
            front = front->next;
            delete tempPtr;
        }
        back = nullptr;
    }

    template<class T>
    void Queue<T>::enqueue(T newItem) {
        if (isFull()){
            throw FullQueue();
        }
        Node* newNode = new Node;
        newNode->data = newItem;
        newNode->next = nullptr;
        if (back == nullptr){
            front = newNode;
            back = newNode;
        }else {
            back->next = newNode;
        }
        back = newNode;
        length++;
    }

    template<class T>
    void Queue<T>::dequeue() {
        if (isEmpty()){
            throw EmptyQueue();
        } else {
            Node* tempNode = front;
            front = front->next;
            if (front == nullptr){
                back = nullptr;
            }
            length--;
            delete tempNode;
        }
    }

    template<class T>
    bool Queue<T>::isEmpty() {
        return length == 0;
    }

    template<class T>
    bool Queue<T>::isFull() {
        return (length == maxSize);
    }

    template<class T>
    void Queue<T>::printQueue() {
        int i = 0;
        Node* currentPos = front;
        std::cout << "----------[Queue]----------------" << std::endl;
        while (currentPos != nullptr){
            std::cout << "Position [" << i << "] " << currentPos->data << std::endl;
            i++;
            currentPos = currentPos->next;
        }
        std::cout << "---------------------------------" << std::endl;
    }

    template<class T>
    void Queue<T>::printQueue(std::ofstream& outFile) {
        int i = 0;
        Node* currentPos = front;
        outFile << "----------[Queue]---------" << std::endl;
        while (currentPos != nullptr){
            outFile << "Position [" << i << "] " << currentPos->data << std::endl;
            i++;
            currentPos = currentPos->next;
        }
        outFile << "---------------------------------" << std::endl;
    }

} // queue

#endif //HW5_QUEUE_H
