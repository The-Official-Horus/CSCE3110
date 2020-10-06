#include <iostream>
#include<sstream>
#include<fstream>
#include<string>
using namespace std;

// Insertion sort
void insertionSort(float arr[], int L, int H)
{
    float temp ;
    // Loop throuh out array from index value L+1
    for (int k = L + 1 ; k <= H ; k++)
    {
        // Current element
        temp = arr[k] ;
        // Element before current element
        int di = k - 1 ;
        // Check current element smaller than temp
        while (di >= L && arr[di] > temp)
        {
            // Move backward
            arr[di+1] = arr[di] ;
            di-- ;
        }
        //Now store temp value
        arr[di+1] = temp ;
    }
}

// Function to merge sorted lists
void merge(float arr[], int L, int H, int midIndex)
{
    int first = L;
    int last = midIndex + 1;
    // Create new array
    float * newarr = new float [H + 1];
    

    // Take two sorted array and combine elements to single array
    for (int ind = L; ind <= H; ind++) {
        if (first <= midIndex && (last > H || arr[first] <= arr[last]))
        {
            newarr[ind] = arr[first];
            first = first + 1;
        }

        else
        {
            newarr[ind] = arr[last];
            last = last + 1;
        }
  
    }
  
// Move remaining elements
    for (int ind = L ; ind <= H ; ind++) {
        arr[ind] = newarr[ind];
    }
}
// Function mergesort
void mergeSort(float arr[], int L, int H)
{
    // If the list size is atmost 6 call insertion sort
    if ( (H - L + 1) <= 6)
    {
        insertionSort(arr, L, H);
    }
    // Otherwise
    else
    {
        // Calculate middle index
        int midIndex = (H+L) / 2;
        
        // Call mergesort for other two parts of the list
        mergeSort(arr, L, midIndex);
        mergeSort(arr, midIndex+1, H);
        
        // Merge sorted sublist
        merge(arr, L, H, midIndex) ;
    }
}


main()
{
   // Open the input and output file
   ifstream fin("data1.txt");
   ofstream fout("out1.txt");
   string line;
   int count=0;
   // Read line by line
   while(getline(fin,line))
   {
       float arr[500];
       count=0;
       stringstream is(line);
       float value;
       // Read each values in the line to array
       while(is>>value)
       {
           arr[count++]=value;
       }
       // Mergesort the array
       mergeSort(arr,0,count-1);
       for(int k=0;k<count;k++)
       {
           // Write to the file
           fout<<arr[k]<<" ";
       }
      // cout<<endl;
       fout<<endl;
   }
}
