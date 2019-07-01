// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef SHELL_COMMON_GIN_CONVERTERS_ARRAY_CONVERTER_H_
#define SHELL_COMMON_GIN_CONVERTERS_ARRAY_CONVERTER_H_

#include <string>

#include "gin/converter.h"

namespace gin {

template <>
struct Converter<v8::Local<v8::Array>> {
  static v8::Local<v8::Value> ToV8(v8::Isolate* isolate,
                                   v8::Local<v8::Array> val) {
    return val;
  }
  static bool FromV8(v8::Isolate* isolate,
                     v8::Local<v8::Value> val,
                     v8::Local<v8::Array>* out) {
    if (!val->IsArray())
      return false;
    *out = v8::Local<v8::Array>::Cast(val);
    return true;
  }
};

}  // namespace gin

#endif  // SHELL_COMMON_GIN_CONVERTERS_ARRAY_CONVERTER_H_
