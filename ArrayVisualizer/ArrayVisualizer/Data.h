#ifndef DATA_H
#define DATA_H
#include <vector>
#include<string>
using namespace std;
namespace Data
{
	const vector<string> features = {
    "Sorting Algorithms",
    "String Algorithms",
    "Array Algorithms",
    "Stack Algorithms",
    "Queue / Priority Queue Algorithms",
    "Tree Algorithms",
    "Graph Algorithms",
    "Trie / Prefix Tree Algorithms",
    "Hashing / Hash Table",
    "Dynamic Programming Visualizer",
    "Recursion / Backtracking Visualizer",
    "Matrix / 2D Array Operations",
    "Number Theory / Math Algorithms",
    "Bit Manipulation Algorithms",
    "Save All Test Cases to Disk",
    "Restore Test Cases from Disk",
    "Settings / Animation Speed",
    "Reset Array / Data",
    "View Algorithm Info",
    "Exit"
    };

   string strToRev = "In a world full of GUIs, be a Linux terminal.";
   const vector<string> stringAlgorithms = {
    "Reverse String",
    "Character Frequency",
    "Palindrome Check",
    "Anagram Check",
    "Substring Search (Naive)",
    "KMP Pattern Search",
    "Longest Common Prefix (LCP)",
    "Longest Palindromic Substring",
    "Horspool Algorithm",
    "String Compression / Run Length Encoding",
    "Remove Duplicates from String",
    "Case Conversion (Upper/Lower)",
    "Check Subsequence",
    "Edit Distance (Levenshtein Distance)",
    "Longest Common Subsequence (LCS)",
    "Minimum Window Substring",
    "Palindrome Partitioning",
    "Group Anagrams",
    "Balanced Parentheses / Bracket Check",
    "Next Lexicographical Permutation",
    "Longest Substring Without Repeating Characters",
    "Word Break Problem",
    "Count Occurrences of Substring",
    "Frequency Sort of Characters",
};
    
    vector<string> sortingAlgorithms = {
        // Basic / Easy
        "Bubble Sort",
        "Selection Sort",
        "Insertion Sort",
        "Counting Sort",
        "Merge Sort",
        "Quick Sort",
        "Heap Sort",

        // Intermediate / Useful in CP
        "Radix Sort",
        "Bucket Sort",
        "Shell Sort",
        "Tim Sort",
        "Cocktail Shaker Sort",
        "Comb Sort",

        // STL / Language Features
        "std::sort (IntroSort)",
        "std::stable_sort (Merge Sort Variant)",
        "partial_sort",
        "nth_element"
    };


    vector<string> arrayAlgorithms = {
        // Basic / Fundamentals
        "Find Maximum / Minimum",
        "Find Sum / Prefix Sum",
        "Reverse Array",
        "Kadane's Algorithm (Max Subarray Sum)",
        "Subarray Sum Problems",
        "Two Pointers Technique",
        "Sliding Window",
        "Move Zeroes / Partitioning",

        // Intermediate / Common Patterns
        "Frequency Count / Hash Map in Array",
        "Sort Array / Custom Sort",
        "Merge Intervals",
        "Next Permutation / Previous Permutation",
        "Dutch National Flag Problem",
        "Prefix XOR / XOR Subarray Problems",

        // Advanced / Competitive Programming
        "Binary Search on Array / Answer",
        "Lower Bound / Upper Bound",
        "Count Inversions (Merge Sort Variant)",
        "Median of Two Sorted Arrays",
        "Maximum Sum Rectangle / Submatrix Sum",
        "Sliding Window Maximum / Minimum",
        "Sparse Table (Range Queries)",
        "Reservoir Sampling",
        "Longest Increasing Subsequence (LIS)",
        "Longest Bitonic Subsequence",
        "Maximum Circular Subarray Sum"
    };
vector<string> stackAlgorithms = {
    // Basic / Fundamentals
    "Push / Pop / Top / IsEmpty",
    "Reverse a Stack using Recursion",
    "Find Minimum / Maximum in Stack",
    "Stack using Array / Linked List",
    
    // Classic Interview / CP Problems
    "Balanced Parentheses / Brackets Check",
    "Next Greater / Smaller Element",
    "Previous Greater / Smaller Element",
    "Sort a Stack",
    "Evaluate Postfix Expression",
    "Convert Infix to Postfix",
    "Convert Infix to Prefix",
    "Implement Two Stacks in One Array",
    "Celebrity Problem (Stack Approach)",
    
    // Advanced / Competitive Programming
    "Largest Rectangle in Histogram",
    "Maximum Area of Binary Matrix",
    "Sliding Window Maximum using Stack",
    "Trapping Rain Water (Stack Approach)",
    "Stock Span Problem",
    "Minimum Stack (O(1) Min Retrieval)",
    "Monotonic Stack Problems",
    "Histogram / Skyline Problem",
    "Expression Evaluation with Variables",
    "Undo / Redo Functionality Simulation"
};
   

vector<string> queueAlgorithms = {
    // Basic / Fundamentals
    "Enqueue / Dequeue / Front / Rear / IsEmpty",
    "Circular Queue using Array",
    "Queue using Two Stacks",
    "Queue using Linked List",
    "Deque (Double-Ended Queue)",

    // Priority Queue / Heap Basics
    "Max Heap / Min Heap Operations",
    "Insert / Extract / Peek / Heapify",
    "Priority Queue using STL / Custom Comparator",

    // Classic Problems
    "Sliding Window Maximum using Deque",
    "First Non-Repeating Character in Stream",
    "Rotting Oranges Problem",
    "Task Scheduling with Cooldown",
    "Recent Counter / Hit Counter Simulation",
    "LRU Cache using Queue + HashMap",

    // Advanced / Competitive Programming
    "Kth Largest / Smallest Element",
    "Merge K Sorted Arrays",
    "Median in a Stream of Integers",
    "Sliding Window Median",
    "Top K Frequent Elements",
    "Minimum Cost to Connect Ropes / Stones",
    "Job Sequencing / Scheduling Problems",
    "Deque / Monotonic Queue Optimization Problems",
    "Dynamic Sliding Window / Online Algorithms"
};

vector<string> treeAlgorithms = {
    // Binary Tree Basics
    "Create / Insert / Delete Nodes",
    "Tree Traversals: Preorder, Inorder, Postorder (Recursive & Iterative)",
    "Level Order Traversal (BFS)",
    "Height / Depth of Tree",
    "Count Nodes / Leaf Nodes / Internal Nodes",
    "Maximum / Minimum Element in Tree",
    "Diameter of Binary Tree",
    "Mirror / Invert Binary Tree",
    "Check if Two Trees are Identical",
    "Lowest Common Ancestor (LCA) in Binary Tree",
    "Check if Tree is Balanced",
    "Check if Tree is Symmetric",

    // Binary Search Tree (BST)
    "Insert / Delete in BST",
    "Search in BST",
    "Find Min / Max in BST",
    "Inorder Predecessor / Successor",
    "Check if BST (Validate BST)",
    "Kth Smallest / Largest Element in BST",
    "Range Sum of BST",
    "BST to Sorted Doubly Linked List",

    // AVL Tree (Self-Balancing BST)
    "Insert in AVL Tree with Rotations (LL, RR, LR, RL)",
    "Delete in AVL Tree with Rotations",
    "Check Balance Factor",
    "Height / Depth Updates after Rotations",
    "Preorder / Inorder / Postorder Traversal in AVL",

    // Advanced / Competitive Programming
    "Serialize / Deserialize Binary Tree",
    "Maximum Path Sum in Binary Tree",
    "Sum of Nodes at Kth Level",
    "Boundary / Zigzag / Spiral Level Order Traversal",
    "Vertical Order Traversal",
    "Top / Bottom / Left / Right View of Tree",
    "Convert Binary Tree to BST",
    "Tree Flattening / Linked List Conversion",
    "Segment Tree using Binary Tree Concept"
};
vector<string> graphAlgorithms = {
    // Graph Basics
    "Graph Representation: Adjacency List / Matrix",
    "Graph Traversals: BFS / DFS (Recursive & Iterative)",
    "Count Connected Components",
    "Check for Cycles (Directed & Undirected)",
    "Topological Sort (Kahn's / DFS)",
    "Check Bipartite Graph",
    "Graph Coloring / 2-Color Problem",
    "Find Path / All Paths Between Nodes",

    // Shortest Path Algorithms
    "Dijkstra's Algorithm (Single Source Shortest Path)",
    "Bellman-Ford Algorithm (Handles Negative Weights)",
    "Floyd-Warshall Algorithm (All Pairs Shortest Path)",
    "SPFA (Shortest Path Faster Algorithm)",
    "A* Search Algorithm",

    // Minimum Spanning Tree (MST)
    "Kruskal's Algorithm",
    "Prim's Algorithm",
    "Boruvka's Algorithm",

    // Advanced / Competitive Programming
    "DFS Tree / Bridges / Articulation Points",
    "Strongly Connected Components (Kosaraju / Tarjan)",
    "2-SAT Problem Using SCC",
    "Eulerian Path / Circuit",
    "Hamiltonian Path / Circuit",
    "Maximum Flow (Ford-Fulkerson / Edmonds-Karp)",
    "Min-Cost Max Flow",
    "Bipartite Matching / Hungarian Algorithm",
    "Graph Compression / Condensation",
    "Tarjan's Offline LCA",
    "Tree Flattening / Binary Lifting (for LCA)",
    "Heavy-Light Decomposition (HLD)",
    "Centroid Decomposition",
    "Floyd-Warshall with Path Reconstruction",

    // Graph Tricks / Optimizations
    "Bitmask DP on Graphs",
    "Dynamic Connectivity",
    "Topological DP / DAG DP",
    "Graph Hashing / Isomorphism Check",
    "Shortest Path with Constraints / K Stops"
};
vector<string> hashingAndMapsAlgorithms = {
    // Basics
    "Frequency Map of Elements",
    "Counting Distinct Elements",

    // Medium Level Patterns
    "Two Sum using HashMap",
    "Longest Substring Without Repeating Characters",
    "Check Anagram using Hash",
    "Group Anagrams",
    "Count Subarrays with Same Prefix XOR",
    "Count Distinct in Every Window (Sliding Window + Hash)",

    // HashSet Usage
    "Check Duplicates in Array",
    "Find Missing & Repeating Number",
    "Union / Intersection of Arrays",
    "Longest Consecutive Sequence (HashSet Trick)",

    // Advanced / CP-Oriented
    "Robin Hood Hashing Concept",
    "Double Hashing (for string matching)",
    "Detect Substring Using Hash",
    "Longest Palindromic Substring Using Hash",
    "2D Hashing (for grids/matrix problems)",

    // Complex / Competitive Programming Level
    "Hash-based Cycle Detection",
    "HashMap for DP Memoization",
    "Hashing for State Compression",
    "Design LRU Cache (uses Hash + DLL)",
    "Design LFU Cache (Hash + MinHeap)",

    // Maps (Ordered)
    "Using map for coordinate compression",
    "Ordered map for interval merging",
    "Multimap for duplicate keys",

    // Unordered Map Tricks
};
vector<string> trieAlgorithms = {
    // Basic Trie Operations
    "Insert Word in Trie",
    "Search Word in Trie",
    "Delete Word from Trie",
    "Check if Prefix Exists",
    "Count Words with Given Prefix",
    "Count Total Words in Trie",

    // Intermediate / Common Problems
    "Autocomplete / Suggestion System",
    "Longest Common Prefix Using Trie",
    "Find All Words with Given Prefix",
    "Pattern Matching with Trie",
    "Implement Dictionary / Spell Checker",

    // Advanced / Competitive Programming
    "Trie + Bit Manipulation (Max XOR Subarray Problem)",
    "Compressed Trie / Radix Tree",
    "Suffix Trie Construction",
    "Palindrome Pair Detection Using Trie",
    "Word Search II (Matrix + Trie)",
    "Count Distinct Substrings Using Trie",
    "Trie for Efficient String Queries",
    "Dynamic Trie / Persistent Trie",

    // Optimizations / Tricks
    "Memory Efficient Trie (Using HashMap / Array)",
    "Implementing Trie with STL / Custom Class",
    "Merge Tries / Sub-Trie Operations",
    "Lazy Updates in Trie (for Range Queries)"
};

vector<string> dpAlgorithms = {
    // Basic / Fundamentals
    "Fibonacci Numbers (Recursive + Memoization + Tabulation)",
    "Climbing Stairs / Staircase Problem",
    "Factorial / Combinatorics using DP",
    "Coin Change (Min Coins / Number of Ways)",
    "Knapsack Problem (0-1 Knapsack / Fractional Knapsack)",
    "Minimum Path Sum in Grid",
    "Maximum Sum Subarray / Subsequence",

    // Intermediate / Classic Problems
    "Longest Common Subsequence (LCS)",
    "Longest Common Substring",
    "Longest Increasing Subsequence (LIS)",
    "Longest Bitonic Subsequence",
    "Edit Distance / Levenshtein Distance",
    "Palindrome Partitioning / Min Cuts",
    "Matrix Chain Multiplication",
    "Subset Sum Problem",
    "Partition Equal Subset Sum",
    "House Robber / Maximum Non-Adjacent Sum",

    // Advanced / Competitive Programming
    "DP on Trees (Max Path / Diameter / Subtree Sum)",
    "Bitmask DP (Traveling Salesman, Subset Problems)",
    "DP on Graphs (Shortest Paths / DAG DP)",
    "Knapsack Variants (Unbounded / Multi-dimensional)",
    "Maximum Profit Stock Problems",
    "Regular Expression / Wildcard Matching",
    "DP with Rolling Array / Space Optimization",
    "Egg Dropping Problem",
    "Weighted Job Scheduling / Task Scheduling",
    "DP with State Compression",

    // Optimizations / Tricks
    "Memoization vs Tabulation",
    "Prefix / Suffix Arrays in DP",
    "Cumulative Sum / Prefix Sum Optimization",
    "Monotonic Queue Optimization in DP",
    "Convex Hull Trick / DP Optimization Techniques"
};
vector<string> recursionBacktrackingAlgorithms = {
    // Basic / Fundamentals
    "Factorial Calculation",
    "Fibonacci Sequence",
    "Sum of Digits / Numbers",
    "Power / Exponentiation",
    "Reverse String / Array Recursively",
    "Check Palindrome Recursively",
    "Print All Subsets / Power Set",

    // Intermediate / Classic Backtracking
    "Permutations of Array / String",
    "Combinations / N Choose K Problems",
    "Subset Sum / Partition Problems",
    "Rat in a Maze / Pathfinding",
    "Sudoku Solver",
    "N-Queens Problem",
    "Word Search / Board Traversal",
    "Knight’s Tour Problem",
    "Maze with Obstacles",

    // Advanced / Competitive Programming
    "Hamiltonian Path / Cycle",
    "Graph Coloring / Backtracking on Graphs",
    "Palindrome Partitioning",
    "String Pattern Matching (with Recursion)",
    "Backtracking with Constraints / Pruning",
    "Word Break / Dictionary Problems",
    "Generate Valid Parentheses Combinations",
    "Tiling Problems / Domino Placement",
    "Lexicographically Smallest / Largest Sequence",
    "Optimization with Recursion + Memoization (Top-Down DP)",

    // Tricks / Tips
    "Pruning / Early Termination to Reduce Search Space",
    "Recursive + Bitmask Approach for Subsets / Combinations",
    "Recursive Backtracking with State Restoration",
    "Use Recursion Tree to Visualize Steps",
    "Convert Recursive Solutions to DP for Optimization"
};
vector<string> matrixAlgorithms = {
    // Basic / Fundamentals
    "Create / Print 2D Matrix",
    "Transpose of Matrix",
    "Rotate Matrix 90° / 180° / 270°",
    "Matrix Addition / Subtraction / Multiplication",
    "Check Symmetric / Skew-Symmetric Matrix",
    "Find Row / Column Sum / Max / Min",
    "Diagonal Sum / Trace of Matrix",
    "Search Element in 2D Matrix (Row & Column Sorted)",

    // Intermediate / Common CP Problems
    "Spiral Order Traversal",
    "Boundary / Perimeter Traversal",
    "Print / Fill Anti-Diagonals",
    "Matrix Chain Multiplication (DP)",
    "Count Number of Islands / Connected Components",
    "Flood Fill / Fill Region Problems",
    "Rotate Matrix in Place",
    "Zero Matrix / Set Rows and Columns to Zero",
    "Maximal Square / Rectangle in Binary Matrix",
    "Submatrix Sum Queries (Prefix Sum / Cumulative Sum)",

    // Advanced / Competitive Programming
    "Kadane’s 2D / Maximum Sum Submatrix",
    "DP on Grid (Min Path Sum / Max Path Sum)",
    "Unique Paths / Robot Grid Path Problems",
    "Shortest Path in Grid (BFS / Dijkstra)",
    "Word Search in Grid",
    "Connected Components in Graph via Matrix",
    "Dynamic Programming on 2D Matrix (Partitioning / Tiling)",
    "Matrix Exponentiation for Recurrence Problems",
    "Rotations / Reflections for Pattern Matching",
    "Convex Hull / Geometry Problems Using Matrix Coordinates",

    // Tricks / Optimization
    "Use Prefix / Suffix Sum to Reduce Complexity",
    "In-Place Operations to Save Space",
    "Bitmasking for Subsets in 2D Grid",
    "Sliding Window / Monotonic Queue in 2D Matrix",
    "Transform 2D Problems to 1D if Possible"
};

vector<string> numberTheoryAlgorithms = {
    // Basic / Fundamentals
    "Prime Number Check (Trial Division / Sieve)",
    "Sieve of Eratosthenes",
    "Sieve of Atkin",
    "Greatest Common Divisor (GCD) / Euclidean Algorithm",
    "Least Common Multiple (LCM)",
    "Modular Arithmetic (Addition, Subtraction, Multiplication)",
    "Modular Inverse (Fermat's / Extended Euclidean)",
    "Exponentiation (Iterative / Recursive / Modular Exponentiation)",
    "Factorial / nCr / nPr",

    // Intermediate / Common CP Problems
    "Prime Factorization",
    "Count Divisors / Sum of Divisors",
    "Euler’s Totient Function (Phi Function)",
    "Number of Coprimes",
    "Binary Exponentiation",
    "Modular Combinatorics (nCr % MOD)",
    "Chinese Remainder Theorem (CRT)",
    "Inclusion-Exclusion Principle",
    "GCD / LCM of Array",
    "Multiplicative Functions (Mobius / Divisor Functions)",

    // Advanced / Competitive Programming
    "Extended Euclidean Algorithm (Solve ax + by = gcd(a, b))",
    "Lucas Theorem (nCr mod p)",
    "Fermat’s Little Theorem",
    "Wilson’s Theorem",
    "Primality Testing (Miller-Rabin, Fermat Test)",
    "Discrete Logarithm Problems",
    "Modular Equations / Congruences",
    "Fast Fourier Transform (FFT) for Convolution",
    "Karatsuba Multiplication",
    "Chinese Remainder Optimization for Large Inputs",

    // Tricks / Optimization
    "Precompute Factorials / Inverses for nCr Queries",
    "Sieve Optimization (Segmented Sieve)",
    "Use Properties of Primes for Efficient Checks",
    "Avoid Overflow with Modular Arithmetic",
    "GCD / LCM Tricks for Large Numbers"
};

vector<string> bitManipulationAlgorithms = {
    // Basic / Fundamentals
    "Check if K-th Bit is Set / Unset",
    "Set / Unset / Toggle K-th Bit",
    "Count Number of Set Bits (Brian Kernighan’s Algorithm)",
    "Check if Number is Power of 2",
    "Find Rightmost Set Bit / Position",
    "Left Shift / Right Shift Operations",
    "Bitwise AND / OR / XOR / NOT",
    "Swap Two Numbers Using XOR",

    // Intermediate / Common CP Problems
    "Find Single Non-Repeating Element (XOR Trick)",
    "Find Two Non-Repeating Elements",
    "Find Missing Number in 1..N",
    "Subset Generation Using Bitmask",
    "Count Subsets with Given XOR / Sum",
    "Check if Two Numbers Have Opposite Signs",
    "Reverse Bits of a Number",
    "Detect if a Number is a Power of 4 / 8",
    "Find Only Set Bit (Isolate Rightmost 1)",

    // Advanced / Competitive Programming
    "Maximum XOR of Two Numbers in Array",
    "XOR of All Subarrays",
    "Bitmask DP (TSP, Subset Problems)",
    "Gray Code Generation",
    "Hamming Distance / Weight Problems",
    "Check if Two Numbers Differ by One Bit",
    "Fast Exponentiation Using Bits",
    "Counting Bits / Population Count Optimizations",
    "Bitwise Tricks for Swapping / Reversing / Rotations",
    "Dynamic Programming with Bitmask States",

    // Tricks / Optimization
    "Use XOR for Cancellation & Difference Detection",
    "Use AND to Mask / Check Bits",
    "Use OR to Set Bits Efficiently",
    "Use Bit Shifts Instead of Multiplication / Division",
    "Precompute Bit Counts for Optimization"
};
}
#endif // !DATA_H
