Problem 1 comments: 
For all three methods, as the number of t steps increases, the relative error decreases.
An exception occurs for RKO4, where the increase from 10k to 50k t steps increases the relative error.
For all three methods, the decrease in relative error is linearly related with the increase in t steps.
That said, the slope of RKO2 is larger (in absolute terms) than Euler, and the slope of RKO4 is larger than RKO2.
That means you get a larger decrease in relative error for the same increase in t steps for higher order methods.

For cost vs granularity, we see pretty much a linear relationship between t steps and instructions.
Unlike error vs granularity, all three methods have the same slopes.
No matter which method you choose, the increase in cost is the same for the same increase in t steps. 
This could be explained by the implementation of the solver. All three methods run the same algorithm, just the matrix size and values are changed.
Interestingly, higher order methods aren't that much costlier than Euler.
For example, at 1000 t steps, RKO4 is about 3 times more expensive than Euler. But the relative error is like 7 or 8 orders of magnitude smaller.

Using the O2 optimization, there is no difference in relative error vs t steps. 
However, there is notable improvements in cost vs t steps. 
Now the graph looks a bit more parabolic maybe. The major difference is that for RKO4 at 50k t steps, we saved more than half the cost.
From about 110 million down to about 50 million.
It looks like the higher the order, and the higher the granularity, the more cost savings we get.

Problem 2 comments: 
For the sine waves, we get frequency spikes at the expected values of 1200 and 1320 Hz. 
The 1320 Hz spike is a bit off due to the coarse frequency interval.

For the beats, again we get two frequency spikes at the expected values of 1200 and 1320 Hz.
The 1320 Hz spike is also a bit off, with the exact same offset.

Looking at beats.gif, the beat produced produced by summing two sine waves and propagating a beat boundary condition is exactly the same.

TECHNICAL COMMENTS:
-All .sh scripts in run/ should be executed in its parent directory
-All .sh and .plt scripts in plot/ should be executed in its parent directory
-The build.sh script should be executed in its current directory
-The .sh scripts in physics/ should be executed in physics/
-The .sh scripts in solver/ should be executed in solver/
-The beats.gif in graphics/ only contains 305 pngs. Above which Quest kills the convert command. 
-generate_gif.sh in plot/ will regenerated all 800 pngs for animation. Takes a long time.
-generate_gif2.sh in plot/ will convert existing pngs to a .gif. 
