
Week 1:
Boolean Algebra
Distributive, cummutative, associative, de morgan properties.

Truth Table to Boolean expression
How? - Write out the bolean exp. for all rows with output 1 such that the value of that expression is 1 only for that row.
To do this use AND.
So for ex a row with x=1,y=1,z=0 and f(x,y,z)=1 is written as X AND Y and NOT(Z)
Then, do an OR for all those expressions.
For example:
X,Y->output
0,0->0
1,0->1 -> X AND NOT(Y)
0,1->0
1,1->1 -> X AND Y

E = (X AND NOT(Y)) OR  (X AND Y)
  = X

Similar method can be applied for any number of variables.
Note - Finding the shortest boolean expression for a truth table is a NP-hard problem.


Theorem1: Any boolean function can be represented using just NOT and AND operations.
This is unlike say real space where not all functions cannot be represented with albebraic operations.
Proof: X or Y = NOT(NOT(X) AND NOT(Y))

Theorem2: Any boolean function can be represented using just NAND gates.
Proof: 1)NOT(X) = (X NAND X)
       2)X AND Y = NOT(X NAND Y) = (X NAND Y) NAND (X NAND Y)


HDL(Hardware description Language)
XOR = (NOT(a) AND b) OR (a AND NOT(b))
```
/*XOR gate: (NOT(a) AND b) OR (a AND NOT(b))*/
CHIP Xor{
  IN a, b;
  OUT out;

  PARTS:
  Not (in=a, out=nota);
  Not (in=b, out=notb);
  And (a=a, b=notb, out=aAndNotb);
  And (a=b, b=nota, out=notaAndb);
  Or (a=aAndNotb, b=notaAndb, out=out);
}
```
- HDL is a functional/declarative language
- order of HDL statements is insignificant. But it's customary to write from left to right.
- Before using a chip part, you must know its interface.

Common HDLs - VHDL, Verilog


Hardware construction projects:
Divide and Conquer - High level design and then write individual chip APIs.

Multi-bit buses
manipulating an array of bits

```
/*
Add two 16-bit numbers
*/
CHIP Add16{
  IN a[16], b[16];
  OUT out[16];
  PART:
  //implementation missing
}

```

```
/*
Add 3 16-bit numbers
*/
CHIP Add3Way16{
  IN first[16], second[16], third[16];
  OUT out[16];
  PARTS:
  Add16(a=first, b=second, out=temp);
  Add16(a=temp, b=third, out=out);
}
```

```
/*
Add two 4-bit numbers bit-wise
CHIP AddBitWise{
  IN a[4], b[4];
  OUT out[4];
  PARTS:
  Add(a=a[0], b=b[0], out=out[0]);
  Add(a=a[1], b=b[1], out=out[1]);
  Add(a=a[2], b=b[2], out=out[2]);
  Add(a=a[3], b=b[3], out=out[3]);
}
*/
```

```
/*
AND the 4 bits of a 4-bit number
CHIP AndBits{
  IN a[4];
  OUT out;
  PARTS:
  AND(a=a[0], b=a[1], out=out);
  AND(a=out, b=a[2], out=out);
  AND(a=out, b=a[3], out=out);
}
*/
```

Sub-buses:
```
...
IN lsb[8], msb[8], ...;
...
Add16(a[0..7]=lsb, a[8..15]=msb, b=..., out)
...
```


Multiplexor(Mux):
IN a, b, sel;
OUT out;
Logic:
out = a if sel=0 and b if sel=1
used in digital designs, comm. networks.


Programmable gate:
AndMuxOr = And, if sel==0
           OR, if sel==1
ie:
if (sel==0) out = a AND b
if (sel==1) out = a OR b
```
CHIP AndMuxOr{
  IN a, b, sel;
  OUT out;
  PARTS:
  And(a=a, b=b, out=andOut);
  OR(a=a, b=b, out=orOut);
  Mux(a=andOut, b=orOut, sel=sel, out=out);
}
```

DeMultiplexor or DMux :
Distributes input to one of two outputs
IN in, sel
OUT a, b
Logic:
a, b = in, 0 if sel==0
a, b = 0, in if sel==1  


WEEK2
Binary conversion, binary addition.
Negative numbers can be represented by 1.... but this is not elegant because 0000 is 0 and 1000 is -0.
Standard way is to use 2's complement for representing them:
-x = 2^(N)-x
like -5 = 1011
In 2's complement notation, we can represent -8 to 7 in 4 bits.
0001 +1
0010 +2
0011 +3
0100 +4
0101 +5
0110 +6
0111 +7
1000 -8
1001 -7
1010 -6
1011 -5
1100 -4
1101 -3
1110 -2
1111 -1

To calculate 2^N - x it's more convenient to calculate (2^(N)-1-x)+1 because 2^(N-1) is made of all 1's and it's easier to subtract from this number than from 2^N (just invert the bits). Adding 1 is also trivial: Invert all bits from left until you see a 0, then stop.

Half Adder:
IN a, b
OUT sum, carry
sum=xor
carry=and


Full Adder:
IN a, b, c
OUT sum, carry


von Neuman Architecture (1940s)
ALU gate:
IN x, y, zx, nx, zy, ny, f, no
OUT out, zr, ng
if zx==1, x=0
if nx==1, x=!x
if zy==1, y=0
if ny==1, y=!y
if f==1 out=x+y
if f==0 out=And(x,y)
if no==1 out=!out
if out==0 zr=1 else zr=0
if out<0 ng=1 else ng=0


WEEK3:
Sequential logic: out(t) = f(in(t)); state(t) = f(state(t-1))

Clocked Data Flip Flop:
Remembers input from last time unit:
out(t) = in(t-1)


1 bit register:
if load(t-1) then out(t) = in(t-1) else out(t) = out(t-1)
can be scaled to 16/32/64 bit registers.

RAM abstraction:
A sequence of n addressable registers, with addresses 0 to n-1
At any given point of time, only 1 register in RAM is selected.

k(width of address input) = log(n)

RAM logic
__________
To read address i:
Set address to i
out emits the state of register i.

To set address i to v:
Set address = i
Set in = v
Set load = 1

A family of 16-bit RAM chips:
RAM8 - 8 unique registers, n=8, k=3
RAM64 - n=64, k=6
RAM16k - n=16384, k=14

Counters
suppose we are designing a robot who'll make brownies. We have instructions numbered 0 to 49.
Program Counter (PC) contains the address of the instruction that'll be fetched and executed next.
reset PC=0
next PC++
fetch PC=n
