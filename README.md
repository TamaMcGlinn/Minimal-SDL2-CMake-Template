# Prerequisites

Install a bunch of SDL2 development libraries; the following installs the lot, not just the necessary ones:

```
apt-cache search libsdl2 | cut -d' ' -f1 | xargs sudo apt-get install -y
```

# Building

```
mkdir build
cd build
cmake ..
make
```

# Run

```
./hello_sdl
```
