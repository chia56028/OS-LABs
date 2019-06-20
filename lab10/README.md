OSLAB 10
===
## Exercise I
#### Exercise 1_1 [+20pts]
Compile previous example code and execute it ten times.
```bash
gcc ex1_1.c -o ex1_1 -pthread
```

#### Exercise 1_2 [+30pts]
Using semaphore to solve the race condition occurred in previous example code.

## Exercise II [+40pts]
- Devise a semaphore solution to the multiple Producer-multiple Consumer problem.
- Constraint:
	- 10 producers and 10 consumers.
	- The maximum amount of  items is  5.
	- The minimum amount of  items is  0.
	- No items are consumed from an empty state.
	- No items are produced from an full state.
	- Only one Producer or Consumer can produce or consume at the same time.
	- Print every transaction.(The amount of items)
