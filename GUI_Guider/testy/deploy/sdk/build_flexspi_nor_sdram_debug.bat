cmake -DCMAKE_TOOLCHAIN_FILE="armgcc.cmake" -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=flexspi_nor_sdram_debug  .
mingw32-make -j
IF "%1" == "" ( pause ) 
