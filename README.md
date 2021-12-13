# SO_LONG
Description This project is a small 2D game that can read/parse any given map.
# COMPILE
```Bash
cd path/to/SO_LONG && make
```
or for bonus part
```Bash
cd path/to/SO_LONG && make bonus
```
# How-To-Play

```Bash
./exec /path/to/my_map.ber
```

#### You can use given maps or you can generate your own one respecting following rules.

* A textfile with '.ber' extension.
* It must be rectangular.
* It must be surrounded by wall '1'.
* Must have at least one exit, only one player and at least one collectible.

|  Character  |          Object          |
|:-----------:|:------------------------:|
|     *1*     | wall                     |
|     *0*     | Empty                    |
|     *C*     | collectible              |
|     *E*     | exit                     |
|     *P*     | Player starting position |
# Map-Examples
```
111111111111111
1100000C10011E1
10000000C000001
1C00000110C0V01
1C00000000P0001
1C00V00000C0001
111111111111111
```
```
1111111111111111111111111
1E0000000000000C000000001
1010010100100000100010101
1010010010101010000010101
1P0000C00C00C0000000000C1
1111111111111111111111111
```
