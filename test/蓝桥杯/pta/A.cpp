#include <cstdio>
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
using namespace std;
using namespace std::chrono;
int main()
{
    freopen("data.out", r, stdin);

    int i = 0;
    time_point<high_resolution_clock> t = high_resolution_clock::now();

    cout << i << "\n";
    cout << duration_cast<microseconds>(high_resolution_clock::now() - t).count();
}