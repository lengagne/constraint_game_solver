#include "ProblemSudoku.h"
#include <iostream>

ProblemSudoku::ProblemSudoku()
{
    dim_ = 100;
    feasible_values_.resize(dim_);
    for (int i=0;i<dim_;i++)
        feasible_values_[i] = get_vector_from_to(1,9);
    
    set_initial(0,0,5);
    set_initial(0,1,3);
    set_initial(0,4,7);
    set_initial(1,0,6);
    set_initial(1,3,1);
    set_initial(1,3,1);
    set_initial(1,4,9);
    set_initial(1,5,5);
    set_initial(2,1,9);
    set_initial(2,2,8);
    set_initial(2,7,6);
    set_initial(3,0,8);
    set_initial(3,4,6);
    set_initial(3,8,3);
    set_initial(4,0,4);
    set_initial(4,3,8);
    set_initial(4,5,3);
    set_initial(4,8,1);
    set_initial(5,0,7);
    set_initial(5,4,2);
    set_initial(5,8,6);
    set_initial(6,1,6);
    set_initial(6,6,2);
    set_initial(6,7,8);
    set_initial(7,3,4);
    set_initial(7,4,1);
    set_initial(7,5,9);
    set_initial(7,8,5);
    set_initial(8,4,8);
    set_initial(8,7,7);
    set_initial(8,8,9);    

    show();
}



unsigned int ProblemSudoku::convert_index(  unsigned int row,
                                            unsigned int col)
{
    return row*10+col;
}


void ProblemSudoku::set_initial ( unsigned int row, 
                                  unsigned int col,
                                  unsigned int value)
{
    unsigned int index = convert_index(row,col);
    
    feasible_values_[index].clear();
    feasible_values_[index].push_back(value);
}

void ProblemSudoku::show()
{
    for (int i=0;i<10;i++)  
    {
        for (int j=0;j<10;j++)
        {
            unsigned int index = convert_index(i,j);
            std::vector<int> c = feasible_values_[index];
            
            if(c.size()==1)
                std::cout<<c[0];
            else 
                std::cout<<" ";
        }
        std::cout<<std::endl;
    }
}
