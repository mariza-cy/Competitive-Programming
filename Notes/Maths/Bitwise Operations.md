# Bitwise Operations

Biwise operations are operations that are done on the binary representation of a number. We can use the binary operators of C++ just like a normal operator (like `+`)

## Main bitwise operators in C++

### NOT (`~` / $\neg$)
**Symbol in C++**: `~`\
**Symbol in maths**: $\neg$

The NOT operation flips all the bits of a number:

|$a$|$\neg a$|
|---|--------|
|0  |1       |
|1  |0       |

For example, the last 5 digits of $\neg(9_{10}) = \neg(01001_2) = 10110_2 = 22_{10}$
```
01001
-----
10110
```

### OR (`|` / $\lor$)
**Symbol in C++**: `|`\
**Symbol in maths**: $\lor$

Each bit in the OR of two numbers is on if it's also on in *at least one* of the numbers:

|$a$|$b$|$a \lor b$|
|---|---|----------|
|0  |0  |0         |
|0  |1  |1         |
|1  |0  |1         |
|1  |1  |1         |

For example, $(9_{10}) \lor (3_{10}) = (1001_2) \lor (0011_2) = 1011_2 = 11_{10}$
```
1001
0011
----
1011
```

### AND (`&` / $\land$)
**Symbol in C++**: `&`\
**Symbol in maths**: $\land$

Each bit in the AND of two numbers is on if on in *both* of the numbers:

|$a$|$b$|$a \land b$|
|---|---|-----------|
|0  |0  |0          |
|0  |1  |0          |
|1  |0  |0          |
|1  |1  |1          |

For example, $(9_{10}) \land (3_{10}) = (1001_2) \lor (0011_2) = 1_2 = 1_{10}$
```
1001
0011
----
0001
```

### XOR (`^` / $\oplus$)
**Symbol in C++**: `^`\
**Symbol in maths**: $\oplus$

Each bit in the XOR of two numbers is on if it's also on in *exactly one* of the numbers:

|$a$|$b$|$a \oplus b$|
|---|---|------------|
|0  |0  |0           |
|0  |1  |1           |
|1  |0  |1           |
|1  |1  |0           |

For example, $(9_{10}) \oplus (3_{10}) = (1001_2) \oplus (0011_2) = 1010_2 = 10_{10}$
```
1001
0011
----
1010
```

#### Properties
1. $a \oplus (b \oplus c) = (a \oplus b) \oplus c$, so we can use it without paying attention to grouping
2. $a \oplus 0 = a$
3. $a \oplus a = 0$, so we can ignore each pair of equal values
4. The $i$-th bit of $a_1 \oplus a_2 \oplus \dots \oplus a_n$ is on if the $i$-th bit is on in an odd number of $a_j$, otherwise it's off
5. $a \oplus b = c \iff a = b \oplus c$

### Bit shift (`<<` and `>>`)
**Symbols in C++**:\
Left shift: `<<`\
Right shift: `>>`

The left and right shift operators shift all the bits to the left and right, respectively, by the value specified.

For example since $9_{10} = 1001_2$, `9 << 2` is equal to $100100_2 = 36_{10}$ - all the bits are shifted 2 positions to the right and the last two positions are set to $0$.

Similarly, `9 >> 1` is $100_2 = 4_{10}$ - all the bits are shifted 1 position to the right and the bits that overflow to the right disappear.
