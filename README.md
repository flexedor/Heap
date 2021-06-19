# Heap
### Implement a max heap and the following operations:
```
+ v
  add a number v to the heap
-
  remove the maximum from the max heap (minimum from the min heap respectively) 
  and write it
p
  write all elements of the heap in the order in which they are stored in an array
r n v1 ...vn
  remove all elements from the heap and create a heap out of n new elements,
  of the values given by v1 ...vn
s
  change the orientation of the heap – from max to min; when the the orientation is min,
  the heap yields the minimal element; next s instruction should return the max order
q
  exit the program
```
Additional remarks: Number of elements in a test doesn't exceed 65536. Operation 'r' is not the same as a sequence of '+' operations. If both children are equal the child of the lesser index is swapped.
### Input
```
A sequence of instructions in the format presented below. The last instruction is q.
```
### Output
```
Result of instructions '-' and 'p'.
```
### Example
```
 Wejście
+ 1
+ 2
+ 3
+ 4
+ 5
+ 6
+ 7
+ 8
p
-
-
-
-
-
-
-
-
p
r 8 1 2 3 4 5 6 7 8
p
-
-
-
-
-
-
-
-
p
r 8 1 2 3 4 5 6 7 8
s
p
-
-
-
-
-
-
-
-
p
q


Output
8 7 6 4 3 2 5 1 
8
7
6
5
4
3
2
1

8 5 7 4 1 6 3 2 
8
7
6
5
4
3
2
1

1 2 3 4 5 6 7 8 
1
2
3
4
5
6
7
8
```
