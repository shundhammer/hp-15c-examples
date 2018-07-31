# HP-15c Examples

Example programs for the HP-15C programmable RPN pocket calculator from the
1980s, the SwissMicros DM-15L replica and the HP-15C simulator by Torsten Manz.

(c) 2018 Stefan Hundhammer <Stefan.Hundhammer@gmx.de>

License: GPL V2

Updated: 2018-07-31


## Motivation

Back in its days, those programmable RPN pocket calculators by HP were
state-of-the art technology. They were used by engineers to build bridges, tall
buildings, aircraft and even spacecraft.

But programming them was never easy since the platform was limiting; it was
basically a high-level assembler that you had to use.

So here are some examples showing how to get from modern high-level programming
languages to the HP-15C.


## But... WHY?

Yes, everybody has a PC (or a Mac) these days.

Yes, even a modern smartphone is light years ahead of those 1980s era
programmable calculators in terms of raw calculating power, memory (both RAM
and mass storage) and versatility.

But not only was it cool back then (in the 1980s), a lot of people (including
me) made their first steps in programming on those devices. It was demanding;
it was a rough way to get into the trade. It could only do numeric stuff. It
was limiting in every aspect: Program size, available registers, usability.

You had to know how to feed your program with the data it needed, and you had
to know what output of your program meant exactly what.

But that meant that it took quite some skill to do anything worthwhile with
those devices; it was challenging, you had to know your platform very well, and
you were forced to program efficiently and not waste program steps, registers
or, worst, computing cycles.

You learned a lot about programming with those devices. You could not afford to
do anything in an inefficient way; you'd run out of resources pretty soon, or
your program would run forever.

And it was cool, of course.

Does mankind need that in this day and age? I don't know.

Does nerdkind need that? Sure thing.

Do I need that? You bet.


## What a HP-15C program looks like

_(Comments added for better readability; the HP-15C platform had no way to add
comments.)_

This program counts up to the number initially entered and pauses for each step:

```
f LBL A    # start with button A
g INT      # whatever the input, use only the integer part
1000       # divide by 1000
/
1          # add 1
+          # loop counter is now 1.007   if the user entered 7 initially
STO 1      # store in register 1
f LBL 1    # define label 1 as a jump address for later use
RCL 1      # recall the contents of register 1 (the loop counter)
g INT      # use only the integer part
g PSE      # pause for 2 seconds (and display the current value)
f ISG 1    # increment register 1 and skip if greater than the loop end value
GTO 1      # goto label 1 (skip this if loop counter not at its end)
g RTN      # return (program ends here)
```

Yes, this looks very much like a (slightly) higher level assembler. That's
basically what it was.

But in the display which could only display numbers with its 7-segment
elements, it looked like this:

```
001 - 42,21,11
002 - 43  44
003 - 1
004 - 0
005 - 0
006 - 0
007 - 10
008 - 1
009 - 40
010 - 44 1
011 - 42,21, 1
012 - 45  1
013 - 43 44
014 - 42 31
015 - 42,  6,  1
016 - 22 1
017 - 43 32
```

I.e. each opcode was represented by the keys to be pressed with row and column
on the keyboard:

42,21,11   f prefix (row #4, col#2), LBL (row #2, col#1), A (row #1, col#1)

This sounds completely crazy, but you get used to this really quickly because
you hold the reference - the keyboard - in your hand.


## Links

- The HP-15C on Wikipedia:

  https://en.wikipedia.org/wiki/HP-15C

- SwissMicros, a company in Switzerland building replicas of the HP-15C (and
other HP pocket calculators), the DM-15L:

  https://www.swissmicros.com/

- A really well-made HP-15C simulator running on Windows, Linux, MacOS X:

  http://hp-15c.homepage.t-online.de/content_web.htm

  This piece of software is so cool it can even interact with SwissMicro's
replica which has a USB port: You can download and upload programs between your
PC (or Mac) and the SwissMicro DM-15L.

