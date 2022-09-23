/**
 * @file main.h
 * @author Thomas Michael (tjm0027@uah.edu)
 * @brief Main driver for taking input from keyboard to create and and utilize ADTs Stack and Queue
 * @date 2022-09-21
 *
 */
#include "queue.h"
#include "stack.h"
#include "string"

//Max size for stack and queue
#define MAX_SIZE 10

using namespace std;
int main(){
    bool continueProgram = true;
    while (continueProgram){
        cout << "Choose 1: Stack 2: Queue 3: Exit" << endl;
        int userInput;
        cin >> userInput;
        /**
         * Handles Stack.
         */
        if (userInput == 1){
            int userSize;
            cout << "Enter stack size. Max is " << MAX_SIZE << endl;
            cin >> userSize;
            if (userSize > MAX_SIZE || userSize < 1){
                cerr << "Choose a size between 1 and " << MAX_SIZE << endl;
                cin.ignore();
                continue;
            }
            stack::Stack<int> userStack(userSize);
            bool continueStack = true;
            while(continueStack){
                cout << "1: Push  2: Pop 3: End" << endl;
                int userInputStack;
                cin >> userInputStack;
                cout << userInputStack << endl;
                /**
                 * Push item onto Stack
                 */
                if (userInputStack == 1){
                    string userInputPush;
                    cin.ignore();
                    cout << "Enter a number to push onto the stack." << endl;
                    getline(cin, userInputPush);
                    int inputToInt;
                    try {
                        inputToInt = stoi(userInputPush);
                    }
                    catch (std::invalid_argument& e){
                        cerr << "invalid input " << userInput << " no conversion to int."<< endl;
                        cin.ignore();
                        continue;
                    }
                    try {
                        userStack.Push(inputToInt);
                    }
                    catch (stack::FullStack &e){
                        cerr << "Full stack exception thrown." << endl;
                        cin.ignore();
                        continue;
                    }
                    cout << inputToInt << " added to stack." << endl;
                    userStack.printStack();
                }
                /**
                 * Remove item from Stack
                 */
                else if (userInputStack == 2){
                    try {
                        userStack.Pop();
                    }
                    catch (stack::EmptyStack &e){
                        cerr << "Empty stack exception thrown." << endl;
                        continue;
                    }
                    cout << "Removed item from stack." << endl;
                    userStack.printStack();
                }
                /**
                 * Exit Stack
                 */
                else if (userInputStack == 3){
                    continueStack = false;
                    continue;
                }
                /**
                 * Handles incorrect input
                 */
                else {
                    cin.ignore();
                    cerr << "Incorrect input." << endl;
                    continue;
                }
            }
        }
        /**
         * Handles Queue.
         */
        else if (userInput == 2){
            int userSize;
            cout << "Enter queue size. Max is " << MAX_SIZE << endl;
            cin >> userSize;
            if (userSize > MAX_SIZE || userSize < 1){
                cerr << "Choose a size between 1 and " << MAX_SIZE << endl;
                cin.ignore();
                continue;
            }
            queue::Queue<int> userQueue(userSize);
            bool continueQueue = true;
            while(continueQueue){
                cout << "1: Enqueue  2: Dequeue 3: End" << endl;
                int userInputQueue;
                cin >> userInputQueue;
                cout << userInputQueue << endl;
                /**
                 * Adds int to queue
                 */
                if (userInputQueue == 1){
                    string userInputQueueString;
                    cin.ignore();
                    cout << "Enter a number to enqueue in the queue." << endl;
                    getline(cin, userInputQueueString);
                    int inputToInt;
                    try {
                        inputToInt = stoi(userInputQueueString);
                    }
                    catch (std::invalid_argument& e){
                        cerr << "invalid input " << userInput << " no conversion to int."<< endl;
                        cin.ignore();
                        continue;
                    }
                    try {
                        userQueue.enqueue(inputToInt);
                    }
                    catch (queue::FullQueue &e){
                        cerr << "Full queue exception thrown." << endl;
                        cin.ignore();
                        continue;
                    }
                    cout << inputToInt << " added to queue." << endl;
                    userQueue.printQueue();
                }
                /**
                 * Remove int from queue
                 */
                else if (userInputQueue == 2){
                    try {
                        userQueue.dequeue();
                    }
                    catch (queue::EmptyQueue &e){
                        cerr << "Empty queue exception thrown." << endl;
                        continue;
                    }
                    cout << "Removed item from queue." << endl;
                    userQueue.printQueue();
                }
                /**
                 * Exits Queue
                 */
                else if (userInputQueue == 3){
                    continueQueue = false;
                    continue;
                }
                /**
                 * Handles incorrect input
                 */
                else {
                    cin.ignore();
                    cerr << "Incorrect input." << endl;
                    continue;
                }
            }
        }
        /**
         * Exits program.
         */
        else if (userInput == 3){
            continueProgram = false;
        }
        /**
         * Handles incorrect input.
         */
        else {
            cin.ignore();
            cout << "Incorrect input." << endl;
        }
    }
}