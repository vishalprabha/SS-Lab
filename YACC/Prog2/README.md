### Question: Develop a yacc program to recognize a valid variable, which starts with a letter, followed by any number of letters or digits.

**@Author: Vishal P**

**@Lab: System Software Lab**

> Note: Execute the following way:

```
$ lex prog2.l
$ yacc prog2.y -d
$ gcc lex.yy.c y.tab.c -ll
> Ignore the warning
$ ./a.out
bleh
valid
$ ./a.out
11bleh
Invalid
$ ./a.out
bleh11
Valid 
```
