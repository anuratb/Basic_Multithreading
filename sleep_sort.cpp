/**
 * Sleep sort is a process where we sleep for time proportional
 * to x for each element x in array and then output that element to sort
 * P.S This prog faces some issues if the input numbers are disparate 
 * for eg. 10000000 , 9, 5 2
 */
#include<bits/stdc++.h>
#include<unistd.h>
#include <pthread.h>
using namespace std;
#define int long long int
int scaling = 1000000;
void slp(int x)
{
    //prime checker
    //Write code
    unsigned int tm_ = x;
    tm_*=scaling;
    usleep(tm_);
    for(int i=0;i<(tm_);i++);
    cout<<x<<"\n";
    return ;

}
signed main()
{
    int n;
    cin>>n;
    int mx = 1;
    vector<int> arr;
    for(int i=0;i<n;i++)
    {
        int x;
        cin>>x;
        mx = max(mx,x);
        arr.push_back(x);
    }
    scaling = (100000/mx);
    if(scaling==0)  scaling = 1;
    vector<thread> threads;
    for(int i=0;i<n;i++)
    {
        
        threads.push_back(thread(slp,arr[i]));
    }
    for(auto &itr:threads)  itr.join();
    return 0;
}