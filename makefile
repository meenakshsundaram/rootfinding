 #
 #    This file is a part of the rootfinding libary. 
 #    rootfinding is free software: you can redistribute it and/or modify
 #    it under the terms of the GNU Lesser General Public License as published by
 #    the Free Software Foundation, either version 3 of the License, or
 #    (at your option) any later version.
 #    rootfinding is distributed in the hope that it will be useful,
 #    but WITHOUT ANY WARRANTY; without even the implied warranty of
 #    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 #    GNU Lesser General Public License for more details.
 #
 #    You should have received a copy of the GNU Lesser General Public License
 #    along with rootfinding.  If not, see <http://www.gnu.org/licenses/>.
 #
 #    Copyright 2009 Meenakshi Sundaram   
 #

CC = gcc
AR = ar
COMP_OPT = -Wall -lm -O2
CASES = rootfinding.a testall

FILES =  aitkens.o bisection.o fixedpointiteration.o raphson.o ridders.o secant.o sign.o

all: $(CASES)

testall: rootfinding.a testall.c
	$(CC) -o $(@) testall.c rootfinding.a $(COMP_OPT)

rootfinding.a: rootfinding.h $(FILES)
	$(AR) r $(@) $(FILES)

clean:
	rm *.o *.a testall
