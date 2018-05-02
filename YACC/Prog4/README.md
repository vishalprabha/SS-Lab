### Question: Develop a yacc program to recognize the strings of the form ambn, where m>=0,n>=0.


**@Author: Vishal P**

**@Lab: System Software Lab**

> Note: Execute the following way:

```
$ lex prog4.l
$ yacc prog4.y -d
> Ignore the "conflicts: 3 reduce/reduce"
$ gcc lex.yy.c y.tab.c -ll
> Ignore the warning
$ ./a.out
a
Valid
$ ./a.out
ab
Valid
$ ./a.out
ccd
Invalid
```
