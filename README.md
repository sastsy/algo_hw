# Homeworks for algorithms and data structures course. 
### Lecture 1
#### 1-1
Problem of rearranging a sequence of integers in a zigzag pattern, where odd-indexed elements are in descending order and even-indexed elements are in ascending order, thus providing an alternative sorting method tailored to this specific pattern.
#### 1-2
This code attempts to solve the problem of sorting a sequence of integers in ascending order using the bubble sort algorithm, but it faces issues when the initial sequence is sorted in non-ascending order, leading to potential incorrect results due to incomplete sorting.
### Lecture 2
#### 2-1
This code solves the problem of comparing the performance of the shell sort algorithm against the built-in sorting function (std::sort) on increasingly larger sequences of randomly generated integers, where the shell sort algorithm utilizes a specific sequence of increments generated by the smoothSeqGenerator function to sort the input sequence efficiently.
#### 2-2
This code solves the problem of efficiently counting the occurrences of each integer within a given range of an input sequence and then answering a series of queries about the total count of integers within specified subranges, thereby facilitating range queries on the frequency distribution of integers in the input sequence.
### Lecture 3
#### 3-1
This code solves the problem of finding the most efficient value for the parameter m in a subarray insertion sort algorithm, where m represents the size of subarrays to be sorted individually before merging. The code systematically tests different values of m for various sizes of input arrays and determines the optimal m value that minimizes the sorting time.
#### 3-2
This code solves the problem of counting the number of inversions in an array and sorting the array using the merge sort algorithm. An inversion occurs when two elements in an array are out of order with respect to each other. The code employs a modified merge sort algorithm that counts inversions during the merge step, providing both the count of inversions in the array and the sorted array itself as output.
#### 3-3
This code solves the problem of finding pairs of elements in a given array whose sum equals a specified target value s, while also sorting the array using the merge sort algorithm. The code counts the number of such pairs and outputs the sorted array along with the count of pairs whose sum equals s.
### Lecture 4
#### 4-1
This code solves the problem of comparing the performance of radix sort against the built-in sorting function (std::sort) on a large array of integers. It generates a random array of integers, performs radix sort on it, and measures the time taken. Then, it sorts the same array using the built-in sorting function and measures the time again. Finally, it outputs the time taken for both sorting algorithms, allowing for a comparison of their efficiency.
#### 4-2
This code solves the problem of comparing the performance of radix sort against the built-in sorting function (std::sort) on a large array of integers. It generates a random array of integers, performs radix sort on it after making all integers non-negative by adding the absolute value of the minimum integer in the array to each element, and measures the time taken. Then, it sorts the same array using the built-in sorting function and measures the time again. Finally, it outputs the time taken for both sorting algorithms, enabling a comparison of their efficiency.
### Lecture 5
#### 5-1
This code solves the problem of comparing the performance of heap sort against the built-in sorting function (std::sort) on a large array of integers. It generates a random array of integers, performs heap sort on it, and measures the time taken. Then, it sorts the same array using the built-in sorting function and measures the time again. Finally, it outputs the time taken for both sorting algorithms, allowing for a comparison of their efficiency.
#### 5-2
The same as the previous one, but implements a 3-node heap
#### 5-3
This code solves the problem of finding the kth smallest element in a large array of integers efficiently. It generates a random array of integers, then uses a heap-based algorithm (findKMin) to find the k smallest elements in the array. Additionally, it sorts the same array using heap sort (heapSort). Finally, it compares the kth smallest element found by findKMin with the kth element after sorting using heapSort
### Lecture 6
#### 6-1
This code compares the execution time of the quick sort algorithm (quickSort) and the standard sorting algorithm (std::sort) for two sets of randomly generated large arrays of integers. It measures the time taken for sorting using both algorithms and outputs the respective execution times. 
#### 6-2
This code implements the quickselect algorithm to find the kth smallest element (kth order statistic) in an unsorted array. 
