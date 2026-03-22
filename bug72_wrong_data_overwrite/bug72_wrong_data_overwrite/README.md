**Error:** Second pass XORed with backup (original) instead of staying as-is.

**Hint:** Wrong data overwrite.
Bug:

Original array values were modified:

data[i] = data[i] * (i + 1)
This corrupted input data

Fix:

Removed overwrite

Used data in read-only manner:

acc ^= data[i] * (i + 1)
Terminal Output:
Result: 23ada46cde3fbb42