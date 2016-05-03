# ecen5013-project-1
ECEN 5013 - James Pentz and Zach Vogel - Project 1 Build System and Software Design

# makefile commands:
These are all the makefile commands, the default architecture is x86:
```
make compile-all                 // compile all files do not link
make build                       // compile and link all files
make build CSTAND=c99            // compile and link all using c99 standard
make upload ARCH=arm             // compile, link, and upload code to beaglebone
make clean                       // clean the project
make build ARCH=arm              // compile and link all files for the ARM architecture
make ./asm/"filename".S          // create a single assembly file and place in asm folder
make ./asm/"filename".asm        // create a single assembly file and place in asm folder
make ./obj/"filename".o          // create a single object file and place in obj folder
```
