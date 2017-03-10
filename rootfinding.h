/*
 *    This file is a part of the rootfinding libary. 
 *    rootfinding is free software: you can redistribute it and/or modify
 *    it under the terms of the GNU Lesser General Public License as published by
 *    the Free Software Foundation, either version 3 of the License, or
 *    (at your option) any later version.
 *    rootfinding is distributed in the hope that it will be useful,
 *    but WITHOUT ANY WARRANTY; without even the implied warranty of
 *    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *    GNU Lesser General Public License for more details.
 *
 *    You should have received a copy of the GNU Lesser General Public License
 *    along with rootfinding.  If not, see <http://www.gnu.org/licenses/>.
 *
 *    Copyright 2009 Meenakshi Sundaram   
*/



#ifndef ROO_T_FINDING_H
#define ROO_T_FINDING_H


/*
*************************
	Root finding routines
*************************
*/

#ifdef _cplusplus
	extern "C"{
#endif
#include <math.h>
    
/*////////////////////////////////////////////////////////////////////////////*/

    /* Sign Finding Routine */                         
        int sign(double value);
/* this returns +1 if the number is positive and -1 if 
the number is negative and 0 if the number is zero  */

/*////////////////////////////////////////////////////////////////////////////*/



/*////////////////////////////////////////////////////////////////////////////*/

    /*	Bisection Routine	*/
        double bisection(double hi,double lo,double (*fn) (void *,double),void *
                user,double tol,int maxiter,int *iter,int *error );
        /*
        hi, lo: 
            the bracketing interval
        double (*fn)(void*,double):
             the single valued function whose root is to be found
        void * user :
            is to pass other parameters to the function
        tol:
            the tolerance or the accuracy till which the values is to be
            calculated
        maxiter:
            the number of iterations that are to be done if the funciton does 
            converge
        iter:
            to pass details on the number of iterations that were done
        error:
            to pass the error details
            
            0- when root is found properly
            
            1- when bracketing  interval is not found. Return value is NaN
            
            2- when root is not found within the max iterations specified
            
            */
            
/*////////////////////////////////////////////////////////////////////////////*/
        
/*////////////////////////////////////////////////////////////////////////////*/
        /*Newton Raphson Routine*/

    double raphson(double start,double (*fn)(void*,double),
        double (*dfn)(void*,double),void * user,double tol,double dtol,
                int maxiter,int *iter,int *error);
                
                /*
                start :
                    is the value that starting the iteration
                *fn :
                    is the function whose roots are to be found
                *dfn:
                    is the derivative of this function
                *user: 
                    contains the parameters to be passed to the funcitons
                tol:
                    the tolerance within which the root must be found
                dtol:
                    the tolerance for the derivative. when it is below 
                    the routine comes out
                maxiter:
                    the maximum iterations till which the iterations must 
                    proceed under no convergence
                *iter:
                    the number of iterations proceeded by the routine
                *error:
                    
                    error details are returned through this
                    
                    0-root found properly
                    
                    1-iteration could not proceed as the derivative 
                                        became nearly zero
                                        
                    2-iteration could not procedd as the derivative 
                                        became infinity
                                        
                    3-number of iterations exceed maxiter value
                    
                */
                
/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
            /*Secant method*/
            
    double secant(double val1,double val2,double(*fn)(void *,double),
        void *user,double tol,double vtol,double ftol,int maxiter,
            int *iter,int *error);
            
            /*
               val1,val2:
                   initial values provided by the user as starting
               fn       :
                    is the function whose roots are to be found
               *user    : 
                    contains the parameters to be passed to the funcitons
               tol:
                    the tolerance within which the root must be found
               vtol:
                    the tolerance for the values(the root values)
                    when the successive difference is below this the
                    routine comes out
               ftol:
                    the tolerance for the function values. 
                    when the successive difference is below this the routine 
                    comes out
               maxiter:
                    the maximum iterations till which the iterations must 
                    proceed under no convergence
               *iter:
                    the number of iterations proceeded by the routine
               *error:
                    error details are returned through this
                    
                    0-root found properly
                    1-succesive root values are nearly same
                    2-successive funciton values are nearly same
                    3-iterations didnot converge within the 
                    specified maxiterations
               */

/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
            /* Fixed Point Iteration */
    double fixedpointiteration(double start,double(*fn)(void *,double),
        void * user,double tol,int maxiter,int *iter,int *error);

            /*
               start:
                   initial value provided by the user as starting
               *fn      :
                    is the function whose fixed point iteration is to be done
               *user    : 
                    contains the parameters to be passed to the funcitons
               tol:
                    the tolerance within which the root must be found
               maxiter:
                    the maximum iterations till which the iterations must 
                    proceed under no convergence
               *iter:
                    the number of iterations proceeded by the routine
               *error:
                    error details are returned through this
                    
                    0-root found properly
                    1-iterations didnot converge within the 
                    specified maxiterations
               */

/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/
            /* Fixed Point Iteration  Aitkens acceleration*/
    double aitkens(double start,double (*fn) (void *,double),
        void * user,double tol,int maxiter,int *iter,int *error);
            /*
               start:
                   initial value provided by the user as starting
               *fn      :
                    is the function whose fixed point iteration is to be done
               *user    : 
                    contains the parameters to be passed to the funcitons
               tol:
                    the tolerance within which the root must be found
               maxiter:
                    the maximum iterations till which the iterations must 
                    proceed under no convergence
               *iter:
                    the number of iterations proceeded by the routine
               *error:
                    error details are returned through this
                    
                    0-root found properly
                    1-iterations didnot converge within the 
                    specified maxiterations
               */

/*////////////////////////////////////////////////////////////////////////////*/

/*////////////////////////////////////////////////////////////////////////////*/

    /*	Ridders Routine	*/
        double ridders(double hi,double lo,double (*fn) (void *,double),void *
                user,double tol,int maxiter,int *iter,int *error );
        /*
        hi, lo: 
            the bracketing interval
        double (*fn)(void*,double):
             the single valued function whose root is to be found
        void * user :
            is to pass other parameters to the function
        tol:
            the tolerance or the accuracy till which the values is to be
            calculated
        maxiter:
            the number of iterations that are to be done if the funciton does 
            converge
        iter:
            to pass details on the number of iterations that were done
        error:
            to pass the error details
            
            0- when root is found properly
            
            1- when bracketing  interval is not found. Return value is NaN
            
            2- when root is not found within the max iterations specified
            
            */
            
/*////////////////////////////////////////////////////////////////////////////*/

#ifdef _cplusplus
}
#endif
#endif /*!define (ROOT_FINDING_H)*/
