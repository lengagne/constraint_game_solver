#ifndef __ABSTRACTCONSTRAINT__
#define __ABSTRACTCONSTRAINT__

#include <vector>

class AbstractConstraint
{
public:
    virtual bool constract(const std::vector< std::vector< int> >& input) = 0;
    
    virtual bool test(const std::vector< std::vector< int> >& input) = 0;
    
protected:
    unsigned int nb_;
    
};

#endif
