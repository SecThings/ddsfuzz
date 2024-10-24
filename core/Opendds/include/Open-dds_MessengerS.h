

#ifndef _TAO_IDL__HOME_DPL5626_DDS_FUZZ_OPEN_DDS_BUILD_OPENDDS_GENERATED_OPEN_DDS_MESSENGERS_H_
#define _TAO_IDL__HOME_DPL5626_DDS_FUZZ_OPEN_DDS_BUILD_OPENDDS_GENERATED_OPEN_DDS_MESSENGERS_H_

#include /**/ "ace/pre.h"

#include "Open-dds_MessengerC.h"
#include "tao/PortableServer/Basic_SArguments.h"
#include "tao/PortableServer/Special_Basic_SArguments.h"
#include "tao/PortableServer/Fixed_Size_SArgument_T.h"
#include "tao/PortableServer/Var_Size_SArgument_T.h"
#include "tao/PortableServer/UB_String_SArguments.h"

// Skeleton file generation suppressed with command line option -SS
// TAO_IDL - Generated from
// /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:64



TAO_BEGIN_VERSIONED_NAMESPACE_DECL


// Arg traits specializations.
namespace TAO
{
  // TAO_IDL - Generated from
  // /home/dpl5626/OpenDDS-3.26/ACE_wrappers/TAO/TAO_IDL/be/be_visitor_arg_traits.cpp:932

  

  template<>
  class SArg_Traits< ::Messenger::Message>
    : public
        Var_Size_SArg_Traits_T<
            ::Messenger::Message,
            TAO::Any_Insert_Policy_Noop
          >
  {
  };
}

TAO_END_VERSIONED_NAMESPACE_DECL



#include /**/ "ace/post.h"

#endif /* ifndef */

