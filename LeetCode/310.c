/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
typedef struct
{
    int val;
    struct Node *next;
}Node;

void make_connection(Node *connections, int y, int x)
{
    if(connections[y].val == -1)
    {
        connections[y].val = x;
        return;
    }

    Node *head = connections + y;
    Node *new_node = malloc(sizeof(Node));

    new_node->val = x;
    new_node->next = head->next;
    head->next = new_node;
}

void destroy_linked_list(Node *list)
{
    while(list)
    {
        Node *to_delete = list;
        list = list->next;
        free(to_delete);
    }
}

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize) {
    if(n <= 2)
    {
        *returnSize = n;
        int *early_return = malloc(sizeof(int) * n);
        for(int i =0;i < n;i++)
            early_return[i] = i;
        
        return early_return;
    }

    Node *connections = malloc(sizeof(Node) * n);
    int *node_degrees = malloc(sizeof(int) * n);
    memset(node_degrees,0, sizeof(int) * n);

    for(int i = 0;i < n;i++)
        connections[i] = (Node){-1,NULL};

    for(int i =0;i < edgesSize;i++)
    {
        make_connection(connections, edges[i][0], edges[i][1]);
        make_connection(connections, edges[i][1],edges[i][0]);
        node_degrees[edges[i][0]] += 1;
        node_degrees[edges[i][1]] += 1;
    }

    int *queue = malloc(sizeof(int) * (n +2));
    int tail = 0;
    int head = 0;

    int bfs_size = 0;
    int new_bfs = 0;
    int prev_bfs = 0;

    for(int i =0;i < n;i++)
    {
        if(node_degrees[i] == 1)
        {
            queue[head++] = i;
            bfs_size +=1;
            node_degrees[i] = 0;
        }
    }

    while(tail < head)
    {
        if(bfs_size == 0)
        {
            if(new_bfs > 0)
                prev_bfs = new_bfs;

            bfs_size = new_bfs;
            new_bfs = 0;
        }

        int node = queue[tail++];
        Node *list_head = (connections + node);
        bfs_size -= 1;

        while(list_head)
        {
            int connection = list_head->val;
            node_degrees[connection] -= 1;

            if(node_degrees[connection] == 1)
            {
                queue[head++] = connection;
                new_bfs += 1;
            }
            list_head = list_head->next;
        }
    }

    *returnSize = prev_bfs;
    int *return_arr = malloc(sizeof(int) * prev_bfs);
    for(int i  =1;i < prev_bfs + 1;i++)
        return_arr[i -1] = queue[head - i];

    free(node_degrees);
    free(queue);

    for(int i =0;i < n;i++)
        destroy_linked_list(connections[i].next);
    
    free(connections);

    return return_arr;
}
