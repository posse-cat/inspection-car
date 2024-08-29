// Generated by gencpp from file camera_control_msgs/SetGainResponse.msg
// DO NOT EDIT!


#ifndef CAMERA_CONTROL_MSGS_MESSAGE_SETGAINRESPONSE_H
#define CAMERA_CONTROL_MSGS_MESSAGE_SETGAINRESPONSE_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace camera_control_msgs
{
template <class ContainerAllocator>
struct SetGainResponse_
{
  typedef SetGainResponse_<ContainerAllocator> Type;

  SetGainResponse_()
    : reached_gain(0.0)
    , success(false)  {
    }
  SetGainResponse_(const ContainerAllocator& _alloc)
    : reached_gain(0.0)
    , success(false)  {
  (void)_alloc;
    }



   typedef float _reached_gain_type;
  _reached_gain_type reached_gain;

   typedef uint8_t _success_type;
  _success_type success;





  typedef boost::shared_ptr< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> const> ConstPtr;

}; // struct SetGainResponse_

typedef ::camera_control_msgs::SetGainResponse_<std::allocator<void> > SetGainResponse;

typedef boost::shared_ptr< ::camera_control_msgs::SetGainResponse > SetGainResponsePtr;
typedef boost::shared_ptr< ::camera_control_msgs::SetGainResponse const> SetGainResponseConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::camera_control_msgs::SetGainResponse_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::camera_control_msgs::SetGainResponse_<ContainerAllocator1> & lhs, const ::camera_control_msgs::SetGainResponse_<ContainerAllocator2> & rhs)
{
  return lhs.reached_gain == rhs.reached_gain &&
    lhs.success == rhs.success;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::camera_control_msgs::SetGainResponse_<ContainerAllocator1> & lhs, const ::camera_control_msgs::SetGainResponse_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace camera_control_msgs

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct HasHeader< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "885668c9ebfd53815071a529456c4b42";
  }

  static const char* value(const ::camera_control_msgs::SetGainResponse_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0x885668c9ebfd5381ULL;
  static const uint64_t static_value2 = 0x5071a529456c4b42ULL;
};

template<class ContainerAllocator>
struct DataType< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "camera_control_msgs/SetGainResponse";
  }

  static const char* value(const ::camera_control_msgs::SetGainResponse_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> >
{
  static const char* value()
  {
    return "# Exact match can not always be reached\n"
"float32 reached_gain\n"
"bool success\n"
"\n"
;
  }

  static const char* value(const ::camera_control_msgs::SetGainResponse_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.reached_gain);
      stream.next(m.success);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct SetGainResponse_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::camera_control_msgs::SetGainResponse_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::camera_control_msgs::SetGainResponse_<ContainerAllocator>& v)
  {
    s << indent << "reached_gain: ";
    Printer<float>::stream(s, indent + "  ", v.reached_gain);
    s << indent << "success: ";
    Printer<uint8_t>::stream(s, indent + "  ", v.success);
  }
};

} // namespace message_operations
} // namespace ros

#endif // CAMERA_CONTROL_MSGS_MESSAGE_SETGAINRESPONSE_H
