#!/bin/bash
export CONAN_HOME=/work/.conan2
echo $CONAN_HOME
conan config home
conan install . \
  --profile:host=./profiles/linux \
  --profile:build=./profiles/linux \
  --build=missing \
  -of=./build/linux/debug \
  -s build_type=Debug \
  -c tools.cmake.cmaketoolchain:user_presets=""
