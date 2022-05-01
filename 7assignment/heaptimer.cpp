#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>
using namespace std;

void heapSort(int a[],int);
void percDown (int a[], int i, int n);
void swap(int *a, int *b);

int main()
{
  float times;
  int big;
  clock_t time1,time2;
  
  cout<<"What's the size of the array needed: "<<endl;
  cin>>big;
  while (cin.fail() == true)
    {
        cin.clear();
        cin.ignore(std::numeric_limits<int>::max(),'\n');
        cin>>big;
    }
  int array[big];
  int first = 0;
  int last = big-1;
  for (int i = 0; i<big; i++)
  {
    array[i] = (rand() %10);
  }
  time1 = clock();

  heapSort(array,big);

  time2 = clock();
  
  
  times = (static_cast <double> (time2) - static_cast <double> (time1) ) / CLOCKS_PER_SEC;

  cout<<"Heap sort time: "<<times<<" seconds."<<endl;
  


  return 0;
}

void heapSort(int a[], int size)
{
  for (int i=size/2-1; i>=0; --i)
    percDown(a,i,size);
  
  for (int j = size-1; j>0; --j)
  {
    swap(a[0], a[j]);
    percDown(a,0,j);
  }
}

void percDown(int a[],int i, int n)
{
  int child;
  int temp;
  for (temp = a[i]; 2*i+i <n; i = child)
  {
    child = 2*i+i;
    if (child != n-1 && a[child]<a[child +1])
      ++ child;
    if (temp < a[child])
      a[i] = a[child];
    else
      break;
  }
  a[i] = temp;
}

void swap(int *a, int *b)
{
  int* temp;
  temp = a;
  a = b;
  b = temp;
  return;
}