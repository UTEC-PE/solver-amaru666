//
// Created by jaox on 9/20/18.
//

#ifndef TAREA_SOLVER_EXPRESSIONTREE_H
#define TAREA_SOLVER_EXPRESSIONTREE_H

#include <string>
using namespace std;
class node{
public:
    node * left;
    node * right;
    float data;
    node() : left(nullptr), right(nullptr) {};
    node(node* left, node* right) : left(left), right(right){};
    node(float n): data(n) {};
    virtual float result() { return 0;};

};
class number: public node {
public:
    number(float n):node(n) {}
    float result() {
        return data;
    }
};
class Menos : public node{
public:
    Menos(node* left_, node* right_) : node(left_, right_) {};
    float result() {
        return left->result()-right->result();
    }
};
class Mas : public node {
public:
    Mas(node * left_, node* right_) : node(left_, right_) {};
    float result(){
        return left->result()+right->result();
    }
};
bool search(string equation, char element, int &pos){
    int parentesis=0;
    for(; pos >= 0; pos--) {
        if(equation[pos] == '(') parentesis++;
        if(equation[pos] == ')') parentesis--;
        if(parentesis == 0 && equation[pos] == element ) return true;
    }
    pos=equation.length();
    return false;
}
string cut_parentesis(string equation) {
    if (equation[0] == '(' && equation[equation.length() - 1] == ')')
        return equation.substr(1, equation.length()-2);
    return "";
}
bool is_digit(string equation) {
    for(int i = 0; i < equation.length(); i++){
        if(!(equation[i] >= '0' && equation[i]<= '9'))
            return false;
    }
    return true;
}
node*build(string equation) {
    int position = equation.length()-1;
    if(search(equation,'+', position)) {
        string subcadena1 = equation.substr(0,position);
        string subcadena2 = equation.substr(position+1);

        return new Mas(build(subcadena1), build(subcadena2));
    }else if (search(equation,'-',position)) {

        string subcadena1 = equation.substr(0,position);
        string subcadena2 = equation.substr(position+1);

        return new Menos(build(subcadena1), build(subcadena2));
    } else if ( is_digit(equation)) {
        float n = strtof(equation.c_str(),0);
        return new number(n);
    } else {
        equation = cut_parentesis(equation);
        return build(equation);
    }
}
#endif //TAREA_SOLVER_EXPRESSIONTREE_H
