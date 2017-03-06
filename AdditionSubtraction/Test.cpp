
//  Test.cpp
//  AdditionSubtraction
//
//  Created by Ahmed Latif on 1/24/17.
//  Copyright © 2017 Ahmed Latif. All rights reserved.
//
/*
#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LL.h"
#include "Stack.h"
#include <vector>

using namespace std;

int main(int argc, const char * argv[]) {
    try{
        LL<double> list;
        
        //list.addToFront(0);
        list.addToFront(1);
        list.addToFront(2);
        list.addToFront(3);
        list.addToFront(4);
        list.addToFront(5);
        list.addToFront(6);
        list.addToFront(7);
        list.addToFront(8);
        list.addToFront(9);
        
        cout <<"list: \n" << list << endl;
        
        LL<double> list2 = list;
        list2.pop_back();
        list2.pop_front();
        cout << list2.at(0) << endl;
        cout <<"list2: \n" << list2 << endl;
        
        LL_iterator<double> lli = list.begin();
        for(int i = 0; i < 5; i++)
        {
            ++lli;
            cout << *lli << endl;
        }
        cout << "this is increement iterator: " << *lli << endl;
        while(lli != list.end())
        {
            cout << *lli << endl;
            --lli;
        }
        cout << "this is decrement iterator: " << *(++lli) << endl;
        
        
        
        
        
        vector<string> one;
        one.push_back("one");
        one.push_back("one");
        one.push_back("one");
        one.push_back("one");
        vector<string> two;
        two.push_back("two");
        two.push_back("two");
        two.push_back("two");
        two.push_back("two");
        vector<string> three;
        three.push_back("three");
        three.push_back("three");
        three.push_back("three");
        three.push_back("three");
        vector<string> four;
        four.push_back("four");
        four.push_back("four");
        four.push_back("four");
        four.push_back("four");
        
        Stack<string> stack;
        stack.push("one");
        stack.push("two");
        stack.push("three");
        stack.push("four");
        
        Stack<string> stack2(stack);
        /*
        while(!(stack2.isEmpty()))
        {
            string i = stack2.top();
            cout << i << endl;// .at(0) << i.at(1) << i.at(2)<< i.at(3) <<endl;
            stack2.pop();
        }
        //stack.top();
        
        cout << stack2 << endl;
        
    }
    catch (out_of_range oof)
    {
        cout << endl << "ERROR: " << oof.what() << endl;
    }
}



*/


