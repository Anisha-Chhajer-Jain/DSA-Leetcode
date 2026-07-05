class Solution {
public:
    bool wordPattern(string pattern, string s) {
      unordered_map<char,string> patternmatch;
      unordered_map<string,char>wordmatch;
      vector<string>words;
      string word;
      stringstream ss(s);
      while(ss >> word) words.push_back(word);
      if(pattern.size()!=words.size())
       return false;
      for(int i=0;i<pattern.size();i++){
        if((patternmatch.count(pattern[i])&& patternmatch[pattern[i]]!=words[i]) ||
        (wordmatch.count(words[i]) && wordmatch[words[i]]!=pattern[i]))
         return false;
        patternmatch[pattern[i]]=words[i];
        wordmatch[words[i]]=pattern[i];
      }
      return true;
    }
};