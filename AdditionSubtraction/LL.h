
#ifndef LL_h
#define LL_h


#include <stdexcept>
#include <iomanip>
#include <iostream>
#include "Term.h"

using std::cout;
using std::endl;
using std::ostream;
using std::string;


template <typename T>
class Node {
public:
    //T obj
    T info;
    
    //LL head
    Node<T>* next;
    Node<T>* prev;
    
    //constructor
    Node(T = T(), Node<T>* = NULL, Node<T>* = NULL);
};


/****************************************************************************
 *                                                                          *
 *                   class LL_iterator declaration                          *
 *                                                                          *
 ****************************************************************************/

// new for P4
template <typename T>
class LL_iterator
{
    
private:
    Node<T> *current;
    //pointer to point to the current
    //node in the linked list
    
public:
    
    //default constructor
    LL_iterator();
    
    LL_iterator(Node<T> *ptr);
    
    //overloaded operator *
    T& operator*();

    //overloaded ++ operator
    LL_iterator operator++();
    //overloaded -- operator
    LL_iterator operator--();
  
    //overloaded equality operator
    bool operator==(const LL_iterator &rhsObj) const;
    
    //overloaded != operator
    bool operator!=(const LL_iterator &rhsObj) const;
    
    
    
}; //END class LL_iterator




/****************************************************************************
 **                                                                        **
 **                       class LL<T> declaration                          **
 **                                                                        **
 ****************************************************************************/


template <typename T>
class LL {
    
    template <typename F>
    friend ostream& operator<<(ostream& os, const LL<F> &rhsObj);
    
protected:
    unsigned long count;
    Node<T> *head; // head is a pointer
    Node<T> sentinel; //empty node, unlike simply a pointer
    
    //copyList is a private function called to ensure deep copy
    void copyList(const LL<T> &listToCopy);
    
public:
    //constructor
    LL();
    
     //destructor
    ~LL();
    
    
    //copy constructor
    LL(const LL<T> &otherLL);
    
    //overloaded = operator
    LL<T> operator=(const LL<T> &rhsObj);
    
    void push_back(T);
    
    //add to front of list
    void addToFront(T);
    
    void pop_back();
    void pop_front();
    
    void clear();
    
    //returns number of objects in the linked list
    unsigned long size() const;
    
    //member function at, same as at function of vector class
    T& at(int ndx) const;
    
    LL_iterator<T> begin() const {return LL_iterator<T>(head->next);}
    LL_iterator<T> end() const {return LL_iterator<T>(head->prev /*sentinal node*/ );}
    LL_iterator<T> header() const {return LL_iterator<T>(head);}
    
};



/****************************************************************************
 **                                                                        **
 **                   class Node<T> implementation                         **
 **                                                                        **
 ****************************************************************************/


template <typename T>
Node<T>::Node(T templateObj, Node<T> *nodeNextPtr, Node<T> *nodePrevPtr ) {
    info = templateObj;
    next = nodeNextPtr;
    prev = nodePrevPtr;
}



/****************************************************************************
 *                                                                          *
 *                   class LL_iterator implemenation                        *
 *                                                                          *
 ****************************************************************************/


//default constructor
template <typename T>
LL_iterator<T>::LL_iterator(){
    current = NULL;
}



//constructor with parameter
template <typename T>
LL_iterator<T>::LL_iterator(Node<T> *ptr){
    current = ptr;
}


//overloaded operator *
template <typename T>
T& LL_iterator<T>::operator*(){
    return current->info;
}


//overloaded ++ operator
template <typename T>
LL_iterator<T> LL_iterator<T>::operator++(){
    current = current->next;
    //if(current->info == NULL) cout << "you are accessing sentinel node" << endl;
    return *this;
}

//overloaded -- operator
template <typename T>
LL_iterator<T> LL_iterator<T>::operator--(){
    current = current->prev;
    //if(current->info == NULL) cout << "you are accessing sentinel node" << endl;
    return *this;
}



//overloaded == operator
template <typename T>
bool LL_iterator<T>::operator==(const LL_iterator &rhsObj) const{
    
    return (current == rhsObj.current);
}


//overloaded != operator
template <typename T>
bool LL_iterator<T>::operator!=(const LL_iterator &rhsObj) const{
    
    return (current != rhsObj.current);
}



/****************************************************************************
 **                                                                        **
 **                    class LL<T> implementation                          **
 **                                                                        **
 ****************************************************************************/


//constructor
template <typename T>
LL<T>::LL(){
    sentinel = *new Node<T>(); //Node(T = T(), Node<T>* = NULL, Node<T>* = NULL)
       head = &sentinel;
    sentinel.next = head;
    sentinel.prev = head;
 
    count = 0;
    
    //cout << "Inside default constructor for class LL<T>" << endl;
}

//destructor
template <typename T>
LL<T>::~LL(){
    //call clear function
    clear();
}


template <typename T>
void LL<T>::copyList(const LL<T> &listToCopy){
    
    try {
        
        //make a deep copy
        Node<T> *current = listToCopy.head;//need to copy sentinel node
        current = current->next;
        while (current != listToCopy.head) {
            //add the element for copy
            this->push_back(current->info);
            //move current node along
            current = current->next;
        }
        
        
    }
    
    //catch any thrown strings
    catch (string a) {
        throw a;
    }
    
    //catch any unknown errors
    catch(...){
        throw;
    }
    
}


//copy constructor
template <typename T>
LL<T>::LL(const LL<T> &otherLL){
    try {
        //set the head = to NULL
        //this is a constructor remember
        sentinel = *new Node<T>(); //Node(T = T(), Node<T>* = NULL, Node<T>* = NULL)
        head = &sentinel;
        sentinel.next = head;
        sentinel.prev = head;
        count = 0;
        
        //copy the list
        copyList(otherLL);
    }
    
    //catch any thrown strings
    catch (string a) {
        throw a;
    }
    
    //catch any unknown errors
    catch(...){
        throw;
    }
}


//***************************
//overloading the = opperator
template <typename T>
LL<T> LL<T>::operator=(const LL<T> &rhsObj){
    try {
        
        //check for self assignment
        if((this == &rhsObj)) throw "self assignment";
        
        //clear the info of 'this'
        this->clear();
        
        //copy the list
        copyList(rhsObj);
        count = rhsObj.size();
        
    }
    
    //catch any thrown strings
    catch (string a) {
        throw a;
    }
    
    //catch any unknown errors
    catch(...){
        throw;
    }
    
    //return the copied rhsObj
    //copy constructor called
    return *this;
    
}

template <typename T>
void LL<T>::push_back(T n){
    try {

        Node<T> *current = head;
        while (current->next != head) {
            current = current->next;
                //cout << current->info << " something" << endl;
        }
        current->next = new Node<T>(n, head, current);
        head->prev = current->next;
        
            //increasing the count
        count++;
            //cout << size() << endl;
            //}
    }
    
    //catch any thrown bad_alloc
    catch(std::bad_alloc& bA)
    {
        throw bA;
    }
    
    //catch any thrown unknown errors
    catch (...)
    {
        throw;
    }
    
}


template <typename T>
void LL<T>::addToFront(T n){
    try {
       
        Node<T> *current = new Node<T>(n);
        
        head->next->prev = current;
        current->next = head->next;
        
        head->next = current;
        current->prev = head;
        //increasing the count
        count++;
            //cout << size() << endl;
        
    }
    
    //catch any thrown bad_alloc
    catch(std::bad_alloc& bA)
    {
        throw bA;
    }
    
    //catch any thrown unknown errors
    catch (...)
    {
        throw;
    }
    
}



//removes the last list object and deallocates memory
template <typename T>
void LL<T>::pop_back(){
    //if list is small
    Node<T> *current = head;
    
    //cycle through stuff
        
    while (current->next != head) {
        current = current->next;
    }
        
    //delete last thing
    head->prev = current->prev;
    current->prev->next = head;
    delete current;
    
    
    //COUNT stuff
    count--;
    
    
}

//pop_front removes the last list object and deallocates memory
template <typename T>
void LL<T>::pop_front(){
   
    Node<T> *current = head->next;
    //cycle through stuff
    head->next->next->prev = head;
    head->next = head->next->next;
    //delete first thing
    delete current;
        
    //COUNT stuff
    count--;
    //}
    
}


template <typename T>
void LL<T>::clear(){
    // cout << "calling clear()" << endl;
    
    Node<T> *trash = head->next;
    while (trash != &sentinel){
        // cout<< "this is whats being deleted " << trash->info << endl;
        
        // Move on to the next node, if any
        head->next->next->prev = head;
        head->next = head->next->next;
                
        
        // Delete the "garbage" node
        delete trash;
        
        
        //move trash onto next part
        trash = head->next;
        
        
        //make sure count goes down
        int i = 0;
        Node<T> *current = head->next;
        while (current != head)
        {
            current = current->next;
            i++;
        }
        
        if (i == (count - 1))
            count --;
        else cout << "clear function ERROR " << count << endl;
        
    }
    
    //make sure head is NULL
    head = &sentinel;
    
}

template <typename T>
unsigned long LL<T>::size() const{
    //int count1 = 0;
    //return the count
    /*Node<T> *current = head;
    while(current != NULL)
    {
        count1++;
        current = current->next;
    }
    */
    return count;
}

template <typename T>
T& LL<T>::at(int ndx) const{
    
    Node<T> *current = head->next;
    try {
        //make sure no out of range acessing happens
        if(ndx > count) throw std::out_of_range ("Linked List");
        //if(count == 0) throw std::out_of_range ("Linked List");
        if(head == current) throw string("The list has not been initialized");
        
        //loop through LL
        for (int i = 1; i <= ndx; i++) {
            current = current->next;
            // cout << "at(i) works" << endl;
        }
    }
    
    //catch any thrown OOR
    catch (std::out_of_range oR) {
        throw oR;
    }
    
    //catch any thrown strings
    catch (string a)
    {
        throw a;
    }
    
    //catch any unknown erros
    catch(...)
    {
        throw;
    }
    
    return current->info;
}


template <typename F>
ostream& operator<<(ostream& os, const LL<F> &rhsObj){
    
    if (rhsObj.count == 0) cout << "bruh" << endl;
    
    for (int i = 1; i <= rhsObj.size(); i++)
    {
        os << /*"this is item " << i-1 << ": " <<*/ rhsObj.at(i-1);
    }
    return os;
}










/****************************************************************************
 **                                                                        **
 **                    class Polynomial<T> Declaration                     **
 **                                                                        **
 ****************************************************************************/

template <typename T>
class Polynomial : LL<Term> {
    
    
    template <typename F>
    friend ostream& operator<<(ostream& os, const Polynomial<F> &rhsObj);
    
private:
    
public:
    Polynomial<Term>();
    
    LL_iterator<Term> begin() const {return LL_iterator<Term>(head->next);}
    LL_iterator<Term> end() const {return LL_iterator<Term>(head->prev /*sentinal node*/ );}
    LL_iterator<Term> header() const {return LL_iterator<Term>(head);}
   
    void insert(Term);
    
    Polynomial<Term> operator+(const Polynomial<Term>&);
    Polynomial<Term> operator-(const Polynomial<Term>&);
    Polynomial<Term> operator*(const Polynomial<Term>&);

    void print() const{cout << *this << endl;}
    
    unsigned long size() const {return count;}
};



/****************************************************************************
 **                                                                        **
 **                    class Polynomial<T> implementation                  **
 **                                                                        **
 ****************************************************************************/

template<>
Polynomial<Term>::Polynomial() : LL<Term>() {}

template<>
ostream& operator<<(ostream& os, const Polynomial<Term> &rhsObj){
    LL_iterator<Term> iter = rhsObj.end();
    
    while (iter != rhsObj.header())
    {
        if ((*iter).coef != 0) {
            os << *iter;
         
            if (iter != rhsObj.begin())
            {
                os << " + ";
            }

        }
                --iter;
    }
    
    return os;
}


template<>
void Polynomial<Term>::insert(Term t){
    Node<Term> *current = head->next;
    
    while(current != head && (current->info).degree < t.degree)
    {
        current = current->next;
        //cout << current->info.coef << " " << current->info.degree << endl;
    }
    // cout <<  "current: " << current->info.coef << " t: " << t.coef << endl;
    if((current->info).degree == t.degree && this->size() != 0)
    {
        Term temp(((current->info).coef + t.coef), t.degree);
        current->info = temp;
        //cout << "in if before else replacinf one" << endl;
    }
    else
    {
        current = current->prev;
        
        Node<Term> *toInsert = new Node<Term>(t, current->next, current);
        
        current->next->prev = toInsert;
        current->next = toInsert;
        count++;
        //cout << "in adding in insert" << endl;
    }
    
    
    
}



template<>
Polynomial<Term> Polynomial<Term>::operator+(const Polynomial<Term> &second){
    
    Polynomial<Term> result;
    
    LL_iterator<Term> iter1 = this->begin();
    LL_iterator<Term> iter2 = second.begin();
    //(--iter1);
    //cout << *iter1 << endl;
    int size;
    if(second.size() > this->size())
        size = this->size();
    else
        size = second.size();
    
    int pos1 = 0;
    int pos2 = 0;
    
    while ((iter1 != this->header()) || (iter2 != second.header())){
        
        //cout << "deg1 " << (*iter1).degree << " & deg2 " << (*iter2).degree << endl;
        if((*iter1).degree == (*iter2).degree)
        {
            int i = (*iter1).coef + (*iter2).coef;
            //cout << i << endl;
            Term t(i, (*iter1).degree);
            result.insert(t);
            ++iter1;
            ++iter2;
            pos1++;
            pos2++;
        }
        
        else if((*iter1).degree > (*iter2).degree)
        {
            while((*iter1).degree > (*iter2).degree &&
                  (iter2 != second.header()))
            {
                Term t((*iter2).coef, (*iter2).degree);
                result.insert(t);
                ++iter2;
                //cout << *iter2 << endl;
                pos2++;
            }
            
        }
        
        
        else if((*iter1).degree < (*iter2).degree)
        {
            while((*iter1).degree < (*iter2).degree &&
                  (iter1 != this->header()))
            {
                Term t((*iter1).coef, (*iter1).degree);
                result.insert(t);
                ++iter1;
                //cout << *iter2 << endl;
                pos1++;
            }
            
        }
        
        if (pos1 == this->size() || pos2 == second.size())
        {
            if(pos1 < this->size())
            {
                //cout << "pos1: " << pos1<< " pos2: " << pos2 << endl;
                while (pos1 < this->size())
                {
                    //cout << pos1 << endl;
                    Term t((*iter1).coef, (*iter1).degree);
                    result.insert(t);
                    ++iter1;
                    pos1++;
                }
            }
            else if (pos2 < second.size())
            {
                //cout << pos2 << endl;
                while (pos2 < second.size())
                {
                    Term t2((*iter2).coef, (*iter2).degree);
                    result.insert(t2);
                    ++iter2;
                    pos2++;
                }
            }
        }
        
        
    }
    
    // cout << term1.size() << endl;
    // cout << term2.size() << endl;
    
    return result;

}



template<>
Polynomial<Term> Polynomial<Term>::operator-(const Polynomial<Term> &subterhend){
    
    Polynomial<Term> result;
    
    LL_iterator<Term> iter = subterhend.begin();
    while(iter != subterhend.header())
    {
        
        (*iter).coef = -1*(*iter).coef;
        //cout << (*iter) << endl;
        ++iter;
    }
    
    result = *this + subterhend;
    
    
    
    return result;
}


template<>
Polynomial<Term> Polynomial<Term>::operator*(const Polynomial<Term>& second){
    
    Polynomial<Term> result;
    
    Polynomial<Term> const *sizeS;
    Polynomial<Term> const *sizeL ;
    
    if(second.size() > this->size())
    {
        sizeS = this;
        sizeL = &second;
        
    }
    else
    {
        sizeS = &second;
        sizeL = this;
        //cout << sizeL->size() <<endl;
    }
    
    LL_iterator<Term> iterL = sizeL->begin();
    LL_iterator<Term> iterS = sizeS->begin();
    
    //cout << sizeS->size() << endl;
    
    for(int i = 0; i < sizeL->size(); i++)
    {
        //cout << "end" << endl;
        for (int j = 0; j < sizeS->size(); j++) {
            //cout << (*iterL).coef << " " << (*iterS).coef << endl;
            int coef = (*iterL).coef * (*iterS).coef;
            //cout << coef << endl;
            int deg = (*iterL).degree + (*iterS).degree;
            
            Term t(coef, deg);
            result.insert(t);
            
            ++iterS;
            // cout << "endin" << endl;
        }
        iterS = sizeS->begin();
        ++iterL;
        
    }
    
    
    return result;


}



#endif /* LL_h */
