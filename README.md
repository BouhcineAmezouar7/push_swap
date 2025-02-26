
# Push_swap 42

Push_swap is a project at 42 School that requires you to implement an algorithm to sort a list of integers with a limited set of operations. The goal is to sort the numbers using the fewest operations possible.

## Requirements
 * A Unix-based OS (Linux/MacOS)
 * C programming language
 * Make

## Setup
Clone the repository :
```
  git clone https://github.com/BouhcineAmezouar7/push_swap.git
  cd push_swap
```

Compile the project:
```
  make
```
This will generate the push_swap executable.

## Usage
Sorting with Push_swap

After compiling the project, you can use the push_swap program to sort an array of integers.

Run the program with the integers you want to sort:
```
  ./push_swap <int1> <int2> <int3> ...
```
Example:
```
  ./push_swap 3 1 4 5 2
```

## Operations
The program sorts the list using a set of predefined operations, such as:

* sa : Swap the first two elements of stack A.

* sb : Swap the first two elements of stack B.

* ss : Perform both sa and sb at the same time.

* pa : Push the top element of stack B to stack A.

* pb : Push the top element of stack A to stack B.

* ra : Rotate stack A (move the first element to the last position).

* rb : Rotate stack B (move the first element to the last position).

* rr : Perform both ra and rb at the same time.

* rra : Reverse rotate stack A (move the last element to the first position).

* rrb : Reverse rotate stack B (move the last element to the first position).

* rrr : Perform both rra and rrb at the same time.

## Example Execution

Compile the project:
```
  make
```
Run the push_swap program:
```
  ./push_swap 3 1 4 5 2
```
Example Output:
```
  sa
  pb
  ra
```

## Testing with Checker
To verify that your solution is correct, you can use the checker program:

Compile the project with:
```
  make bonus
```

Run the checker with a set of numbers:
```
  ARG="3 1 4 5 2"; ./push_swap $ARG | ./checker $ARG
```
The checker will return:

* OK if the sorting is correct.

* KO if the sorting is incorrect.
