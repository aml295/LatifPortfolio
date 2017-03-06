/*
//  main.cpp
//  AdditionSubtraction
//
//  Created by Ahmed Latif on 1/16/17.
//  Copyright © 2017 Ahmed Latif. All rights reserved.
//

#include <stdexcept>
#include <iomanip>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "LL.h"

using namespace std;

LL<int> addition(LL<int> minuend, LL<int> subterhend);
LL<int> subtraction(LL<int> minuend, LL<int> subterhend, bool &isNeg);

int main(int argc, const char * argv[]) {

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
        
        string min;
        string sub;
        char sign; //+ or -
        char minSign  = '\0';
        char subSign = '\0';
        LL<int> minuend;
        LL<int> subterhend;
        LL<int> result;
        bool isSubtractionNegResult = false;
        
        //while loop
        while(inputFile >> min, inputFile >> sub, inputFile >> sign)
        {
            bool isResultNegative = false;
            
            cout << min << endl << sub << endl << sign << endl;
            //read in three strings
        
            for(int i = 0; i < min.size(); i++)
            {
                if(i == 0 && (min[i] == '+' || min[i] == '-'))
                {
                    minSign = min[i];
                    //cout << "minsign" << minSign << endl;
                }
                else
                {
                    if (i == 0 && min[i] != '+' && min[i]!= '-')
                    {
                        minSign = '+';
                        //cout << "minsign" << minSign << endl;
                    }
                    char * c = new char(min[i]);
                    int holdsInt = atoi(c);
                    //cout << "int holder: " << holdsInt << endl;
                    minuend.addToFront(holdsInt);
                }
            }
        
            //cout << endl;
    
            for(int i = 0; i < sub.size(); i++)
            {
                if(i == 0 && (sub[i] == '+' || sub[i] == '-'))
                {
                    subSign = sub[i];
                    //cout << "subsign" << subSign << endl;
                }
                else
                {
                    if (i == 0 && sub[i] != '+' && sub[i] != '-')
                    {
                        subSign = '+';
                        //cout << "subsign" << subSign << endl;
                    }

                    char * c = new char(sub[i]);
                    int holdsInt = atoi(c);
                    //cout << "int holder: " << holdsInt << endl;
                    subterhend.addToFront(holdsInt);
                }
            }
        
            //cout << endl << minuend << endl << subterhend << endl <<endl << endl << "break \n";
        
            //process info in order to decide cases
        
            //++ +
            if(minSign == '+' && subSign == '+' && sign  == '+')
                result = addition(minuend, subterhend);
            
            //+- +
            if(minSign == '+' && subSign == '-' && sign  == '+')
                result = subtraction(minuend, subterhend, isSubtractionNegResult = false);

            //-- +
            if(minSign == '-' && subSign == '-' && sign  == '+')
            {
                result = addition(minuend, subterhend);
                isResultNegative = true;
            }
            
            //++ -
            if(minSign == '+' && subSign == '+' && sign  == '-')
                result = subtraction(minuend, subterhend, isSubtractionNegResult = false);
            
            //+- -
            if(minSign == '+' && subSign == '-' && sign  == '-')
                result = addition(minuend, subterhend);
            
            //-+ -
            if(minSign == '-' && subSign == '+' && sign  == '-')
            {
                result = addition(minuend, subterhend);
                isResultNegative = true;
            }
            
            //-- -
            if(minSign == '-' && subSign == '-' && sign  == '-')
                result = subtraction(minuend, subterhend, isSubtractionNegResult = true) ;
            
            // -+ +
            if(minSign == '-' && subSign == '+' && sign  == '+')
                result = subtraction(minuend, subterhend, isSubtractionNegResult = true);

            
            //print out results
            
            //if isSubtractionNegResult is true print out neg before
            //if isSubtractionNegResult and isResultNegative anf both true then do nothing
            //if isResultNegative is true then print out neg sign
            
            //if (result.at(0) == 0) result.pop_front();
            cout << "result: " << endl;
            if (isSubtractionNegResult || isResultNegative) {
                cout<< '-';
            }
            cout << result << endl;
            
            
            minuend.clear();
            subterhend.clear();
            result.clear();
            cout << endl << endl << endl;// << endl;
        }
    
    
    }
    
      
    return 0;
}






LL<int> addition(LL<int> minuend, LL<int> subterhend){
    LL_iterator<int> iterMin = minuend.begin();
    LL_iterator<int> iterSub = subterhend.begin();
    LL<int> result;
    bool isMinuendBigger = false;
    bool isSubterhendBigger = false;
    unsigned long count = 0;
    
    //check count
    if(minuend.size() == subterhend.size())
    {
        count  = minuend.size();
    }
    else if(minuend.size() > subterhend.size())
    {
        count = subterhend.size();
        isMinuendBigger = true;
        
    }
    else if(minuend.size() < subterhend.size())
    {
        count  = minuend.size();
        isSubterhendBigger = true;
    }
    
    //add up until the min and sub are sme length
    int carry = 0;
    
    for(int i = 0; i < count; i++)
    {
        int sum = 0;
        
        //if greater than 10
        if((*iterMin + *iterSub) >= 10)
        {
            sum = (*iterMin + *iterSub) - 10 + carry;

            result.addToFront(sum);
            carry = 1;
        }
        //if less than 10
        else
        {
            sum = (*iterMin + *iterSub) + carry;
            if(sum >= 10)
            {
                result.addToFront(sum-10);
                sum = sum - 10;
            }
            result.addToFront(sum);
            carry = 0;
        }
        ++iterMin;
        ++iterSub;
    }
    
    //based on which is larger, add rest of list to result list
    if(isMinuendBigger)
    {
        for(int i = (int) subterhend.size(); i < minuend.size(); i++)
        {
            result.addToFront(*iterMin);
            ++iterMin;
        }
    }
    else if(isSubterhendBigger)
    {
        for(int i = (int) minuend.size(); i < subterhend.size(); i++)
        {
            result.addToFront(*iterSub);
            ++iterSub;
        }
    }
    
    //cout << "result in add: " << result << endl;
    return result;
}



LL<int> subtraction(LL<int> minuend, LL<int> subterhend, bool &isNeg){
    LL_iterator<int> iterMin = minuend.begin();
    LL_iterator<int> iterSub = subterhend.begin();
    LL<int> result;
    LL<int> complementList;
    bool isMinuendBigger = false;
    bool isSubterhendBigger = false;
    unsigned long count = 0;
    
    //check count and which is bigger
    if(minuend.size() == subterhend.size())
    {
        count  = minuend.size();
        bool isFound = false;
        //go through remaining numbers back of the list to front
        //in order to determine which number is larger
        for(int i = 0; i < count; i++)
        {
            
            if (i != count -1 && !isFound)
            {
                if (minuend.at(count - i - 1) == subterhend.at(count - i - 1));
                else if (minuend.at(count - i - 1) > subterhend.at(count - i - 1))
                {
                    isMinuendBigger = true;
                    isFound = true;
                }
                else if (minuend.at(count - i - 1) < subterhend.at(count - i - 1))
                {
                    isSubterhendBigger = true;
                    isFound = true;
                }
            }
            else if (i == count -1 && !isFound)
            {
                if (minuend.at(count - i - 1) == subterhend.at(count - i - 1));
                else if (minuend.at(count - i - 1) > subterhend.at(count - i - 1))
                {
                    isMinuendBigger = true;
                    isFound = true;
                }
                else if (minuend.at(count - i - 1) < subterhend.at(count - i - 1))
                {
                    isSubterhendBigger = true;
                    isFound = true;
                }

            }
            
        }
        
    }
    else if(minuend.size() > subterhend.size())
    {
        count = subterhend.size();
        isMinuendBigger = true;
        
    }
    else if(minuend.size() < subterhend.size())
    {
        count  = minuend.size();
        isSubterhendBigger = true;
    }
    
    
    
    //if minuend is bugger normal subtraciton
    if (isMinuendBigger)
    {   //cout << "isMinuendBigger: " << "yes" << endl;
        complementList.push_back(10 - *iterSub);
        ++iterSub;
        
        for (int i = 1; i < subterhend.size(); i++)
        {
            complementList.push_back(9 - *iterSub);
            ++iterSub;
        }
        
        for (int i = count; i < minuend.size(); i++)
        {
            complementList.push_back(9);
        }
        
        
        result = addition(minuend, complementList);
         //************** remove first thing not last
        if(result.size() > minuend.size())
        {
            result.pop_front();
            //cout << "POOOOO" << endl;
        }
       
        LL_iterator<int> iterResult = result.begin();
        while(*iterResult == 0)
        {
            //cout << "iterResult: " << *iterResult << endl;
            ++iterResult;
            result.pop_front();
        }
    }
    else if (isSubterhendBigger)
    {   //cout << "isMinuendBigger: " << "yes" << endl;
        complementList.push_back(10 - *iterMin);
        ++iterMin;
        
        for (int i = 1; i < count; i++)
        {
            complementList.push_back(9 - *iterMin);
            ++iterMin;
        }
        
        for (int i = count; i < subterhend.size()-1; i++)
        {
            complementList.push_back(9);
        }
        
        //cout << "compliment List: " << complementList << endl;
        result = addition(subterhend, complementList);
        isNeg = true;
        //************** remove first thing not last
        if(result.size() > minuend.size())
            result.pop_front();
    }
    else if(!isSubterhendBigger && !isMinuendBigger)
    {
        result.push_back(0);
    }
    
    //cout << "result size: " << result.size() << endl;
    //cout << "minuend size: " << minuend.size() << endl;
    //cout << "subterhend size: " << subterhend.size() << endl;
    //if(result.size() <)
    
    //cout << "result in sub: " << result << endl;
    return result;
}

*/
