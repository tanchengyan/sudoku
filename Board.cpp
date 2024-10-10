//
//  Board.cpp
//  SudokuGame
//
//
#include <iostream>
#include "Board.h"

namespace cs32
{
    
    Board::Board( )
    {
        // the default Cell constructor will be called on
        // every element of this Board's cell array
    }

    // stringify this Board, turning 0's into    .
    //   and using |s and -s between groups of three rows and columns
    std::string Board::stringify( ) const
    {
        std::string s = "";
        
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {

                s = s + mCells[ i ][ j ].stringify();
                if (j == 3 || j == 6)
                {
                    s = s + "|";
                }
            }
            if (i == 3 || i == 6)
            {
                s = s + "\n-----------";
            }
            s = s + "\n";
        }

        return( s );
    }
    

    Cell  Board::getValue( int row, int column )
    {
        return( mCells[ row ][ column ] );
    }

    // if the value is OKtoSet for the bounding box, row and column
    // of the Cell position specified, then change the corresponding
    // Cell's value to the parameter value and update the Cell's
    // immutability, if desired
    bool Board::acceptValue( int value, int row, int column, bool immutable )
    {
        bool result = false;
        
        NumberSet box = buildBox( row, column );
        NumberSet r = buildRow( row, column );
        NumberSet c = buildColumn( row, column );
        if (mCells[ row ][ column ].isOKToSetValue(value,box,r,c))
        {
            mCells[ row ][ column ].setValue( value );
            result = true;
        }
        if (immutable)
        {
            mCells[ row ][ column ].setImmutable( immutable );
        }
        return( result );
    }
    
    // CS 32 TODO : CS 32 Students need to implement this operation
    // return true if this Board is completed correctly
    // each cell must have a non-zero value
    // each cell must have a legal value when considering its
    //      row and column and bounding box
    bool Board::completed() const
    {
        for (int i =1;i<10;i++){
            for(int j = 1; j<10;j++){
                NumberSet box = buildBox(i,j);
                NumberSet row = buildRow(i,j);
                NumberSet column = buildColumn(i,j);
                if(mCells[i][j].getValue()==0 || !mCells[i][j].isValueOK(mCells[i][j].getValue(),box,row,column)){
                    return false;
                }

            }
        }
        return true;
    }
    
    // for testing purposes, allow for any Board configuration
    //     legal or otherwise
    void Board::cheat()
    {
        for (int i = 1; i <= 9; i++)
        {
            for (int j = 1; j <= 9; j++)
            {
                mCells[ i ][ j ].setValue( 3 );
            }
        }
    }

    void Board::cheat( std::string boardstring )
    {
        int row = 1;
        int column = 1;
        int integer = 0;
        for (size_t index = 0; index < boardstring.length(); index++)
        {
            char c = boardstring.at( index );
            switch( c )
            {
                case '|':
                    // go to next row... and reset the column back to zero!
                    row++;
                    column = 1;
                    break;
                    
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                case '8':
                case '9':
                    // set a value
                    // convert character to integer
                    integer = (c - '0');
                    mCells[ row ][ column ].setValue( integer );
                    // cheated values are supposed to be immutable
                    mCells[ row ][ column ].setImmutable( true );
                    column++;
                    break;
                    
                case '.':
                    // ignore value
                    // a valid letter which means blank
                    column++;
                    break;
                    
            }
        }
    }
    
    // create the NumberSet associated with the bounding box
    // for the row and column specified
    NumberSet Board::buildBox( int row, int column ) const
    {
        NumberSet set;
        int startingRow = 0, startingColumn = 0;
        int array[8];
        int counter = 0;
        int r = 0, c = 0;
        if (row <= 3)
        {
            startingRow = 1;
        }
        else if (row <= 6)
        {
            startingRow = 4;
        }
        else
        {
            startingRow = 7;
        }
        if (column <= 3)
        {
            startingColumn = 1;
        }
        else if (column <= 6)
        {
            startingColumn = 4;
        }
        else
        {
            startingColumn = 7;
        }
        
        for( int i = 0; i <= 2; i++ )
        {
            r = startingRow + i;
            for (int j = 0; j <= 2; j++)
            {
                c = startingColumn + j;
                if (r == row && c == column)
                {
                    
                }
                else
                {
                    array[ counter ] = mCells[ r ][ c ].getValue();
                    counter = counter + 1;
                }
            }
        }
        set = NumberSet( array[0], array[1], array[2],
                         array[3], array[4], array[5],
                         array[6], array[7] );
        return( set );
    }

    // create the NumberSet associated with the column
    // for the row and column specified
    NumberSet Board::buildColumn( int row, int column ) const
    {
        NumberSet set;
        int array[8];
        int counter = 0;
        
        for( int c = 1; c <= 9; c++ )
        {
            if (c == row)
            {
                
            }
            else
            {
                array[ counter ] = mCells[ c ][ column ].getValue();
                counter = counter + 1;
            }
        }

        set = NumberSet( array[0], array[1], array[2],
                         array[3], array[4], array[5],
                         array[6], array[7] );

        return( set );
    }
    
    // create the NumberSet associated with the row
    // for the row and column specified
    NumberSet Board::buildRow( int row, int column ) const
    {
        NumberSet set;
        int array[8];
        int counter = 0;
        
        for( int i = 1; i <= 9; i++ )
        {
            if (i == column)
            {
                
            }
            else
            {
                array[ counter ] = mCells[ row ][ i ].getValue();
                counter = counter + 1;
            }
        }

        set = NumberSet( array[0], array[1], array[2],
                         array[3], array[4], array[5],
                         array[6], array[7] );

        return( set );
    }

    // CS 32 TODO : CS 32 Students need to implement this operation
    // the Board evaluation function
    int Board::evaluate() const
    {
        int result = 0;

        for (int i =1;i<10;i++){
            for(int j = 1; j<10;j++){
                NumberSet box = buildBox(i,j);
                NumberSet row = buildRow(i,j);
                NumberSet column = buildColumn(i,j);
                if(mCells[i][j].getValue()!=0 && mCells[i][j].isValueOK(mCells[i][j].getValue(),box,row,column)){
                    result++;
                }

            }
        }

        if (result ==81){
            result = 100;
        }

        return( result );
    }
    
}
