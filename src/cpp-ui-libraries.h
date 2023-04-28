#pragma once


#ifdef _WIN32
  #define CPP_UI_LIBRARIES_EXPORT __declspec(dllexport)
#else
  #define CPP_UI_LIBRARIES_EXPORT
#endif

CPP_UI_LIBRARIES_EXPORT void cpp_ui_libraries();
