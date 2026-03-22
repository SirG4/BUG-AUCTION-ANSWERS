**Error:** Last element skipped (range stops at len-1).

**Hint:** Skipped last element.
Bug:

Loop stopped early (i < 9 or len(data) - 1)
Last element was skipped

Fix:

Changed loop condition to include full range:
i < 10
range(len(data))
Terminal Output:
Result: 0x23ada46cde3fbb42