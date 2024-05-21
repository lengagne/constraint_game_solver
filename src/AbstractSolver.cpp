#include "AbstractSolver.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>


bool AbstractSolver::get_unique_solution( const std::vector< std::vector<int> > & soluce)
{
    for (int i=0;i<soluce.size();i++)
        if (soluce[i].size() !=1)
            return false;
    return true;
}

void AbstractSolver::set_problem( AbstractProblem* pb)
{
    pb_ = pb;
}

void AbstractSolver::solve()
{
    std::vector< std::vector<int> > soluce = pb_->get_init_value();
    std::vector< AbstractConstraint*> ctr = pb_->get_constraints();
    unsigned int nb_ctr = ctr.size();
    
    unsigned int cpt = 0;
    do
    {
        std::cout<<"Dealing with constraint "<< cpt%nb_ctr << " / "<< nb_ctr <<std::endl;
        while( ctr[cpt%nb_ctr]->constract(soluce));
        
        pb_->show(soluce);
        getchar();
        cpt++;
    }while(!get_unique_solution(soluce) );
    
    
}
