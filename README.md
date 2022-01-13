# SO_LONG
So_Long project is a 2D game builder with minilibx that can read/parse any given map.
<p align="center">
	<img alt="GitHub code size in bytes" src="https://img.shields.io/github/languages/code-size/Ajjig/SO_LONG?color=blueviolet" />
	<img alt="Number of lines of code" src="https://img.shields.io/tokei/lines/github/Ajjig/SO_LONG?color=blueviolet" />
	<img alt="Code language count" src="https://img.shields.io/github/languages/count/Ajjig/SO_LONG?color=blue" />
	<img alt="GitHub top language" src="https://img.shields.io/github/languages/top/Ajjig/SO_LONG?color=blue" />
	<img alt="GitHub last commit" src="https://img.shields.io/github/last-commit/Ajjig/SO_LONG?color=brightgreen" />
</p>
<img width="1859" alt="Screen Shot 2021-12-14 at 8 53 40 PM" src="https://user-images.githubusercontent.com/74059327/146507928-2f87bd86-dd32-4761-b141-b1252f14df31.png">

# COMPILE
```Bash
cd path/to/SO_LONG && make
```
for bonus part:
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
