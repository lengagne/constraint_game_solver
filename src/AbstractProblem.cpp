#include "AbstractProblem.h"


std::vector<int> AbstractProblem::get_vector_from_to( int from, int to)
{
    std::vector<int> out;
    
    for (int i=from;i<= to;i++)
        out.push_back(i);
    
    return out;
}
