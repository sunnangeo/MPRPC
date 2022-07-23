// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mprpcheader.proto

#ifndef PROTOBUF_mprpcheader_2eproto__INCLUDED
#define PROTOBUF_mprpcheader_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace mprpc {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_mprpcheader_2eproto();
void protobuf_AssignDesc_mprpcheader_2eproto();
void protobuf_ShutdownFile_mprpcheader_2eproto();

class MprpcHeader;

// ===================================================================

class MprpcHeader : public ::google::protobuf::Message {
 public:
  MprpcHeader();
  virtual ~MprpcHeader();

  MprpcHeader(const MprpcHeader& from);

  inline MprpcHeader& operator=(const MprpcHeader& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const MprpcHeader& default_instance();

  void Swap(MprpcHeader* other);

  // implements Message ----------------------------------------------

  MprpcHeader* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const MprpcHeader& from);
  void MergeFrom(const MprpcHeader& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional bytes service_name = 1;
  inline bool has_service_name() const;
  inline void clear_service_name();
  static const int kServiceNameFieldNumber = 1;
  inline const ::std::string& service_name() const;
  inline void set_service_name(const ::std::string& value);
  inline void set_service_name(const char* value);
  inline void set_service_name(const void* value, size_t size);
  inline ::std::string* mutable_service_name();
  inline ::std::string* release_service_name();
  inline void set_allocated_service_name(::std::string* service_name);

  // optional bytes method_name = 2;
  inline bool has_method_name() const;
  inline void clear_method_name();
  static const int kMethodNameFieldNumber = 2;
  inline const ::std::string& method_name() const;
  inline void set_method_name(const ::std::string& value);
  inline void set_method_name(const char* value);
  inline void set_method_name(const void* value, size_t size);
  inline ::std::string* mutable_method_name();
  inline ::std::string* release_method_name();
  inline void set_allocated_method_name(::std::string* method_name);

  // optional uint32 args_size = 3;
  inline bool has_args_size() const;
  inline void clear_args_size();
  static const int kArgsSizeFieldNumber = 3;
  inline ::google::protobuf::uint32 args_size() const;
  inline void set_args_size(::google::protobuf::uint32 value);

  // @@protoc_insertion_point(class_scope:mprpc.MprpcHeader)
 private:
  inline void set_has_service_name();
  inline void clear_has_service_name();
  inline void set_has_method_name();
  inline void clear_has_method_name();
  inline void set_has_args_size();
  inline void clear_has_args_size();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* service_name_;
  ::std::string* method_name_;
  ::google::protobuf::uint32 args_size_;
  friend void  protobuf_AddDesc_mprpcheader_2eproto();
  friend void protobuf_AssignDesc_mprpcheader_2eproto();
  friend void protobuf_ShutdownFile_mprpcheader_2eproto();

  void InitAsDefaultInstance();
  static MprpcHeader* default_instance_;
};
// ===================================================================


// ===================================================================

// MprpcHeader

// optional bytes service_name = 1;
inline bool MprpcHeader::has_service_name() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void MprpcHeader::set_has_service_name() {
  _has_bits_[0] |= 0x00000001u;
}
inline void MprpcHeader::clear_has_service_name() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void MprpcHeader::clear_service_name() {
  if (service_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    service_name_->clear();
  }
  clear_has_service_name();
}
inline const ::std::string& MprpcHeader::service_name() const {
  // @@protoc_insertion_point(field_get:mprpc.MprpcHeader.service_name)
  return *service_name_;
}
inline void MprpcHeader::set_service_name(const ::std::string& value) {
  set_has_service_name();
  if (service_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    service_name_ = new ::std::string;
  }
  service_name_->assign(value);
  // @@protoc_insertion_point(field_set:mprpc.MprpcHeader.service_name)
}
inline void MprpcHeader::set_service_name(const char* value) {
  set_has_service_name();
  if (service_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    service_name_ = new ::std::string;
  }
  service_name_->assign(value);
  // @@protoc_insertion_point(field_set_char:mprpc.MprpcHeader.service_name)
}
inline void MprpcHeader::set_service_name(const void* value, size_t size) {
  set_has_service_name();
  if (service_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    service_name_ = new ::std::string;
  }
  service_name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:mprpc.MprpcHeader.service_name)
}
inline ::std::string* MprpcHeader::mutable_service_name() {
  set_has_service_name();
  if (service_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    service_name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:mprpc.MprpcHeader.service_name)
  return service_name_;
}
inline ::std::string* MprpcHeader::release_service_name() {
  clear_has_service_name();
  if (service_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = service_name_;
    service_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void MprpcHeader::set_allocated_service_name(::std::string* service_name) {
  if (service_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete service_name_;
  }
  if (service_name) {
    set_has_service_name();
    service_name_ = service_name;
  } else {
    clear_has_service_name();
    service_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:mprpc.MprpcHeader.service_name)
}

// optional bytes method_name = 2;
inline bool MprpcHeader::has_method_name() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void MprpcHeader::set_has_method_name() {
  _has_bits_[0] |= 0x00000002u;
}
inline void MprpcHeader::clear_has_method_name() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void MprpcHeader::clear_method_name() {
  if (method_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    method_name_->clear();
  }
  clear_has_method_name();
}
inline const ::std::string& MprpcHeader::method_name() const {
  // @@protoc_insertion_point(field_get:mprpc.MprpcHeader.method_name)
  return *method_name_;
}
inline void MprpcHeader::set_method_name(const ::std::string& value) {
  set_has_method_name();
  if (method_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    method_name_ = new ::std::string;
  }
  method_name_->assign(value);
  // @@protoc_insertion_point(field_set:mprpc.MprpcHeader.method_name)
}
inline void MprpcHeader::set_method_name(const char* value) {
  set_has_method_name();
  if (method_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    method_name_ = new ::std::string;
  }
  method_name_->assign(value);
  // @@protoc_insertion_point(field_set_char:mprpc.MprpcHeader.method_name)
}
inline void MprpcHeader::set_method_name(const void* value, size_t size) {
  set_has_method_name();
  if (method_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    method_name_ = new ::std::string;
  }
  method_name_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:mprpc.MprpcHeader.method_name)
}
inline ::std::string* MprpcHeader::mutable_method_name() {
  set_has_method_name();
  if (method_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    method_name_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:mprpc.MprpcHeader.method_name)
  return method_name_;
}
inline ::std::string* MprpcHeader::release_method_name() {
  clear_has_method_name();
  if (method_name_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = method_name_;
    method_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void MprpcHeader::set_allocated_method_name(::std::string* method_name) {
  if (method_name_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete method_name_;
  }
  if (method_name) {
    set_has_method_name();
    method_name_ = method_name;
  } else {
    clear_has_method_name();
    method_name_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:mprpc.MprpcHeader.method_name)
}

// optional uint32 args_size = 3;
inline bool MprpcHeader::has_args_size() const {
  return (_has_bits_[0] & 0x00000004u) != 0;
}
inline void MprpcHeader::set_has_args_size() {
  _has_bits_[0] |= 0x00000004u;
}
inline void MprpcHeader::clear_has_args_size() {
  _has_bits_[0] &= ~0x00000004u;
}
inline void MprpcHeader::clear_args_size() {
  args_size_ = 0u;
  clear_has_args_size();
}
inline ::google::protobuf::uint32 MprpcHeader::args_size() const {
  // @@protoc_insertion_point(field_get:mprpc.MprpcHeader.args_size)
  return args_size_;
}
inline void MprpcHeader::set_args_size(::google::protobuf::uint32 value) {
  set_has_args_size();
  args_size_ = value;
  // @@protoc_insertion_point(field_set:mprpc.MprpcHeader.args_size)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace mprpc

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_mprpcheader_2eproto__INCLUDED
