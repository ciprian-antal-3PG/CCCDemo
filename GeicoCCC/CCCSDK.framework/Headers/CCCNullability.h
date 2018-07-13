//
//  CCCNullability.h
//  CCCSDK
//
//  Created by Viggnesh K on 4/15/15.
//  Copyright (c) 2015 cccis. All rights reserved.
//

#ifndef CCCSDK_CCCNullability_h
#define CCCSDK_CCCNullability_h

///--------------------------------------
/// @name Nullability Annotation Support
///--------------------------------------

#if __has_feature(nullability)
#  define CCC_NONNULL nonnull
#  define CCC_NONNULL_S __nonnull
#  define CCC_NULLABLE nullable
#  define CCC_NULLABLE_S __nullable
#  define CCC_NULLABLE_PROPERTY nullable,
#else
#  define CCC_NONNULL
#  define CCC_NONNULL_S
#  define CCC_NULLABLE
#  define CCC_NULLABLE_S
#  define CCC_NULLABLE_PROPERTY
#endif

#if __has_feature(assume_nonnull)
#  ifdef NS_ASSUME_NONNULL_BEGIN
#    define CCC_ASSUME_NONNULL_BEGIN NS_ASSUME_NONNULL_BEGIN
#  else
#    define CCC_ASSUME_NONNULL_BEGIN _Pragma("clang assume_nonnull begin")
#  endif
#  ifdef NS_ASSUME_NONNULL_END
#    define CCC_ASSUME_NONNULL_END NS_ASSUME_NONNULL_END
#  else
#    define CCC_ASSUME_NONNULL_END _Pragma("clang assume_nonnull end")
#  endif
#else
#  define CCC_ASSUME_NONNULL_BEGIN
#  define CCC_ASSUME_NONNULL_END
#endif

#endif
