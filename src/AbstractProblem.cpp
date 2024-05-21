#include "AbstractProblem.h"


std::vector<int> AbstractProblem::get_vector_from_to( int from, int to)
{
    std::vector<int> out;
    
    for (int i=from;i<= to;i++)
        out.push_back(i);
    
    return out;
}


std::vector< AbstractConstraint*> AbstractProblem::get_constraints() const
{
    return constraints_;
}

std::vector< std::vector< int> > AbstractProblem::get_init_value() const
{
    return feasible_values_;
}

void AbstractProblem::show()
{
    show(feasible_values_);
}
