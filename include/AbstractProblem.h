#ifndef __ABSTRACTPROBLEM__
#define __ABSTRACTPROBLEM__

#include <vector>

class AbstractProblem
{
    
    virtual void show() = 0;
    
protected :
    unsigned int dim_;
    std::vector< std::vector< int> > feasible_values_;
    
// private:
    std::vector<int> get_vector_from_to( int from, int to);
    
};

#endif
