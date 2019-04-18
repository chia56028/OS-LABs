OS LAB5
===
## Exercise
- Create three modules
    - Module A
        - Export a function symbol
    - Module B
        - Export a variable symbol
        - Call the function exported by Module A
    - Module C
        - Use the variable exported by Module B
        - Declare it as a parameter
    - Notice: load order is A, B, then C

### [Module_A](./Module_A.c) [30pts]
- Export a function symbol
    - The function accept an integer argument.
    - Use printk() to show the comparison result between 100 and the input argument.
        - If argument > 100: return 1
        - If argument = 100: return 0
        - If argument < 100: return -1

### [Module_B](./Module_B.c) [30pts]
- Export a variable symbol
    - Declare an int variable (value=56) and export it as an exported symbol.
- Call the function exported by Module A
    - Use the variable declared above as an argument to the function exported by Module A.

### [Module_C]((./Module_B.c)) [30pts]
- Use the variable exported by Module B
    - Hint: extern statement.
- Declare it as a parameter
    - Pass a command line argument to set the variable.
    - Show the new value by printk().

### Execute
- Make the module
```bash=
make
```
- Insert Module_A and Module_B into kernel under root
```bash=
sudo insmod Module_A.ko
sudo insmod Module_B.ko
```
- Try to remove Module_A.ko from kernel
```bash=
sudo rmmod Module_A.ko
```
```
rmmod: ERROR: Module Module_A is in use by: Module_B
```
- Insert Module_C into kernel under root
```bash=
sudo insmod Module_C.ko
```
- Remove Module_C.ko from kernel, then pass a command line argument to set the variable
```bash=
sudo rmmod Module_C.ko
sudo insmod Module_C.ko symbol_variable_B=77
```
