### Question: Develop a lex Program to recognize and count the number of identifiers in a given input file.

**@Author: Vishal P**

**@Lab: System Software Lab**

> Note: Execute the following way:

```
$ lex prog4.l
$ gcc lex.yy.c
$ ./a.out test.txt
The number of comments is : 2
temp is an identifier
11temp is an not an identifer
temp_1_ is an identifier
1234 is an not an identifer
temp@ is an not an identifer
Number of identifers is : 2
```
