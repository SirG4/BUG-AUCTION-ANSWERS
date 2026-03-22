**Error:** Reverse loop stops at 1 not 0, skips index 0.

**Hint:** Incorrect reverse loop.
Bug:

Reverse loop skipped first element (i > 0)
Index 0 was never processed

Fix:

Changed condition to:
i >= 0
Python: range(len(data)-1, -1, -1)
Terminal Output:
Result: 23ada46cde3fbb42