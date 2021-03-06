// https://thispointer.com/how-to-put-a-thread-to-sleep-in-c11-sleep_for-sleep_until/
// https://thispointer.com/c11-multithreading-part-8-stdfuture-stdpromise-and-returning-values-from-thread/
// https://thispointer.com//c11-multithreading-part-9-stdasync-tutorial-example/
// https://thispointer.com/c11-multithreading-part-10-packaged_task-example-and-tutorial/



#include <thread>
#include <iostream>
#include <future>
#include <chrono>
#include <bits/stdc++.h>
using namespace std;

void initiazer(promise<int>* proObj) {
    //proObj->set_value(3);
    int run=0;
    while (1) {
        this_thread::sleep_for(chrono::milliseconds(200));
        cout<<"run="<<run<<"\n";
        run++;
        if (run == 5) proObj->set_value(3);
    }
}

int main() {
    promise<int> promiseObj;
    future<int> futureObj=promiseObj.get_future();
    thread th(initiazer, &promiseObj);

    // blocked here until value is set by promise object
    cout<<"ok get the value:"<<futureObj.get()<<"\n";
    th.join();
    return 0;
}
