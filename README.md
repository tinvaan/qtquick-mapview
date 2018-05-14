# QtQuick-Mapview
A map UI interface that allows a user to plot a series of points and a UAV and simulate it's flight along the plotted path.

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
