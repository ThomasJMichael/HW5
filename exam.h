//
// Created by Jacob on 10/18/2022.
//

#ifndef HW5_EXAM_H
#define HW5_EXAM_H

namespace exam {

    class Exam {
    private:
        int score;
    public:
        Exam(){
            score = 0;
        }
        inline int& getScore () { return score;};
        void chapter1();
        void chapter2();
        void chapter3();
        void chapter4();
        void chapter5();
        void allChapters();
        static int getAnswer();

        void processAnswer(int studentAnswer, int correctAnswer);

        void printScore(int chapter) const;
    };

} // exam

#endif //HW5_EXAM_H
