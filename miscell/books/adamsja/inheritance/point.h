/* File: point.h
 *
 * Author: Deitel & Deitel
 * Contributors: J. Adams
 * Description:  This class defines a circle
 * Revisions:
 * 	$Log$
 */

#ifndef POINT_H
#define POINT_H

#include <iostream>

#include "shape.h"

class Point : public Shape {
public:
/* Name: constructor
 * 
 * Description: Initalize the class attributes
 * Pre: none
 * Post: The attributes should represent the 
 *           default values.
 * Exceptions: none
 */
   Point( int aPoint = 0, int bPoint = 0 ): x(aPoint),
    y(bPoint)  { };  // default constructor

/* Name: setPoint
 * 
 * Description: set the point values
 * Arguments: two ints
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   void setPoint( int aPoint, int bPoint){
     x = aPoint;
     y = bPoint;
   };

/* Name: getX
 * 
 * Description: get the x value
 * Arguments: none 
 * Modifies: none
 * Returns: int
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   int getX() const { return x; }

/* Name: getY
 * 
 * Description: get the Y value
 * Arguments: none 
 * Modifies: none
 * Returns: int
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   int getY() const { return y; }

/* Name: printShapeName
 * 
 * Description: print the name of this shape
 * Arguments: none 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   virtual void printShapeName() const { 
     std::cout << "Point: "; }

/* Name: print
 * 
 * Description: print the values of a point
 * Arguments: none 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   virtual void print() const{
  std::cout << '[' << x << ", " << y << ']'; };

private:
   int x, y;   // x and y coordinates of Point
};

#endif                                          



/**************************************************************************
 * (C) Copyright 2000 by Deitel & Associates, Inc. and Prentice Hall.     *
 * All Rights Reserved.                                                   *
 *                                                                        *
 * DISCLAIMER: The authors and publisher of this book have used their     *
 * best efforts in preparing the book. These efforts include the          *
 * development, research, and testing of the theories and programs        *
 * to determine their effectiveness. The authors and publisher make       *
 * no warranty of any kind, expressed or implied, with regard to these    *
 * programs or to the documentation contained in these books. The authors *
 * and publisher shall not be liable in any event for incidental or       *
 * consequential damages in connection with, or arising out of, the       *
 * furnishing, performance, or use of these programs.                     *
 *************************************************************************/
