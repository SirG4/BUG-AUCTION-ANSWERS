# Bug 16 – Loop Never Executes

## Bug Description
The while loop condition uses the wrong comparison operator (`>`), so it never executes since `i` starts at `0` and can never be greater than the length of the list.

---

## Python (`main.py`)

### Buggy Code (relevant lines)
```python
while i > len(items):   # BUG: should be <
```

### Fixed Code
```python
while i < len(items):   # FIX: changed > to <
```

### Lines Changed
- **Line 8**: `while i > len(items):` → `while i < len(items):`

### Output (Terminal)
```
1Q3jpJsRtjM=
```

---

## Java (`main.java`)

### Buggy Code (relevant lines)
```java
while (i > items.length) {   // BUG: should be <
```

### Fixed Code
```java
while (i < items.length) {   // FIX: changed > to <
```

### Lines Changed
- **Line 13**: `while (i > items.length)` → `while (i < items.length)`

### Output (Terminal)
```
1Q3jpJsRtjM=
```

---

## C (`main.c`)

### Buggy Code (relevant lines)
```c
while (i > len) {   // BUG: should be <
```

### Fixed Code
```c
while (i < len) {   // FIX: changed > to <
```

### Lines Changed
- **Line 44**: `while (i > len)` → `while (i < len)`

### Output (Terminal)
```
1Q3jpJsRtjM=
```

---

## C++ (`main.cpp`)

### Buggy Code (relevant lines)
```cpp
while (i > items.size()) {   // BUG: should be <
```

### Fixed Code
```cpp
while (i < items.size()) {   // FIX: changed > to <
```

### Lines Changed
- **Line 42**: `while (i > items.size())` → `while (i < items.size())`

### Output (Terminal)
```
1Q3jpJsRtjM=
```

---

## JavaScript (`main.js`)

### Buggy Code (relevant lines)
```js
while (i > items.length) {   // BUG: should be <
```

### Fixed Code
```js
while (i < items.length) {   // FIX: changed > to <
```

### Lines Changed
- **Line 5**: `while (i > items.length)` → `while (i < items.length)`

### Output (Terminal)
```
1Q3jpJsRtjM=
```
