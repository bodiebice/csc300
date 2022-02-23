// Bodie Bice
// CSC 300

#include <iostream>
#include <iomanip>
#include <ctime>
#include <limits>
using namespace std;

void mergeSort(int[], int, int);
void msort(int[], int, int, int);
void quicksort(int[], int, int);
int partition(int[], int, int);
void insertsort(int[]);

int main()
{
  float times[3];
  int big;
  clock_t time1,time2,time3,time4,time5,time6;
  
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
  int copy1[big];
  int copy2[big];
  for (int x = 0; x<big; x++)
  {
    copy1[x] = array[x];
    //copy2[x] = array[x];
  }

  //time1 = clock();
  //insertsort(array);
  //time2 = clock();
  //times[0] = (static_cast <double> (time2) - static_cast <double> (time1) ) / CLOCKS_PER_SEC;
  for (int y = 0; y<big; y++)
  {
    cout<<copy1[y]<<endl;
  }
  time3 = clock();
  mergeSort(copy1,first, last);
  for (int o = 0; o<big; o++)
  {
    cout<<copy1[o]<<endl;
  }
  time4 = clock();
  times[1] = (static_cast <double> (time4) - static_cast <double> (time3) ) / CLOCKS_PER_SEC;

  //time5 = clock();
  //quicksort(copy2,first,last);
  //time6 = clock();
  //times[2] = (static_cast <double> (time6) - static_cast <double> (time5) ) / CLOCKS_PER_SEC;

  cout<<fixed<<setprecision(2)<<"Insert Sort Time: "<<times[0]<<" seconds."<<endl;
  cout<<fixed<<setprecision(2)<<"Merge sort time: "<<times[1]<<" seconds."<<endl;
  cout<<fixed<<setprecision(2)<<"Quick sort time: "<<times[2]<<" seconds."<<endl;
  return 0;
}

void mergeSort(int array[], int first, int last)
{
  int middle;
  if (first!=last)
  {
    middle = (first+last)/2;
    mergeSort(array,first,middle);
    mergeSort(array,middle+1,last);
    msort(array,first,middle,last);
  }
}

void msort(int array[], int first, int middle, int last)
{
  int *temp;
  int f1 = first, l1 = middle;
  int f2 = middle + 1, l2 = last;
  int fTemp = 0;
  int numi = last-first+1;
  temp = new int[numi];

  // making the temp array dynamically allocated, need last-first +1 size.
  while ((f1<= l1)&& (f2<=l2))
  {  
    if ( array[ f1 ] < array[ f2 ] )
    {
      temp[ fTemp ] = array[ f1 ];
      ++f1;
    }
    else
    {
      temp[ fTemp ] = array[ f2 ];
      ++f2;
      ++fTemp;
    } 
  }
  for ( int i = f1; i <= l1; ++i )
  {
    temp[ fTemp ] = array[ i ];
    ++fTemp;
  }
  for ( int i = f2; i <= l2; ++i )
  {
    temp[ fTemp ] = array[ i ];
    ++fTemp;
  }
  for ( int i = first; i <= last; ++i )
  {
    array[ i ] = temp[ i-first ];
  }
  delete temp;
  return;
}

void quicksort(int array[],int left, int right)
{
  if (left<right)
  {
    //int pivotpos = partition(array, left, right);
    //quicksort(array, left, pivotpos-1);
    //quicksort(array,pivotpos,right);
  }
}

