pair<int, int> findSimilarity(
    vector<int> arr1, vector<int> arr2, int n, int m) {
  map<int, bool> arr;
  for (int i = 0; i < n; i++) {
    arr[arr1[i]] = true;
  }
  int count = 0;
  for (int i = 0; i < m; i++) {
    if (arr[arr2[i]]) count++;
  }
  return {count, m + n - count};
}
