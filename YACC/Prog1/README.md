### Question: Develop a yacc program to recognize a valid arithmetic expression that uses operators + ,- ,* and /.

**@Author: Vishal P**

**@Lab: System Software Lab**

> Note: Execute the following way:

```
$ lex prog1.l
$ yacc prog1.y -d
$ gcc lex.yy.c y.tab.c -ll
> Ignore the warning
$ ./a.out
a+b
Valid
$ ./a.out
a++b
Invalid 
```
