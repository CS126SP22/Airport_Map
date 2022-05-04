

## How to run the project
* Download the Cinder
* Move this project to Cinder/my-projects
* Run the cinder_app_main.cc

## What my project does

![app_interface](/images/app.png)

### Summary
My project could help users find the shortest path 
from starting point to ending point. Users could place
starting point and ending point and set obstacles.  By clicking show path, the shortest path will show on the map.

### Cells
Left-clicking on the white cells could turn the empty cells to
the obstacles. Similarly, left-clicking on the gray cells could turn the obstacles to empty cells.
* White cell: empty
* Green cell: starting point
* Red cell: ending point
* Gray cell: obstacle
* Blue cell: Shortest path cell

### Buttons
* Choose Starting Point or Ending Point: After clicking the button, you could place the starting point or ending point 
by right-clicking on the map
* Clear Button: Removes all the obstacles and reset the starting point and ending point to default position
* Show Path: By clicking this button, the shortest path shows. If there is no path from the starting point to ending pointy,
no path will show
* Save Graph: It will save the current graph setting to data/map.txt
* Load Graph: It will load the graph setting from data/map.txt

