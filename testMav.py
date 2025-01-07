#!/bin/python3

import sys, time
# Import mavutil
import MAV
from pymavlink import mavutil
# print(mavutil.__file__)

# Create the connection
master = mavutil.mavlink_connection('tcp:0.0.0.0:5760', source_system=0)
# Wait a heartbeat before sending commands
master.wait_heartbeat()

# Choose a mode
mode = MAV.LEAF_MODE_LEARNING
status = MAV.LEAF_STATUS_READY_TO_LEARN

# # Check if mode is available
# if mode not in master.mode_mapping():
#     print('Unknown mode : {}'.format(mode))
#     print('Try:', list(master.mode_mapping().keys()))
#     sys.exit(1)

# # Get mode ID
# mode_id = master.mode_mapping()[mode]
# # Set new mode
# # master.mav.command_long_send(
# #    master.target_system, master.target_component,
# #    mavutil.mavlink.MAV_CMD_DO_SET_MODE, 0,
# #    0, mode_id, 0, 0, 0, 0, 0) or:
# # master.set_mode(mode_id) or:
# master.mav.set_mode_send(
#     master.target_system,
#     mavutil.mavlink.MAV_MODE_FLAG_CUSTOM_MODE_ENABLED,
#     mode_id)

# while True:
#     # Wait for ACK command
#     # Would be good to add mechanism to avoid endlessly blocking
#     # if the autopilot sends a NACK or never receives the message
#     ack_msg = master.recv_match(type='COMMAND_ACK', blocking=True)
#     ack_msg = ack_msg.to_dict()

#     # Continue waiting if the acknowledged command is not `set_mode`
#     if ack_msg['command'] != mavutil.mavlink.MAV_CMD_DO_SET_MODE:
#         continue

#     # Print the ACK result !
#     print(mavutil.mavlink.enums['MAV_RESULT'][ack_msg['result']].description)
#     break

# Request all parameters
master.mav.param_request_list_send(
    master.target_system, master.target_component
)

while True:
    time.sleep(0.01)
    mode_msg = MAV.MAVLink_leaf_mode_message(mode)
    status_msg = MAV.MAVLink_leaf_status_message(status)
    master.mav.send(mode_msg)
    master.mav.send(status_msg)
    print(master.target_id)
    try:
        message = master.recv_match(type=MAV.MAVLINK_MSG_ID_LEAF_SET_MODE,  blocking=False)
        if message is not None:
            print(message)
    except Exception as error:
        print(error)