# Digit Histogram From Standard Input

This program reads user input until `EOF` and counts how many times each digit (0-9) appears.
It also counts how many spaces, digits, and other characters were entered.

---

### The `K & R` book describe it:
Let us write a program to count the number of occurrences of each digit, of white spaces characters (blank, tab, newline). and of all other characters. This is artificial, but it permits us to illustrate serveral aspects of C in one program.

There are twelve categories of input, so it is convenient to use an array to hold the number of occurrnces of each digit, rather than ten invidual variables.

> I override this program in the book for myself for more study, also I needed to study these topics again, so I overrided it!

---

### Example Input:
`Hi, I love 01 world (I mean binary world). S0, 1'm R1ch13 4nd I l0v3 l0w-l3v3l pr09r4mm1n9.`

### Example Output:

```sql
0: 5 Repetitions.
1: 5 Repetitions.
3: 4 Repetitions.
4: 2 Repetitions.
9: 2 Repetitions.

Spaces: 18      Digits: 18      Others: 57
```

---

### Compile

```sh
gcc digit_counter_analysis.c -o digitCounter.out

./digitCounter.out
```
