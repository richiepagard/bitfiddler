# Folding Long Input Lines Into Two Or More Shorter Lines

This is an exercise from **The C Programming Language** book by **Brian Kernighan** and **Dennis Ritchie**.
It appears in **Chapter 1**, last 5 exercises. This is the **Exercise 1-22**.

> **Exercise:**
> Write a program to ``fold'' long input lines into two or more shorter lines after
the last non-blank character that occurs before the n-th column of input. Make sure your
program does something intelligent with very long lines, and if there are no blanks or tabs
before the specified column.

---

## Notes

- `#define` a line limit (`LINELIMIT`) to specify the maximum number of characters per line.
- Count each character to track the current line position.
- Count character even in the condition, if the current character is space go to the next character anyway.
- Use `continue` to skip printing the space itself, so folded lines don't start with a blank.

---
