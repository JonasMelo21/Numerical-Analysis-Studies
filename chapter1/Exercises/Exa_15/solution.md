# Solution

## A) Let's show that for F1(x) = L1 + O(x^a), F2(x) = L1 + O(x^b) and y = min{a,b} we have: F(x) = c1*L1 + c2*L2 + O(x^y). Where c1 and c2 are not zero

F(x) = c1 * F1(x) + c2 * F2(x)

As F1(x) = L1 + O(x^a) and F2(x) = L1 + O(x^b), then:

F(x) = c1 * (L1 + O(x^a)) + c2 * (L2 + O(x^b))

F(x) = c1 * L1 + c2 * L2 + O(x^a + x^b)

As y = min {a,b} we have.:

F(x) = c1 * L1 + c2 * L2 + O(x^y)

## B) Let's show that G(x) = L1 + L2 + O(x^y)

G(x) = F1(c1 * x) + F2(c2 * x)

G(x) = L1 + O(c1 * x^a) + L2 + O(c2 * x^b)

G(x) = L1 + L2 + O(x^y). Where y = min{a,b}