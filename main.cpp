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
#include "exam.h"
#include "binary_search_tree.h"

//Max size for stack and queue
#define MAX_SIZE 10

using namespace std;
int main(){
    bool continueProgram = true;
    while (continueProgram){
        cout << "Choose\n"
                " 1: Stack\n"
                " 2: Queue\n"
                " 3: Exams\n"
                " 4: Binary Search Tree\n"
                " 5: Exit" << endl;
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
                cout << "1: Push\n"
                        "2: Pop \n"
                        "3: End" << endl;
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
                cout << "1: Enqueue  \n"
                        "2: Dequeue \n"
                        "3: End" << endl;
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
        else if (userInput == 3){
            bool continueTesting = true;
            while (continueTesting){
                cout << "Choose Chapter to test.\n"
                        "1. Chapter 1\n"
                        "2. Chapter 2\n"
                        "3. Chapter 3\n"
                        "4. Chapter 4\n"
                        "5. Chapter 5\n"
                        "6. Chapters 1-5\n"
                        "7. Exit" << endl;
                int userInputExam;
                cin >> userInputExam;
                if (userInputExam == 1){
                    exam::Exam ch1Exam;
                    ch1Exam.chapter1();
                }
                if (userInputExam == 2){
                    exam::Exam ch2Exam;
                    ch2Exam.chapter2();
                }
                if (userInputExam == 3){
                    exam::Exam ch3Exam;
                    ch3Exam.chapter3();
                }
                if (userInputExam == 4){
                    exam::Exam ch4Exam;
                    ch4Exam.chapter4();
                }
                if (userInputExam == 5){
                    exam::Exam ch5Exam;
                    ch5Exam.chapter3();
                }
                if (userInputExam == 6){
                    exam::Exam allExams;
                    allExams.allChapters();
                }
                if (userInputExam == 7){
                    continueTesting = false;
                }
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
        else if (userInput == 4){
            bool continueTree = true;
            BST::binary_search_tree<int> bst;
            while(continueTree){
                cout <<  "Choose an option \n"
                        << "1. Insert int into tree\n"
                        << "2. Delete int from tree\n"
                        << "3. Print tree smallest to largest\n"
                           "4. Exit tree." << endl;
                 int userInputTree;
                 cin >> userInputTree;
                 //Insert int into tree
                 //TODO need to make sure the int is unique
                 if (userInputTree == 1){
                     string userInputTreeString;
                     cin.ignore();
                     cout << "Enter int to add to tree." << endl;
                     getline(cin, userInputTreeString);
                     cout << userInputTreeString << endl;
                     int inputToInt;
                     try {
                         inputToInt = stoi(userInputTreeString);
                     }
                     catch (std::invalid_argument& e){
                         cerr << "invalid input " << userInput << " no conversion to int."<< endl;
                         cin.ignore();
                         continue;
                     }
                     if (!bst.isFull()){
                         bst.putItem(inputToInt);
                     } else {
                         cerr << "The tree is full." << endl;
                         continue;
                     }
                 }
                 //Delete int from tree
                 else if (userInputTree == 2){
                     if (!bst.isEmpty()){
                         cout << "Enter an int to remove from tree." << endl;
                         int intToRemove;
                         cin >> intToRemove;
                         bool containsInt;
                         bst.getItem(intToRemove, containsInt);
                         if (containsInt){
                             bst.deleteItem(intToRemove);
                         } else {
                             cerr << intToRemove << " is not in the tree." << endl;
                             continue;
                         }

                     } else {
                         cerr << "The tree is empty." << endl;
                         continue;
                     }
                 }
                 //Print items in tree
                 else if (userInputTree == 3){
                    bst.print(cout);
                 }
                 //Exit tree
                 else if (userInputTree == 4){
                     continueTree = false;
                 }
                 else {
                     cin.ignore();
                     cerr << "Incorrect input." << endl;
                     continue;
                 }
             }
         }
        else if (userInput == 5){
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