#include <iostream>
#include "Error.h"
#include "Set.h"

using namespace std;


int main()
{
    try{
        string set1;
        string set2;
        cout << "Enter Set A separated with komas:   " << endl;
        getline(cin, set1);
        cout << "Enter Set B separated with komas:   " << endl;
        getline(cin, set2);

        Set A(set1);
        Set B(set2);

        cout << "A = {";
        A.out();
        cout << "}" << endl;

        cout << "B = {";
        B.out();
        cout << "}" << endl;


        cout << "A+B = {";
        (A + B).out();
        cout << "}" << endl;

        cout << "A*B = {";
        (A * B).out();
        cout << "}" << endl;

        cout << "A-B = {";
        (A - B).out();
        cout << "}" << endl;


        cout << "Enter the element, that you want to add:   " << endl;
        string s;
        cin >> s;
        int p = 0;
        int num = 0;
        int elem = 1;
        while (p < s.length()) {
            if (isdigit(s[p])) {
                num = num * 10 + s[p] - 48;
            } else if (s[p] == '-') {
                elem *= -1;
            } else {
                throw WrongEl();
            }
            p++;
        }
        if(elem == -1){
            num *= -1;
        }
        cout << "B<<" << num << " = {";
        B = B << num;
        B.out();
        cout << "}" << endl;

        num = 0;
        cout << "Enter the element, that you want to delete:   " << endl;
        cin >> s;
        p = 0;
        elem = 1;
        while (p < s.length()) {
            if (isdigit(s[p])) {
                num = num * 10 + s[p] - 48;
            } else if (s[p] == '-') {
                elem *= -1;
            } else {
                throw WrongEl();
            }
            p++;
        }
        if(elem == -1){
            num *= -1;
        }
        cout << "B>>" << num << " = {";
        B = B >> num;
        B.out();
        cout << "}" << endl;
    }
    catch(WrongSet& m){
        m.message();
    }
    catch(WrongEl& mm){
        mm.message();
    }
}