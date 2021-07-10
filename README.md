# RND Render Engine

Toy rendering engine for running biochemical simulations in an OpenGL context.

## Goals

The purpose of this rendering engine is to allow for an arbitrary application to setup your simulation parameters (or load from a file), and then execute that simulation visually in a separate window.

While the end goal is to be platform and language-agnostic, this means that unique bindings will need to be generated for each language. At the moment, no bindings exist and the entire application consists of the renderer. Once the renderer is mature enough, bindings will be generated for different platforms and languages, starting with the simplest bindings first.

### Bindings Timeline

[ ] *Standalone Renderer*: The renderer library should be able to run well on its own, capable of populating an arbitrary number of simulation contexts.

[ ] *CLI Wrapper*: Invoke the renderer using command-line arguments to specify your simulation parameters.

[ ] *File Loader*: Load simulation parameters from a file, starting by adding a file path argument to the CLI.

[ ] *C++ ImGui Wrapper*: First standalone application capable of specifying simulation parameters through a GUI. As the bindings to C++ are simplest here, ImGui will be used to create the GUI.

### Stretch Goals

While the "bare minimum" will be the C++ GUI, eventually the idea is to provide bindings to allow a visual application and library API for a variety of languages and runtimes.

[ ] *.NET Core*: GUI using standard .NET forms. Library which can be imported into .NET and used with languages like C#.

[ ] *Python Library*: Library for Python. Probably no point in building a Python-based GUI.

[ ] *WebAssembly Wrapper*: By far the biggest stretch goal. Ideally, the C++ library could be compiled to WebAssembly and draw calls be made with WebGL.

## Compiling

CMake is used for our build system, and Git submodules are currently used heavily for dependency management. Obviously, other dependencies which may forego the use of submodules may appear in the future. However, recursive cloning is required at the moment.

### Required:

- Git (obviously)
- CMake v3.19+
- GPU capable of supporting OpenGL 4

### Install/Build

1. Clone the repository recursively.

2. Run `cmake .` to generate project files. Out-of-source is also optional but recommended.

3. Run `cmake --build .` to build, or invoke your platform's build tool.

```sh
$ git clone --recursive https://github.com/jtcooper10/RNDRender
# In-source:
$ cmake .
$ cmake --build .
# On Linux, you can run this instead of cmake --build:
$ make RenderingEngine
```

Currently, no system-level dependencies are required, but this is likely to change in the future.

Once built, ensure that `LibRenderer.dll` (or `LibRenderer.so` on Posix platforms) exists in the same directory as the executable. CMake should handle this automatically. Otherwise, run `RenderingEngine.exe` (or `RenderingEngine` on Posix platforms).
