#pragma once
// MESSAGE LEAF_DO_ARM PACKING

#define MAVLINK_MSG_ID_LEAF_DO_ARM 77003


typedef struct __mavlink_leaf_do_arm_t {
 uint8_t target_system; /*<  The system needs to be armed*/
} mavlink_leaf_do_arm_t;

#define MAVLINK_MSG_ID_LEAF_DO_ARM_LEN 1
#define MAVLINK_MSG_ID_LEAF_DO_ARM_MIN_LEN 1
#define MAVLINK_MSG_ID_77003_LEN 1
#define MAVLINK_MSG_ID_77003_MIN_LEN 1

#define MAVLINK_MSG_ID_LEAF_DO_ARM_CRC 236
#define MAVLINK_MSG_ID_77003_CRC 236



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LEAF_DO_ARM { \
    77003, \
    "LEAF_DO_ARM", \
    1, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_leaf_do_arm_t, target_system) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LEAF_DO_ARM { \
    "LEAF_DO_ARM", \
    1, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_leaf_do_arm_t, target_system) }, \
         } \
}
#endif

/**
 * @brief Pack a leaf_do_arm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  The system needs to be armed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_leaf_do_arm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LEAF_DO_ARM_LEN];
    _mav_put_uint8_t(buf, 0, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN);
#else
    mavlink_leaf_do_arm_t packet;
    packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LEAF_DO_ARM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LEAF_DO_ARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_CRC);
}

/**
 * @brief Pack a leaf_do_arm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  The system needs to be armed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_leaf_do_arm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LEAF_DO_ARM_LEN];
    _mav_put_uint8_t(buf, 0, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN);
#else
    mavlink_leaf_do_arm_t packet;
    packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LEAF_DO_ARM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LEAF_DO_ARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_CRC);
}

/**
 * @brief Encode a leaf_do_arm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param leaf_do_arm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_leaf_do_arm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_leaf_do_arm_t* leaf_do_arm)
{
    return mavlink_msg_leaf_do_arm_pack(system_id, component_id, msg, leaf_do_arm->target_system);
}

/**
 * @brief Encode a leaf_do_arm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param leaf_do_arm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_leaf_do_arm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_leaf_do_arm_t* leaf_do_arm)
{
    return mavlink_msg_leaf_do_arm_pack_chan(system_id, component_id, chan, msg, leaf_do_arm->target_system);
}

/**
 * @brief Send a leaf_do_arm message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  The system needs to be armed
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_leaf_do_arm_send(mavlink_channel_t chan, uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LEAF_DO_ARM_LEN];
    _mav_put_uint8_t(buf, 0, target_system);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEAF_DO_ARM, buf, MAVLINK_MSG_ID_LEAF_DO_ARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_CRC);
#else
    mavlink_leaf_do_arm_t packet;
    packet.target_system = target_system;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEAF_DO_ARM, (const char *)&packet, MAVLINK_MSG_ID_LEAF_DO_ARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_CRC);
#endif
}

/**
 * @brief Send a leaf_do_arm message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_leaf_do_arm_send_struct(mavlink_channel_t chan, const mavlink_leaf_do_arm_t* leaf_do_arm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_leaf_do_arm_send(chan, leaf_do_arm->target_system);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEAF_DO_ARM, (const char *)leaf_do_arm, MAVLINK_MSG_ID_LEAF_DO_ARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_CRC);
#endif
}

#if MAVLINK_MSG_ID_LEAF_DO_ARM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_leaf_do_arm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEAF_DO_ARM, buf, MAVLINK_MSG_ID_LEAF_DO_ARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_CRC);
#else
    mavlink_leaf_do_arm_t *packet = (mavlink_leaf_do_arm_t *)msgbuf;
    packet->target_system = target_system;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEAF_DO_ARM, (const char *)packet, MAVLINK_MSG_ID_LEAF_DO_ARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN, MAVLINK_MSG_ID_LEAF_DO_ARM_CRC);
#endif
}
#endif

#endif

// MESSAGE LEAF_DO_ARM UNPACKING


/**
 * @brief Get field target_system from leaf_do_arm message
 *
 * @return  The system needs to be armed
 */
static inline uint8_t mavlink_msg_leaf_do_arm_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a leaf_do_arm message into a struct
 *
 * @param msg The message to decode
 * @param leaf_do_arm C-struct to decode the message contents into
 */
static inline void mavlink_msg_leaf_do_arm_decode(const mavlink_message_t* msg, mavlink_leaf_do_arm_t* leaf_do_arm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    leaf_do_arm->target_system = mavlink_msg_leaf_do_arm_get_target_system(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LEAF_DO_ARM_LEN? msg->len : MAVLINK_MSG_ID_LEAF_DO_ARM_LEN;
        memset(leaf_do_arm, 0, MAVLINK_MSG_ID_LEAF_DO_ARM_LEN);
    memcpy(leaf_do_arm, _MAV_PAYLOAD(msg), len);
#endif
}
