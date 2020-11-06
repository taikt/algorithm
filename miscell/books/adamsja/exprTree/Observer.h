
class Observer
{
public:
  virtual void update (void) = 0;
};

class Concrete_Observer : public Observer
{
public:
  virtual void update (void) {
    // ..
  }
};

class Observer_Event_Handler : public Event_Handler
{
public:
  virtual register_handler (Observer *observer)
  {
    observer_map_.push_back (observer);
  }

  virtual remove_handler (Observer *observer)
  {
    observer_map_.erase (observer);
  }

  virtual handle_input (void)
  {
    std::for_each (observer_map_.begin (),
                   observer_map_.end (),
                   std::mem_fun_ptr (&Observer::update));
  }

private:
  std::vector <Observer *> observer_map_;
}

