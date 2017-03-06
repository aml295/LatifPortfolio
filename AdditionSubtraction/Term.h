//
//  Term.hpp
//  AdditionSubtraction
//
//  Created by Ahmed Latif on 2/5/17.
//  Copyright © 2017 Ahmed Latif. All rights reserved.
//

#ifndef Term_h
#define Term_h



#include <stdexcept>
#include <iomanip>
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;
using std::string;

class Term {
friend ostream& operator<<(ostream& os, const Term &t);
private:
public:
    int coef = 0;
    int degree = 0;

    
    //constructor
    Term(){};
    Term(int,int);
    
    
};


#endif /* Term_hpp */
