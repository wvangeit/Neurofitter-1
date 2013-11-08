/******************************************************************************
* NOMAD -  Nonlinear Optimization for Mixed vAriables and Derivatives.        *
* Copyright (C) 2001-2004  Gilles Couture - Ecole Polytechnique,              *
*                          Charles Audet - Ecole Polytechnique,               *
*		           John Dennis - Rice University.                     *
*                                                                             *
* Author: Gilles Couture                                                      *
* �cole Polytechnique de Montr�al - GERAD                                     *
* C.P. 6079, Succ. Centre-ville, Montr�al (Qu�bec) H3C 3A7 Canada             *
* Tel:  (514) 340-6053 x6928                                                  *
* Email: Gilles.Couture@gerad.ca                                              *
* Fax: (514) 340-5665                                                         *
*                                                                             *
* This program is free software; you can redistribute it and/or               *
* modify it under the terms of the GNU General Public License                 *
* as published by the Free Software Foundation. You can find the              *
* GNU General Public License at:                                              *
*             http://www.gnu.org/copyleft/gpl.html                            *
*                                                                             *
* This program is distributed in the hope that it will be useful,             *
* but WITHOUT ANY WARRANTY; without even the implied warranty of              *
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the               *
* GNU General Public License for more details.                                *
*                                                                             *
* You should have received a copy of the GNU General Public License           *
* along with this program; if not, write to the Free Software                 *
* Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA. *
*                                                                             *
* You can find information on the NOMAD software at:                          *
*             http://www.gerad.ca/NOMAD/                                      *
******************************************************************************/

/* augmentedpoint.h -- class definition for AugmentedPoint. This class defines
   all the points generated by NOMAD. */

#ifndef _AUGMENTEDPOINT_H_
#define _AUGMENTEDPOINT_H_
#include "defines.h"
#include "point.h"

class AugmentedPoint
{
/* An AugmentedPoint object has the following data:
   - An enumeration, indicating the possible index values stored in
     'output_values'.
     'Fx' is for f(x): one f(x) is stored in every problem.
     'Sx' is for the surrogate function value, s(x). There can be zero or
     one (if the problem uses a surrogate) s(x) value stored in a problem.
     'Gx' is for the general constraints function values, gi(x). There can be
     zero, one or many gi(x) values stored in a problem.
   - a integer variable, 'output_dimension' contains the number of outputs for
     all augmented points in the run.
   - an array of integers, 'index', describes what kind of outputs are stored
     in the 'output_values' array for all augmeneted points.
   - an array of real numbers, 'output_values', contains the values of the
     outputs of the point.
   - A real number, Hx is the feasibility function value of the point. Feasible
     points have an Hx of 0, unfeasible points have an Hx > 0.
   - a pointer to a Point object. */
 private:
  enum {Fx, Sx, Gx};
  static unsigned int output_dimension;
  static const unsigned int * index;
  double * output_values;
  double Hx;
  Point * p;

  // The class methods are described in "augmentedpoint.cpp"
 public:
  AugmentedPoint(const unsigned int dim, const unsigned int out,
		 const unsigned int * out_index, double * coord,
		 const double * scales_add, const double * scales_mult);
  AugmentedPoint(const unsigned int dim, double * coord);
  AugmentedPoint(const AugmentedPoint & ap);
  ~AugmentedPoint();
  // This method returns the dimension of the point p.
  unsigned int getDimension() {return p->getDimension();}
  // This method returns 'output_dimension'.
  unsigned int getOutputDim() {return output_dimension;}
  int getPosition(const unsigned int val) const;
  // This method returns the point's array of real numbers.
  double * getPoint() {return p->getPoint();}
  // This method returns the point's outputs.
  double * getTruthValues() {return output_values;}
  // This method returns an output value, as specified by 'n'.
  double getOutput(const unsigned int n) {return output_values[n];}
  double getLow() const;
  double getHx();
  // This method sets the 'n'th output value to 'val'.
  void setOutput(const unsigned int n, const double val)
    {output_values[n] = val;}
  void setLow(const double val);
  void setHx(const double val);
  void operator=(const AugmentedPoint & ap);
  void update(const AugmentedPoint * ap);
  void show() const;
  void showHistory(ofstream & fout, const double * scales_add,
		   const double * scales_mult) const;
  void showResults(ofstream & fout, const double * scales_add,
		   const double * scales_mult) const;
};
#endif