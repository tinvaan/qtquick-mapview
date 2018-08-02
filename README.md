# QtQuick-Mapview
A map UI interface that allows a user to plot a series of points and a UAV and simulate it's flight along the plotted path.
For a given list of initial waypoints, a more complete list of waypoints are calculated using linear interpolation between every successive pair of waypoints and this forms the path for the UAV's flight simulation.

## Requirements
The following packages must be installed in order to build the current source.
1. `cmake`
2. `Qt5` (`QtLocation` and `QtPositioning` modules must be installed)

## Installing
Clone the repository.
```
    $ cd qtqtuick-mapview
    $ mkdir build; cd build
    $ cmake ..
    $ make
```

Launch the `mapview` executable, inside the `build/src` directory.

```
    ./mapview
```

## Instructions
* Click anywhere on the map to plot waypoints.(indicated by red `MapCircle`s)
* Double click anywhere on the map to park the UAV.(indicated by a black `MapCircle`)
* Click on the `Fly` button at the bottom right corner of the window to launch the simulation.

## Screenshot
![UAV flight simulation around a part of Singapore](https://i.imgur.com/hzDYMAW.png "QtQuick Mapview Flight Simulator")
