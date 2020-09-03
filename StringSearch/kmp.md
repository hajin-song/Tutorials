# Knuth-Morris-Pratt Algorithm
Given a sentence, N, I would like to see if there is a word, M, in it.

## tl;dr;
When I am searching for a word in a sentence, only information I have fully is about the word I am looking for. And based on the characters of the word, I can skip some character comparison at each search attempt if there is some sort of a pattern in the word.

## Idea
Unlike naive string search (or pattern matching to be exact), I would like to find some clever way to avoid checking every single character in the sentence and avoid making unnecessary comparisons.

Since in naive algorithm, I continuously shift M by 1 until I find a match in N or run out of letters to search, so if I can shift M by some larger amount, I should still be able to find a match and save time on unncessary comparisons.

However, I cannot jump aggressively and shift by M as I could be missing some patterns.
```
//This is bad idea! I just missed a pattern!
A A A A B A A A A A B B B A A A A B
A A A B
      x
        A A A B
        x
                A A A B
                    x
                        A A A B
                        x
                                A A A B
```
Another thing I can try it by only jumping amount of characters I actually matched so far.
```
//...this didn't work either
A A A A B A A A A A B B B A A A A B
A A A B
      x
      A A A B
        x
        A A A B
        x
          A A A B
                x
                A A A B
                    x
                    A A A B
                    x
                      A A A B
                      x
                        A A A B
                        x
                          A A A B
                                x
                                A A A B
```
That didn't work either, the next thing we could try it jumping based on pattern we have matched so far.
```
A A A A C A A A A A B B B A A A A B
A A A B
o o o x // Move 1, but we can skip some comparisons
  A A A B
  - - o x // still some A's that could match
    A A A B
    - - x // still some A that could match
      A A A B
      - x // No more we can match :(
        A A A B
        x
          A A A B
          o o o x // skip some!
            A A A B
            - - o x // again!
              A A A B
              - - o o // match!
```

Ok, we still shifted by 1, but we didn't do full comparison on each step because we assumed some letters were already matching (and correctly so!).

So I need some information on what I matched so far somehow, but how we can dervie this without storing every single possible search?

## The main part
Since we are looking for a word to be found in a sentence, we can see it this way - we know what we are searching for, but we don't know the thing we are searching from!

So, we should seek information about comparisons that we can skip from the word we are looking for. From what I have seen earlier, if there is a pattern in the word, I can some how use it to skip some searching!

The Knuth-Morris-Pratt algorithm suggests one way to find this information.

Given
```
A A A B
```
If I mismatch at the first character, `A`, I can skip 0 letters for comparison (because I haven't seen anything yet!).

```
A A A B
0 ? ? ?
```

If I mismatch at the second character, `A`, I can skip 1 letters for comparison since I have seen one `A` immediately before!

```
A A A B
0 1 ? ?
```

If I mismatch at the third character, `A`, I can skip 2 letters for comparison since I have seen two `A` immediately before!

```
A A A B
0 1 2 ?
```

If I mismatch at the fourth character, `B`, I can skip 3 letters for comparison since I have seen three `A` immediately before!

```
A A A B
0 1 2 3
```