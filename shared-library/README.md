```
mkdir build
cmake -S . -B build
cmake --build build --config Debug
cmake --build build --config Release
cmake --install build --prefix install --config Debug
cmake --install build --prefix install --config Release
```
