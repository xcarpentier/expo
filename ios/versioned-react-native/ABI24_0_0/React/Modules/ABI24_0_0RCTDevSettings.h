/**
 * Copyright (c) 2015-present, Facebook, Inc.
 * All rights reserved.
 *
 * This source code is licensed under the BSD-style license found in the
 * LICENSE file in the root directory of this source tree. An additional grant
 * of patent rights can be found in the PATENTS file in the same directory.
 */

#import <ReactABI24_0_0/ABI24_0_0RCTBridge.h>
#import <ReactABI24_0_0/ABI24_0_0RCTDefines.h>

@protocol ABI24_0_0RCTPackagerClientMethod;

/**
 * An abstraction for a key-value store to manage ABI24_0_0RCTDevSettings behavior.
 * The default implementation persists settings using NSUserDefaults.
 */
@protocol ABI24_0_0RCTDevSettingsDataSource <NSObject>

/**
 * Updates the setting with the given key to the given value.
 * How the data source's state changes depends on the implementation.
 */
- (void)updateSettingWithValue:(id)value forKey:(NSString *)key;

/**
 * Returns the value for the setting with the given key.
 */
- (id)settingForKey:(NSString *)key;

@end

@interface ABI24_0_0RCTDevSettings : NSObject

- (instancetype)initWithDataSource:(id<ABI24_0_0RCTDevSettingsDataSource>)dataSource;

@property (nonatomic, readonly) BOOL isHotLoadingAvailable;
@property (nonatomic, readonly) BOOL isLiveReloadAvailable;
@property (nonatomic, readonly) BOOL isRemoteDebuggingAvailable;
@property (nonatomic, readonly) BOOL isJSCSamplingProfilerAvailable;

/**
 * Whether the bridge is connected to a remote JS executor.
 */
@property (nonatomic, assign) BOOL isDebuggingRemotely;

/*
 * Whether shaking will show ABI24_0_0RCTDevMenu. The menu is enabled by default if ABI24_0_0RCT_DEV=1, but
 * you may wish to disable it so that you can provide your own shake handler.
 */
@property (nonatomic, assign) BOOL isShakeToShowDevMenuEnabled;

/**
 * Whether performance profiling is enabled.
 */
@property (nonatomic, assign, setter=setProfilingEnabled:) BOOL isProfilingEnabled;

/**
 * Whether automatic polling for JS code changes is enabled. Only applicable when
 * running the app from a server.
 */
@property (nonatomic, assign, setter=setLiveReloadEnabled:) BOOL isLiveReloadEnabled;

/**
 * Whether hot loading is enabled.
 */
@property (nonatomic, assign, setter=setHotLoadingEnabled:) BOOL isHotLoadingEnabled;

/**
 * Toggle the element inspector.
 */
- (void)toggleElementInspector;

/**
 * Toggle JSC's sampling profiler.
 */
- (void)toggleJSCSamplingProfiler;

/**
 * Enables starting of profiling sampler on launch
 */
@property (nonatomic, assign) BOOL startSamplingProfilerOnLaunch;

/**
 * Whether the element inspector is visible.
 */
@property (nonatomic, readonly) BOOL isElementInspectorShown;

/**
 * Whether the performance monitor is visible.
 */
@property (nonatomic, assign) BOOL isPerfMonitorShown;

#if ABI24_0_0RCT_DEV

- (void)addHandler:(id<ABI24_0_0RCTPackagerClientMethod>)handler forPackagerMethod:(NSString *)name;

#endif

@end

@interface ABI24_0_0RCTBridge (ABI24_0_0RCTDevSettings)

@property (nonatomic, readonly) ABI24_0_0RCTDevSettings *devSettings;

@end
