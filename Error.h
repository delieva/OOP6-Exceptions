//
// Created by Александра on 11.12.18.
//

#ifndef LAB2_ERROR_H
#define LAB2_ERROR_H

using namespace std;

class Error {
public:
    Error () {
        cout << "Error! " << endl;
    }
    virtual void message() {
        cout << "Найдена ошибка!" << endl;
    }
};
class WrongEl : public Error {
public:
    void message() {
        cout << "This is not a single integer" << endl;
    }
};
class WrongSet : public Error {
public:
    void message() {
        cout << "You entered wrong data" << endl;
    }
};


#endif //LAB2_ERROR_H
