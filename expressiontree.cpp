//
// Created by jaox on 9/20/18.
//

#include <iostream>
#include "expressiontree.h"
using namespace std;
int main() {
    string expresion = "(-4-(-4))+8+16";
    node *bicho = build(expresion);
    cout<<bicho->result();
}