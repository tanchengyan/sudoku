//
//  NumberSet.h
//  SudokuGame
//
//

#ifndef NUMBERSET_H
#define NUMBERSET_H

#include <string>

namespace cs32
{
    // a NumberSet is a collection of eight board numbers
    // it might represent a box, a row or a column
    // regardless of what it represents, it provides a
    // a way to match a potential additional value
    // against the numbers already in the NumberSet
    class NumberSet
    {
    public:
        /* a collection of eight board numbers to match against */
        NumberSet( );
        NumberSet( int one, int two, int three,
                  int four, int five, int six,
                  int seven, int eight );
        
        /* turn this NumberSet into a string */
        /* very handy for testing purposes */
        std::string stringify( ) const;
        
        // CS 32 TODO : CS 32 Students need to implement this operation
        /* is the passed value not already in the set? */
        bool        notFound( int value ) const;
        
    private:
        // the eight values in this NumberSet
        int mOne, mTwo, mThree, mFour, mFive, mSix, mSeven, mEight;
    };
}
#endif
