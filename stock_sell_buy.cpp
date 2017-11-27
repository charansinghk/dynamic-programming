#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int maxProfit(int a[], int n) {

   int min_so_far = std::numeric_limits<int>::max();
   int result = 0;
   for (int i=0; i<n; i++) {
      int tmp = a[i] - min_so_far; // day's gain
      result = std::max(result, tmp);
      min_so_far = std::min(min_so_far, a[i]);
   }
   return result;
}

int main() {
   int a[] = {120, 300,325, 380, 100, 110, 150, 220};
   int n = 8;
   cout <<"Max profit = "<<maxProfit(a,n)<<endl;
   return 0;
}
