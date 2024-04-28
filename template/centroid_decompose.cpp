/// Name: centroid_decompose
/// Guarantee: void decomposeTree(int root)
 
vector<int> tree[MX];
bool centroidMarked[MX];

int subtree_size[MX];
 
/* method to add edge between to nodes of the undirected tree */
void addEdge(int u, int v)
{
    tree[u].push_back(v);
    tree[v].push_back(u);
}
 
/* method to setup subtree sizes and nodes in current tree */
void DFS(int src,int parent)
{
    /* initialize subtree size for current node*/
    subtree_size[src] = 1;
 
    vector<int>::iterator it;
 
    /* recur on non-visited and non-centroid neighbours */
    for (it = tree[src].begin(); it!=tree[src].end(); it++)
        if (*it!=parent && !centroidMarked[*it])
        {
            DFS(*it, src);
            subtree_size[src]+=subtree_size[*it];
        }
}
 
int getCentroid(int src, int parent, int n)
{
    /* assume the current node to be centroid */
    bool is_centroid = true;
 
    /* track heaviest child of node, to use in case node is
       not centroid */
    int heaviest_child = 0;
 
    vector<int>::iterator it;
 
    /* iterate over all adjacent nodes which are children
       (not visited) and not marked as centroid to some
       subtree */
    for (it = tree[src].begin(); it!=tree[src].end(); it++)
        if (*it!=parent && !centroidMarked[*it])
        {
            /* If any adjacent node has more than n/2 nodes,
             * current node cannot be centroid */
            if (subtree_size[*it]>n/2)
                is_centroid=false;
 
            /* update heaviest child */
            if (heaviest_child==0 ||
                subtree_size[*it]>subtree_size[heaviest_child])
                heaviest_child = *it;
        }
 
    /* if current node is a centroid */
    if (is_centroid && n-subtree_size[src]<=n/2)
        return src;
 
    /* else recur on heaviest child */
    return getCentroid(heaviest_child, src, n);
}

void calc(int src,int parent, int depth)
{
   
    vector<int>::iterator it;
 
    /* recur on non-visited and non-centroid neighbours */
    for (it = tree[src].begin(); it!=tree[src].end(); it++)
        if (*it!=parent && !centroidMarked[*it])
        {
            calc(*it, src,depth+1);
        }
}
void add(int src,int parent, int depth)
{
    
    vector<int>::iterator it;
 
    /* recur on non-visited and non-centroid neighbours */
    for (it = tree[src].begin(); it!=tree[src].end(); it++)
        if (*it!=parent && !centroidMarked[*it])
        {
            add(*it, src,depth+1);
        }
}
void findval(int src,int parent,int k)
{

    vector<int>::iterator it;
    /* recur on non-visited and non-centroid neighbours */
    for (it = tree[src].begin(); it!=tree[src].end(); it++)
        if (*it!=parent && !centroidMarked[*it])
        {
            calc(*it, src,1);
            add(*it, src,1);
        }
}

/* function to get the centroid of tree rooted at src.
 * tree may be the original one or may belong to the forest */
int getCentroid(int src)
{
    /* DFS to set up subtree sizes and nodes in current tree */
    DFS(src,-1);
 
    int centroid = getCentroid(src, -1, subtree_size[src]);
 
    centroidMarked[centroid]=true;
    
    

    return centroid;
}
 
/* function to generate centroid tree of tree rooted at src */
void decomposeTree(int root)
{
    //printf("decomposeTree(%d)\n", root);
 

    /* get centroid for current tree */
    int cend_tree = getCentroid(root);
    //error(cend_tree);
    findval(cend_tree,-1);
 
    vector<int>::iterator it;
 
    /* for every node adjacent to the found centroid
     * and not already marked as centroid */
    for (it=tree[cend_tree].begin(); it!=tree[cend_tree].end(); it++)
    {
        if (!centroidMarked[*it])
        {
            /* decompose subtree rooted at adjacent node */
            decomposeTree(*it,k);
 
        }
    }
 
    /* return centroid of tree */
    return ;
}