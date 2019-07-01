// Copyright (c) 2019 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#include "shell/common/gin_converters/gin_value_converter.h"

#include <memory>

#include "base/values.h"
#include "shell/common/gin_converters/gin_v8_value_converter.h"

namespace gin {

bool Converter<base::DictionaryValue>::FromV8(v8::Isolate* isolate,
                                              v8::Local<v8::Value> val,
                                              base::DictionaryValue* out) {
  electron::V8ValueConverter converter;
  std::unique_ptr<base::Value> value(
      converter.FromV8Value(val, isolate->GetCurrentContext()));
  if (value && value->is_dict()) {
    out->Swap(static_cast<base::DictionaryValue*>(value.get()));
    return true;
  } else {
    return false;
  }
}

v8::Local<v8::Value> Converter<base::DictionaryValue>::ToV8(
    v8::Isolate* isolate,
    const base::DictionaryValue& val) {
  electron::V8ValueConverter converter;
  return converter.ToV8Value(&val, isolate->GetCurrentContext());
}

bool Converter<base::Value>::FromV8(v8::Isolate* isolate,
                                    v8::Local<v8::Value> val,
                                    base::Value* out) {
  electron::V8ValueConverter converter;
  std::unique_ptr<base::Value> value(
      converter.FromV8Value(val, isolate->GetCurrentContext()));
  if (value) {
    *out = value->Clone();
    return true;
  } else {
    return false;
  }
}

v8::Local<v8::Value> Converter<base::Value>::ToV8(v8::Isolate* isolate,
                                                  const base::Value& val) {
  electron::V8ValueConverter converter;
  return converter.ToV8Value(&val, isolate->GetCurrentContext());
}

bool Converter<base::ListValue>::FromV8(v8::Isolate* isolate,
                                        v8::Local<v8::Value> val,
                                        base::ListValue* out) {
  electron::V8ValueConverter converter;
  std::unique_ptr<base::Value> value(
      converter.FromV8Value(val, isolate->GetCurrentContext()));
  if (value->is_list()) {
    out->Swap(static_cast<base::ListValue*>(value.get()));
    return true;
  } else {
    return false;
  }
}

v8::Local<v8::Value> Converter<base::ListValue>::ToV8(
    v8::Isolate* isolate,
    const base::ListValue& val) {
  electron::V8ValueConverter converter;
  return converter.ToV8Value(&val, isolate->GetCurrentContext());
}

}  // namespace gin
