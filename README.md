# Local-Alignment-Problem  
algorithm，bioinfoematics，Dynamic programming  
/*  
author wangyang   
address School of computer science ,xidian university   
time 2018/10/5  
e-mail wangyang_cs2014@163.com  
this project is solve the problem that about longest common subsequence (LCS) problem.  
References "https://en.wikipedia.org/wiki/Smith%E2%80%93Waterman_algorithm".  
if you have any question ,plaese write letter give me for e-mail.    
welcome you visit;  
*/
# problem describe  
The Smith–Waterman algorithm performs local sequence alignment; that is, for determining similar regions between two strings of nucleic acid sequences or protein sequences. Instead of looking at the entire sequence, the Smith–Waterman algorithm compares segments of all possible lengths and optimizes the similarity measure.  
# Algorithm  
let A = a(i) i=1,2,3...N and B = b(j) ,j=1,2,3...M be the sequence to be aligned ,where n and m are the length of A and B respectively(分别地 apart).  
1 detemine the substitution(替代，replace) matrix and gap penalty scheme.  
scorevalue(a,b) - similarity score of the elements that constituted the two sequences
W(k) - the penalty of a gap that has length k
2 construct a scoring matrix H and initialize its frist row and frist column. the size of the scoring matrix is (n+1）*（m+1）.Note the 0-based indexing..
H(k,0) = H（0，l） = 0 for k=0--n,l=0--m;
3 fill the scoring matrix using teh equation below.  
H(i,j) = max(H(i-1,j-1)+scorevalue(a(i),b(j)),H(i-1,j)-W(K),H(i,j-1)-W(k),0)  
4 Traceback.  
