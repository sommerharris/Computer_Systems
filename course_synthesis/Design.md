INTERNAL STRUCTURE DESIGN QUESTIONS
*please find accompanying diagrams in the readme for this directory

The idea behind this project is to create a least recently used (LRU) cache, as a concurrent linked hashmap. My first step in designing this project was to break down and understand the following concepts:
>least recently used cache (and LRU eviction policy)
>What kind of linked list would I use?
>How does the hashmap fit in?
>What might concurrency mean in the context of data structures?

    Least Recently Used (LRU) cache:

This cache has a limited amount of space,  so there will be a maximum capacity that we can fill the cache to. When we search for something in the cache, if the item is present we call this a "cache hit" and will return the value. If the item is not present we will call this a "cache miss" and return -1. When we get a cache hit, the item is 'used' in come capacity by our programs, so we will move the item to the front of the list. We will expand upon this interface functionality when we explore the functions, below. 

If we want to add another item to the cache, we add it to the front of the list. If we are already at full capacity when we add this item, we need to choose which item to 'evict' to make space for our new item. This is where the LRU cache eviction policy comes into play-- the item we remove is the least recently used one. In other words, the item closest to the rear of our list.

    What kind of linked list do we use?

In this cache, we will want to use a doubly linked list (DLL) because that allows for easy removal from the middle of the list. The key insight here is that our cache will remove an item from the center of the list and move it to the front (if it is not already there) every time we get a cache hit. Thus, a structure like the DLL that allows for easy removal is ideal for this design.

    How does the hashmap fit in?

Very simply put, a hashmap is a dictionary structure that will allow for quick lookup of key value pairs. The hashmap comes out in the function that we use to search for a cache hit. When an item is put into our DLL, the node inserted will contain a key and value pair, as well as the pointers to the previous and next node. Outside of the DLL, we will have an array that stores these keys as indexes to the array, and each element in the array will hold the address of the corresponding node in the DLL. This way, we are able to leverage the functionality of indexing from an array, while maintaining the ability to easily delete internal nodes in a DLL.

I am still parsing apart the nuances of a hashtable versus a hashmap. The main information I can find is that the nuances of this difference have to do with ordering and synchronization. I read that a hashmap allows for null values, while a hashtable does not. If the items in our hashtable correspond to nodes in the cache, and pointers to nodes in the DLL are stored in our hashmap array, it would make sense that when we remove a node from the DLL we would still keep that index in the hashmap array, but update the value to NULL so that it no longer points to a node in the DLL. This is one of the key nuances between a hashmap and a DLL.

    What might concurrency mean in the context of data structures?

While I am still very much exploring this idea, I've focused around the question 'what is the simplest way to implement concurrency in this project?' This question can translate into 'what is the simplest way to ensure mutual exclusion for our data?' One of the risks of using a hashstructure, is that we can have hash collisions, where there are simultaneous attempts to use the same hashkey.

We can test how our concurrency works by declaring a gobal variable for the data structure and running the program to see what happens.

INTERFACE DESIGN

My next step in this project was to zero in on the specifics of of my interface. What is the necessary functionality I will need for this project? Identifying these specifics will help me clarify what individual mechanisms I will need in the internal structure to achieve my desired interface.

This project will have the following user operations:

>cacheInitialization(capacity): 
    Our cache will be initialized with a capacity. The total number of key:value pairs in the cache must be at or below this capacity. If the capacity is full, we evict the LRU key:value pair from the cache.

>get(key)
    This function finds and returns the value given the key. If the key is not in the cache, it returns -1.

>put(key, value)
    This function inserts a key value pair into the cache, if it does not already exist. If the cache is full it must evict the LRU item. 

>print()
    This function will print the items in the cache.


INTERNAL STRUCTURE DESIGN COMPONENTS

>the node:
    The node will hold previous and next node addresses, as well as the key value pair:

    class Node { 
        int key
        int value
        Node pre
        Node next
        public Node(int key, int value) { 
            this.key = key
            this.value = value
        } 
    }

>the doubly linked list (dlist):
    The doubly linked list can be built as a simple collection of nodes, contianing a head and tail node. It will have a capacity as well as size:
    
    typedef struct dlist{
	    node_t* head;
	    node_t* tail;
	    int size;
        int capacity;
    }dlist_t;   

>the hashtable array:
    I'm still sorting out if the index and the key are the exact same number in the simplest version of a hashtable. 

>functions:
    We can use several of the functions that already exist in our version of the array and doubly linked list.


THEORETICAL ANALYSIS OF OPERATION COMPLEXITY

Our goal is to stay with a constant time complexity, O(1). Constant time is where there is an upper bound to computation time that does not change dependent on the size of the input. The operations we will need to support are get() and put()-- where we usually also evict the least used element. 

We want to look things up quickly, so a hashtable should be able to do that since we are working with a key:value set. Hashmap is a good choice if our goal is lower complexity because it will likely be O(1). Without using a hashtable, we would potentially be doing O(n) operations to even find an item.

For quick removals we want to use a doubly linked list because we can remove a node in constant time. We can easily link the previous and next node together in a way that we cannot do with a singly linked list. A singly linked list would take much more time to remove a node because we would have to iterate back through the list to find the previous node. We also won't need to shift any pointers like we would if removing an item from an array.
