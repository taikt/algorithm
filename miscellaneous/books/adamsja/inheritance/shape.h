/* File: shape.h
 *
 * Author: Deitel & Deitel
 * Contributors: J. Adams
 * Description:  This class defines an abstract shape
 * Revisions:
 * 	$Log$
 */

#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
/* Name: area
 * 
 * Description: calculate the area of a shape
 * Arguments: none 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   virtual double area() const { return 0.0; }

/* Name: volume
 * 
 * Description: calculate the volume of a shape
 * Arguments: none 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   virtual double volume() const { return 0.0; }

   // pure virtual functions overridden in derived classes
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
   virtual void printShapeName() const = 0;

/* Name: print
 * 
 * Description: print the values of a shape
 * Arguments: none 
 * Modifies: none
 * Returns: void
 * Pre: none
 * Post: none.
 * Exceptions: none
 */
   virtual void print() const = 0;
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
