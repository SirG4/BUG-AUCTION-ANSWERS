# Bug 19 – Appended to Wrong List

## Bug Description
In the `else` branch (odd numbers), `evens.append(n)` is used instead of `odds.append(n)`. This fills `evens` with all 20 numbers and leaves `odds` empty, causing a crash.

---

## Python (`main.py`)
### Buggy Line
```python
else:
    evens.append(n)   # BUG: odd numbers go to evens
```
### Fixed Line
```python
else:
    odds.append(n)    # FIX: odd numbers must go to odds
```
### Line Changed: **Line 10**
### Output
```
SGuFBk48l3Y=
```

---

## Java (`main.java`)
### Buggy Line
```java
else { evens.add(n); }
```
### Fixed Line
```java
else { odds.add(n); }
```
### Line Changed: **Line 14**
### Output
```
SGuFBk48l3Y=
```

---

## C (`main.c`)
### Buggy Line
```c
else { evens[evens_len++] = n; }
```
### Fixed Line
```c
else { odds[odds_len++] = n; }
```
### Line Changed: **Line 42**
### Output
```
SGuFBk48l3Y=
```

---

## C++ (`main.cpp`)
### Buggy Line
```cpp
else { evens.push_back(n); }
```
### Fixed Line
```cpp
else { odds.push_back(n); }
```
### Line Changed: **Line 44**
### Output
```
SGuFBk48l3Y=
```

---

## JavaScript (`main.js`)
### Buggy Line
```js
else { evens.push(n); }
```
### Fixed Line
```js
else { odds.push(n); }
```
### Line Changed: **Line 7**
### Output
```
SGuFBk48l3Y=
```
