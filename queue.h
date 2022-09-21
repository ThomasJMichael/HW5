//
// Created by Jacob on 9/21/2022.
//

#ifndef HW5_QUEUE_H
#define HW5_QUEUE_H

#include <iostream>

namespace queue {
class FullQueue : public std::exception{};
class EmptyQueue : public std::exception{};
    template <class T> class Queue {
        struct Node{
            T data;
            T* next;
        };
    public:
        Queue(int userSize){
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
        T dequeue();
        bool isEmpty();
        bool isFull();
        void printQueue();
    private:
        Node* front;
        Node* back;
        Node* currentPos;
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
            back = newNode;
        }else {
            back->next = newNode;
        }
        back = newNode;
        length++;
    }

    template<class T>
    T Queue<T>::dequeue() {
        if (isEmpty()){
            throw EmptyQueue();
        } else {
            Node tempPtr = front;
            front = front->next;
            if (front == nullptr){
                back = nullptr;
            }
            return tempPtr;
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
        currentPos = front;
        while (currentPos != nullptr){
            std::cout << "Position [" << i << "] " << currentPos->data << std::endl;
            i++;
            currentPos = currentPos->next;
        }
    }

} // queue

#endif //HW5_QUEUE_H
