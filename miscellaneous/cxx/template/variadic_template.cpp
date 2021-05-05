#if 0
// https://www.geeksforgeeks.org/variadic-function-templates-c/

// C++ program to demonstrate working of
// Variadic function Template
#include <iostream>
using namespace std;

// To handle base case of below recursive
// Variadic function Template
void print()
{
    cout << "I am empty function and "
            "I am called at last.\n" ;
}

// Variadic function Template that takes
// variable number of arguments and prints
// all of them.
template <typename T, typename... Types>
void print(T var1, Types... var2)
{
    cout << var1 << endl ;

    print(var2...) ;
}

// Driver code
int main()
{
    print(1, 2, 3.14, "Pass me any "
              "number of arguments",
                  "I will print\n");

    return 0;
}

#endif

#if 1
#include <iostream>

using namespace std;

#include <iostream>

template <typename A>
A myMax(A a,A b)      //this is an overload, not specialization
{
   if (a>b)
      return a;
   else
      return b;
}

template <typename A, typename ... Args>
A myMax(A a, A b, Args ... args)
{
   return myMax(myMax(a,b),args...);
}

int main()
{
   std::cout<<myMax(1,5,2,9,20);
}

#endif
