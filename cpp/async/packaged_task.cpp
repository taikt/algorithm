// https://thispointer.com/c11-multithreading-part-10-packaged_task-example-and-tutorial/
#include <thread>
#include <thread>
#include <future>
#include <string>
#include <bits/stdc++.h>
using namespace std;

string getData(string token) {
    int run=0;
    while (1) {
        this_thread::sleep_for(chrono::milliseconds(200));
        cout<<"run="<<run<<"\n";
        run++;
        if (run == 5) {
            string data = "mydata" + token;
            return data;
        }
    }
}

int main() {
#if 0
    packaged_task<string(string)> task(getData);
    future<string> result = task.get_future();
    cout<<"I am waiting\n";
    thread th(move(task), "pending data");

    th.join();
    cout<<"ok:"<<result.get()<<"\n";
#endif // 0

#if 1
    // use lambda
    packaged_task<string(string)> task([](string token) {
        int run=0;
        while (1) {
            this_thread::sleep_for(chrono::milliseconds(200));
            cout<<"run="<<run<<"\n";
            run++;
            if (run == 5) {
                string data = "mydata" + token;
                return data;
            }
        }
    }
    );

    future<string> result = task.get_future();
    cout<<"I am waiting\n";
    thread th(move(task), "pending data");

    th.join();
    cout<<"ok:"<<result.get()<<"\n";
#endif // 1
    return 0;
}
