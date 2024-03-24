# bat2exe

A simple builder tool to compile a .bat as a series of commands in a .exe program wrapper. 

## Program Usage

Terminal / cmd.exe: 
- Just open bat2.exe (double-click, etc)
CLI:
```
./bat2.exe <path/to/file>
```


## Compiling Example

```
g++ main.cpp -static -o bat2

bat2.exe demo.bat

g++ run.cpp -static -o run
```

You must compile main into bat2.exe first, then use that to convert a bat (ex: demo.bat) file, so that the data.h file is fully generated. Once this is done, you can compile run.cpp, which is your converted .bat - You must always re-compile run.cpp each time you want to convert a new bat to a Windows PE / exe program.


### Files

- main.cpp contains the logic to accept a .bat file as an input (on CLI or drag & drop original program on top of bat2 in file explorer). It then pushes the XOR-encrypted bytes to a header file (data.h) 

- data.h contains the XOR-encrypted bytes for the original .bat, line by line

- xor.cpp contains the single key XOR encrypt/decrypt 2-way function. Note: this is a beginner demo example and should not be considered secure for sensitive data

- run.cpp contains the logic to include the data from data.h file, decrypt XOR and then run each line of the original batch file. 

- demo.bat is a basic example that lists current folder items & pauses the open console