#include<bits/stdc++.h>
#include <pthread.h>
using namespace std;

void solve(int x)
{
    //prime checker
    //Write code
    for(int i=2;i*i<=x;i++)
    {
        if(x%i==0)  {cout<<x<<"is Not Prime\n";return ;}
    }
    cout<<x<<"is Prime\n";
    return ;

}
int main()
{
    int t;
    cin>>t;
    vector<thread> threads;
    for(int i=0;i<t;i++)
    {
        int x;
        cin>>x;
        threads.push_back(thread(solve,x));
    }
    for(auto &itr:threads)  itr.join();
    return 0;
}