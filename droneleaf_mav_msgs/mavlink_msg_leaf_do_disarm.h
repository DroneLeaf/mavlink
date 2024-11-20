#pragma once
// MESSAGE LEAF_DO_DISARM PACKING

#define MAVLINK_MSG_ID_LEAF_DO_DISARM 77004


typedef struct __mavlink_leaf_do_disarm_t {
 uint8_t target_system; /*<  The system needs to be disarmed*/
} mavlink_leaf_do_disarm_t;

#define MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN 1
#define MAVLINK_MSG_ID_LEAF_DO_DISARM_MIN_LEN 1
#define MAVLINK_MSG_ID_77004_LEN 1
#define MAVLINK_MSG_ID_77004_MIN_LEN 1

#define MAVLINK_MSG_ID_LEAF_DO_DISARM_CRC 221
#define MAVLINK_MSG_ID_77004_CRC 221



#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_LEAF_DO_DISARM { \
    77004, \
    "LEAF_DO_DISARM", \
    1, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_leaf_do_disarm_t, target_system) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_LEAF_DO_DISARM { \
    "LEAF_DO_DISARM", \
    1, \
    {  { "target_system", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_leaf_do_disarm_t, target_system) }, \
         } \
}
#endif

/**
 * @brief Pack a leaf_do_disarm message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param target_system  The system needs to be disarmed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_leaf_do_disarm_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN];
    _mav_put_uint8_t(buf, 0, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN);
#else
    mavlink_leaf_do_disarm_t packet;
    packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LEAF_DO_DISARM;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_LEAF_DO_DISARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_CRC);
}

/**
 * @brief Pack a leaf_do_disarm message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param target_system  The system needs to be disarmed
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_leaf_do_disarm_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN];
    _mav_put_uint8_t(buf, 0, target_system);

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN);
#else
    mavlink_leaf_do_disarm_t packet;
    packet.target_system = target_system;

        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_LEAF_DO_DISARM;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_LEAF_DO_DISARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_CRC);
}

/**
 * @brief Encode a leaf_do_disarm struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param leaf_do_disarm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_leaf_do_disarm_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_leaf_do_disarm_t* leaf_do_disarm)
{
    return mavlink_msg_leaf_do_disarm_pack(system_id, component_id, msg, leaf_do_disarm->target_system);
}

/**
 * @brief Encode a leaf_do_disarm struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param leaf_do_disarm C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_leaf_do_disarm_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_leaf_do_disarm_t* leaf_do_disarm)
{
    return mavlink_msg_leaf_do_disarm_pack_chan(system_id, component_id, chan, msg, leaf_do_disarm->target_system);
}

/**
 * @brief Send a leaf_do_disarm message
 * @param chan MAVLink channel to send the message
 *
 * @param target_system  The system needs to be disarmed
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_leaf_do_disarm_send(mavlink_channel_t chan, uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN];
    _mav_put_uint8_t(buf, 0, target_system);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEAF_DO_DISARM, buf, MAVLINK_MSG_ID_LEAF_DO_DISARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_CRC);
#else
    mavlink_leaf_do_disarm_t packet;
    packet.target_system = target_system;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEAF_DO_DISARM, (const char *)&packet, MAVLINK_MSG_ID_LEAF_DO_DISARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_CRC);
#endif
}

/**
 * @brief Send a leaf_do_disarm message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_leaf_do_disarm_send_struct(mavlink_channel_t chan, const mavlink_leaf_do_disarm_t* leaf_do_disarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_leaf_do_disarm_send(chan, leaf_do_disarm->target_system);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEAF_DO_DISARM, (const char *)leaf_do_disarm, MAVLINK_MSG_ID_LEAF_DO_DISARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_CRC);
#endif
}

#if MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This variant of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_leaf_do_disarm_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t target_system)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, target_system);

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEAF_DO_DISARM, buf, MAVLINK_MSG_ID_LEAF_DO_DISARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_CRC);
#else
    mavlink_leaf_do_disarm_t *packet = (mavlink_leaf_do_disarm_t *)msgbuf;
    packet->target_system = target_system;

    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_LEAF_DO_DISARM, (const char *)packet, MAVLINK_MSG_ID_LEAF_DO_DISARM_MIN_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN, MAVLINK_MSG_ID_LEAF_DO_DISARM_CRC);
#endif
}
#endif

#endif

// MESSAGE LEAF_DO_DISARM UNPACKING


/**
 * @brief Get field target_system from leaf_do_disarm message
 *
 * @return  The system needs to be disarmed
 */
static inline uint8_t mavlink_msg_leaf_do_disarm_get_target_system(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Decode a leaf_do_disarm message into a struct
 *
 * @param msg The message to decode
 * @param leaf_do_disarm C-struct to decode the message contents into
 */
static inline void mavlink_msg_leaf_do_disarm_decode(const mavlink_message_t* msg, mavlink_leaf_do_disarm_t* leaf_do_disarm)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    leaf_do_disarm->target_system = mavlink_msg_leaf_do_disarm_get_target_system(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN? msg->len : MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN;
        memset(leaf_do_disarm, 0, MAVLINK_MSG_ID_LEAF_DO_DISARM_LEN);
    memcpy(leaf_do_disarm, _MAV_PAYLOAD(msg), len);
#endif
}
