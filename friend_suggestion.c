#include <stdio.h>
#include <stdlib.h>

#define MAX_USERS 1000

typedef struct Node {
    int user;
    struct Node *next;
} Node;

Node *adjList[MAX_USERS];
int visited[MAX_USERS];

Node* createNode(int user) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->user = user;
    newNode->next = NULL;
    return newNode;
}

void addEdge(int u, int v) {
    Node *newNode = createNode(v);
    newNode->next = adjList[u];
    adjList[u] = newNode;

    newNode = createNode(u);
    newNode->next = adjList[v];
    adjList[v] = newNode;
}

void suggestFriendsBFS(int user) {
    int queue[MAX_USERS], level[MAX_USERS];
    int front = 0, rear = 0;

    for (int i = 0; i < MAX_USERS; i++) {
        visited[i] = 0;
        level[i] = -1;
    }

    visited[user] = 1;
    level[user] = 0;
    queue[rear++] = user;

    printf("\n🔹 Friend suggestions for User %d (BFS):\n", user);

    while (front < rear) {
        int current = queue[front++];
        Node *temp = adjList[current];

        while (temp != NULL) {
            int neighbor = temp->user;
            if (!visited[neighbor]) {
                visited[neighbor] = 1;
                level[neighbor] = level[current] + 1;
                queue[rear++] = neighbor;
                if (level[neighbor] == 2)
                    printf("👉 Suggest User %d (friend of friend)\n", neighbor);
            }
            temp = temp->next;
        }
    }
}

void dfsUtil(int user, int depth, int origin) {
    if (depth > 2) return;

    Node *temp = adjList[user];
    while (temp != NULL) {
        int neighbor = temp->user;
        if (!visited[neighbor]) {
            visited[neighbor] = 1;
            if (depth == 2)
                printf("👉 Suggest User %d (friend of friend)\n", neighbor);
            dfsUtil(neighbor, depth + 1, origin);
        }
        temp = temp->next;
    }
}

void suggestFriendsDFS(int user) {
    for (int i = 0; i < MAX_USERS; i++)
        visited[i] = 0;

    visited[user] = 1;
    printf("\n🔹 Friend suggestions for User %d (DFS):\n", user);
    dfsUtil(user, 1, user);
}

int main() {
    int u, v, userChoice;
    char filename[100];

    printf("Enter dataset file name (e.g., facebook_edges.txt): ");
    scanf("%s", filename);

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("❌ Unable to open file.\n");
        return 1;
    }

    while (fscanf(fp, "%d %d", &u, &v) == 2) {
        addEdge(u, v);
    }
    fclose(fp);

    printf("\n✅ Graph loaded successfully from %s\n", filename);
    printf("\nEnter user ID for friend suggestion: ");
    scanf("%d", &userChoice);

    suggestFriendsBFS(userChoice);
    suggestFriendsDFS(userChoice);

    return 0;
}
