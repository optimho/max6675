# Raspberry PICO max6675
a working example with a library file for a max6675 thermocouple transducer
Use this to program the raspberry pico to read a max6675 driven thermocouple.

Included in this repository is the datasheet for the max6675

To get this to work you may have to edit the links in the CMakeLists file to match the name and location that you have cloned the project to.

change directory to build abd than you should beable to run cmake .. and then make - fix any problems as you go.

To make this project work, try creating a setup on your computer so that you can build a project for the PICO.
Then copy the max6675.h and max6675.c and max665_example.c into your project, make sure your CMakeLists refere to max665_example.c
I have not tried this but that should work.

Or create a project and just cut and past the code from in the .c and .h files into your own creations.


