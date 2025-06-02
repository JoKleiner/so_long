# so_long – 42 Project
**About:**<br/>
so_long is a small 2D game made with C and MiniLibX.<br/>
The goal: collect all items and reach the exit.<br/>
You learn about graphics, maps, and basic game logic.<br/>

![Game Screenshot](/Users/joklein/Desktop/so_long.png)

**Gameplay:**<br/>
Move with W, A, S, D<br/>
Collect all C (collectibles)<br/>
Go to E (exit) after collecting everything<br/>
Map includes: 1 = wall, 0 = floor, P = player, C = item, E = exit<br/>

**Features:**<br/>
Map loaded from .ber file<br/>
2D graphics with MiniLibX<br/>
Input handling and step counter<br/>

**Compile & Run:**

    make && ./so_long maps/map.ber

**Learned:**<br/>
Drawing with MiniLibX<br/>
Parsing maps and validating input<br/>
Handling movement and collisions<br/>
Writing clean and leak-free C code<br/>
