// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: test_enum.proto

#include "test_enum.pb.h"

#include <algorithm>

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/wire_format_lite.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>

PROTOBUF_PRAGMA_INIT_SEG

namespace _pb = ::PROTOBUF_NAMESPACE_ID;
namespace _pbi = _pb::internal;

static const ::_pb::EnumDescriptor* file_level_enum_descriptors_test_5fenum_2eproto[2];
static constexpr ::_pb::ServiceDescriptor const** file_level_service_descriptors_test_5fenum_2eproto = nullptr;
const uint32_t TableStruct_test_5fenum_2eproto::offsets[1] = {};
static constexpr ::_pbi::MigrationSchema* schemas = nullptr;
static constexpr ::_pb::Message* const* file_default_instances = nullptr;

const char descriptor_table_protodef_test_5fenum_2eproto[] PROTOBUF_SECTION_VARIABLE(protodesc_cold) =
  "\n\017test_enum.proto*\034\n\tPhoneType\022\006\n\002MP\020\000\022\007"
  "\n\003TEL\020\001*\031\n\rPhoneTypeCopy\022\010\n\004MP_C\020\000b\006prot"
  "o3"
  ;
static ::_pbi::once_flag descriptor_table_test_5fenum_2eproto_once;
const ::_pbi::DescriptorTable descriptor_table_test_5fenum_2eproto = {
    false, false, 82, descriptor_table_protodef_test_5fenum_2eproto,
    "test_enum.proto",
    &descriptor_table_test_5fenum_2eproto_once, nullptr, 0, 0,
    schemas, file_default_instances, TableStruct_test_5fenum_2eproto::offsets,
    nullptr, file_level_enum_descriptors_test_5fenum_2eproto,
    file_level_service_descriptors_test_5fenum_2eproto,
};
PROTOBUF_ATTRIBUTE_WEAK const ::_pbi::DescriptorTable* descriptor_table_test_5fenum_2eproto_getter() {
  return &descriptor_table_test_5fenum_2eproto;
}

// Force running AddDescriptors() at dynamic initialization time.
PROTOBUF_ATTRIBUTE_INIT_PRIORITY2 static ::_pbi::AddDescriptorsRunner dynamic_init_dummy_test_5fenum_2eproto(&descriptor_table_test_5fenum_2eproto);
const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PhoneType_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_test_5fenum_2eproto);
  return file_level_enum_descriptors_test_5fenum_2eproto[0];
}
bool PhoneType_IsValid(int value) {
  switch (value) {
    case 0:
    case 1:
      return true;
    default:
      return false;
  }
}

const ::PROTOBUF_NAMESPACE_ID::EnumDescriptor* PhoneTypeCopy_descriptor() {
  ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&descriptor_table_test_5fenum_2eproto);
  return file_level_enum_descriptors_test_5fenum_2eproto[1];
}
bool PhoneTypeCopy_IsValid(int value) {
  switch (value) {
    case 0:
      return true;
    default:
      return false;
  }
}


// @@protoc_insertion_point(namespace_scope)
PROTOBUF_NAMESPACE_OPEN
PROTOBUF_NAMESPACE_CLOSE

// @@protoc_insertion_point(global_scope)
#include <google/protobuf/port_undef.inc>