#ifndef LETTER_H
#define LETTER_H


#include <iostream>



class Letter
{
    char l;

    void initLetter();

public:
    Letter();
    virtual ~Letter();

    char getLetter();

};

#endif // LETTER_H
