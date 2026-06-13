// Problem Statement An archaeologist has uncovered an ancient stone tablet — a rectangular grid of carved symbols. Each cell of the tablet contains exactly one lowercase symbol. Adjacent symbols are considered connected if they share a horizontal or vertical edge.

// The archaeologist holds a glossary of sacred inscription words believed to be hidden within the tablet. A word is considered inscribed on the tablet if you can trace it by starting at any cell and moving to orthogonally adjacent cells, using each cell at most once per word trace.

// Given the tablet grid and the glossary, return all words from the glossary that are inscribed on the tablet, sorted in lexicographic order. Each word should appear in the output at most once, even if it can be traced along multiple paths.

// Input Format m n row_0 row_1 ... row_{m-1} k word_0 word_1 ... word_{k-1} Line 1: two integers m and n — the number of rows and columns of the tablet. Next m lines: each line is a string of exactly n lowercase letters representing one row of the tablet (no spaces). Next line: integer k — the number of words in the glossary. Next k lines: one word per line. Output Format Print all found words, one per line, in lexicographic (sorted) order. If no words are found, print nothing (empty output).

// Example 1 Input:

// 4 4 oath etae ihrs iflv 4 eat oath peas rain Output:

// eat oath Explanation:

// The tablet is:

// o a t h e t a e i h r s i f l v eat: Trace e@(1,3) → a@(1,2) → t@(0,2). Each step is orthogonally adjacent. Found. oath: Trace o@(0,0) → a@(0,1) → t@(0,2) → h@(0,3). Top row, left to right. Found. peas: Letter p does not appear on the tablet. Not found. rain: r@(2,2) is adjacent to h@(2,1), s@(2,3), i@(2,0)... none is a. Not found.

// Example 3 Input 3 3 cat ror dog 5 cat dog rod car tar Output cat dog rod Example 4 Input 3 4 abcd efgh ijkl 5 abc cfi aei ghl mnop Output abc cfi ghl Example 5 Input 2 3 aaa aaa 4 aa aaa aaaa aaaaa Output aa aaa aaaa aaaaa Example 6 Input 4 4 xyza bcde fghi jklm 6 xyz cde ghij klm abcf mnop Output cde klm xyz

// Constraints 1 <= m, n <= 12 Each tablet[i][j] is a lowercase English letter. 1 <= k <= 30000 1 <= len(word_i) <= 10 Total characters across all words in the glossary: <= 100000 All words in the glossary are distinct.
#include<iostream>
#include<vector>
using namespace std;

class Solution {
    struct TrieNode{
        bool eow;
        string word;
        TrieNode* children[26];
    };

    TrieNode* getNode(){
        TrieNode * newNode = new TrieNode();
        newNode->eow = false;
        newNode->word = "";
        for(int i=0;i<26;i++)
            newNode->children[i] = NULL;
        return newNode;
    }

    void insert(TrieNode* root, string word){
        TrieNode* crawler = root;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            if(crawler->children[ch-'a']==NULL)
                crawler->children[ch-'a'] = getNode();
            crawler = crawler->children[ch-'a'];
        }
        crawler->eow=true;
        crawler->word = word;
    }
public:
    vector<string> result;
    int m,n;
    vector<vector<int>> directions{{1,0},{-1,0},{0,1},{0,-1}};
    void findWords(vector<vector<char>>& board,int i,int j,TrieNode* root){
        if(i<0 || i>=m || j<0 || j>=n)
            return;
        if(board[i][j]=='$' || root->children[board[i][j]-'a']==NULL)
            return;
        root = root->children[board[i][j]-'a'];

        if(root->eow==true){
            result.push_back(root->word);
            root->eow = false;
        }

        char temp = board[i][j];
        board[i][j] = '$'; // marked visited

        // left,right,up,down
        for(vector<int> & dir : directions){
            int new_i = i+ dir[0];
            int new_j = j+ dir[1];

            findWords(board,new_i,new_j,root);
        }
        board[i][j] = temp; // marked unvisited
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size(); // row
        n = board[0].size(); // column

        TrieNode* root = getNode();

        for(string &word : words)
            insert(root,word);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                char ch = board[i][j];
                if(root->children[ch-'a']!=NULL)
                    findWords(board,i,j,root);
            }
        }
        return result;
    }
};

