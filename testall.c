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


/* test file for ridders method*/
#include <stdio.h>
#include <math.h>
#include "rootfinding.h"

double func(void * user,double x)
{
    /* Function */
    /* x^3+x-(*val)=0 */
    double * val;
    val= (double *)user;
    return x*(x*x+1.0)-(*val);
}

double dfunc(void * user,double x)
{
    /* Derivative Function */
    /* x^3+x-(*val)=0 */
    /* 3x^2+1 */
    double * val;
    val= (double *)user;
    return 3.0*x*x+1.0;
}

double fixedfunc(void * user,double x)
{
    /* Function for fixed point iteration*/
    /* x^3+x-*val=0 */
    double * val;
    val= (double *)user;
    return (*val)/(1+x*x);
}


int main()
{
    double user,root;
    int iter,error;
    user =1.0;
    double tol=1E-10;
    int maxiter=100;
    double hi=0.0;
    double lo=2.0;
    
    /* Test with bisection */
    root=bisection(hi,lo,func,&user,tol,maxiter,&iter,&error);
    printf("Bisection method: root=%4.10f\n iterations=%d\n error=%d\n",root,iter,error);
    
    /* Test with secant */
    root=secant(hi,lo,func,&user,tol,tol,tol,maxiter,&iter,&error);
    printf("Secant method: root=%4.10f\n iterations=%d\n error=%d\n",root,iter,error);
    
    /* Test with raphson */    
    root=raphson(lo,func,dfunc,&user,tol,tol,maxiter,&iter,&error);
    printf("Newton Raphson method: root=%4.10f\n iterations=%d\n error=%d\n",root,iter,error);
    
    /* Fixed Point iteration */
    root=fixedpointiteration(lo,fixedfunc,&user,tol,maxiter,&iter,&error);
    printf("Fixed Point Iteration method: root=%4.10f\n iterations=%d\n error=%d\n",root,iter,error);
    
    /* Aitkens acceleration for the fixed point iteration */
    root=aitkens(lo,fixedfunc,&user,tol,maxiter,&iter,&error);
    printf("Aitkens Acceleration: root=%4.10f\n iterations=%d\n error=%d\n",root,iter,error);
    
    /* Test with ridders */    
    root=ridders(hi,lo,func,&user,tol,maxiter,&iter,&error);
    printf("Ridders method: root=%4.10f\n iterations=%d\n error=%d\n",root,iter,error);
    
    return 0;
}        
