class Solution {
public:
    int strStr(string haystack, string needle) {

        int idx = haystack.find(needle);

        if (idx == string::npos)  
        //Ye C++ ka special value hai.Iska matlab: string ni mili


            return -1;

        return idx;
    }
};