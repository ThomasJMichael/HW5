//
// Created by Jacob on 9/21/2022.
//

#ifndef HW5_STACK_H
#define HW5_STACK_H

#include <iostream>

#define MAX_SIZE 10

namespace stack {
class FullStack : public std::exception{};
class EmptyStack : public std::exception{};
    template <class T> class Stack {
    public:
        Stack(int userSize){
            top = -1;
            maxSize = userSize;
            items = new T[userSize];
        };
        ~Stack(){
            delete [] items;
        }
        bool isEmpty() const;
        bool isFull() const;
        void Push(T item);
        T Pop();
        T Top() const;
        void printStack() const;
    private:
        int top;
        int maxSize;
        T* items;
    };

    template<class T>
    bool Stack<T>::isEmpty() const {
        return top == -1;
    }

    template<class T>
    bool Stack<T>::isFull() const {
        return top == maxSize - 1;
    }

    template<class T>
    void Stack<T>::Push(T newItem) {
        if (isFull()){
            throw FullStack();
        }
        top++;
        items[top] = newItem;
    }

    template<class T>
    T Stack<T>::Pop() {
        if (isEmpty()){
            throw EmptyStack();
        }
        T poppedElement = items[top];
        top--;
        return items[poppedElement];
    }

    template<class T>
    T Stack<T>::Top() const {
        if (isEmpty()){
            throw EmptyStack();
        }
        return items[top];
    }

    template<class T>
    void Stack<T>::printStack() const {
        int i = 0;
        for (auto item : items){
            std::cout << "Position [" << i << "] " << item << std::endl;
            i++;
        }
    }

} // stack

#endif //HW5_STACK_H
