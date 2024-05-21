#ifndef __ABSTRACTSOLVER__
#define __ABSTRACTSOLVER__

#include "AbstractProblem.h"

class AbstractSolver
{
public:
    
    bool get_unique_solution( const std::vector< std::vector<int> > & soluce);
    
    void set_problem( AbstractProblem* pb);
    
    void solve();
    
protected:
    AbstractProblem* pb_;
};

#endif
