#ifndef __ABSTRACTPROBLEM__
#define __ABSTRACTPROBLEM__

#include <vector>
#include "AbstractConstraint.h" 

class AbstractProblem
{
public:
    std::vector< AbstractConstraint*> get_constraints() const;
    
    std::vector< std::vector< int> > get_init_value() const;
    
    void show();
    
    virtual void show(const std::vector< std::vector< int> >& value) = 0;
    
protected :
    unsigned int dim_;
    std::vector< std::vector< int> > feasible_values_;
    
    std::vector< AbstractConstraint*> constraints_;
    
// private:
    std::vector<int> get_vector_from_to( int from, int to);
    
};

#endif
