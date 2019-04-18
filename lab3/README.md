OS LAB3
===
## Exercise_1 [75 pt]
- Write a program “printid.c” with the authority of superuser to print the real user ID and the effective user ID
- Create a new user
- Add the setuid attribute
- Change to the new user 
- Execute the “printid” to print the real user ID and the effective user ID
- The result should be as follow:
    - Real user id: 1000
    - Effective user id: 0

### Implement
- Create [printid.c](./ex1/printid.c)
- Compile printid.c under root
```bash
$ sudo gcc -Wall printid.c -o printid
```
- Execute process under original user
```bash
$ ./printid
```
```
Real		UID = 1000
Effective 	UID = 1000
```
- Set SUID
    - Let user temporarily obtain extra privileges while running the process
```bash
$ sudo chmod 4755 ./printid
```
- Execute process under original user again
```bash
$ ./printid
```
```
Real		UID = 1000
Effective 	UID = 0
```
- Create a new user called "abc"
```bash
sudo adduser abc
```
- Change to the new user
```bash
su abc
```
- Execute process under user "abc"
```bash
$ ./printid
```
```
Real		UID = 1001
Effective 	UID = 0
```

## Exercise_2 [+10 pt]
![](https://i.imgur.com/dY2js20.png)
![](https://i.imgur.com/f9W4UIK.png)

### Implement
```bash
sudo touch datafile
sudo chmod 644 datafile
```
- Create [changefile.c](./ex2/changefile.c)
- Compile printid.c under root
```bash
$ sudo gcc -Wall changefile.c -o changefile
```
- Execute process under original user
```bash
$ ./changefile
```
```
My real user id = 1000
My effective user id = 1000
Can't open file!
```
- Set SUID to let it work
```bash
sudo chmod 4755 changefile
```
- Execute process under original user again
```bash
$ ./changefile
```
```
My real user id = 1000
My effective user id = 0
```

## Exercise_2 Bonus [+5 pt]
![](https://i.imgur.com/OA32659.png)
因為如果不是 root 去呼叫 seteuid() 的話，是無法拿到其他使用者的權限的，所以還是用 chmod 進行提權。

### Implement
Here we modify exercise_1 and take it for example.
If we add "seteuid(300);" at the beginning of process:
- Create [modify of printid.c](./ex2_bonus/printid.c)
- - Compile printid.c under root
```bash
$ sudo gcc -Wall printid.c -o printid
```
- Execute process under root
```bash
$ ./printid
```
```
Real		UID = 0
Effective 	UID = 300
```
- Execute process under original user
```bash
$ ./printid
```
```
Real		UID = 1000
Effective 	UID = 1000
```
- Set SUID
```bash
$ sudo chmod 4755 ./printid
```
- Execute process under original user again
```bash
$ ./printid
```
```
Real		UID = 1000
Effective 	UID = 300
```
