//
//  Term.cpp
//  AdditionSubtraction
//
//  Created by Ahmed Latif on 2/5/17.
//  Copyright © 2017 Ahmed Latif. All rights reserved.
//

#include "Term.h"


ostream& operator<<(ostream& os, const Term &t){
    
    if(t.coef == 0)
    {
        os << 0;
    }
    else if(t.degree > 0)
    {
        os << t.coef << "x^" << t.degree;
    }
    else if(t.degree == 0)
    {
        os << t.coef;
    }
    
    return os;
}

Term::Term(int coef, int deg){
    this->coef = coef;
    degree = deg;
}
