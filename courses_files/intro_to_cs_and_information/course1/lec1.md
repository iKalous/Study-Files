# About Set

There are 8 axioms for set, but we only discuss one of them in class, Axiom of Regularity.

**Axiom of Regularity**
- For a set A, it must follow that:
    $$
        \exists x \in A, x \cap A = \emptyset
    $$

Take $ A = \{ x | x > 1, x \in R \}  $ for an example.
For an arbitrary element in this set, for instance, 2, $ 2 \cap A = \emptyset $, **Please Note that**, $ \{2\} \ne 2$, $ \{2\} \cap A = \{2\} $, but $ \{2\} \notin A$

So here pay attention to the differencese between **element** and **subset**.

Then we talk about some operations on set, set difference, power set.

**set difference**

For set $A$ and $B$, $A - B:$
$$
    A - B = \{x|x \in A, x \notin B \}
$$

**power set**

For set $A$, $P(A):$
$$
    P(A) = \{X|X \subseteq A \}
$$