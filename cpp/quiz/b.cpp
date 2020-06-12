#include <cstdio>
#include <memory>
#include <string>
using namespace std;

// printf("%d %d\n",x,y);
// printf("%d\n",x);
// printf("%s",x.c_str());
#if 0
int main () {
	return 0;
}
#endif

class MyMakeShared {
public:
    std::shared_ptr< MyMakeShared > getShared() {
        return std::shared_ptr< MyMakeShared>(this);
    }
};


int main () {
	
	MyMakeShared* myMakeShared = new MyMakeShared ();
    auto mPtr1 = myMakeShared->getShared();
    auto mPtr2 = myMakeShared->getShared();	

	return 0;
}


