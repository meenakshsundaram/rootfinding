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

double fixedpointiteration(double start,double(*fn)(void *,double),
    void * user,double tol,int maxiter,int *iter,int *error)
    {
            double val,tmp;            

            tmp =start;
            
            val = (*fn)(user,start);
            
            *iter = 1;
            
            *error = 0;
            
            while(fabs(val-tmp)>tol && (*iter)<maxiter)
            {
                
               /* 
                printf("\n %lf \t %lf",tmp,val);
                printf("\n %lf \t %lf",val,val);  
                 added to visualise the iteration.. 
                use test_fixed and uncomment the printf statements 
                */
                
                
                (*iter)+=1;
                
                tmp = val;
                
                val = (*fn)(user,tmp);
                
            }
            
            if ((*iter) == maxiter)
            
               *error =1;
               
               /* did not converge within the 
               specified number of maxiterations*/
               
            return val;    
    }    
