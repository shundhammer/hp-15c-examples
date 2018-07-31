# Calculate prime numbers

## The C/C++ structured approach

https://github.com/shundhammer/hp-15c-examples/blob/master/prime/prime-01.cc

## C/C++ the HP-15C way with GOTOs

Yes, GOTOs are yucky and forbidden and every good C/C++ programmer who even
thinks about using them will rot in hell forevermore. But since the HP-15C did
not have any nice `while` loops or even multi-statement `if` conditions, you
need to use GOTOs and jump labels a lot on that platform.

So here is the first transition from the pure holy C/C++ gospel to
assembly-like HP-15C code:

https://github.com/shundhammer/hp-15c-examples/blob/master/prime/prime-02.cc


## HP-15C'ifying it even more

Since the HP-15C only had numbered registers and jump labels A..E, 0..9 and .0,
.1, .., .9, this is getting even closer to what you can do on the HP-15C
platform:

https://github.com/shundhammer/hp-15c-examples/blob/master/prime/prime-03.cc


## The real thing: HP-15C code

https://github.com/shundhammer/hp-15c-examples/blob/master/prime/prime-01.15c


### Usage

Enter an odd (!) integer number greater or equal to 3, then start program A
(`f` `A`). It will display the next prime number.

When it stops, use the `R/S` key to continue with the next one.


### Quirks and limitations

- Program behavior is undefined when starting with an even number (i.e. the
results will be just garbage).

- It cannot calculate the first prime numbers 2 and 3.

- If you started with a prime number, it will display the starting number, so
you can also use this as a check if a number is a prime number.

