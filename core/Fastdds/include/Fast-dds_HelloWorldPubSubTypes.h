

/*!
 * @file HelloWorldPubSubTypes.h
 */


#ifndef _FAST_DDS_GENERATED_HELLOWORLD_PUBSUBTYPES_H_
#define _FAST_DDS_GENERATED_HELLOWORLD_PUBSUBTYPES_H_

#include <fastdds/dds/topic/TopicDataType.hpp>
#include <fastrtps/utils/md5.h>

#include "Fast-dds_HelloWorld.h"

#if !defined(GEN_API_VER) || (GEN_API_VER != 1)
#error \
    Generated HelloWorld is not compatible with current installed Fast DDS. Please, regenerate it with fastddsgen.
#endif  // GEN_API_VER

/*!
 * @brief This class represents the TopicDataType of the type HelloWorld defined by the user in the IDL file.
 * @ingroup HELLOWORLD
 */
class HelloWorldPubSubType : public eprosima::fastdds::dds::TopicDataType
{
public:

    typedef HelloWorld type;

    eProsima_user_DllExport HelloWorldPubSubType();

    eProsima_user_DllExport virtual ~HelloWorldPubSubType() override;

    eProsima_user_DllExport virtual bool serialize(
            void* data,
            eprosima::fastrtps::rtps::SerializedPayload_t* payload) override;

    eProsima_user_DllExport virtual bool deserialize(
            eprosima::fastrtps::rtps::SerializedPayload_t* payload,
            void* data) override;

    eProsima_user_DllExport virtual std::function<uint32_t()> getSerializedSizeProvider(
            void* data) override;

    eProsima_user_DllExport virtual bool getKey(
            void* data,
            eprosima::fastrtps::rtps::InstanceHandle_t* ihandle,
            bool force_md5 = false) override;

    eProsima_user_DllExport virtual void* createData() override;

    eProsima_user_DllExport virtual void deleteData(
            void* data) override;

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED
    eProsima_user_DllExport inline bool is_bounded() const override
    {
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_BOUNDED

#ifdef TOPIC_DATA_TYPE_API_HAS_IS_PLAIN
    eProsima_user_DllExport inline bool is_plain() const override
    {
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_IS_PLAIN

#ifdef TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE
    eProsima_user_DllExport inline bool construct_sample(
            void* memory) const override
    {
        (void)memory;
        return false;
    }

#endif  // TOPIC_DATA_TYPE_API_HAS_CONSTRUCT_SAMPLE

    MD5 m_md5;
    unsigned char* m_keyBuffer;
};

#endif // _FAST_DDS_GENERATED_HELLOWORLD_PUBSUBTYPES_H_