#include <iostream>
#include "AbstractSolver.h"
#include "ProblemSudoku.h"

int main(int argc, char** argv)
{       
        std::cout<<"Constraint Problem Solver"<<std::endl;
        std::cout<<"We start by considering Sudoku problem "<<std::endl;
        
        
        AbstractSolver* solver = new AbstractSolver();
        
        AbstractProblem* problem = new ProblemSudoku();
        
        solver->set_problem(problem);
        
        return 0;
} 
