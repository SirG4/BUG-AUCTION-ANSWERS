**Error:** The script fails with an `IndexError: list index out of range` because the `while` loop condition `i <= len(seeds)` allows the index `i` to reach the length of the list, which is one past the valid maximum index.

**Hint:** Loop extra iteration.

## Fixes
- **C**: `// FIX: Changed loop condition from (i <= len(seeds)) to (i < len(seeds)) to prevent index out of range error.`
- **C++**: `// FIX: Changed loop condition from (i <= len(seeds)) to (i < len(seeds)) to prevent index out of range error.`
- **Java**: `// FIX: Changed loop condition from (i <= len(seeds)) to (i < len(seeds)) to prevent index out of range error.`
- **JavaScript**: `// FIX: Changed loop condition from (i <= len(seeds)) to (i < len(seeds)) to prevent index out of range error.`
- **Python**: `// FIX: Changed loop condition from (i <= len(seeds)) to (i < len(seeds)) to prevent index out of range error.`
