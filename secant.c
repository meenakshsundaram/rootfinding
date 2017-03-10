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
        double secant(double val1,double val2,double(*fn)(void *,double),void *user,
                double tol,double vtol,double ftol,int maxiter,int *iter,int *error)
        {
                double fval1,fval2,val,fval;
                
                /* initialising iter and error to zero*/
                
                *iter=0;
                
                *error=0;
                /* finding the function values at these two locations */
                
                fval1 = (*fn)(user,val1);
                            
                fval2 = (*fn)(user,val2);
                
                /* locating the value close to the root*/
                if(fval1>fval2)
                {
                        val =val2;
                        fval =fval2;
                        
                }
                else
                {
                        val = val1;
                        fval = fval1;
                        val1 = val2;
                        fval1 = fval2;
                }        
                
                while(fabs(fval)>tol && (*iter)<maxiter)
                {                             

                            if (fabs(val-val1)<vtol)
                            {
                                *error =1;
                                /* the same point is reached*/
                                return val;
                            }    
                            
                            if (fabs(fval-fval1)<ftol)
                            {
                                *error = 2;
                                /* the slope is parallel to the x axis */
                                return val;
                            }    
                            
                            /* temporary storage of elements will be transferred to val1
                            and fval1 later after the calculation is done*/
                            
                            val2=val;
                            fval2=fval;
                            
                            /* the calculation is performed */
                           
                            val -= fval/(fval-fval1)*(val-val1);
                            fval = (*fn)(user,val);
                            
                            /* the previous value is transferred to val1 */
                            
                            val1=val2;
                            fval1=fval2;
                            
                            (*iter)++;
                                 
                }
                if ((*iter) == maxiter)
                   
                   *error = 3;
                   /* root did not converge within 
                   the provided no of maxiterations*/
                return val;
                
        }           
