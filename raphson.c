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


#include "rootfinding.h"


double raphson(double start,double (*fn)(void*,double),
    double (*dfn)(void*,double),void * user,double tol,double dtol,
        int maxiter,int *iter,int *error)
{
    
    double val,fval,dfval;
    
    /*
    
        val is for storing the root value which is going to be returned
        fval is the funciton value at that root
        dfval is the derivative at that location
        
    */
    *iter=0;
    
    *error=0;
    
    val = start;
    
    /* though start can be omitted it offers some clarity */
    
    
    do
    {
        fval = (*fn)(user,val);
        
        /*uncomment the below line and run test-raphson 
        to follow the iterations*/
        
       /* printf("\n%lf\t%lf",val,fval);*/
       
        if(fabs(fval)<tol) break;
    
        dfval = (*dfn)(user,val);
                
        /* begining the iteration the newton raphson step */
                     
        /* to check whether the slope turns out to be very huge that it becomes 
        infinity in the machine */
        if(finite(dfval))
        

                if (fabs(dfval)>dtol)
                {
                    
                                (*iter)++;
                
                                 val -= fval/dfval;
                                 
                                 /*uncomment the below line and run test-raphson 
                                         to follow the iterations*/
                                 
                                 /*printf("\n%lf\t%lf",val,0.000);*/
				 
                                 
                }        
                else
                {   
                                 
                    *error=1;
                    
                    /*division by near zero point is either a local max or 
                      min or a point of inflection cannot 
                      proceed further*/
                      
                    return val;
                    
                }
        
        else
        
        {
                
                *error=2;
                
                /*infinite value of derivative so transferring control back*/
                
                  return val;
        }    
                       
     }while ((*iter)<maxiter);    
     
     if ((*iter)==maxiter)
    
              *error =3;
         
         /*it did not converge within the maxiter no of iterations*/
         
     return val;
}
