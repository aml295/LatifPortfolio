//
//  StackPolyOperations.cpp
//  AdditionSubtraction
//
//  Created by Ahmed Latif on 2/4/17.
//  Copyright © 2017 Ahmed Latif. All rights reserved.
//


#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LL.h"
#include "Stack.h"
#include <vector>
#include "Term.h"

using namespace std;


int main(int argc, const char * argv[]) {
    try{
        
        string fileName = argv[1];
        ifstream inputFile;
        
        inputFile.open(fileName.c_str());
        
        if(!inputFile)
        {
            cout << "\nThe file name you have entered is incorrect.\n";
            
        }
        else
        {
            cout << "\nFile has opened correctly\n\n";
            
            string line;
            Stack<Polynomial<Term>> stack;
            
            //while loop
            while(!inputFile.eof())
            {
                getline(inputFile, line);
                cout << "line: " << line << endl;
                
                
                char holder1 = line[0];
                
                if((holder1 == '*' || holder1 == '-' || holder1 == '+'))
                {
                    Polynomial<Term> result;
                    
                    Polynomial<Term> term2;
                    term2 = stack.top();
                    //cout << "term2: " << term2 << endl;
                    stack.pop();
                    
                    Polynomial<Term> term1;
                    term1 = stack.top();
                    //cout << "term1: " << term1 << endl;
                    stack.pop();
                    
                    if(holder1 == '*')
                    {
                        result = term1 * term2;
                    }
                    else if(holder1 == '-')
                    {
                        result = term1 - term2;
                    }
                    else if(holder1 == '+')
                    {
                        result = term1 + term2;
                    }
                    
                    stack.push(result);
                }
                else
                {
                    Polynomial<Term> term;

                    stringstream ss;
                    ss << line;
                    
                    int coef;
                    int deg;
                    while(!ss.eof()){
                        ss >> coef >> deg;
                        
                        Term t(coef, deg);
                        term.insert(t);
                    }
                    
                    //cout << "term: " << term << endl << endl;

                    stack.push(term);
                    
                }
                cout << stack << endl;
            }
            
            cout << "result: " << stack << endl;
        }
    }
    catch(out_of_range oof)
    {
        cout << oof.what() << endl;
    }
    catch(...)
    {
        cout << "ERROR: unknown exception" << endl;
    }
}

