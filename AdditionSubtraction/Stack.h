//
//  STACK.h
//  AdditionSubtraction
//
//  Created by Ahmed Latif on 2/4/17.
//  Copyright © 2017 Ahmed Latif. All rights reserved.
//

#ifndef Stack_h
#define Stack_h
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <string>
#include "LL.h"

using std::cout;
using std::endl;
using std::ostream;
using std::string;
using std::out_of_range;

template <typename T>
class Stack{
    
    template<typename F>
    friend ostream& operator<<(ostream& os, Stack<T> );
    
    
private:
    LL<T> topOfStack;
    T at(int ndx);
    int size();
    
public:
    //constructor
    Stack(){}
    
    //copy constructor
    Stack( Stack<T> &otherStack);
    
    //destructor
    ~Stack(){}
    
    //returns the top of the stack
    T top();
    
    //deletes the top of the stack
    void pop();
    
    //adds to peram to top of stack
    void push(T);
    
    //returns if empty
    bool isEmpty() const;
    
};


//returns the top of the stack
template <typename T>
T Stack<T>::top(){
    
    try {
        if(topOfStack.size() == 0)
            throw out_of_range("nothing in stack to top");
        
        LL_iterator<T> iter = topOfStack.begin();
        
        return *iter;
    }
    catch (out_of_range oof) {
        throw oof;
    }
}

//deletes the top of the stack
template <typename T>
void Stack<T>::pop(){
    try {
        if(topOfStack.size() ==0)
            throw out_of_range("nothing in stack to pop");
        
        topOfStack.pop_front();
    }
    catch (out_of_range oof) {
        throw oof;
    }
    
}

//adds to peram to top of stack
template <typename T>
void Stack<T>::push(T element){
    topOfStack.addToFront(element);
}

//returns if empty
template <typename T>
bool Stack<T>::isEmpty() const{
    if(topOfStack.size() == 0)
        return true;
    else
        return false;
}

template <typename T>
Stack<T>::Stack(Stack<T> &otherStack){

    LL<T> list;
    int i = 0;
    while(list.size() < otherStack.size())
    {
        list.addToFront(otherStack.at(i));
        i++;
    }
    
    //cout << list << endl;
    
    LL_iterator<T> iter = list.begin();
    while (iter != list.header())
    {
        push(*iter);
        ++iter;
    }
    
}
template<typename T>
T Stack<T>::at(int ndx){
    return topOfStack.at(ndx);
}

                        
template<typename T>
int Stack<T>::size(){
    return topOfStack.size();
}
                        

template <typename T>
ostream& operator<<(ostream& os, Stack<T> &stack){

    
    Stack<T> other = *new Stack<T>(stack);
    
    while(!(other.isEmpty()))
    {
        os << other.top() << endl;
        other.pop();
    }
    
    
    return os;
}





#endif /* STACK_h */
