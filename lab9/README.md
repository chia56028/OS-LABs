oslab 9
===
## Exercise I [+40pts]
- A program starts and immediately creates four identical threads
	- Also declare a global variable count = 0.
	- The main program passes a value containing the number of iterations to the threads.
- Each thread increments the same global variable 250,000 times
	- Each thread prints the number of iterations from argument and its thread ID.
	- So count is incremented a total of 1,000,000 times.

![](https://i.imgur.com/yWZAibj.png)


### Compile
```
gcc -o ex1 ex1.c -pthread
```
### Execute
```
./ex1
```

## Exercise II [+50pts]
- Using the message queue which we learned last week
- Create two processes, each of them has two threads
	- One thread can allow user type messages iteratively and send those messages to a queue.
	- The other one can receive the messages which be sent to the queue by the other process and print on screen.
- The two processes use the same message queue, but assign different message type to distinguish each other

![](https://i.imgur.com/sAOCsBW.png)
