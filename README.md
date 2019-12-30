qml-serialport
==============

qml-serialport contains QML wrappers for QSerialPort. It is tested with Qt 5.11.0 on the following:

- Ubuntu 18.04
- Windows 10 (MSVC 2017 x64) with Visual Studio 2017 Community

See [samples/](samples/) for example uses.

build [Linux]
---------------------

```
  $ mkdir build && cd build
  $ qt-install-dir/qt-version/target-platform/bin/qmake ..
  $ make install
```

This will install the QML plugin inside the Qt sysroot, which you must have write access to. **Be aware that this is not a sandboxed installation.**

build [Windows]
---------------

Run the following in the `Developer Command Prompt for VS 2017`:

```
  > "C:\Program Files (x86)\Microsoft Visual Studio\2017\Community\VC\Auxiliary\Build\vcvarsall.bat" amd64
  > mkdir build
  > cd build
  > qt-install-root\qt-version\target-platform\bin\qmake ..
  > nmake
  > nmake install
```

This will install the QML plugin inside the Qt sysroot, which you must have write access to. **Be aware that this is not a sandboxed installation.**
