void permute(string &str, int i, set<string> &ans) {
  if(i == str.length()) {
      ans.insert(str);
      return;
  }
  for(int j=i; j<str.length();j++) {
      swap(str[i], str[j]);
      permute(str, i+1, ans);
      swap(str[i], str[j]);
  }
}


vector<string> findPermutation(string &str) {
    // Code here there
    set<string> ans;
    permute(str, 0, ans);
    vector<string> result(ans.begin(), ans.end());
    return result;
}