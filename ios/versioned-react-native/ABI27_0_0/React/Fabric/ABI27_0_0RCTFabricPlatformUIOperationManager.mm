/**
 * Copyright (c) 2015-present, Facebook, Inc.
 *
 * This source code is licensed under the MIT license found in the
 * LICENSE file in the root directory of this source tree.
 */

#import "ABI27_0_0RCTFabricPlatformUIOperationManager.h"

namespace facebook {
namespace ReactABI27_0_0 {

ABI27_0_0RCTFabricPlatformUIOperationManagerConnector::ABI27_0_0RCTFabricPlatformUIOperationManagerConnector() {
  self_ = (__bridge_retained void *)[ABI27_0_0RCTFabricPlatformUIOperationManager new];
  manager_ = (__bridge ABI27_0_0RCTFabricPlatformUIOperationManager *)self_;
}

ABI27_0_0RCTFabricPlatformUIOperationManagerConnector::~ABI27_0_0RCTFabricPlatformUIOperationManagerConnector() {
  CFRelease(self_);
  self_ = NULL;
  manager_ = NULL;
}

void ABI27_0_0RCTFabricPlatformUIOperationManagerConnector::performUIOperation() {
  [manager_ performUIOperation];
}

} // namespace ReactABI27_0_0
} // namespace facebook

// -----------------------------------------------------------------------------
// Start of ObjC++ impl
// Access UIKit here.
// -----------------------------------------------------------------------------
@implementation ABI27_0_0RCTFabricPlatformUIOperationManager

- (void)dealloc
{
  NSLog(@"ABI27_0_0RCTFabricPlatformUIOperationManager: dealloc()");
}

- (void)performUIOperation
{
  // TODO
  NSLog(@"ABI27_0_0RCTFabricPlatformUIOperationManager: performUIOperation()");
}

@end
