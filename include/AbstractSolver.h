#ifndef __ABSTRACTSOLVER__
#define __ABSTRACTSOLVER__

#include "AbstractProblem.h"

class AbstractSolver
{
public:
    
    void set_problem( AbstractProblem* pb);
    
protected:
    AbstractProblem* pb_;
};

#endif
