<div align="center">
  <img src="https://user-images.githubusercontent.com/98427284/220715371-f7c22a01-7a44-43d4-9180-5dfecf0c0485.png" height="150" width="150"/>

</div>

<h1 align ="center">
  42 Cursus' Minitalk

</h1>
<p align="center">This project is about coding a small data exchange program using ✨UNIX signals✨.</p>

## Installation

```sh
$> git clone https://github.com/Grsaiago/Minitalk.git && cd Minitalk && make
```

`make` supports the following flags.
- `all` or simply `make` -> Compiles the client and server and gets the project ready to go!
- `make clean` -> removes the executables.
- `make re` -> removes the executable and recompiles everything.

## Usage

```sh
./server
```
On another terminal:
```sh
./client <pid_printed_by_server> "<your_message>"
```
