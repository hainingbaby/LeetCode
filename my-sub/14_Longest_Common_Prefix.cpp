/**
 * 14. Longest Common Prefix

    Write a function to find the longest common prefix string amongst an array of strings.

    If there is no common prefix, return an empty string "".

    Example 1:

    Input: ["flower","flow","flight"]
    Output: "fl"
    Example 2:

    Input: ["dog","racecar","car"]
    Output: ""
    Explanation: There is no common prefix among the input strings.
    Note:

    All given inputs are in lowercase letters a-z.

 */

class Solution {
public:
    /**
     * [longestCommonPrefix description]
     * @hainingbaby
     * @Time        2019-04-10T20:07:06+0800
     * @param       strs                     [description]
     * @return                               lcp
     */
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size() == 0)
            return "";
        for(int i = 0; i < strs[0].length() ; i++){
            for(int j = 1; j < strs.size(); j++){
                if(strs[0][i] != strs[j][i] || i == strs[j].length())
                    return strs[0].substr(0,i);
            }
        }
        return strs[0];
    }
};