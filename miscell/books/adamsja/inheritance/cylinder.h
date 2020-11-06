/* File: cylindr.h
 *
 * Author: Deitel & Deitel
 * Contributors: J. Adams
 * Description:  This class defines a cylinder
 * Revisions:
 * 	$Log$
 */

#ifndef CYLINDER_H
#define CYLINDER_H
#include <math.h>

#include "circle.h"


class Cylinder : public Circle {
public:
 /* Name: constructor
 * 
 * Description: Initalize the class attributes
 * Pre: none
 * Post: The attributes should represent the 
 *           default values.
 * Exceptions: none
 */
   Cylinder( double h = 0.0, double r = 0.0,
             int x = 0, int y = 0 )  : Circle( r, x, y ), height(h)   {  };

/* Name: setHeight
 * 
 * Description: set the height to a double
 * Arguments: a double 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   void setHeight( double newHeight) { 
     height = newHeight > 0 ? newHeight : 0; };

/* Name: getHeight
 * 
 * Description: get the height value
 * Arguments: none 
 * Modifies: none
 * Returns: double
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   double getHeight() const { return height; };

/* Name: area
 * 
 * Description: calculate the area of a cylinder
 * Arguments: none 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   virtual double area() const {
     // surface area of Cylinder
     return 2 * Circle::area() +
       2 * (2 * acos(0.0)) * getRadius() * height;
   };

/* Name: volume
 * 
 * Description: calculate the volume of a cylinder
 * Arguments: none 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   virtual double volume() const { return Circle::area() * height; };

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
     std::cout << "Cylinder: ";}

/* Name: print
 * 
 * Description: print the values of a cylinder
 * Arguments: none 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   virtual void print() const {
     Circle::print();
     std::cout << "; Height = " << height;
   };

private:
   double height;   // height of Cylinder
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
