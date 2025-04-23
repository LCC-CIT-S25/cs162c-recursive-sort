# Objective

1. Practice recursive approaches to problem solving
2. Practice sorting
3. Practice use of 2D arrays

## Recursive sorting
- [ ] Update README.md with description of the algorithms
- [ ] Add a new file to implement a recursive integer sorting algorithm
  - This will take in an array and the length to sort. This will be done by calling itself.
    With the material we have covered so far, the recommended approach is to find
    the largest value, swap it to make it the final element, then call the
    function on the array with a short length to sort the n-1 elements.
  - It is left as an exercise to define the terminating condition.
  - This is a good to commit your code.
  - Add comments on how the code works and what type of sort this is a variation of.
- [ ] Use the above function to sort the inner dimension of a 2D dimensional array.
    ```c++
    {
     { 1, 2, 13, 0},
     { 12, 6, -1, 2}
    }
    ```
    would become
    ```c++
    {
     { 0, 1, 2, 13},
     { -1, 2, 12, 6 }
    }
    ```
  
## Maze solving path
Can you find the shortest path?

Write a function that takes in an 2D `int` array of size `[M,N]` and the size, `M` and `N` 
and find the shortest path to the end. The values represent a cost for moving to that location.
With a starting at location (0,0) and ending at (M-1, N-1) and only taking steps by +1 in the x and y directions (no decreasing coordinates).
Return the lowest total cost.

consider a map
```c++
{
 { 1, 1, 1, 1},
 { 2, 2, 6, 3},
 { 5, 1, 1, 1}, 
}
```
The shortest path is right, down, down, right, right and a cost of 7.

Consider creating an array of the minimum cost to get to any particular location.
The cost of a specific location will be the value of that location plus the cost
of the smallest of the location either above or to the left. There is a
step-by-step description below.


### TODO:
- [ ] Create new file and header for the maze cost problem
- [ ] Write a helper function that can be used to recursively calculate the cost of all locations
  - This will need a prototype of
    `void CalculateLevelCost(int locationCost[][MAX_D1], size_t d0, size_t d1, int totalCose[][MAX_D1], size_t next_level)`
- [ ] Write a function that takes in a 2D array to return the minimum cost of traversing it
  - This will call the above _helper_ function with an additional 2D array to hold the minimum costs along the way
- [ ] In the driver write a few test cases to make sure it finds the correct answer


### Step-by-step

We can see the cost of moving left or down could result in an array
```c++
{
 { 1, 2, 0 , 0},
 { 3, 0, 0, 0},
 { 0, 0, 0, 0}, 
}
```
moving another left or down
```c++
{
 { 1, 2, 3 , 0},
 { 3, 4, 0, 0},
 { 8, 0, 0, 0}, 
}
```
Note you need to check if you at an edge
- Location [0,2] it is `1 + min(2, 0)` because above is off the board.
- Location [2,0] it is `5 + min(3, 0)` because to the left is off the board
- for location [1,1] it is `2 + min(2,3)` which is 4

moving another left or down
```c++
{
 { 1, 2, 3 , 4}, // 1 + min(3,0) 0 due to edged
 { 3, 4, 9, 0},  // 6 + min(3,4)
 { 8, 5, 0, 0},  // 1 + min(8,4)
}
```
moving another left or down
```c++
{
 { 1, 2, 3 , 4}, // skip as it is complete
 { 3, 4, 9, 7},  // 3 + min(4,9)
 { 8, 5, 6, 0},  // 1 + min(5, 9)
}
```

moving another left or down
```c++
{
 { 1, 2, 3 , 4}, // skip as it is complete
 { 3, 4, 9, 7},  // skip as it is complete
 { 8, 5, 6, 7},  // 1 + min(6, 7)
}
```