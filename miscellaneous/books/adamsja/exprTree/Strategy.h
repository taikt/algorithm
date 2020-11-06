#ifndef _EXPRESSION_TREE_EVENT_HANDLER_H_
#define _EXPRESSION_TREE_EVENT_HANDLER_H_

#include "Event_Handler.h"
#include "Expression_Tree_Context.h"
#include "Expression_Tree_Command_Factory.h"

class Prompt_User_Strategy
{
};

/**
 * @class Expression_Tree_Event_Handler
 * @brief Provides an abstract interface for handling input events
 *        and commands associated with the expression tree application. 
 *
 *        This class plays the role of "event handler" in the Reactor
 *        pattern and defines methods for use in the Template Method
 *        pattern that is used to process user input commands. 
 *
 * @see   Verbose_Expression_Tree_Event_Handler and
 *        Macro_Command_Expression_Tree_Event_Handler.
 */
template <typename PROMPT_USER_STRATEGY,
          typename GET_INPUT_STRATEGY,
          typename MAKE_COMMAND_STRATEGY,
          typename EXECUTE_COMMAND_STRATEGY>
class Expression_Tree_Event_Handler : public Event_Handler
{
public:
  /// Constructor.
  Expression_Tree_Event_Handler (const PROMPT_USER_STRATEGY &pu_strategy,
                                 const GET_INPUT_STRATEGY &gi_strategy,
                                 const MAKE_COMMAND_STRATEGY &mc_strategy,
                                 const EXECUTE_COMMAND_STRATEGY &ec_strategy)
    : pu_strategy_ (pu_strategy),
      ....
  {
  }

  /// Dtor.
  virtual ~Expression_Tree_Event_Handler (void) = 0;

  /// Factory that creates the appropriate subclass of @a
  /// Expression_Tree_Event_Handler, i.e., @a
  /// Verbose_Expression_Tree_Event_Handler or @a
  /// Macro_Command_Expression_Tree_Event_Handler.
  static Expression_Tree_Event_Handler *make_handler (bool verbose)
  {
    if (!verbose)
          return new Expression_Tree_Event_Handler (verbose_prompt_strategy,
                                                    default_get_input_strategy,
                                                    macro_command_create_command_strategy,
                                                    ...
  }

  /// This method is called back by the reactor when input is
  /// available.  It is a template method that performs the sequence
  /// of steps associated with processing expression tree application
  /// commands.
  virtual void handle_input (void)
  {
    prompt_user ();

    std::string input;
  
    if (get_input (input) == false)
      Reactor::instance ()->end_event_loop ();
    
    Expression_Tree_Command command = make_command (input);
  
    try
      {
        if (execute_command (command) == false)
          Reactor::instance ()->end_event_loop ();
        else
          {
            last_valid_command_ = command;
            command.print_valid_commands ();
          }
      }
    catch (Expression_Tree::Invalid_Iterator e)
      {
        std::cout << "\nERROR: Bad traversal type (" << e.what() << ")\n";
        last_valid_command_.print_valid_commands ();
      }
    catch (Expression_Tree_State::Invalid_State e)
      {
        std::cout << "\nERROR: Can't call that command yet.\n";
        last_valid_command_.print_valid_commands ();
      }
  }

protected:
  /// This hook method is a placeholder for prompting the user for
  /// input.
  void prompt_user (void) 
  {
    pu_strategy_.prompt_user ();
  }

  /// This hook method gets user input.
  bool get_input (std::string &user_input)
  {
    gi_strategy_.get_input (user_input);
  }

  /// This hook method is a placeholder for making a command based on
  /// the user input.
  Expression_Tree_Command make_command (const std::string &user_input)
  {
    return mc_strategy.make_command (user_input)
  }

  /// This hook method executes a command.
  bool execute_command (Expression_Tree_Command &command)
  {
    return ec_strategy.execute_command (command);
  }  

  /// The context where the expression tree state resides.
  Expression_Tree_Context tree_context_;

  /// A factory for creating a command.
  Expression_Tree_Command_Factory command_factory_;
  
  /// Handle to last valid command that was executed.
  Expression_Tree_Command last_valid_command_;

  PROMPT_USER_STRATEGY pu_strategy_;
};

#endif /* _EXPRESSION_TREE_EVENT_HANDLER_H_ */
