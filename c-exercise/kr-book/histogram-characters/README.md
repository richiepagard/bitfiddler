# Histogram Of The Frequencies Of Different Characters

This is an exercise from **The C Programming Language** book by **Brian Kernighan** and **Dennis Ritchie**.
It appears in **Chapter 1**, under the topic of **Arrays**.

> **Exercise:**
> Write a program to print a histogram of the frequencies of different characters in its input.

---

### Notes
---
- Characters in C are represented as **integers** (based on the **ACII** table), so we can use them in arithmetic and comparison. Actually, everything is an integer!
- How to find the place of an alpha character in the alphabet. I just had to subtract a specific character by `a`.
> e.g., **t** is in the **19**. I found it like this: `printf("%d\n", 't' - 'a');`

- How to find a character in alphabet with its place in alphabet. Just need to plus `a` by the specific place like `19`.
> e.g., **19** is **t**. I found it like this: `printf("%c\n", 'a' + 19);`
---
