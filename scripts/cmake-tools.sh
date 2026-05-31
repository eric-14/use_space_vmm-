#!/usr/bin/env bash 

#configure 
#!/usr/bin/env bash

set -euo pipefail

BUILD_DIR="build"

case "${1:-build}" in
    build)
        echo "Building Spartan... "
        cmake -S . -B "$BUILD_DIR"
        cmake --build "$BUILD_DIR" 
        "$BUILD_DIR/spartan"
        ;;
    rebuild)
        echo "Cleaning Spartan build history"
        rm -rf "$BUILD_DIR"

        echo "Building spartan...."
        cmake -S . -B "$BUILD_DIR"
        cmake --build "$BUILD_DIR"
        "$BUILD_DIR/spartan"
        ;;
    dev) 
        echo -e "[INFO] Building spartan with dev enable.\n 
              Clang Tidy and Clang Format will parse changes\n"
        cmake -S . -B "$BUILD_DIR"
        cmake --build "$BUILD_DIR" --target format
        cmake --build "$BUILD_DIR" --target tidy
        "$BUILD_DIR/spartan"
    ;;
    *)
        echo "Usage: $0 [build|rebuild]"
        exit 1
        ;;
esac

# echo "Completed building spartan"