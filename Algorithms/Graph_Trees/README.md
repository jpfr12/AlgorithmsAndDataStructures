# Graph and Tree Algorithms (Source: book "Competitive Programming 3")

---  

1. Breadth First Search (BFS):  

    * Breadth First Search—abbreviated as BFS—is another graph traversal algorithm. Starting from a distinguished source vertex, BFS will traverse the graph ‘breadth-first’. That is, BFS will visit vertices that are direct neighbors of the source vertex (first layer), neighbors of direct neighbors (second layer), and so on, layer by layer.  

    * BFS starts with the insertion of the source vertex s into a queue, then processes the queue as follows: Take out the front most vertex u from the queue, enqueue all unvisited neighbors of u (usually, the neighbors are ordered based on their vertex numbers), and mark them as visited. With the help of the queue, BFS will visit vertex s and all vertices in the connected component that contains s layer by layer. BFS algorithm also runs in O(V + E) and O(V^2) on a graph represented using an Adjacency List and Adjacency Matrix, respectively.  

2. Depth First Search (DFS):  

    * Depth First Search—abbreviated as DFS—is a simple algorithm for traversing a graph. Starting from a distinguished source vertex, DFS will traverse the graph ‘depth-first’. Every time DFS hits a branching point (a vertex with more than one neighbors), DFS will choose one of the unvisited neighbor(s) and visit this neighbor vertex. DFS repeats this process and goes deeper until it reaches a vertex where it cannot go any deeper. When this happens, DFS will ‘backtrack’ and explore another unvisited neighbor(s), if any.  

    * The time complexity of this DFS implementation depends on the graph data structure used. In a graph with V vertices and E edges, DFS runs in O(V + E) and O(V^2) if the graph is stored as Adjacency List and Adjacency Matrix, respectively.  

3. Topological Sort:  

    * Topological sort(or topological ordering) of a Directed Acyclic Graph (DAG) is a linear ordering of the vertices in the DAG so that vertex u comes before vertex v if edge(u→v)exists in the DAG. Every DAG has one or more topological sorts.  

---  

* Problems you can solve using these algorithms:  

    - "1-D Frogger (Easy)", link: https://open.kattis.com/problems/1dfroggereasy  

        - BFS on 1D array

    - "Help Clotilde", link: https://www.beecrowd.com.br/judge/en/problems/view/1910  

        - BFS on 1D array  

    - "Connected Components", link: https://www.beecrowd.com.br/judge/en/problems/view/1082  

        - can be solved with either DFS or BFS  

    - "Knight Moves", link: https://www.beecrowd.com.br/judge/en/problems/view/1100  

        - BFS single source on 2D array  

    - "Level Order Tree Traversal", link: https://www.beecrowd.com.br/judge/en/problems/view/1466  

        - BFS on trees  

    - "Cyanide Rivers", link: https://open.kattis.com/problems/cyaniderivers  

        - BFS multi source on 1D array  

    - "Grid", link: https://open.kattis.com/problems/grid?tab=submissions  

        - BFS shortest path on 2D array  

    - "Knight Jump", link: https://open.kattis.com/problems/knightjump  

        - BFS shortest path on 2D-array (single source)  

    - "Zoning", link: https://open.kattis.com/problems/zoning?tab=metadata  

        - BFS multi-souce on 2D array  

    - "10 Kinds of People", link: https://open.kattis.com/problems/10kindsofpeople  

        - BFS, colouring a 2D array and/or flood-fill  

    - "Forever Winter", link: https://codeforces.com/contest/1829/problem/F  

        - BFS/DFS on trees. Might be handy to know "Centroid Decomposition", but it is not necessary to pass this problem.  

    - "Longest Flight Route", link: https://cses.fi/problemset/task/1680  

        - Requires "Topological Sort" in order to your program run in the time limit given.  



