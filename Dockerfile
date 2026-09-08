FROM ubuntu:latest
RUN apt update && apt install -y \
    clang \
    mingw-w64 \
    ninja-build \
    make \
    cmake \
    libgtest-dev


#    libc++-dev \
#    libc++abi-dev
