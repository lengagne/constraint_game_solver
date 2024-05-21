#ifndef __CONSTRAINTALLINSIDE__
#define __CONSTRAINTALLINSIDE__

#include "AbstractConstraint.h"

class ConstraintAllInside: public AbstractConstraint
{
public:
    ConstraintAllInside( const std::vector<int> & values,
                         const std::vector<unsigned int> & index);
    
    virtual bool constract(const std::vector< std::vector< int> >& input);
    
    virtual bool test(const std::vector< std::vector< int> >& input);
    
    
private:
    std::vector<int> values_;
    std::vector<unsigned int> index_;
    
};

#endif
