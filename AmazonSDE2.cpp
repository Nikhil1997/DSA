#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> arr = {1,24,15,18,9};
  sort(arr.begin(), arr.end());
  int n = arr.size();
  int ans = INT_MAX;
  for(int i=1; i<n; i++) {
  int median = arr[i];
  int l = 0, r = n-1, minDiff = INT_MAX;
  while(l<r && l<i && r>i) {
   int mean = (arr[l]+arr[i]+arr[r]);
   int diff = abs(mean-3*median);
   if(diff<minDiff) minDiff = diff;
   else break;
   if(minDiff==0) break;
   if(mean>median) r--;
   else l++;
  }
  ans = min(ans, minDiff);
 }
 cout << ans;
 return 0;
}
