/**
 * @file stack.h
 * @author Thomas Michael (tjm0027@uah.edu)
 * @brief ADT Stack w/ templates to handle different types of queues
 * @date 2022-09-21
 *
 */

#ifndef HW5_STACK_H
#define HW5_STACK_H

#include <iostream>

namespace stack {
class FullStack : public std::exception{};
class EmptyStack : public std::exception{};
    template <class T> class Stack {
    public:
        explicit Stack(int userSize){
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
    /**
     * @brief Return if the stack is empty
     * @tparam T ItemType
     * @return bool
     */
    template<class T>
    bool Stack<T>::isEmpty() const {
        return top == -1;
    }
    /**
     * @brief Returns if stack is full
     * @tparam T ItemType
     * @return bool
     */
    template<class T>
    bool Stack<T>::isFull() const {
        return top == maxSize - 1;
    }
    /**
     * @breif Adds item to top of stack
     * @tparam T ItemType
     * @param newItem item to add the stack
     * @throw FullStack Full stack exception
     */
    template<class T>
    void Stack<T>::Push(T newItem) {
        if (isFull()){
            throw FullStack();
        }
        top++;
        items[top] = newItem;
    }
    /**
     * @Brief removes item from top of stack
     * @tparam T ItemType
     * @throw EmptyStack Empty stack exception
     */
    template<class T>
    T Stack<T>::Pop() {
        if (isEmpty()){
            throw EmptyStack();
        }
        T poppedElement = items[top];
        top--;
        return items[poppedElement];
    }
    /**
     * @brief Returns the item at the top of the stack
     * @tparam T ItemType
     * @throws EmptyStack throws empty stack exception
     * @return T ItemType at top of stack
     */
    template<class T>
    T Stack<T>::Top() const {
        if (isEmpty()){
            throw EmptyStack();
        }
        return items[top];
    }
    /**
     * @brief prints stack to console
     * @tparam T ItemType
     */
    template<class T>
    void Stack<T>::printStack() const {
        std::cout << "--------[Stack]---------" << std::endl;
        for (int i = 0; i <= top; i++){
            std::cout << "Position [" << i << "] " << items[i] << std::endl;
        }
        std::cout << "------------------------" << std::endl;
    }

} // stack

#endif //HW5_STACK_H
