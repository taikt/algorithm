/**
 * Description: When a string is supplied, the method 
 * _Notify() is called, in order to notify all observers of the event's 
 * occurrence, in the form of an invocation of their 'update' methods - 
 * in our example, reset()
 */ 
#include <iostream>
#include <string>
#include <list>
 
class SupervisedString;
class IObserver{
public:
  virtual void handleEvent(const SupervisedString&) = 0;
};
 
class SupervisedString{ // Observable class
  std::string _str;
  std::list<IObserver*> _observers;
  
  typedef std::list<IObserver*>::iterator _iterator;
  
  void _Notify(){
    for(_iterator it = _observers.begin(); it != _observers.end(); it++)
      (*it)->handleEvent(*this);
  }
  
public:
  void add(IObserver& ref){
    _observers.push_back(&ref);
  }
  
  void remove(IObserver& ref){
    _observers.remove(&ref);
  }
  
  const std::string& get() const{
    return _str;
  }
  
  void reset(const std::string &str){
    _str = str;
    _Notify();
  }
};

class Reflector: public IObserver{ // Prints the observed string into std::cout
public:
  virtual void handleEvent(const SupervisedString& ref){
    std::cout << ref.get() << std::endl;
  }
};
 
class Counter: public IObserver{  // Prints the length of observed string into std::cout
  virtual void handleEvent(const SupervisedString& ref){
    std::cout << "length = " << ref.get().length() << std::endl;
  }
};
 
int main(){
 
  SupervisedString str;
  Reflector refl;
  Counter    cnt;
  
  str.add(cnt);
  str.add(refl);
  str.reset("Hello, World!");
  str.reset("test it");
  std::cout << std::endl;
  
  str.remove(refl);
  //str.add   (cnt);
  str.reset("World, Hello!");
  std::cout<<std::endl;
  
  return 0;
}
