OSLAB 9
===
## Exercise I
- Step1: Using the fork() function to create a new process.
- Step2: Using command line to kill the process.[+30pt.]
- Step3: Repeat step1 and use system calls to kill process.[+30pt.]


## Exercise II
- Writing handler1 : show “How are you?” message.
- Writing handler2 : show ”I am fine!” message.
- In the first 3 seconds, you have to maintain handler1 as your SIGINT handler.
- Next 3 seconds, you have to maintain handler2 as your SIGINT handler.
- Then you set SIGINT handler to “default” handler.[+20pt.]
- Note: you should use alarm()!!![+10pt.]
