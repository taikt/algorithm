/* File: circle.h
 *
 * Author: Deitel & Deitel
 * Contributors: J. Adams
 * Description:  This class defines a circle
 * Revisions:
 * 	$Log$
 */

#ifndef CIRCLE_H
#define CIRCLE_H
#include <math.h>

#include "point.h"

class Circle : public Point {
public:

/* Name: constructor
 * 
 * Description: Initalize the class attributes
 * Pre: none
 * Post: The attributes should represent the 
 *           default values.
 * Exceptions: none
 */
 Circle( double r = 0.0, int x = 0, int y = 0 ) : 
  Point( x, y ), radius(r) {  };

/* Name: setRadius
 * 
 * Description: set the radius to a double
 * Arguments: a double 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   void setRadius( double rad) { 
     radius = rad > 0 ? rad : 0; 
   };

/* Name: getRadius
 * 
 * Description: get the radius value
 * Arguments: none 
 * Modifies: none
 * Returns: double
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   double getRadius() const { return radius; };

/* Name: area
 * 
 * Description: calculate the area of a circle
 * Arguments: none 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   virtual double area() const { return (2 * acos(0.0)) * radius * radius; };

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
     std::cout << "Circle: "; }

/* Name: print
 * 
 * Description: print the values of a circle
 * Arguments: none 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   virtual void print() const {
     Point::print();
     std::cout << "; Radius = " << radius;
   };

private:
   double radius;   // radius of Circle
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
