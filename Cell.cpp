//
//  Cell.cpp
//  SudokuGame
//
//

#include "Cell.h"

#include <iostream>

namespace cs32
{
    // default Cell constructor
    // since it has no arguments, we can declare an array of Cell's
    Cell::Cell()
    {
        mValue = 0;
        mImmutable = false;
    }

    // mutator method for the member mValue
    void Cell::setValue( int value )
    {
        mValue = value;
    }
    
    // stringify this Cell, turning 0's into    .
    std::string Cell::stringify() const
    {
        std::string s;
        if (mValue == 0)
        {
            s = ".";
        }
        else
        {
            s = s + std::to_string( mValue );
        }
        return( s );
    }
    
    // CS 32 TODO : CS 32 Students need to implement this operation
    // validates that the number is legal with no conflicts in the
    // passed box, row or column which means thisvalue should not be
    // found in the passed box, row or column
    // immutability should not be taken into consideration here
    // when thisvalue is zero, always return true
    bool Cell::isValueOK( int thisvalue, NumberSet box, NumberSet row, NumberSet column ) const
    {
        if (thisvalue==0){
            return true;
        }
        return box.notFound(thisvalue)&&row.notFound(thisvalue)&&column.notFound(thisvalue);
    }

    // called before the Board attempts to change a cell's value
    // when true, the Board will change the cell's value to thisvalue
    bool Cell::isOKToSetValue( int thisvalue, NumberSet box, NumberSet row, NumberSet column ) const
    {
        // thisvalue cannot be found any of the NumberSets passed here
        bool result = isValueOK(thisvalue, box, row, column);
        // in addition, this cell must not be immutable
        if (mImmutable)
        {
            result = false;
        }
        return( result );
    }
    
    // accessor method for member mValue
    int Cell::getValue() const
    {
        return( mValue );
    }
    
    // CS 32 TODO : CS 32 Students need to implement this operation
    // accessor method for member mImmutable
    bool Cell::isImmutable() const 
    {
        return mImmutable;
    }
    
    // CS 32 TODO : CS 32 Students need to implement this operation
    // mutator method for member mImmutable
    void Cell::setImmutable( bool i )
    {
        mImmutable = i;
    }

}
