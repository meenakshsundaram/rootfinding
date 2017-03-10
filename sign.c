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

int sign(double value)
{
	if (value > 0)
	return 1;
	else if (value < 0)
	return -1;
	else
	return 0;
}	
