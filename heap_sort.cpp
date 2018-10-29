#include<iostream>
using namespace std;
void __swap(int *a,int*b)
{
  int temp=*a;
  *a=*b;
  *b=temp;
}

void max_hepify(int *a,int i,int heap_size)
{

     int l=2*i;
     int r=2*i+1;
   int largest;

   if(l<=heap_size&&a[i]<a[l])
         largest=l;
    else
         largest=i;
   if(r<=heap_size&&a[r]>a[largest])
   {
     largest=r;
   }

  if(largest!=i)
    {
      __swap(&a[i],&a[largest]);
      max_hepify(a,largest,heap_size);
    }

}
void print(int*a,int n)
{
  for(int i=1;i<=n;i++)
     cout<<a[i]<<" ";
}

void increment(int*a,int i,int key)
{
    if(key<a[i])
       cout<<"u are supposed to increment the value"<<endl;
    else
    { a[i]=key;

     while(i>1&&a[i/2]<a[i])
     {
        __swap(&a[i/2],&a[i]);
          i=i/2;
     }
    }
}






int main()
{
   int x,k;
   cout<<endl;
   cout<<"enter no of elment";
   cin>>x;
   int a[x+1];
   a[0]=-1;
   for(int i=0;i<x;i++)
   {
      int j=i+1;
       cin>>a[j];
   }
  cout<<"the given array is"<<endl;
      print(a,x);
   cout<<"@@@@@@@@@@@"<<endl;

  for(k=x/2;k>=1;k--)
   max_hepify(a,k,x);


   for(int i=x; i>=2; i--)
    {
      __swap(&a[1], &a[i]);
      max_hepify(a, 1, i-1);
    }


  print(a,x);

    cout<<endl;
    cout<<"enter no of times u want to increment the value"<<endl;
    int y;
    cin>>y;
    for(int i=0;i<y;i++)
    {
      cout<<"enteer ur choice of index to be changed"<<endl;
      int j;
      cin>>j;
      cout<<"now enter the value"<<endl;
      int val;
      cin>>val;
      increment(a,j,val);
      print(a,x);
    }

  
  
  
   return  0;
}
