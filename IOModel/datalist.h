/* 
 * Justin Ventura, 03/09/20
 * COSC320-002, Dr. Anderson
 * Project 1: datalist.h
*/

#ifndef DATALIST_H
#define DATALIST_H

template <class T>
class datalist {
private:
    node<T> * head;
    size_t listsize;
public:
    datalist();
    datalist(size_t size);
    datalist(const datalist<T> & list);
    ~datalist();

    void append();
    void remove();
    void operator=(const datalist<T> & list);
    T & operator[](size_t int);

};

#include "datalist.cpp"
#endif