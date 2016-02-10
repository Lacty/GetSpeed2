
#GetSpeed2

## 環境
    Windows10 vs2015
    OSX Xcode

## 症状
    glfwSwapIntervalで1を指定しているにも関わらず
    FPSが60を超えてしまう
    なお、Xcodeだと正常に動作する(60fps)

- glfwSwapInterval : appNative.cpp (18行)
- 描画はtitle.cppにて
