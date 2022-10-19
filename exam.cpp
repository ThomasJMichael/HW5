//
// Created by Jacob on 10/18/2022.
//

#include "exam.h"
#include <iostream>


namespace exam {

    void Exam::chapter1() {
        int studentAnswer;
        std::cout << "Chapter 1." << std::endl;
        std::cout << "1. Operating systems, development environments, and high level languages are examples of " << std::endl
                << "a. Hardware" << std::endl
                << "b. Software" << std::endl
                << "c. Ideaware" << std::endl
                << "d. Modules" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        std::cout << "2. True or false: A statement of what is to be provided by a computer system or software product is called a Software specification." << std::endl
                  << "a. True" << std::endl
                  << "b. False" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        std::cout << "3. _____ -Down Design is where a problem is first broken down into several large parts. Each of the parts"
                     "is, in turn, divided into sections." << std::endl
                  << "a. Top" << std::endl
                  << "b. Driven" << std::endl
                  << "c. Turn" << std::endl
                  << "d. Object" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'a');
        std::cout << "4. When every statement in the program is executed at least once" << std::endl
                  << "a. Black-box testing" << std::endl
                  << "b. White-box testing" << std::endl
                  << "c. Statement coverage" << std::endl
                  << "d. Integration testing" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'c');
        std::cout << "5. True or false: An assertion is a logical proposition that can be true or false." << std::endl
                  << "a. True" << std::endl
                  << "b. False" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'a');
        printScore(1);

    }

    void Exam::chapter2() {
        int studentAnswer;
        std::cout << "Chapter 2." << std::endl;
        std::cout << "1. What is the separation of representation of data from the applications that use the data at a logical level?" << std::endl
                  << "a. Encapsulation" << std::endl
                  << "b. Polymorphism" << std::endl
                  << "c. Data structure" << std::endl
                  << "d. Transformer" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'a');
        std::cout << "2. True or false: A constructor is an operation that creates a new instance of an ADT." << std::endl
                  << "a. True" << std::endl
                  << "b. False" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'a');
        std::cout << "3. ___ Data type allows a collection of values to be associated with an object of that type. " << std::endl
                  << "a. Driven" << std::endl
                  << "b. Composite" << std::endl
                  << "c. Free " << std::endl
                  << "d. Object" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        std::cout << "4. Giving the same name to more than one function or using the same operator symbol for more than one operation, usually associated with static binding is" << std::endl
                  << "a. Exerting" << std::endl
                  << "b. Dynamic function calls" << std::endl
                  << "c. Overloading" << std::endl
                  << "d. Heap" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'c');
        std::cout << "5. Which of the following is bounded time?" << std::endl
                << "a. O(1) " << std::endl
                << "b. O(N)" << std::endl
                << "c. O(log N)" << std::endl
                << "d. O(N^2)" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'a');
        printScore(2);
    }

    void Exam::chapter3() {
        int studentAnswer;
        std::cout << "Chapter 3." << std::endl;
        std::cout << "1.True or false: Lists are a heterogeneous collection of elements. They do not care about the type of elements they store." << std::endl
                  << "a. True" << std::endl
                  << "b. False" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        std::cout << "2. What is the blank in the following unsorted linked list code example:"
                  << "Void UnsortedType::PutItem(ItemType item){\n"
                     "NodeType* location;\n"
                     "location->info = item;\n"
                     "location->next = listData;\n"
                     "listData = location\n"
                     "____++;" << std::endl
                << "a. length" << std::endl
                << "b. location" << std::endl
                << "c. listData" << std::endl
                << "d. item" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'a');
        std::cout << "3. What is the Big-O complexity for GetItem in a Linked List implementation:" << std::endl
                  << "a. O(1)" << std::endl
                  << "b. O(N)" << std::endl
                  << "c. O(N2)" << std::endl
                  << "d. O(N+1)" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        std::cout << "4. True or False: A linked list is a random-access structure." << std::endl
                  << "a. True" << std::endl
                  << "b. False" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        std::cout << "5. What is the complexity of searching a sorted list with the binary search algorithm?" << std::endl
                  << "a. O(1) " << std::endl
                  << "b. O(N)" << std::endl
                  << "c. O(log N)" << std::endl
                  << "d. O(N^2)" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'c');
        printScore(3);
    }
    void Exam::chapter4() {
        int studentAnswer;
        std::cout << "Chapter 4." << std::endl;
        std::cout << "1. True or false: A bounded ADT has no logical limit." << std::endl
                  << "a. True" << std::endl
                  << "b. False" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        std::cout << "2. Which of the following is not a stage of the Object-oriented Design Methodology" << std::endl
                << "a. Brainstorming" << std::endl
                << "b. Deployment" << std::endl
                << "c. Scenarios " << std::endl
                << "d. Responsibility Algorithms" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        std::cout << "3. A header ___ is included to prevent the header fle being included multiple times" << std::endl
                  << "a. Guard" << std::endl
                  << "b. Class" << std::endl
                  << "c. File " << std::endl
                  << "d. Object" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'a');
        std::cout << "4. Dynamic arrays are allocated on the" << std::endl
                  << "a. Stack" << std::endl
                  << "b. Heap" << std::endl
                  << "c. Disk" << std::endl
                  << "d. Drive" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'c');
        std::cout << "5. Which implementation has a O(1) complexity for the Put operation on a sorted list." << std::endl
                  << "a. Array-Based " << std::endl
                  << "b. Linked List" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        printScore(4);
    }
    void Exam::chapter5() {
        int studentAnswer;
        std::cout << "Chapter 5." << std::endl;
        std::cout << "1. True or false: A stack is a FIFO or first in first out ADT." << std::endl
                  << "a. True" << std::endl
                  << "b. False" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        std::cout << "2. Resulting condition from trying to pop an empty stack." << std::endl
                  << "a. Stack underflow" << std::endl
                  << "b. Stack overflow" << std::endl
                  << "c. Free stack" << std::endl
                  << "d. Undefined operation" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'a');
        std::cout << "3. ___ /Catch statements are used to gracefully handle exceptions being thrown" << std::endl
                  << "a. Pass" << std::endl
                  << "b. Throw" << std::endl
                  << "c. Try " << std::endl
                  << "d. Caught" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'c');
        std::cout << "4. Which operation has a O(1) complexity for a MakeEmpty operation on a Queue ADT" << std::endl
                  << "a. Dynamic Array" << std::endl
                  << "b. Linked Queue" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'a');
        std::cout << "5. The front pointer is pointed at the third node in a 4 node circular queue implementation. If the queue is full what node would the rear pointer be pointing to?" << std::endl
                << "a. 1" << std::endl
                << "b. 2" << std::endl
                << "c. 3 " << std::endl
                << "d. 4" << std::endl;
        studentAnswer = getAnswer();
        processAnswer(studentAnswer, 'b');
        printScore(5);
    }

    void Exam::allChapters() {
        Exam::chapter1();
        Exam::chapter2();
        Exam::chapter3();
        Exam::chapter4();
        Exam::chapter5();
        printScore(6);
    }
    int Exam::getAnswer(){
        char studentAnswer;
        std::cout << "Enter the letter for your answer." << std::endl;
        std::cin >> studentAnswer;
        int toLowerAnswer = tolower(studentAnswer);
        while (toLowerAnswer < 97 || toLowerAnswer > 100){
            std::cin.ignore();
            std::cerr << "Incorrect input. Choose a,b,c,d" << std::endl;
            std::cin >> studentAnswer;
            toLowerAnswer = tolower(studentAnswer);
        }
        return toLowerAnswer;
    }
    void Exam::processAnswer(int studentAnswer, int correctAnswer){
        if (studentAnswer == correctAnswer ){
            std::cout << "Correct Answer." << std::endl;
            score++;
        } else {
            std::cout << "Wrong Answer. Correct answer was " << (char)correctAnswer << std::endl;
        }
    }
    void Exam::printScore(int chapter) const{
        double scoreInPercent = ((score * 20.00) / 100) * 100;
        if (chapter == 1){
            std::cout << "Chapter 1 score " << scoreInPercent << "%." << std::endl
                    << score << " out of " << "5" << std::endl;
        }
        if (chapter == 2){
            std::cout << "Chapter 2 score " << scoreInPercent << "%." << std::endl
                      << score << " out of " << "5" << std::endl;
        }
        if (chapter == 3){
            std::cout << "Chapter 3 score " << scoreInPercent << "%." << std::endl
                      << score << " out of " << "5" << std::endl;
        }
        if (chapter == 4){
            std::cout << "Chapter 4 score " << scoreInPercent << "%." << std::endl
                      << score << " out of " << "5" << std::endl;
        }
        if (chapter == 5){
            std::cout << "Chapter 5 score " << scoreInPercent << "%." << std::endl
                      << score << " out of " << "5" << std::endl;
        }
        if (chapter == 6){
            std::cout << "Chapters 1-5 score " << scoreInPercent << "%." << std::endl
                      << score << " out of " << "5" << std::endl;
        }
    }

} // exam