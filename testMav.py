#!/bin/python3

import sys, time
# Import mavutil
import MAV
from pymavlink import mavutil
# print(mavutil.__file__)

# Create the connection
master = mavutil.mavlink_connection('tcp:0.0.0.0:5760', source_system=3)
# Wait a heartbeat before sending commands
master.wait_heartbeat()

# Choose a mode
mode = MAV.LEAF_MODE_INSPECTION
status = MAV.LEAF_STATUS_READY_TO_FLY

# Request all parameters
master.mav.param_request_list_send(
    master.target_system, master.target_component
)

client_msg = MAV.MAVLink_leaf_client_tagname_message("ENEC")
master.mav.send(client_msg)
while True:
    time.sleep(0.1)
    mode_msg = MAV.MAVLink_leaf_mode_message(mode)
    status_msg = MAV.MAVLink_leaf_status_message(status)
    master.mav.send(mode_msg)
    master.mav.send(status_msg)
    
    try:
        message = master.recv_match(type=MAV.MAVLINK_MSG_ID_LEAF_SET_MODE,  blocking=False)
        if message is not None:
            print(message)
    except Exception as error:
        print(error)