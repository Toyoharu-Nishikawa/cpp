{
    "version": 6,

    "configurePresets": [
        {
            "name": "linux-release",
            "generator": "Ninja",
            "binaryDir": "${sourceDir}/build/linux",
            "cacheVariables": {
                "CMAKE_BUILD_TYPE": "Release"
            }
        },

        {
            "name": "windows-release",
            "generator": "Ninja",
            "binaryDir": "${sourceDir}/build/windows",
            "toolchainFile": "${sourceDir}/cmake/mingw-w64-x86_64.cmake",
            "cacheVariables": {
                "CMAKE_BUILD_TYPE": "Release"
            }
        }
    ],

    "buildPresets": [
        {
            "name": "linux-release",
            "configurePreset": "linux-release"
        },

        {
            "name": "windows-release",
            "configurePreset": "windows-release"
        }
    ]
}
