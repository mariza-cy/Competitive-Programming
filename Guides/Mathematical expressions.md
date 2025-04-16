
## Adding an equasion
You can add equations either in-line: $a^2 = b^2 + c^2$, or as a block:
```math
a^2 = b^2 + c^2
```

### In-line equations
In both Markdown and Codeforces, to add an in-line equation add a `$` before and after the equation. For example:
```
The Pythagorean theorem: $a^2 = b^2 + c^2$
```
The result is:\
The Pythagorean theorem: $a^2 = b^2 + c^2$

### Block equations
In Codeforces, to add a block equation simply add `$$` instead of `$` before and after it. For example:
```
$$a^2 = b^2 + c^2$$
```
In Markdown, create a code block (using ```` ``` ```` before and after), but writing `math` after the beginning ```` ``` ````:
````
```math
a^2 = b^2 + c^2
```
````

The result of both is:
```math
a^2 = b^2 + c^2
```

## The basics
- Use `^` for superscript and `_` for subscript: `a^2`: $a^2$, `x_i`: $x_i$
- `{}` work like parentheses in programming: `a^{10}`: $a^{10}$ (while `a^10` is presented as $a^10$)
<!-- - `\` is used in the beginning of commands, but is also an escape character: `S = \{1, 2, 3\}`: $S = \{1, 2, 3\}$ (while `S = {1, 2, 3}` is $S = {1, 2, 3}$) -->
- You can use other characters, such as `+`, `=` and `(` normally

## Common symbols

<!--
|Name           |Command        |Result         |Example        |Example result |
|---------------|---------------|---------------|---------------|---------------|
|               |               |               |               |               |
-->

### Basic operators

|Name           |Command        |Result         |Example        |Example result |
|---------------|---------------|---------------|---------------|---------------|
|Multiplication |`\cdot`        |$\cdot$        |`a \cdot b`    |$a \cdot b$    |
