# Social Network Friend Suggestion using Graph Traversal (BFS/DFS)

## 📖 Project Overview
This mini project simulates a simple social network and suggests new friends using BFS and DFS graph traversal algorithms.

### Dataset
Uses the **SNAP Facebook Circles dataset** (https://snap.stanford.edu/data/egonets-Facebook.html).

Each line in the dataset represents a friendship connection between two users:
```
0 1
0 2
1 3
2 4
...
```

## ⚙️ How to Compile and Run
1. Compile the program:
   ```bash
   gcc friend_suggestion.c -o friend_suggestion
   ```
2. Run the executable:
   ```bash
   ./friend_suggestion
   ```
3. Input example:
   ```
   Enter dataset file name (e.g., facebook_edges.txt): facebook_edges.txt
   Enter user ID for friend suggestion: 1
   ```

## 🧠 Algorithms Used
- **BFS (Breadth-First Search)** to find friends of friends within 2 hops.
- **DFS (Depth-First Search)** to traverse connections recursively.

## 📦 Files Included
- `friend_suggestion.c` — Main source code.
- `README.md` — Documentation.

## 👨‍💻 Author
Your Name  
SRM TRP College, Department of CSE
