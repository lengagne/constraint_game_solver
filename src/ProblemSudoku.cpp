#include "ProblemSudoku.h"
#include <iostream>

#define RED "\e[0;31m"
#define GRN "\e[0;00m"



ProblemSudoku::ProblemSudoku()
{
    dim_ = 81;
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

    AbstractProblem::show();
    
    std::vector<int> values = get_vector_from_to(1,9);
    
    std::vector<unsigned int> indexes(9);
    // for each line    
    for (int i=0;i<9;i++)   
    {
        for (int j=0;j<9;j++)
        {
            indexes[j] = convert_index(i,j);
        }
        constraints_.push_back( new ConstraintAllInside(values,indexes));
    }
    // for each colonne    
    for (int i=0;i<9;i++)   
    {
        for (int j=0;j<9;j++)
        {
            indexes[j] = convert_index(j,i);
        }
        constraints_.push_back( new ConstraintAllInside(values,indexes));
    }
    
    // for each box
    for (int ii=0;ii<3;ii++)    for (int jj=0;jj<3;jj++)    
    {
        unsigned int cpt = 0;
        for (int i=0;i<3;i++)   for (int j=0;j<3;j++)
        {
            indexes[cpt++] = convert_index(3*ii+i,3*jj+j);
        }
        constraints_.push_back( new ConstraintAllInside(values,indexes));
    }
}



unsigned int ProblemSudoku::convert_index(  unsigned int row,
                                            unsigned int col)
{
    return row*9+col;
}


void ProblemSudoku::set_initial ( unsigned int row, 
                                  unsigned int col,
                                  unsigned int value)
{
    unsigned int index = convert_index(row,col);
    
    feasible_values_[index].clear();
    feasible_values_[index].push_back(value);
}

void ProblemSudoku::show(const std::vector< std::vector< int> >& value)
{   
    for (int i=0;i<9;i++)  
    {
        for (int k=0;k<3;k++)
        {
            for (int j=0;j<9;j++)
            {
                unsigned int index = convert_index(i,j);
                std::vector<int> c = value[index];
                for (int kk=0;kk<3;kk++)
                {
                    int v = k*3+kk+1;
                    bool is_in = false;
                    for (int p=0;p<c.size();p++)
                        if ( c[p] == v)
                            is_in = true;
                        
                    if (is_in)
                        std::cout<<GRN <<v;
                    else
                        std::cout<<RED <<v;
                }
                std::cout<<" ";
            }
            std::cout<<std::endl;
        }
        std::cout<<std::endl;
    }
}
