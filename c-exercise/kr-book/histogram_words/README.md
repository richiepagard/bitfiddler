# Histogram Of The Length Of Words

This is an exercise from **The C Programming Language** book by **Brian Kernighan** and **Dennis Ritchie**.
It appears in **Chapter 1**, under the topic of **Arrays**.

> **Exercise:**
> Write a program to print a histogram of the length of words in its input.
> It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.

---

### Notes
---
- Learned how to read input character by character using `getchar()`.
- Managing **word boundaries** manually requires careful **state** control (i.e., knowing when we're inside or outside a word).
- In C, **array subscripts always start at `0`**.
- Characters in C are represented as **integers** (based on the **ACII** table), so we can use them in arithmetic and comparison.

---
