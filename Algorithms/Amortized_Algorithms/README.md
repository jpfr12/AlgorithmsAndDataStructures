# Amortized Analysis  

* The time complexity of an algorithm is often easy to analyze just by examining the structure of the algorithm: what loops does the algorithm contain and how many times the loops are performed. However, sometimes a straightforwardanalysis does not give a true picture of the efficiency of the algorithm.  

* Amortized analysis can be used to analyze algorithms that contain operations whose time complexity varies. The idea is to estimate the total time used to all such operations during the execution of the algorithm, instead of focusing on individual operations.

---

1. Sliding Window  

    * A sliding window is a constant-size subarray that moves from left to right through the array. At each window position, we want to calculate some information about the elements inside the window.  

    * Time complexity: O(n)  

1.1. Exercises envolving *sliding window*:  

    - "Snowy Hill", link: https://codeforces.com/gym/104217/problem/E  (the slidingWindow file in this folder solves this problem)  

    - "Aliens at the train", link: https://www.spoj.com/problems/ALIEN/  

    - "subarrays", link: https://www.spoj.com/problems/ARRAYSUB/  

    - "Subarray Sums I", link: https://cses.fi/problemset/task/1660  

---  

2. Sweep Line  

    * A *sweep line* algorithm models a problem of a set of events that are processed in a sorted order. For example, suppose that there is a restaurant and we know the arriving and leaving times of all customers on a certain day. Our task is to find out the maximum number of customers who visited the restaurant at the same time.  

    * Time complexity: O(n)  

2.1. Exercises involving *Sweep Line*:  

    - "Number of Flowers in Full Bloom", link: https://leetcode.com/problems/number-of-flowers-in-full-bloom/?envType=daily-question&envId=2023-10-11  

    - "Firefly", link: https://open.kattis.com/problems/firefly  
