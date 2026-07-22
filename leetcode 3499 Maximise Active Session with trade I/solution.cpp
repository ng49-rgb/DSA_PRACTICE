class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        // finding total 1 first
        int ones = 0;
        for(char ch : s){
            if(ch == '1') ones++;
        }

        string aug = "1" + s + "1";
        // prepare for runs
        vector<pair<char,int>> segments;
        for(char ch : aug){
            if(segments.empty() || segments.back().first != ch){
                segments.push_back({ch,1});
            }
            else segments.back().second++;
        }

        int gain = 0;
        // find max gain & neglect 1st and last segment as they have no neighbours.
        for(int i = 1; i+1<segments.size(); i++){
            if(segments[i].first == '1' && segments[i-1].first == '0' && segments[i+1].first == '0'){
                gain = max(gain, segments[i-1].second + segments[i+1].second);
            }
        }
        return gain + ones;
    }
};