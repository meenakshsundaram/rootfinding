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
    
    double aitkens(double start,double (*fn) (void *,double),
        void * user,double tol,int maxiter,int *iter,int *error)
        {
            
            double  val,fval,val1,val2,val3,dval1,dval2,ddval,slope,err;
            
            val = start;
            fval = (*fn)(user,val);
            
            /*uncomment and use test-aitkens.c*/
           /* 
            printf("\n%lf\t%lf",val,fval);
            printf("\n%lf\t%lf",fval,fval);
            */
            *iter = 1;
            *error = 0;
            while(fabs(fval-val)>tol && (*iter)<maxiter)
            {
                val1 = fval;
                val2 = (*fn)(user,val1);
                val3 = (*fn)(user,val2);
            /*uncomment and use test-aitkens.c*/
              /*              
                printf("\n%lf\t%lf",val1,val2);
                printf("\n%lf\t%lf",val2,val2);
                printf("\n%lf\t%lf",val2,val3);
                printf("\n%lf\t%lf",val3,val3);
              */
                dval1 = val2 - val1;
                dval2 = val3 - val2;
                
                ddval = dval1-dval2;
                
                slope = dval2/dval1;
                
                err = dval1*dval1/ddval;
                
                val = val3 + slope*slope*err;
                
                fval = (*fn)(user,val);
    
           /*uncomment and use test-aitkens.c*/
            /*
              printf("\n%lf\t%lf",val,fval);
              printf("\n%lf\t%lf",fval,fval);
           */
           
                *iter+=3;  
            }
            if((*iter)==maxiter)
            
               *error = 1;
               /* not convergent within the given maxiteration */
               
            return fval;
        }    
