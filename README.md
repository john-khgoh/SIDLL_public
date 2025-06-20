# Sparse Indexed Doubly Linked List (SIDLL)

## Introduction

### What is it?
A Sparse Indexed Doubly Linked List (SIDLL) is a linked list that is linked in both directions and which has indices (or pointers) distributed throughout the list which enables O(log p + k) worst case time complexity for inserts, deletes and lookups where p is the size of the indices/pointers and k is the maximum distance travelled between the pointer and a given node. Sparse distribution gives the user choice to trade-off between lookup times (faster if the interpointer distance is small) and memory (less if the interpointer distance is large). 

### What can it be used for?
Given that it is always sorted by key, it can be used to keep track of metrics like the streaming mean, median, head/tail as well as min/max (and their associated values).

### Languages
Python, C++

## Methods
- insertNode(key,value)
- deleteNode(key)
- getMinKey()
- getMaxKey()
- getMean()
- getMedian()
- getLength()
- head(length:optional)
- tail(length:optional) 
- keyExists(key)
- getValue(key,index:optional)
- setInterpointerDistance(distance)

## Installing
### Python
There are installers for Windows and [manylinux](https://github.com/pypa/manylinux) works with multiple Linux distros. For example, for Python 3.8 on CentOS:

```
pip install sidll
```

### C++
The .h, .cpp files and CMakeLists.txt are in the SIDLL_C++ directory. 

## Example
### Python
```
import sidll
import random

s = sidll.SIDLL()
s.setVerbosity(0)
s.setInterpointerDistance(10)
deleteList = []

print("-" * 25)
print("Inserting...")
for i in range(0,100):
    randKey = random.uniform(1,100000)
    randVal = random.uniform(1,100000)
    s.insertNode(randKey,0)
    deleteList.append(randKey)
    
print("Length:%d" %s.getLength())
print("MinKey:%f" %s.getMinKey())
print("MaxKey:%f" %s.getMaxKey())
print("Median:%f" %s.getMedian())
print("Mean:%f" %s.getMean())
print(s.head())
print(s.tail())

print("-" * 25)
print("Deleting...")
for i in range(0,50):
    if not deleteList:
        break
    keyToDelete = deleteList.pop()
    s.deleteNode(keyToDelete)
    
print("Length:%d" %s.getLength())
print("MinKey:%f" %s.getMinKey())
print("MaxKey:%f" %s.getMaxKey())
print("Median:%f" %s.getMedian())
print("Mean:%f" %s.getMean())
print(s.head())
print(s.tail())

print(dir(s))

```
### C++
```
#include "SIDLL.h"

SIDLL s = SIDLL();
s.setVerborsity(0);

printf("Inserting...\n");
for (int i = 0; i < 1000; i += 1) {
    s.insertNode(i, i);
}

printf("Length:%d\n", s.getLength());
printf("maxKey:%f\n", s.toDouble(s.getMaxKey()));
printf("minKey:%f\n", s.toDouble(s.getMinKey()));
printf("Mean:%f\n", s.getMean());
printf("Median:%f\n\n", s.getMedian());

printf("Deleting...\n");
for (int i = 0; i < 950; i += 1) {
    s.deleteNode(i);
}

printf("Length:%d\n", s.getLength());
printf("maxKey:%f\n", s.toDouble(s.getMaxKey()));
printf("minKey:%f\n", s.toDouble(s.getMinKey()));
printf("Mean:%f\n", s.getMean());
printf("Median:%f\n", s.getMedian());
```
