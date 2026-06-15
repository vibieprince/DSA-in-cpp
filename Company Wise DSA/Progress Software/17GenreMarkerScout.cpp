// Gene Marker Scout
// A genomics research lab is sequencing a long DNA strand to locate a specific set of genetic markers needed for a rare-disease study. The strand is represented as a string strand of nucleotide codes (uppercase and lowercase letters), and the required marker set is represented as a string markers — each character in markers is a code that must appear in the target segment, including duplicates (if markers contains the same code twice, the segment must contain it at least twice).

// Your task is to find the shortest contiguous segment of strand that contains every code in markers (with the required frequencies). If no such segment exists, return an empty string "".

// If there are multiple shortest segments of the same minimum length, return the one that starts at the leftmost position.

// Note: The matching is case-sensitive: 'A' and 'a' are different codes.

// Input Format Line 1: string strand — the full DNA strand being searched Line 2: string markers — the required marker codes (including possible duplicates) Output Format A single line: the shortest substring of strand that contains all characters of markers (with required frequencies), or "" if no such substring exists.

// Examples Example 1 Input:

// ADOBECODEBANC ABC Output: BANC

// Explanation:

// The strand is "ADOBECODEBANC" and the required markers are A, B, C. Several segments contain all three markers: "ADOBEC" (indices 0–5, length 6) "DOBECODEBA" is missing C at the right point — not valid without scanning further "CODEBA" — missing C? No: C(5), O(6), D(7), E(8), B(9), A(10) — has C, B, A. Length 6. "BANC" (indices 9–12, length 4) — contains B(9), A(10), N(11), C(12). Length 4. "BANC" is the shortest valid segment.

// Example 2 Input a a Output a

// Example 3 Input a aa Output ""

// Example 4 Input aa aa Output aa

// Example 5 Input aaflslflsldkalskaaa aaa Output aaa

// Example 6 Input thisisateststring tist Output tstri

// Constraints 1 <= strand.length <= 10^5 1 <= markers.length <= 10^5 strand and markers consist of uppercase and lowercase English letters. The answer is unique (if it exists) among all windows of minimum length (guaranteed by leftmost-first rule).

#include<iostream>
#include<climits>
#include<unordered_map>
using namespace std;

int main(){
    string strand,markers;
    cin>>strand>>markers;

    int n = strand.length();
    int need = markers.length();
    if(need>n){
        cout<<"";
        return 0;
    }

    unordered_map<char,int> map;
    for(char ch:markers)
        map[ch]++;

    int left=0,right=0,windowSize=INT_MAX,start=0,currentWS;
    while(right<n){
        char ch = strand[right];
        if(map[ch]>0)
            need--;
        map[ch]--;
        while(need==0){
            currentWS = right-left+1;
            if(windowSize>currentWS){
                windowSize = currentWS;
                start = left;
            }
            map[strand[left]]++;
            if(map[strand[left]]>0)
                need++;
            left++;
        }
        right++;
    }

    cout<< (windowSize ==INT_MAX ? "" : strand.substr(start,windowSize));
    return 0;
}