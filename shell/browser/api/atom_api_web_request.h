// Copyright (c) 2015 GitHub, Inc.
// Use of this source code is governed by the MIT license that can be
// found in the LICENSE file.

#ifndef SHELL_BROWSER_API_ATOM_API_WEB_REQUEST_H_
#define SHELL_BROWSER_API_ATOM_API_WEB_REQUEST_H_

#include "gin/arguments.h"
#include "gin/handle.h"
#include "gin/object_template_builder.h"
#include "shell/browser/api/trackable_object_gin.h"
#include "shell/browser/net/atom_network_delegate.h"

namespace electron {

class AtomBrowserContext;

namespace api {

class WebRequest : public gin::TrackableObject<WebRequest> {
 public:
  static gin::Handle<WebRequest> Create(v8::Isolate* isolate,
                                        AtomBrowserContext* browser_context);

  // gin::Wrappable
  gin::ObjectTemplateBuilder GetObjectTemplateBuilder(
      v8::Isolate* isolate) override;

  static gin::WrapperInfo kWrapperInfo;

 protected:
  WebRequest(v8::Isolate* isolate, AtomBrowserContext* browser_context);
  ~WebRequest() override;

  // C++ can not distinguish overloaded member function.
  template <AtomNetworkDelegate::SimpleEvent type>
  void SetSimpleListener(gin::Arguments* args);
  template <AtomNetworkDelegate::ResponseEvent type>
  void SetResponseListener(gin::Arguments* args);
  template <typename Listener, typename Method, typename Event>
  void SetListener(Method method, Event type, gin::Arguments* args);

 private:
  scoped_refptr<AtomBrowserContext> browser_context_;

  DISALLOW_COPY_AND_ASSIGN(WebRequest);
};

}  // namespace api

}  // namespace electron

#endif  // SHELL_BROWSER_API_ATOM_API_WEB_REQUEST_H_
