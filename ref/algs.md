Cheatsheet for the Olympics

### 1. [Sorting](https://visualgo.net/en/sorting)
#### Bubble sort
```
do
  swapped = false
  for i = 1 to indexOfLastUnsortedElement-1
    if leftElement > rightElement
      swap(leftElement, rightElement)
      swapped = true; ++swapCounter
while swapped
```

Iterate over all element pairs of two and swap if the first one is bigger than the second one.

#### Selection Sort
```
repeat (numOfElements - 1) times
  set the first unsorted element as the minimum
  for each of the unsorted elements
    if element < currentMinimum
      set element as new minimum
  swap minimum with first unsorted position
```

Iterate over all elements, find the minimum and put it in the first position.

#### Insertion Sort
```
for each unsorted element X
  'extract' the element X
  for j = lastSortedIndex down to 0
    if current element j > X
      move sorted element to the right by 1
    break loop and insert X here
```

Check each element with the previous one if it is larger or not.

#### Merge Sort
```
split each element into partitions of size 1
recursively merge adjacent partitions
  for i = leftPartIdx to rightPartIdx
    if leftPartHeadValue <= rightPartHeadValue
      copy leftPartHeadValue
    else: copy rightPartHeadValue; Increase InvIdx
copy elements back to original array
```
Still sorting, but in pairs.

#### Quick Sort
```
for each (unsorted) partition
set first element as pivot
  storeIndex = pivotIndex+1
  for i = pivotIndex+1 to rightmostIndex
    if ((a[i] < a[pivot]) or (equal but 50% lucky))
      swap(i, storeIndex); ++storeIndex
  swap(pivot, storeIndex-1)
```

#### Random Quick Sort
```
for each (unsorted) partition
randomly select pivot, swap with first element
  storeIndex = pivotIndex+1
  for i = pivotIndex+1 to rightmostIndex
    if ((a[i] < a[pivot]) or (equal but 50% lucky))
      swap(i, storeIndex); ++storeIndex
  swap(pivot, storeIndex-1)
```

#### Counting Sort
```
create key (counting) array
for each element in list
  increase the respective counter by 1
for each counter, starting from smallest key
  while counter is non-zero
    restore element to list
    decrease counter by 1
```
Sorting using a counting array

#### Radix Sort
```
create 10 buckets (queues) for each digit (0 to 9)
for each digit placing
 for each e in list, move e into its bucket
   for each bucket b, starting from smallest digit
     while b is non-empty, restore e to list
```
Sort based on first-to-last elements.

C++ already has a function, that sorts
```c++
sort(arr.begin(), arr.end());
```

### 2. Data Structures

#### Linked List
Head and tail, each element pointing to the next one

##### 1. Inserting
```
Vertex vtx = new Vertex(v)
vtx.next = head
head = vtx
```
##### 2. Searching
```
if empty, return NOT_FOUND
index = 0, tmp = head
while (tmp.item != v)
  index++, tmp = tmp.next
  if tmp == null
    return NOT_FOUND
return index
```
##### 3. Removing
```
if empty, do nothing
tmp = head
head = head.next
delete tmp
```

Same principles apply for the other data structures. Keep in mind, that for the nodes you can use `struct`

```c++
struct Node {
	int data;
	Node* next;

	Node(int value) : data(value), next(nullptr) {}
};
```

For working with graphs, use a `unordered_map`, keeping all neighboring edges as elements.

Some other algorithms for working with graphs.

### MST (Minimum Spanning Tree)
1. The minimum spanning tree ensures that all the nodes in the graph are connected together.
2. 1. Among all the possible spanning trees of the graph, the minimum spanning tree has the smallest total sum of edge weights.

Kruskural:
```
Sort E edges by increasing weight
T = {}
for (i = 0; i < edgeList.length; i++)
  if adding e = edgelist[i] does not form a cycle
    add e to T
  else ignore e
MST = T
```

Prim:
```
T = {s}
enqueue edges connected to s in PQ (by inc weight)
while (!PQ.isEmpty)
  if (vertex v linked with e = PQ.remove ∉ T)
    T = T ∪ {v, e}, enqueue edges connected to v
  else ignore e
MST = T
```

You already know how DFS and BFS works, don't be silly.

### Max flow
Im pretty sorry for you if you got to this point, bud

* source - start
* sink - end

Ford-Fulkerson:
```
initMaxFlow
while there is an augmenting path
  find an augmenting path using DFS
  for each edge u->v in the path
    decrease capacity u->v by bottleneck
    increase capacity v->u by bottleneck
  increase maxflow by bottleneck
```

Edmonds-Karp:
```
initMaxFlow
while there is an augmenting path
  find an augmenting path using BFS
  for each edge u->v in the path
    decrease capacity u->v by bottleneck
    increase capacity v->u by bottleneck
  increase maxflow by bottleneck
```

### Finding Shortest Paths
Dijkstra
```
initSSSP
for i = 1 to |V|-1
  for each edge(u, v) in E // in Edge List order
    relax(u, v, w(u, v))
for each edge(u, v) in E
  if can still relax that edge, -∞ cycle found
```

