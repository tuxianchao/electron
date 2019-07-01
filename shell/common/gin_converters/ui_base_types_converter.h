// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef SHELL_COMMON_GIN_CONVERTERS_UI_BASE_TYPES_CONVERTER_H_
#define SHELL_COMMON_GIN_CONVERTERS_UI_BASE_TYPES_CONVERTER_H_

#include "gin/converter.h"
#include "ui/base/ui_base_types.h"

namespace gin {

template <>
struct Converter<ui::MenuSourceType> {
  static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,
                                   const ui::MenuSourceType& in) {
    switch (in) {
      case ui::MENU_SOURCE_MOUSE:
        return gin::StringToV8(isolate, "mouse");
      case ui::MENU_SOURCE_KEYBOARD:
        return gin::StringToV8(isolate, "keyboard");
      case ui::MENU_SOURCE_TOUCH:
        return gin::StringToV8(isolate, "touch");
      case ui::MENU_SOURCE_TOUCH_EDIT_MENU:
        return gin::StringToV8(isolate, "touchMenu");
      default:
        return gin::StringToV8(isolate, "none");
    }
  }
};

}  // namespace gin

#endif  // SHELL_COMMON_GIN_CONVERTERS_UI_BASE_TYPES_CONVERTER_H_
