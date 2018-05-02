### Question: Develop a yacc program to evaluate an arithmetic expression involving operators +,-,* and /.

**@Author: Vishal P**

**@Lab: System Software Lab**

> Note: Execute the following way:

```
$ lex prog3.l
$ yacc prog3.y -d
$ gcc lex.yy.c y.tab.c -ll
> Ignore the warning
$ ./a.out
2+3
Value is 5
```
