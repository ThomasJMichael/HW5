/**
 * @file queue.h
 * @author Thomas Michael (tjm0027@uah.edu)
 * @brief ADT Queue w/ templates to handle different types of queues
 * @date 2022-09-21
 *
 */
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

    /**
     * @brief frees the memory of the queue
     * @tparam T Itemtype
     */
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
    /**
     * @breif Adds item to queue
     * @tparam T ItemType
     * @param newItem item to add the queue
     * @throw FullQueue Full queue exception
     */
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

    /**
     * @Brief removes item from front of queue
     * @tparam T ItemType
     * @throw EmptyQueue Empty queue exception
     */
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
    /**
     * @brief Return if the queue is empty
     * @tparam T ItemType
     * @return bool
     */
    template<class T>
    bool Queue<T>::isEmpty() {
        return length == 0;
    }
    /**
     * @brief Returns if queue is full
     * @tparam T ItemType
     * @return bool
     */
    template<class T>
    bool Queue<T>::isFull() {
        return (length == maxSize);
    }
    /**
     * @brief prints queue to console
     * @tparam T ItemType
     */
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
    /**
     * @brief prints queue to file.
     * @tparam T ItemType
     * @param outFile output file
     */
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
