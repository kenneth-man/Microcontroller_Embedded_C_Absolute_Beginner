# Data types in C
- ### Memory sizes depend on the compiler; found in the documentation
- ### E.g. GCC compiler
![](./imgs/C_Fundamentals.png)

![](./imgs/C_Fundamentals_2.png)

<br>

## `char`
![](./imgs/C_Fundamentals_3.png)
![](./imgs/C_Fundamentals_4.png)

- ### E.g. printf() requires a `format specifier` to print the variables
![](./imgs/C_Fundamentals_5.png)

- ### E.g. signed `char` representation
![](./imgs/C_Fundamentals_6.png)
### `1's complement form:`
- ### is used to represent negative numbers (for signed integers)
- ### flipping all bits of binary representation of a positive number
- ### has 2 representations of zero: 0000 0000 and 1111 1111
### `2's complement form:`
- ### is used to represent negative numbers (for signed integers)
- ### flipping all bits of binary representation of a positive number and then add 1 to the least significant bit (LSB)
- ### has only 1 representation of zero: 0000 0000
### Hex value of `-25` is `0xE7`:
- ### split the 8-bit binary representation into two parts: 0001 1001
![](./imgs/C_Fundamentals_7.png)
![](./imgs/C_Fundamentals_8.png)

- ### E.g. Max and Min values of a signed `char` (saying just `char` implies signed by default)
![](./imgs/C_Fundamentals_9.png)
![](./imgs/C_Fundamentals_10.png)

- ### Unsigned `char` range is 0 to 255

<br>

## / `short` / `short int` (equivalent)
![](./imgs/C_Fundamentals_11.png)

- ### E.g. signed `short` representation
![](./imgs/C_Fundamentals_12.png)

- ### E.g. Max and Min values of a signed `short`
![](./imgs/C_Fundamentals_13.png)

<br>

## `int`
![](./imgs/C_Fundamentals_14.png)

<br>

## `long`
![](./imgs/C_Fundamentals_15.png)

<br>

# Variables
- ### A variable acts as a label to a memory location where data is stored
- ### Variables names are not stored in memory; the compiler replaces them with their memory addresses
- ### E.g.
![](./imgs/C_Fundamentals_16.png)
![](./imgs/C_Fundamentals_17.png)

<br>

# Address Of `&`
- ### Returns the memory address of a variable
- ### E.g.
```
char a1 = 'A';
printf("%p", &a1);
```
![](./imgs/C_Fundamentals_18.png)

- ### E.g. typecasting
![](./imgs/C_Fundamentals_19.png)

<br>

# Storage Class specifiers
- ### `static`
	- ### Local variable that retains it's value between function calls
	- ### `static` variables are private to the file

- ### `extern`
	- ### Used to access a global variable which is defined outside of a file

<br>

# ASCII
![](./imgs/C_Fundamentals_20.png)
![](./imgs/C_Fundamentals_21.png)
![](./imgs/C_Fundamentals_22.png)

<br>

# Typecasting
- ### Implicit casting = Done by the compiler
- ### Explicit casting = Done by the programmer
- ### E.g.
![](./imgs/C_Fundamentals_23.png)

<br>

- ### E.g.
![](./imgs/C_Fundamentals_24.png)

<br>

- ### E.g.
![](./imgs/C_Fundamentals_25.png)

<br>

- ### E.g.
![](./imgs/C_Fundamentals_26.png)

<br>

# Hexidecimals
- ### The prefix `0x` means hexadecimal notation
- ### The digits following `0x` can range from 0 - 9 and A - F, where A represents 10, B represents 11, and so on, up to F representing 15
- ### Each hexadecimal digit represents a group of 4 bits
	- ### Hexadecimal digit "0" represents the binary value "0000"
	- ### Hexadecimal digit "9" represents the binary value "1001"
	- ### Hexadecimal digit "F" represents the binary value "1111"

- ### E.g. Convert Hexadecimal to Decimal and vice versa
```
Hexidecimal number: 1A3

3 × 160^0 + 10 × 160^1 + 1 × 160^2

Decimal number: 419
```

```
Decimal number: 450

450/16 == 28, remainder 2
28/16 == 1, remainder 12 (C)
1/16 == 0, left remaining 1

Hexidecimal number: 1C2

```