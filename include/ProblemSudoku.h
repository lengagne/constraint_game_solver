#ifndef __PROBLEMSUDOKU__
#define __PROBLEMSUDOKU__

#include "AbstractProblem.h"
#include "ConstraintAllInside.h"

class ProblemSudoku: public AbstractProblem
{
public:
    ProblemSudoku();
    
    unsigned int convert_index( unsigned int row,
                                unsigned int col);
    
    void set_initial ( unsigned int row, 
                       unsigned int col,
                       unsigned int value);

    virtual void show(const std::vector< std::vector< int> >& value);
        
};

#endif
