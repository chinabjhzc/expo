/**
 * Copyright (c) Facebook, Inc. and its affiliates.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#pragma once

#include <ABI36_0_0React/attributedstring/AttributedString.h>
#include <ABI36_0_0React/textlayoutmanager/TextLayoutManager.h>

#ifdef ANDROID
#include <folly/dynamic.h>
#endif

namespace ABI36_0_0facebook {
namespace ABI36_0_0React {

/*
 * State for <Paragraph> component.
 * Represents what to render and how to render.
 */
class ParagraphState final {
 public:
  /*
   * All content of <Paragraph> component represented as an `AttributedString`.
   */
  AttributedString attributedString;

  /*
   * `TextLayoutManager` provides a connection to platform-specific
   * text rendering infrastructure which is capable to render the
   * `AttributedString`.
   */
  SharedTextLayoutManager layoutManager;

#ifdef ANDROID
  ParagraphState(
      AttributedString const &attributedString,
      SharedTextLayoutManager const &layoutManager)
      : attributedString(attributedString), layoutManager(layoutManager) {}
  ParagraphState() = default;
  ParagraphState(folly::dynamic const &data) {
    assert(false && "Not supported");
  };
  folly::dynamic getDynamic() const;
#endif
};

} // namespace ABI36_0_0React
} // namespace ABI36_0_0facebook
