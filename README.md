HeyWhereAreYouInConst
=====================
# Instroduction #
Check whether &amp; where a given numeric string is in the previous one hundred million decimal digits of constant Pi or E. 

# How To #
1. Compile the source code; 
2. Run it with your numeric sequence as the first and the only argument; 
3. Wait for the result. 

# Performance #
* Only accept 2~31 digits sequence(You can change this yourself); 
* Returns at most 32 results(You can change this yourself); 
* It only checks the previous 100000000 digits; 
* It hashes the sequence first, averagely O(n) complexity, and worst O(n^2) when a hardly happening event. And normally, perform better if sequence is longer. 

# To do #
* Optimize the I/O;
* Get included in PHP or some other. 

# Thanks to #
* The constant data is calculated by PiFast V4.3, very fast and space-saving. 
* Zikai Han provides technical support all the time.   

# Licence #
GPLv2. 