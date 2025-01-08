# Amortized Analysis (Common optimization techniques)  

* The time complexity of an algorithm is often easy to analyze just by examining the structure of the algorithm: what loops does the algorithm contain and how many times the loops are performed. However, sometimes a straightforwardanalysis does not give a true picture of the efficiency of the algorithm.  

* Amortized analysis can be used to analyze algorithms that contain operations whose time complexity varies. The idea is to estimate the total time used to all such operations during the execution of the algorithm, instead of focusing on individual operations.

---

* Sliding Window  

    * A sliding window is a constant-size subarray that moves from left to right through the array. At each window position, we want to calculate some information about the elements inside the window.  

    * Time complexity: O(n)  

* Exercises involving *sliding window*:  

    - "Snowy Hill", link: https://codeforces.com/gym/104217/problem/E  (the slidingWindow file in this folder solves this problem)  

    - "Aliens at the train", link: https://www.spoj.com/problems/ALIEN/  

    - "subarrays", link: https://www.spoj.com/problems/ARRAYSUB/  

    - "Subarray Sums I", link: https://cses.fi/problemset/task/1660  

    - "lineup (USACO 2011)", link: https://codebreaker.xyz/problem/lineup  

    - "Unique Snowflakes", from USACO 2006, link: https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2619  

        - You can see the problem text in the pdf located in this folder  

        - The cpp file named "uniqueSnowflakes" solves this problem  

    - "Three Parts of the Array", link: https://codeforces.com/contest/1006/problem/C  


---  

* Sweep Line  

    * A *sweep line* algorithm models a problem of a set of events that are processed in a sorted order. For example, suppose that there is a restaurant and we know the arriving and leaving times of all customers on a certain day. Our task is to find out the maximum number of customers who visited the restaurant at the same time.  

    * Time complexity: O(n)  

* Exercises involving *Sweep Line*:  

    - "Number of Flowers in Full Bloom", link: https://leetcode.com/problems/number-of-flowers-in-full-bloom/?envType=daily-question&envId=2023-10-11  

    - "Firefly", link: https://open.kattis.com/problems/firefly  

    - "A Furious Cocktail", link: https://open.kattis.com/problems/cocktail  

---

* Monotonic Stack  

    * A "monotonic stack" is a concept rather than a distinct data structure. It is a variation of the regular stack data structure that is used to solve specific problems more efficiently.  

    * In a monotonic stack, elements are stored in such a way that they either strictly increase or strictly decrease in order as you move from the bottom to the top of the stack. This property allows for efficient querying of nearest smaller or larger elements, finding maximum or minimum elements in sliding windows, and solving various other problems involving monotonic sequences.  

    * The monotonic stack concept does not change the underlying implementation of the stack data structure itself. It still supports the usual operations of push and pop, as well as querying the top element, but the elements are arranged in a particular order to facilitate efficient problem-solving.  

    * Time Complexity: O(n)  

* Exercises involving *Monotonic Stack*:  

    - "Largest Number", link: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/largest-number-7-eee0b7c3/  

    - "Jumpy Humpy", link: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/jumpy-humpy-5e0231d6/  

        - The file "jumpyHump.cpp" solves this problem.  

    - "Next Greater Element I", link: https://leetcode.com/problems/next-greater-element-i/description/  

    - "Good Indices", link: https://www.hackerearth.com/practice/data-structures/stacks/basics-of-stacks/practice-problems/algorithm/good-indices-c7058c9b/  

        - The file "goodIndices.cpp" solves this problem.  

    - "Daily Temperatures", link: https://leetcode.com/problems/daily-temperatures/description/  

    - "Nearest Smaller Values", link: https://cses.fi/problemset/result/9021150/  

    - "Look Up", from USACO 2009, link: https://www.luogu.com.cn/problem/P2947  

    - "K Consequal", link: https://csacademy.com/contest/archive/task/k-consequal/  

        - A similar problem was used in InfO(1) Cup 2019, "Treasure", and everyone can submit their solution at the following link: https://oj.uz/problem/view/info1cup19_treasure  

    