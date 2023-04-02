# A backprop implementation for 'fun'!

Linux package install with `conan`:
```
conan install . -pr:h=conan/profiles/x86_64_linux -pr:b=conan/profiles/x86_64_linux -s build_type=Release --build=missing -of=build/x86_64_linux/release
conan install . -pr:h=conan/profiles/x86_64_linux -pr:b=conan/profiles/x86_64_linux -s build_type=Debug --build=missing -of=build/x86_64_linux/debug
```
