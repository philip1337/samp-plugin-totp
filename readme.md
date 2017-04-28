# TOTP API - Google Authenticator for San Andreas Multiplayer #
This plugin allows you to use totp authentication in a sa-mp gamemode.
Using the [CppTotp Library](https://github.com/Sphinxila/cpptotp).

## Flush properties for logger
|native|params|return|
|-------|-------|:-----:|
|Totp|const secret[], step|int(totp code)|
|Totp|const secret[], time, step|int(totp code)|

## Build
#### Requirements
- [Modified version of gclient](https://github.com/timniederhausen/gclient)
- CMake >=3.1
- C++11
  - debian package: libc6-dev-i386

Synchronize dependencies from [DEPS](DEPS) File.

    gclient.py sync -v -f

You can also download it manually and place it into the external directory.

    mkdir build
    cd build
    cmake ..\samp-plugin-totp
    make

- [How to use cmake](https://github.com/bast/cmake-example)

## License
- [License](LICENSE)