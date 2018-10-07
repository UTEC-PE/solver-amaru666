//
// Created by jaox on 9/20/18.
//

#include <iostream>
#include "expressiontree.h"
using namespace std;

// Solo resuelve sumas y restas
// Falta multiplicación, división, variables, unarios
// No combina bien los operadores, e.g. 5+--4

int main(int argc, char const *argv[]) {
    string expresion;
    if (argc == 2) {
        expresion = argv[1];
    }
    else {
      throw "One argument expected";
    }
    //string expresion = "(-4-(-4))+8+16";
    node *bicho = build(expresion);
    cout<<bicho->result()<<endl;
    return 0;
}