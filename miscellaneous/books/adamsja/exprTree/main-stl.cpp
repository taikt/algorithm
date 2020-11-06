#include <iostream>
#include <functional>
#include <algorithm>
#include <memory>

#include "Expression_Tree.h"
#include "Options.h"
#include "Print_Visitor.h"

struct acceptor
{
  acceptor (Tree_Visitor &v): visitor_ (v) {}

  void operator () (TREE t) { t.accept (visitor_); }

  Tree_Visitor &visitor_;
};

int 
main (int argc, char *argv[])
{
  try 
    {
      // Create options class to parse command line options.
      std::auto_ptr<Options> options (Options::instance ());

      // Parse the command-line options. If the user requested help (via "-h"
      // or "-?") then print out the usage and return.
      if (!Options::instance ()->parse_args (argc, argv))
        return 0;

      std::cout << "--Testing options class (singleton)--\n\n";

      // Print out the options used.
      std::cout << "  traversal option: " << options->traversal_strategy ()
                << std::endl;
      std::cout << "  queue option: " << options->queue_type ()
                << std::endl << std::endl;

      // Use the factory to create the tree.
      TREE root_node = factory.make_tree ();

      std::cout << "Testing the Print_Visitor: " << std::endl;

      Print_Visitor visitor;

      // Use the STL for_each() algorithm.
      std::for_each (root_node.begin (Options::instance ()->traversal_strategy ()),
                     root_node.end (Options::instance ()->traversal_strategy ()),
                     acceptor (visitor)); 

      // Use an explicit for loop.
      for (TREE::iterator iter = root_node.begin (Options::instance ()->traversal_strategy ());
           iter != root_node.end (Options::instance ()->traversal_strategy ());
           ++iter)
        (*iter).accept (visitor);

      std::cout << std::endl;
    }
  catch (...)
    {
      std::cout << "some exception occurred" << std::endl;
    }

  return 0;
}
