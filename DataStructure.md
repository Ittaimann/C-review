# DATA STRUCTURES AND USE CASES

# arrays
- arrays are essentially blocks of memory allocated at the amount wanted with the size of the objects to be inserted ddescribibng how much size each one is given. These objects are set, and can not change size nore be expanded upon without dedicating space to a new array of objects. 

# linked list
- A linked list is a chain of elements that each contain an object we want to store, and a pointer or refernce to the next element in the sequence  
       
       header-> obj1|ptr->obj2|ptr->obj3|ptr-> ...->nullptr

- the benefit of linked lists is their dynamic nature, we can easily extend and remove from them. We can also extend their ease of use/ efficiency by adding more pointers, such as a tail pointer, doubly linked pointers, or a circular linked list  
```
    header-> obj1 | prt <-> ptr | obj2 | ptr <-> ptr | obj3 | ptr <->... null or  obj1 for circular  
            ^                                                                    v
            |====================================================================|
```
- the dangers and annoyances of linked lists is primarily in building them. These are objects that are pretty much all dynamically allocated. so to ensure no memory leaks we need to be careful about how we reference and remove and add everything, as we could be left with undefined pointers, or even worse objects whose pointers no longer exist.
- Also while these are good for linear lists such as maybe a queue or stack based on insertion, anything else more than that isn't as fast as they could be via another data structure. Even in queues and stacks, we can find better data types that work much faster 

# heaps

# trees


# queues
- Queues are a first in first out data structure and have the O(1) removal as we can only really remove from the front.
- and depending on how we created the queue, insertion should also be O(1) as we simply need to remember the end point of the underlying container
- to remove the first element we usually call pop, to insert to the end we call push
- to get the first element it depends, I remember seeing implementation where pop would return and implementations where it would not, so this is kinda touch and go. Usually there should be a front function
## priority queue
- derivative of queue which attempts to self order on insertion
- given a comparator function, the inserted element in the queue will ultimately find a place in the queue.
- While this seems like it would be  inefficient for a linear data structure, a tree like structure such as a heap, actually makes this acceptably efficient. 
# stack
- essentially a Queue, BUT IN REVERSE. It is last in first out (think cookie jar). Again we use push and pop 

## maps
# sets
- an unorderd list of elements where insertion is simple O(log n) (as the order no longer matters). removing from a set and checking for an elements exsistance can really depend on the underlying container. Having it as a linked list versus having it be a heap or red black tree can lead to a lot of different complexity class jumps based on implementation. For example the default c++ set is implemented via red black trees with incredibly fast O(log n) search insert and delete. 
- another important detail. no duplicate elements.

# Trees, there are a lot but the two I can cover now are...
## binary search trees
- binary search trees are trees where the order of the elements are based on where on the tree they fall relative to their parent elements. so for instance a node 5 could have a left child 3 and a right child 6, as 6 is greater
## heaps
- a balanced tree data structure usually implemented as some kind of dynamic array. where the left child and right child formula as well as parent can be determined mathematically. The entire idea of a heap is the ability to insert at the top and sift down. This is actually pretty efficient do too the bankers argument (?)