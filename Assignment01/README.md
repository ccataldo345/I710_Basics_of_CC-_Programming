=== Assignment ===
------------
Write a program that reads values from a file and outputs the result to stdout.

====== Input ======
------------
Input file's name is "input.txt".

The file contains index-value pairs of integers on a single line. Integers in a pair are separated with a comma (,) and pairs are separated with a semicolon (;).

All indices between 0 and (count_of_pairs - 1) are guaranteed to be present.

The indices are guaranteed to be unique.

The indices are not guaranteed to appear in an ascending order.

Sample input:
1,4;0,2;2,8

====== Output ======
------------
The program should output the differences between consecutive values as the index increases.

Output should be printed as a comma separated list of values on a single line to stdout.

For input:
 0,1;2,4;1,2

Calculates:
 0,1 to 1,2 -> 2 - 1 = 1
 1,2 to 2,4 -> 4 - 2 = 2

And outputs:
 1,2

====== Examples ======
------------
 ->
 0,2 -> 0
 1,2;0,1 -> 1
 1,4;0,2;2,8 -> 2,4
 1,4;0,2;2,-2 -> 2,-6

====== Compile ======
------------
gcc Assignment01.c -o run </br>
./run
