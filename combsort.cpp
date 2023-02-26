
// C++ Code for Comb Sort 
#include <iostream>
using namespace std;
// function to update gap value
int updateGap(int gap)
{ 
// Shrink gap by the shrink factor 
  gap = (gap * 10) / 13;
  // gap *= (1/1.3)
  if (gap < 1)
    return 1;
  else
    return gap;
}
// Function to sort arr[] using Comb Sort 
void combSort( int arr[], int n) 
{
  // initialize gap 
  int gap = n; // 1
  // Initialize swapped as true to make sure that the loop runs 
  bool swapped = true; // 1
  while (gap > 1 || swapped == true) // (1/1.3)log(n) || (1/1.3)^x * n > 1 || x ~ (1/1.3)log(1) - (1/1.3)log(n) || (1/1.3)log(1) - (1/1.3)log(n) + n
  {
    // Update gap value
    gap = updateGap(gap); // 0 - (1/1.3)log(n)
    swapped = false; // 0 - (1/1.3)log(n)
    // Compare all elements with current gap 
    for (int i = 0; i < (n - gap); i++) // (n - (1/1.3)^x n) * ((1/1.3)log(1) - (1/1.3)log(n)) + 1 || ... + (n - 1 + 1) * n
    {
      int temp; // (n - (1/1.3)^x n) * ((1/1.3)log(1) - (1/1.3)log(n))
      if (arr[i] > arr[i + gap]) // (n - (1/1.3)^x n) * ((1/1.3)log(1) - (1/1.3)log(n)) 
      {
        // Swap arr[i] and arr[i+gap] 
        temp = arr[i];
        arr[i] = arr[i + gap];
        arr[i + gap] = temp;
        swapped = true;
      }
    }
  }
  // (n - (1/1.3)^x n) * ((1/1.3)log(1) - (1/1.3)log(n))
  // Omega(n log(n))
  // O(n**2)
}
// Driver function
int main() {
  int arr[10] = {7, 5, 1, 50, 3, -20, 25, -4, 30, 0};
  int n = 10;
  combSort(arr, n);
  cout << "Sorted array" << endl;
  for (int i = 0; i < n; i++)
    cout << arr[i] << " ";
}        
