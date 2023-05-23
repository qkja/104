// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test_enum.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_test_5fenum_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_test_5fenum_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3021000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3021011 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/generated_enum_reflection.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_test_5fenum_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_test_5fenum_2eproto {
  static const uint32_t offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_test_5fenum_2eproto;
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

enum PhoneType : int {
  MP = 0,
  TEL = 1,
  PhoneType_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  PhoneType_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool PhoneType_IsValid(int value);
constexpr PhoneType PhoneType_MIN = MP;
constexpr PhoneType PhoneType_MAX = TEL;
constexpr int PhoneType_ARRAYSIZE = PhoneType_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PhoneType_descriptor();
template<typename T>
inline const std::string& PhoneType_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PhoneType>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PhoneType_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PhoneType_descriptor(), enum_t_value);
}
inline bool PhoneType_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PhoneType* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PhoneType>(
    PhoneType_descriptor(), name, value);
}
enum PhoneTypeCopy : int {
  MP_C = 0,
  PhoneTypeCopy_INT_MIN_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::min(),
  PhoneTypeCopy_INT_MAX_SENTINEL_DO_NOT_USE_ = std::numeric_limits<int32_t>::max()
};
bool PhoneTypeCopy_IsValid(int value);
constexpr PhoneTypeCopy PhoneTypeCopy_MIN = MP_C;
constexpr PhoneTypeCopy PhoneTypeCopy_MAX = MP_C;
constexpr int PhoneTypeCopy_ARRAYSIZE = PhoneTypeCopy_MAX + 1;

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PhoneTypeCopy_descriptor();
template<typename T>
inline const std::string& PhoneTypeCopy_Name(T enum_t_value) {
  static_assert(::std::is_same<T, PhoneTypeCopy>::value ||
    ::std::is_integral<T>::value,
    "Incorrect type passed to function PhoneTypeCopy_Name.");
  return ::PROTOBUF_NAMESPACE_ID::internal::NameOfEnum(
    PhoneTypeCopy_descriptor(), enum_t_value);
}
inline bool PhoneTypeCopy_Parse(
    ::PROTOBUF_NAMESPACE_ID::ConstStringParam name, PhoneTypeCopy* value) {
  return ::PROTOBUF_NAMESPACE_ID::internal::ParseNamedEnum<PhoneTypeCopy>(
    PhoneTypeCopy_descriptor(), name, value);
}
// ===================================================================


// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)


PROTOBUF_NAMESPACE_OPEN

template <> struct is_proto_enum< ::PhoneType> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::PhoneType>() {
  return ::PhoneType_descriptor();
}
template <> struct is_proto_enum< ::PhoneTypeCopy> : ::std::true_type {};
template <>
inline const EnumDescriptor* GetEnumDescriptor< ::PhoneTypeCopy>() {
  return ::PhoneTypeCopy_descriptor();
}

PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_test_5fenum_2eproto