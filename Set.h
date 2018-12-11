//
// Created by Александра on 12.12.18.
//

#ifndef LAB2_SET_H
#define LAB2_SET_H
#include "Error.h"


class Set {
    int len;
    int values[256];
public:
    Set(string s) {
        len = 0;
        int p = 0;
        int num = 0;
        int elem = 1;
        while (p < s.length()) {
            if (isdigit(s[p])) {
                num = num * 10 + s[p] - 48;
            }
            else if (s[p] == '-') {
                elem *= -1;
            }
            else if (s[p] == ',')
            {
                *this << num * elem;
                num = 0;
                elem = 1;
            }
            else if (s[p] == ' ')
            {
                p++;
                continue;
            }
            else
            {
                len = 0;
                throw WrongSet();
            }
            p++;
        }

        *this << num * elem;
    }
    Set() {
        len = 0;
    }
    void out() {
        if (len > 0)
            cout << values[0];
        for (int i = 1; i < len; i++)
            cout << ", " << values[i];
    }
    Set operator+(const Set &B) {
        Set rez;
        int i = 0;
        int j = 0;
        while (i < this->len && j < B.len) {
            if (this->values[i] < B.values[j]) {
                rez.values[rez.len++] = this->values[i];
                i++;
            }
            else if (this->values[i] > B.values[j]) {
                rez.values[rez.len++] = B.values[j];
                j++;
            }
            else {
                rez.values[rez.len++] = this->values[i];
                i++;
                j++;
            }
        }

        while (i < this->len) {
            rez.values[rez.len++] = this->values[i];
            i++;
        }

        while (j < B.len) {
            rez.values[rez.len++] = B.values[j];
            j++;
        }

        return rez;
    }
    Set operator*(const Set &B) {
        Set rez;
        int i = 0;
        int j = 0;
        while (i < this->len && j < B.len) {
            if (this->values[i] < B.values[j]) {
                i++;
            }
            else if (this->values[i] > B.values[j]) {
                j++;
            }
            else {
                rez.values[rez.len++] = this->values[i];
                i++;
                j++;
            }
        }

        return rez;
    }
    Set operator-(const Set &B) {
        Set rez;
        int i = 0;
        int j = 0;
        while (i < this->len && j < B.len) {
            if (this->values[i] < B.values[j]) {
                rez.values[rez.len++] = this->values[i];
                i++;
            }
            else if (this->values[i] > B.values[j]) {
                j++;
            }
            else {
                i++;
                j++;
            }
        }

        while (i < this->len) {
            rez.values[rez.len++] = this->values[i];
            i++;
        }

        return rez;
    }
    Set operator<<(const int &el) {
        int pos = -1;

        if (len > 0 && el < values[0])
            pos = 0;

        for (int i = 0; i < len - 1; i++)
            if (values[i] == el) {
                return *this;
            }
            else if (values[i] < el && values[i + 1]>el) {
                pos = i + 1;
                break;
            }

        if (values[len - 1] == el) {
            return *this;
        }

        if (pos == -1)
            pos = len;
        len++;

        int val = el;
        for (int i = pos; i < len; i++) {
            int x = values[i];
            values[i] = val;
            val = x;
        }
        return *this;
    }
    Set operator>>(const int &el) {
        int i = 0;
        while (i < len && values[i] < el)
            i++;
        if (i < len && values[i] == el) {
            for (i; i < len - 1; i++)
                values[i] = values[i + 1];
            len--;
        }

        return *this;
    }

    Set operator+=(const Set &B) {
        *this = (*this + B);
        return *this;
    }

    Set operator*=(const Set &B) {
        *this = (*this * B);
        return *this;
    }

    Set operator-=(const Set &B) {
        *this = (*this - B);
        return *this;
    }
};


#endif //LAB2_SET_H
