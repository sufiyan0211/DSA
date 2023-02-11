vector<vector<string>> findSequences(string beginWord, string endWord, 
    vector<string>& wordList) 
{
    vector<vector<string>> ans;
    queue<vector<string>> q;
    q.push({beginWord});
    unordered_set<string> words(wordList.begin(), wordList.end());
    vector<string> usedOnLevel;
    usedOnLevel.push_back(beginWord);
    int level = 0;
    
    while(!q.empty()) {
        vector<string> vect = q.front(); 
        q.pop();
        
        if(vect.size() > level) {
            level++;
            for(auto it: usedOnLevel) {
                words.erase(it);
            }
        }
        
        string word = vect.back();
        if(word == endWord) {
            if(ans.size() == 0) {
                ans.push_back(vect);
            }
            else if(ans[0].size() >= vect.size()) {
                ans.push_back(vect);
            }
        }
        
        for(int i=0; i<word.size(); i++) {
            char original = word[i];
            for(char ch = 'a'; ch<='z'; ch++) {
                word[i] = ch;
                // if word exist is wordsList
                if(words.find(word) != words.end()) {
                    vect.push_back(word);
                    q.push(vect);
                    usedOnLevel.push_back(word);
                    vect.pop_back();
                }
            }
            word[i] = original;
        }
    }
    return ans;
}