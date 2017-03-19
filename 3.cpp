vector < int > mystery(vector < string > letter) {
    vector<int> res;
    int n = letter.size();
     for(int k = 0 ;  k < n ; ++k)
     {
     string s1 = letter[k];
     int i = 0;
     int j = s1.length() - 1 ;
     int ans = 0 ;

     while(i <= j )
      {
          int max1 = max(letter[k][i],letter[k][j]) ;
          int min1 = min(letter[k][i],letter[k][j]) ;
          ans = ans + (max1 - min1) ;
          i++;
          j--;
   
      }
         res.push_back(ans);
     }
    return res;

}
