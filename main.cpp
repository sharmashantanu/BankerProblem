#include <iostream>
#include <conio.h>
#include <cstdlib>
#include<stdlib.h>
#include<windows.h>

using namespace std;

int main()
{
    int p,r,all[100][100],mx[100][100],avil[100],p1,r1[100],need[100][100],work[100],finish[100],seq[100],k=0;
    char ch;
    cout<<"\n\n\n\n\t\t\t\tBANKER'S PROBLEM\n\n\n\n\n\n";
    cout<<" Enter the number of processes : ";
    cin>>p;
    cout<<"\n\n\n Enter the number of Resources : ";
    cin>>r;
    system("cls");
    cout<<"\n\n\n\t\t\t\tAvailable Array\n\n\n ";
    for(int i=0;i<r;i++)
    {
        cout<<"\n Enter the Available value for Resource "<<i+1<<" : ";
        cin>>avil[i];
    }
  //  system("cls");
    cout<<"\n\n\n\t\t\t\tAllocation Array\n\n\n ";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout<<"\n Enter the allocated instances of process "<<i+1<<" of resource type "<<j+1<<" : ";
            cin>>all[i][j];
        }
        cout<<endl;
        cout<<"------------------------------------------------------------------------";
        cout<<endl;
    }
  //  system("cls");
    cout<<"\n\n\n\t\t\t\tMaximum Array\n\n\n ";
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            cout<<"\n Enter the maximum instances needed by the process "<<i+1<<" of resource "<<j+1<<" : ";
            cin>> mx[i][j];
        }
        cout<<endl;
        cout<<"------------------------------------------------------------------------";
        cout<<endl;
    }
    for(int i=0;i<p;i++)
    {
        for(int j=0;j<r;j++)
        {
            need[i][j]=mx[i][j]-all[i][j];
        }
    }
   // system("cls");
    do
    {
        cout<<"\n\n\n\n Enter the process that wants to demand resource : ";
        cin>>p1;
        cout<<"\n\n Enter the resources - ";
        for(int i=0;i<r;i++)
        {
            cin>>r1[i];
        }
        int c=0,d=0;
        for(int i=0;i<r;i++)
        {
            if(r1[i]<=need[p1][i])
            c++;
        }
        for(int i=0;i<r;i++)
        {
            if(r1[i]<=avil[i])
            d++;
        }
        if(c!=r || d!=r)
            cout<<"\n\n\t\t\t Resource cannot be allocated!!!"<<endl;
        else if(c==r && d==r)
        {
            for(int i=0;i<r;i++)
            {
                avil[i]=avil[i]-r1[i];
                all[p1][i]=all[p1][i]+r1[i];
                need[p1][i]=need[p1][i]-r1[i];
            }
            for(int i=0;i<p;i++)
    {
        cout<<"Need array is:"<<endl;
        for(int j=0;j<r;j++)
        {
            cout<<need[i][j];
        }
        cout<<endl;
    }


            for(int i=0;i<r;i++)
            {
                work[i]=avil[i];
            }
            for(int i=0;i<p;i++)
            {
                finish[i]=0;
            }

            int flag1=0,flag=0,k=0;

            while(true)
            {
                flag=0;
                int f=0;
                for(int i=0;i<p;i++)
                {
                    int e=0;
                    for(int j=0;j<r;j++)
                    {
                        if(need[i][j]<=work[j])
                            e++;
                    }
                    if(e==r && finish[i]==0)
                    {
                        finish[i]=1;
                        for(int j=0;j<r;j++)
                        {
                            work[j]=work[j]+all[i][j];
                        }
                        seq[k]=i;
                        k++;
                        flag=1;
                        cout<<"avilable array is"<<endl;
                         for(int j=0;j<r;j++)
                        {
                            cout<<work[j];
                        }
                        cout<<endl;
                    }
                }
                for(int i=0;i<p;i++)
                {
                    if(finish[i]==1)
                        f++;
                }
                if(f==p)
                {
                    cout<<"\n\n\n\t\t\tProcess is SAFE!!";
                    flag1=1;
                    break;
                }
                else if(f!=p && flag==0)
                {
                    cout<<"\n\n\t\t\tProcess is UNSAFE!!"<<endl;
                    for(int i=0;i<r;i++)
                    {
                        avil[i]=avil[i]+r1[i];
                        all[p1][i]=all[p1][i]-r1[i];
                        need[p1][i]=need[p1][i]+r1[i];
                    }
                    /*for(int i=0;i<r;i++)
                    {
                        cout<<avil[i]<<" ";
                    }
                    cout<<endl;
                    for(int i=0;i<p;i++)
                    {
                        for(int c=0;c<r;c++)
                            cout<<all[i][c]<<" ";
                    }
                    cout<<endl;
                    for(int i=0;i<p;i++)
                        for(int h=0;h<r;h++)
                        cout<<need[i][h]<<" ";
                    */flag1=1;
                    break;
                }
            }
           // system("cls");
            cout<<"\n\n\n\n\n\n\t\t\t\tSAFE SEQUENCE\n\n\n\n\n\n";
            for(int i=0;i<k-1;i++)
            {
                cout<<"\t"<<seq[i]<<"\t-->";
            }
cout<<"avilable array is:"<<endl;
for(int i=0;i<r;i++)
{
    cout<<avil[i]<<"\t";
}
cout<<endl;
            if(k==p)
            cout<<"\t"<<seq[k-1];
        }
        Sleep(5000);
        //system("cls");
        cout<<"\n\n\n\n\n\n\n\t\t\t Want to Enter more request : ";
        cin>>ch;
    }while(ch=='y' || ch=='Y');
    return 0;
}





