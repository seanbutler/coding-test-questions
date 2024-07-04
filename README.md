# various little exercises / prep for interviews

## min max sum

- traverses a std::array returns the sum of the largest and smallest elements
- sort of c-ish code

## coin sorting

- given a random value calculates minimum british coins equal it
- sort of c-ish code
- traverses a vector of std coin values and divides then subtracts the amount given to get the number of coins of that value, continues through the list of coins

## move to front

- given a special value, move _all_ elements of an array of that value to the front of the array
- works via 2 iterators, one fast and one slow
- fast one moves ahead till it finds the value, then it swaps with the slow one, which iterates
- continues in this manner till fast reaches end of array
- curently written with own code, could be done with stl swaps and such instead, prolly

## diamond pattern

- demonstration of the diamond pattern
- uses cout to show how the root of the diamond has its destructor called twice! 
- be careful with this is also allocating/freeing memory

## reverse linked list

- written in mostly c (some std)
- nicely structured but inefficient program 
- reverses the list by iterating over it to the end (a lot)

## hash

- simple has table

## efficient janitor

- janitor can only carry so much, but the bags all weigh different amounts, whats an efficient way for him to take them out?


## tree1

- binary tree
- cheap to insert
- if you want things out in order to a tree walk
