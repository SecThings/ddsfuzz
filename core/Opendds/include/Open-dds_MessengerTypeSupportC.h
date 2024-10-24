

#ifndef _TAO_IDL__HOME_DPL5626_DDS_FUZZ_OPEN_DDS_BUILD_OPENDDS_GENERATED_OPEN_DDS_MESSENGERTYPESUPPORTC_H_
#define _TAO_IDL__HOME_DPL5626_DDS_FUZZ_OPEN_DDS_BUILD_OPENDDS_GENERATED_OPEN_DDS_MESSENGERTYPESUPPORTC_H_

#include /**/ "ace/pre.h"


#include /**/ "ace/config-all.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */


#include "tao/ORB.h"
#include "tao/SystemException.h"
#include "tao/Basic_Types_IDLv4.h"
TAO_BEGIN_VERSIONED_NAMESPACE_DECL

namespace CORBA
{
  using namespace IDLv4;
}

TAO_END_VERSIONED_NAMESPACE_DECL

#include "tao/ORB_Constants.h"
#include "dds/DCPS/ZeroCopyInfoSeq_T.h"
#include "dds/DCPS/ZeroCopySeq_T.h"
#include "tao/Object.h"
#include "tao/String_Manager_T.h"
#include "tao/Sequence_T.h"
#include "tao/Objref_VarOut_T.h"
#include "tao/Seq_Var_T.h"
#include "tao/Seq_Out_T.h"
#include "tao/Arg_Traits_T.h"
#include "tao/Basic_Arguments.h"
#include "tao/Special_Basic_Arguments.h"
#include "tao/Any_Insert_Policy_T.h"
#include "tao/Fixed_Size_Argument_T.h"
#include "tao/Var_Size_Argument_T.h"
#include "tao/UB_String_Arguments.h"
#include /**/ "tao/Version.h"
#include /**/ "tao/Versioned_Namespace.h"

#include "Open-dds_MessengerC.h"
#include "dds/DdsDcpsInfrastructureC.h"
#include "dds/DdsDcpsPublicationC.h"
#include "dds/DdsDcpsSubscriptionExtC.h"
#include "dds/DdsDcpsTopicC.h"
#include "dds/DdsDcpsTypeSupportExtC.h"

#if TAO_MAJOR_VERSION != 2 || TAO_MINOR_VERSION != 5 || TAO_MICRO_VERSION != 20
//#error This file should be regenerated with TAO_IDL
#endif
// TAO_IDL - Generated from
// /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:34

namespace Messenger
{

  
  // TAO_IDL - Generated from
  // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_sequence/sequence_ch.cpp:98

  

  typedef ::TAO::DCPS::ZeroCopyDataSeq< Messenger::Message, DCPS_ZERO_COPY_SEQ_DEFAULT_SIZE> MessageSeq;
  
  // TAO_IDL - Generated from
  // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_interface.cpp:747

  

#if !defined (_MESSENGER_MESSAGETYPESUPPORT__VAR_OUT_CH_)
#define _MESSENGER_MESSAGETYPESUPPORT__VAR_OUT_CH_

  class MessageTypeSupport;
  typedef MessageTypeSupport *MessageTypeSupport_ptr;
  typedef TAO_Objref_Var_T<MessageTypeSupport> MessageTypeSupport_var;
  typedef TAO_Objref_Out_T<MessageTypeSupport> MessageTypeSupport_out;
  

#endif /* end #if !defined */

  
  // TAO_IDL - Generated from
  // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:39

  

  class  MessageTypeSupport
    : public virtual ::OpenDDS::DCPS::TypeSupport
  
  {
  public:
    // TAO_IDL - Generated from
    // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_type.cpp:301

    typedef MessageTypeSupport_ptr _ptr_type;
    typedef MessageTypeSupport_var _var_type;
    typedef MessageTypeSupport_out _out_type;

    // The static operations.
    static MessageTypeSupport_ptr _duplicate (MessageTypeSupport_ptr obj);

    static void _tao_release (MessageTypeSupport_ptr obj);

    static MessageTypeSupport_ptr _narrow (::CORBA::Object_ptr obj);
    static MessageTypeSupport_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static MessageTypeSupport_ptr _nil (void);

    virtual ::DDS::ReturnCode_t encode_to_string (
      const ::Messenger::Message & sample,
      ::CORBA::String_out encoded,
      ::OpenDDS::DCPS::RepresentationFormat_ptr format) = 0;

    virtual ::DDS::ReturnCode_t encode_to_bytes (
      const ::Messenger::Message & sample,
      ::DDS::OctetSeq_out encoded,
      ::OpenDDS::DCPS::RepresentationFormat_ptr format) = 0;

    virtual ::DDS::ReturnCode_t decode_from_string (
      const char * encoded,
      ::Messenger::Message_out sample,
      ::OpenDDS::DCPS::RepresentationFormat_ptr format) = 0;

    virtual ::DDS::ReturnCode_t decode_from_bytes (
      const ::DDS::OctetSeq & encoded,
      ::Messenger::Message_out sample,
      ::OpenDDS::DCPS::RepresentationFormat_ptr format) = 0;

    
    // TAO_IDL - Generated from
    // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:135

    

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    MessageTypeSupport (void);

    

    virtual ~MessageTypeSupport (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ACE_UNIMPLEMENTED_FUNC (MessageTypeSupport (const MessageTypeSupport &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (MessageTypeSupport (MessageTypeSupport &&))
#endif /* ACE_HAS_CPP11 */
    ACE_UNIMPLEMENTED_FUNC (MessageTypeSupport &operator= (const MessageTypeSupport &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (MessageTypeSupport &operator= (MessageTypeSupport &&))
#endif /* ACE_HAS_CPP11 */
  };
  // TAO_IDL - Generated from
  // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_interface.cpp:747

  

#if !defined (_MESSENGER_MESSAGEDATAWRITER__VAR_OUT_CH_)
#define _MESSENGER_MESSAGEDATAWRITER__VAR_OUT_CH_

  class MessageDataWriter;
  typedef MessageDataWriter *MessageDataWriter_ptr;
  typedef TAO_Objref_Var_T<MessageDataWriter> MessageDataWriter_var;
  typedef TAO_Objref_Out_T<MessageDataWriter> MessageDataWriter_out;
  

#endif /* end #if !defined */

  
  // TAO_IDL - Generated from
  // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:39

  

  class  MessageDataWriter
    : public virtual ::DDS::DataWriter
  
  {
  public:
    // TAO_IDL - Generated from
    // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_type.cpp:301

    typedef MessageDataWriter_ptr _ptr_type;
    typedef MessageDataWriter_var _var_type;
    typedef MessageDataWriter_out _out_type;

    // The static operations.
    static MessageDataWriter_ptr _duplicate (MessageDataWriter_ptr obj);

    static void _tao_release (MessageDataWriter_ptr obj);

    static MessageDataWriter_ptr _narrow (::CORBA::Object_ptr obj);
    static MessageDataWriter_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static MessageDataWriter_ptr _nil (void);

    virtual ::DDS::InstanceHandle_t register_instance (
      const ::Messenger::Message & instance) = 0;

    virtual ::DDS::InstanceHandle_t register_instance_w_timestamp (
      const ::Messenger::Message & instance,
      const ::DDS::Time_t & timestamp) = 0;

    virtual ::DDS::ReturnCode_t unregister_instance (
      const ::Messenger::Message & instance,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::ReturnCode_t unregister_instance_w_timestamp (
      const ::Messenger::Message & instance,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & timestamp) = 0;

    virtual ::DDS::ReturnCode_t write (
      const ::Messenger::Message & instance_data,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::ReturnCode_t write_w_timestamp (
      const ::Messenger::Message & instance_data,
      ::DDS::InstanceHandle_t handle,
      const ::DDS::Time_t & source_timestamp) = 0;

    virtual ::DDS::ReturnCode_t dispose (
      const ::Messenger::Message & instance_data,
      ::DDS::InstanceHandle_t instance_handle) = 0;

    virtual ::DDS::ReturnCode_t dispose_w_timestamp (
      const ::Messenger::Message & instance_data,
      ::DDS::InstanceHandle_t instance_handle,
      const ::DDS::Time_t & source_timestamp) = 0;

    virtual ::DDS::ReturnCode_t get_key_value (
      ::Messenger::Message & key_holder,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::InstanceHandle_t lookup_instance (
      const ::Messenger::Message & instance_data) = 0;

    
    // TAO_IDL - Generated from
    // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:135

    

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    MessageDataWriter (void);

    

    virtual ~MessageDataWriter (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ACE_UNIMPLEMENTED_FUNC (MessageDataWriter (const MessageDataWriter &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (MessageDataWriter (MessageDataWriter &&))
#endif /* ACE_HAS_CPP11 */
    ACE_UNIMPLEMENTED_FUNC (MessageDataWriter &operator= (const MessageDataWriter &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (MessageDataWriter &operator= (MessageDataWriter &&))
#endif /* ACE_HAS_CPP11 */
  };
  // TAO_IDL - Generated from
  // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_interface.cpp:747

  

#if !defined (_MESSENGER_MESSAGEDATAREADER__VAR_OUT_CH_)
#define _MESSENGER_MESSAGEDATAREADER__VAR_OUT_CH_

  class MessageDataReader;
  typedef MessageDataReader *MessageDataReader_ptr;
  typedef TAO_Objref_Var_T<MessageDataReader> MessageDataReader_var;
  typedef TAO_Objref_Out_T<MessageDataReader> MessageDataReader_out;
  

#endif /* end #if !defined */

  
  // TAO_IDL - Generated from
  // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:39

  

  class  MessageDataReader
    : public virtual ::OpenDDS::DCPS::DataReaderEx
  
  {
  public:
    // TAO_IDL - Generated from
    // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_type.cpp:301

    typedef MessageDataReader_ptr _ptr_type;
    typedef MessageDataReader_var _var_type;
    typedef MessageDataReader_out _out_type;

    // The static operations.
    static MessageDataReader_ptr _duplicate (MessageDataReader_ptr obj);

    static void _tao_release (MessageDataReader_ptr obj);

    static MessageDataReader_ptr _narrow (::CORBA::Object_ptr obj);
    static MessageDataReader_ptr _unchecked_narrow (::CORBA::Object_ptr obj);
    static MessageDataReader_ptr _nil (void);

    virtual ::DDS::ReturnCode_t read (
      ::Messenger::MessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t take (
      ::Messenger::MessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t read_w_condition (
      ::Messenger::MessageSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t take_w_condition (
      ::Messenger::MessageSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t read_next_sample (
      ::Messenger::Message & received_data,
      ::DDS::SampleInfo & sample_info) = 0;

    virtual ::DDS::ReturnCode_t take_next_sample (
      ::Messenger::Message & received_data,
      ::DDS::SampleInfo & sample_info) = 0;

    virtual ::DDS::ReturnCode_t read_instance (
      ::Messenger::MessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t take_instance (
      ::Messenger::MessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t read_instance_w_condition (
      ::Messenger::MessageSeq & received_data,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t take_instance_w_condition (
      ::Messenger::MessageSeq & received_data,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t read_next_instance (
      ::Messenger::MessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t take_next_instance (
      ::Messenger::MessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t a_handle,
      ::DDS::SampleStateMask sample_states,
      ::DDS::ViewStateMask view_states,
      ::DDS::InstanceStateMask instance_states) = 0;

    virtual ::DDS::ReturnCode_t read_next_instance_w_condition (
      ::Messenger::MessageSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t previous_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t take_next_instance_w_condition (
      ::Messenger::MessageSeq & data_values,
      ::DDS::SampleInfoSeq & sample_infos,
      ::CORBA::Long max_samples,
      ::DDS::InstanceHandle_t previous_handle,
      ::DDS::ReadCondition_ptr a_condition) = 0;

    virtual ::DDS::ReturnCode_t return_loan (
      ::Messenger::MessageSeq & received_data,
      ::DDS::SampleInfoSeq & info_seq) = 0;

    virtual ::DDS::ReturnCode_t get_key_value (
      ::Messenger::Message & key_holder,
      ::DDS::InstanceHandle_t handle) = 0;

    virtual ::DDS::InstanceHandle_t lookup_instance (
      const ::Messenger::Message & instance_data) = 0;

    
    // TAO_IDL - Generated from
    // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_interface/interface_ch.cpp:135

    

    virtual ::CORBA::Boolean _is_a (const char *type_id);
    virtual const char* _interface_repository_id (void) const;
    virtual ::CORBA::Boolean marshal (TAO_OutputCDR &cdr);
  
  protected:
    // Abstract or local interface only.
    MessageDataReader (void);

    

    virtual ~MessageDataReader (void);
  
  private:
    // Private and unimplemented for concrete interfaces.
    ACE_UNIMPLEMENTED_FUNC (MessageDataReader (const MessageDataReader &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (MessageDataReader (MessageDataReader &&))
#endif /* ACE_HAS_CPP11 */
    ACE_UNIMPLEMENTED_FUNC (MessageDataReader &operator= (const MessageDataReader &))
#if defined (ACE_HAS_CPP11)
    ACE_UNIMPLEMENTED_FUNC (MessageDataReader &operator= (MessageDataReader &&))
#endif /* ACE_HAS_CPP11 */
  };


// TAO_IDL - Generated from
// /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_module/module_ch.cpp:62


} // module Messenger
// TAO_IDL - Generated from
// /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:64



TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
}

TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_traits.cpp:58



TAO_BEGIN_VERSIONED_NAMESPACE_DECL

// Traits specializations.
namespace TAO
{

#if !defined (_MESSENGER_MESSAGETYPESUPPORT__TRAITS_)
#define _MESSENGER_MESSAGETYPESUPPORT__TRAITS_

  template<>
  struct  Objref_Traits< ::Messenger::MessageTypeSupport>
  {
    static ::Messenger::MessageTypeSupport_ptr duplicate (
        ::Messenger::MessageTypeSupport_ptr p);
    static void release (
        ::Messenger::MessageTypeSupport_ptr p);
    static ::Messenger::MessageTypeSupport_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::Messenger::MessageTypeSupport_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_MESSENGER_MESSAGEDATAWRITER__TRAITS_)
#define _MESSENGER_MESSAGEDATAWRITER__TRAITS_

  template<>
  struct  Objref_Traits< ::Messenger::MessageDataWriter>
  {
    static ::Messenger::MessageDataWriter_ptr duplicate (
        ::Messenger::MessageDataWriter_ptr p);
    static void release (
        ::Messenger::MessageDataWriter_ptr p);
    static ::Messenger::MessageDataWriter_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::Messenger::MessageDataWriter_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */

#if !defined (_MESSENGER_MESSAGEDATAREADER__TRAITS_)
#define _MESSENGER_MESSAGEDATAREADER__TRAITS_

  template<>
  struct  Objref_Traits< ::Messenger::MessageDataReader>
  {
    static ::Messenger::MessageDataReader_ptr duplicate (
        ::Messenger::MessageDataReader_ptr p);
    static void release (
        ::Messenger::MessageDataReader_ptr p);
    static ::Messenger::MessageDataReader_ptr nil (void);
    static ::CORBA::Boolean marshal (
        const ::Messenger::MessageDataReader_ptr p,
        TAO_OutputCDR & cdr);
  };

#endif /* end #if !defined */
}
TAO_END_VERSIONED_NAMESPACE_DECL


// TAO_IDL - Generated from
// /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_codegen.cpp:1649

#if defined (__ACE_INLINE__)
#include "Open-dds_MessengerTypeSupportC.inl"
#endif /* defined INLINE */

#include /**/ "ace/post.h"

#endif /* ifndef */

