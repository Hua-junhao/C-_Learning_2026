#include<iostream>
using namespace std;
int main()
{
    int N,M,X,Y;
    cin>>N>>M>>X>>Y;
    int x_min,x_max,y_min,y_max;
    for(int i=0;i<N;i++)
    {
        int a=0;
        cin>>a;
        if(i==0)
        {
            x_max=a;
            x_min=a;
            continue;
        }
        if(a>x_max)
        {
            x_max=a;
        }
        if(a<x_min)
        {
            x_min=a;
        }
    }
    for(int i=0;i<M;i++)
    {
        int a=0;
        cin>>a;
        if(i==0)
        {
            y_min=a;
            y_max=a;
            continue;
        }
        if(a>y_max)
        {
            y_max=a;
        }
        if(a<y_min)
        {
            y_min=a;
        }
    }
    int vx[2]={X,X};
    int vy[2]={Y,Y};
    if(x_min<X)
    {
        vx[0]=x_min;
    }
    if(x_max>X)
    {
        vx[1]=x_max;
    }
    if(y_min<Y)
    {
        vy[0]=y_min;
    }
    if(y_max>Y)
    {
        vy[1]=y_max;
    }
    if(vx[1] >= vy[0] && vy[1] >= vx[0])
    {
        cout<<X<<" and "<<Y<<": possible";
    }
    else{
        cout<<X<<" and "<<Y<<": impossible";
    }
    return 0;
}