#include "ConstraintAllInside.h"
#include <iostream>

ConstraintAllInside::ConstraintAllInside( const std::vector<int> & values,
                                          const std::vector<unsigned int> & index)
{
    values_ = values;
    index_ = index;  
    
    if(values_.size() != index_.size())
    {
        std::cerr<<"Error in file "<< __FILE__<< " at line "<< __LINE__<<std::endl;
        std::cerr<<"Size "<< values_.size()<<" is different from "<< index_.size()<<std::endl;
        std::exit(1);
    }
    nb_ = values_.size();
}

bool ConstraintAllInside::constract(const std::vector< std::vector< int> >& input)
{

        return false;
}

bool ConstraintAllInside::test(const std::vector< std::vector< int> >& input)
{
    for (int i=0;i<nb_;i++)
    {
        // looking for value 
        int value = values_[i];
                
        for (int j=0;j<nb_;j++)
        {
            bool found = false;
            unsigned int index = index_[j];
            unsigned int s = input[index].size();
            for (int k=0;k<s;k++)   if (input[index][k] == value)  
            {
                found = true; 
                break;
            }
            
            if (!found) return false;
        }
        return true;
    }
}


