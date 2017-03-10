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
    
    double bisection(double hi,double lo,double (*fn) (void *,double),
        void * user,double tol,int maxiter,int *iter,int *error)
    {
        double mid,fmid;
        
        int shi,slo,smid;

        /* first to check whether the limits provided bracket the root*/
        
        *error =0;        /* error is initialise set to zero that is the no error flag*/
        *iter =0;         /* iteration is also set to zero*/
        
        /*finding the signs of the function value at the given location*/
        
        
        /* here 'mid' denotes the middle value and fmid the functional value at this location
        and 'smid' the sign value of the function value 'slo' the sign value of the function 
        at 'lo' and 'shi' the function values at 'hi'*/
        
        shi=sign((*fn)(user,hi));

        slo=sign((*fn)(user,lo));

        
        if (slo==0)
            return lo;
            /* root is lo itself*/
        if (shi==0)
            /*root is hi itself*/
            return hi;
        if (shi==slo)
        {
            *error =1;
            return 0.0/0.0;
            /* error 1 meaning the root is not bracketed*/
        }    
        
        /*if the control passes till this location then definitely the root is bracketed*/
        do
        {
            
            /* the bisection process*/
            mid=(hi + lo)/2;
            fmid=(*fn)(user,mid);
            smid=sign(fmid);

            /*incrementing the iteration values*/
            (*iter)++;
            if (smid==0)
            
            /*hit the root very nearly rare*/
            
                    return mid;
                       
            else if (smid!=slo)
            {
                /*change the bracket */
                    hi = mid;
                    shi=sign((*fn)(user,hi));       
            }    
            else
            {
                /*change the bracket*/
                    lo = mid;
                    slo=sign((*fn)(user,lo));
            }    
            
            
        }while( (fabs(fmid)>tol) && (*iter) < maxiter);
        
        if (*iter==maxiter)
           
           *error=2;
           /*not convergent within the given maxiter no of iterations*/
           
        return mid;  
    }    
