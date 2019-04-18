Lab1
===
### Topic: Number Guessing Game
- Define the number range between 1 and 10
- Ask the user to enter a target number at beginning
- Keep narrowing down the number range until the player guessing the right target number

### Exercise_1
- Use echo, read, loop and conditionals [75 pt]
    - Set the default target number
```bash=
$ sh ./exercise_1.sh
```
```
Welcome to the Number Guessing Game!
Please enter a number between 1 and 10: 10
Please enter a number between 1 and 9: 4
Please enter a number between 4 and 9: 7
Bingo!
```

### Exercise_2
- Use function to ask for guessing number [+5 pt]
```bash=
$ sh ./exercise_2.sh
```
```
Welcome to the Number Guessing Game!
Please enter the target number: 7
Please enter a number between 1 and 10: 10
Please enter a number between 1 and 9: 4
Please enter a number between 4 and 9: 7
Bingo!
```

### Exercise_3
- Use argument to set the target number [+5 pt]
```bash=
$ sh ./exercise_3.sh 7
```
```
Welcome to the Number Guessing Game!
Please enter a number between 1 and 10: 10
Please enter a number between 1 and 9: 4
Please enter a number between 4 and 9: 7
Bingo!
```

### Exercise_py
- Bonus: use other scripting language like Perl and Python to do the same thing. [+5 pt]
```bash=
$ python exercise_py.py
```
```
Welcome to the Number Guessing Game!
Please enter the target number: 7
Please enter a number between 1 and 10: 10
Please enter a number between 1 and 9: 4
Please enter a number between 4 and 9: 7
Bingo!
```
